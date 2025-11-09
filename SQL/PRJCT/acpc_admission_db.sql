-- ============================================================
-- MODULE 1 & 2: APPLICANT REGISTRATION AND PROFILE
-- ============================================================

CREATE TABLE applicants (
    applicant_id SERIAL PRIMARY KEY,
    app_number VARCHAR(20) UNIQUE NOT NULL,
    full_name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phone VARCHAR(15) NOT NULL,
    dob DATE NOT NULL,
    gender VARCHAR(10) CHECK (gender IN ('Male', 'Female', 'Other')),
    address TEXT,
    city VARCHAR(50),
    state VARCHAR(50) NOT NULL,
    pincode VARCHAR(10),
    category VARCHAR(10) CHECK (category IN ('OPEN','SC','ST','SEBC','EWS')) NOT NULL,
    jee_roll_number VARCHAR(20) UNIQUE,
    jee_rank INT NOT NULL,
    jee_percentile DECIMAL(6,3),
    percentage_12th DECIMAL(5,2) NOT NULL,
    docs_verified BOOLEAN DEFAULT FALSE,
    password_hash VARCHAR(255),
    registration_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ============================================================
-- MODULE 3: COLLEGE AND COURSES MANAGEMENT
-- ============================================================

CREATE TABLE colleges (
    college_id SERIAL PRIMARY KEY,
    college_code VARCHAR(10) UNIQUE NOT NULL,
    college_name VARCHAR(200) NOT NULL,
    college_type VARCHAR(30) CHECK (college_type IN ('Government','Private','Autonomous')),
    city VARCHAR(50) NOT NULL,
    state VARCHAR(50) DEFAULT 'Gujarat',
    phone VARCHAR(15),
    email VARCHAR(100),
    naac_grade VARCHAR(5),
    established_year INT
);

CREATE TABLE courses (
    course_id SERIAL PRIMARY KEY,
    course_code VARCHAR(10) UNIQUE NOT NULL,
    course_name VARCHAR(100) NOT NULL,
    duration_years INT DEFAULT 4
);

CREATE TABLE college_courses (
    cc_id SERIAL PRIMARY KEY,
    college_id INT REFERENCES colleges(college_id),
    course_id INT REFERENCES courses(course_id),
    academic_year INT NOT NULL,
    total_seats INT NOT NULL,
    tuition_fees DECIMAL(10,2),
    UNIQUE(college_id, course_id, academic_year)
);

-- ============================================================
-- MODULE 4: STATE-WISE MERIT ALLOTMENT
-- ============================================================

CREATE TABLE merit_list (
    merit_id SERIAL PRIMARY KEY,
    applicant_id INT REFERENCES applicants(applicant_id),
    academic_year INT NOT NULL,
    state VARCHAR(50) NOT NULL,
    category VARCHAR(10) NOT NULL,
    jee_rank INT NOT NULL,
    state_rank INT,
    category_rank INT,
    merit_score DECIMAL(10,3),
    is_eligible BOOLEAN DEFAULT TRUE,
    UNIQUE(applicant_id, academic_year)
);

-- ============================================================
-- MODULE 5 & 6: SEAT DISTRIBUTION AND ALLOCATION
-- ============================================================

CREATE TABLE seat_matrix (
    matrix_id SERIAL PRIMARY KEY,
    cc_id INT REFERENCES college_courses(cc_id),
    total_seats INT NOT NULL,
    open_seats INT DEFAULT 0,
    sc_seats INT DEFAULT 0,
    st_seats INT DEFAULT 0,
    sebc_seats INT DEFAULT 0,
    ews_seats INT DEFAULT 0,
    available_open INT DEFAULT 0,
    available_sc INT DEFAULT 0,
    available_st INT DEFAULT 0,
    available_sebc INT DEFAULT 0,
    available_ews INT DEFAULT 0
);

CREATE TABLE counseling_rounds (
    round_id SERIAL PRIMARY KEY,
    round_number INT NOT NULL,
    round_name VARCHAR(50) NOT NULL,
    academic_year INT NOT NULL,
    choice_filling_start DATE NOT NULL,
    choice_filling_end DATE NOT NULL,
    allotment_date DATE,
    status VARCHAR(30) DEFAULT 'Upcoming'
);

CREATE TABLE applicant_choices (
    choice_id SERIAL PRIMARY KEY,
    applicant_id INT REFERENCES applicants(applicant_id),
    round_id INT REFERENCES counseling_rounds(round_id),
    cc_id INT REFERENCES college_courses(cc_id),
    preference_order INT NOT NULL,
    choice_locked BOOLEAN DEFAULT FALSE,
    UNIQUE(applicant_id, round_id, preference_order)
);

CREATE TABLE seat_allocations (
    allocation_id SERIAL PRIMARY KEY,
    applicant_id INT REFERENCES applicants(applicant_id),
    round_id INT REFERENCES counseling_rounds(round_id),
    cc_id INT REFERENCES college_courses(cc_id),
    allotted_category VARCHAR(10) NOT NULL,
    status VARCHAR(20) DEFAULT 'Allotted',
    allocation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    UNIQUE(applicant_id, round_id)
);

-- ============================================================
-- MODULE 7: FEE PAYMENT MANAGEMENT
-- ============================================================

CREATE TABLE fee_structure (
    fee_id SERIAL PRIMARY KEY,
    category VARCHAR(10) NOT NULL,
    registration_fee DECIMAL(10,2) NOT NULL,
    counseling_fee DECIMAL(10,2) NOT NULL,
    academic_year INT NOT NULL,
    UNIQUE(category, academic_year)
);

CREATE TABLE fee_payments (
    payment_id SERIAL PRIMARY KEY,
    applicant_id INT REFERENCES applicants(applicant_id),
    payment_type VARCHAR(30),
    amount DECIMAL(10,2) NOT NULL,
    transaction_id VARCHAR(100) UNIQUE NOT NULL,
    payment_mode VARCHAR(20),
    payment_status VARCHAR(20) DEFAULT 'Success',
    payment_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ============================================================
-- MODULE 8: COUNSELING MANAGEMENT
-- ============================================================

CREATE TABLE counseling_attendance (
    attendance_id SERIAL PRIMARY KEY,
    applicant_id INT REFERENCES applicants(applicant_id),
    round_id INT REFERENCES counseling_rounds(round_id),
    attended BOOLEAN DEFAULT FALSE,
    attendance_time TIMESTAMP,
    remarks TEXT
);

-- ============================================================
-- VIEWS
-- ============================================================

CREATE VIEW vw_applicants AS
SELECT app_number, full_name, email, state, category, jee_rank, docs_verified
FROM applicants ORDER BY jee_rank;

CREATE VIEW vw_seat_availability AS
SELECT c.college_name, co.course_name, sm.total_seats, 
       sm.available_open, sm.available_sc, sm.available_st, 
       sm.available_sebc, sm.available_ews, cc.tuition_fees
FROM seat_matrix sm
JOIN college_courses cc ON sm.cc_id = cc.cc_id
JOIN colleges c ON cc.college_id = c.college_id
JOIN courses co ON cc.course_id = co.course_id;

CREATE VIEW vw_allocations AS
SELECT a.app_number, a.full_name, c.college_name, co.course_name,
       sa.allotted_category, sa.status, r.round_name
FROM seat_allocations sa
JOIN applicants a ON sa.applicant_id = a.applicant_id
JOIN college_courses cc ON sa.cc_id = cc.cc_id
JOIN colleges c ON cc.college_id = c.college_id
JOIN courses co ON cc.course_id = co.course_id
JOIN counseling_rounds r ON sa.round_id = r.round_id;

-- ============================================================
-- TRIGGER 1: REDUCE SEATS AFTER ALLOCATION
-- ============================================================

CREATE FUNCTION trg_reduce_seats() RETURNS TRIGGER AS $$
BEGIN
    UPDATE seat_matrix SET 
        available_open = CASE WHEN NEW.allotted_category='OPEN' THEN available_open-1 ELSE available_open END,
        available_sc = CASE WHEN NEW.allotted_category='SC' THEN available_sc-1 ELSE available_sc END,
        available_st = CASE WHEN NEW.allotted_category='ST' THEN available_st-1 ELSE available_st END,
        available_sebc = CASE WHEN NEW.allotted_category='SEBC' THEN available_sebc-1 ELSE available_sebc END,
        available_ews = CASE WHEN NEW.allotted_category='EWS' THEN available_ews-1 ELSE available_ews END
    WHERE cc_id = NEW.cc_id;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER after_seat_allocation
AFTER INSERT ON seat_allocations FOR EACH ROW EXECUTE FUNCTION trg_reduce_seats();

-- ============================================================
-- TRIGGER 2: RESTORE SEATS ON REJECTION
-- ============================================================

CREATE FUNCTION trg_restore_seats() RETURNS TRIGGER AS $$
BEGIN
    IF NEW.status IN ('Rejected','Cancelled') AND OLD.status NOT IN ('Rejected','Cancelled') THEN
        UPDATE seat_matrix SET 
            available_open = CASE WHEN NEW.allotted_category='OPEN' THEN available_open+1 ELSE available_open END,
            available_sc = CASE WHEN NEW.allotted_category='SC' THEN available_sc+1 ELSE available_sc END,
            available_st = CASE WHEN NEW.allotted_category='ST' THEN available_st+1 ELSE available_st END,
            available_sebc = CASE WHEN NEW.allotted_category='SEBC' THEN available_sebc+1 ELSE available_sebc END,
            available_ews = CASE WHEN NEW.allotted_category='EWS' THEN available_ews+1 ELSE available_ews END
        WHERE cc_id = NEW.cc_id;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER after_allocation_update
AFTER UPDATE ON seat_allocations FOR EACH ROW EXECUTE FUNCTION trg_restore_seats();

-- ============================================================
-- FUNCTION 1: CALCULATE MERIT SCORE
-- ============================================================

CREATE FUNCTION calculate_merit_score(p_jee_percentile DECIMAL, p_percentage_12th DECIMAL)
RETURNS DECIMAL AS $$
BEGIN
    RETURN ROUND((p_jee_percentile * 0.6) + (p_percentage_12th * 0.4), 3);
END;
$$ LANGUAGE plpgsql;

-- ============================================================
-- FUNCTION 2: CHECK SEAT AVAILABILITY
-- ============================================================

CREATE FUNCTION check_seat_available(p_cc_id INT, p_category VARCHAR)
RETURNS BOOLEAN AS $$
DECLARE v_available INT;
BEGIN
    SELECT CASE p_category
        WHEN 'OPEN' THEN available_open
        WHEN 'SC' THEN available_sc
        WHEN 'ST' THEN available_st
        WHEN 'SEBC' THEN available_sebc
        WHEN 'EWS' THEN available_ews
    END INTO v_available FROM seat_matrix WHERE cc_id = p_cc_id;
    RETURN COALESCE(v_available, 0) > 0;
END;
$$ LANGUAGE plpgsql;

-- ============================================================
-- PROCEDURE 1: GENERATE MERIT LIST (WITH CURSOR)
-- ============================================================

CREATE PROCEDURE generate_merit_list(p_academic_year INT, p_state VARCHAR)
LANGUAGE plpgsql AS $$
DECLARE
    cur CURSOR FOR 
        SELECT applicant_id, jee_rank, jee_percentile, percentage_12th, category
        FROM applicants 
        WHERE state = p_state AND docs_verified = TRUE
        ORDER BY jee_rank;
    rec RECORD;
    v_state_rank INT := 0;
    v_cat_ranks INT[] := ARRAY[0,0,0,0,0];
    v_score DECIMAL;
BEGIN
    DELETE FROM merit_list WHERE academic_year = p_academic_year AND state = p_state;
    
    OPEN cur;
    LOOP
        FETCH cur INTO rec;
        EXIT WHEN NOT FOUND;
        
        v_state_rank := v_state_rank + 1;
        v_cat_ranks[CASE rec.category WHEN 'OPEN' THEN 1 WHEN 'SC' THEN 2 
                    WHEN 'ST' THEN 3 WHEN 'SEBC' THEN 4 WHEN 'EWS' THEN 5 END] := 
        v_cat_ranks[CASE rec.category WHEN 'OPEN' THEN 1 WHEN 'SC' THEN 2 
                    WHEN 'ST' THEN 3 WHEN 'SEBC' THEN 4 WHEN 'EWS' THEN 5 END] + 1;
        
        v_score := calculate_merit_score(rec.jee_percentile, rec.percentage_12th);
        
        INSERT INTO merit_list (applicant_id, academic_year, state, category, jee_rank, 
                                state_rank, category_rank, merit_score)
        VALUES (rec.applicant_id, p_academic_year, p_state, rec.category, rec.jee_rank,
                v_state_rank, v_cat_ranks[CASE rec.category WHEN 'OPEN' THEN 1 WHEN 'SC' THEN 2 
                WHEN 'ST' THEN 3 WHEN 'SEBC' THEN 4 WHEN 'EWS' THEN 5 END], v_score);
    END LOOP;
    CLOSE cur;
    
    RAISE NOTICE 'Merit list generated for %: % applicants', p_state, v_state_rank;
END;
$$;

-- ============================================================
-- PROCEDURE 2: ALLOCATE SEATS (WITH CURSOR)
-- ============================================================

CREATE PROCEDURE allocate_seats(p_round_id INT)
LANGUAGE plpgsql AS $$
DECLARE
    cur CURSOR FOR
        SELECT ch.applicant_id, ch.cc_id, a.category
        FROM applicant_choices ch
        JOIN applicants a ON ch.applicant_id = a.applicant_id
        WHERE ch.round_id = p_round_id AND ch.choice_locked = TRUE
        AND NOT EXISTS (SELECT 1 FROM seat_allocations sa 
                       WHERE sa.applicant_id = ch.applicant_id AND sa.round_id = p_round_id)
        ORDER BY a.jee_rank, ch.preference_order;
    rec RECORD;
    v_count INT := 0;
BEGIN
    OPEN cur;
    LOOP
        FETCH cur INTO rec;
        EXIT WHEN NOT FOUND;
        
        IF check_seat_available(rec.cc_id, rec.category) THEN
            INSERT INTO seat_allocations (applicant_id, round_id, cc_id, allotted_category)
            VALUES (rec.applicant_id, p_round_id, rec.cc_id, rec.category);
            v_count := v_count + 1;
        END IF;
    END LOOP;
    CLOSE cur;
    
    RAISE NOTICE 'Allocated % seats in round %', v_count, p_round_id;
END;
$$;

-- ============================================================
-- SAMPLE DATA
-- ============================================================

INSERT INTO fee_structure (category, registration_fee, counseling_fee, academic_year) VALUES
('OPEN', 1000, 5000, 2025), ('SC', 500, 2500, 2025), ('ST', 500, 2500, 2025),
('SEBC', 750, 3500, 2025), ('EWS', 750, 3500, 2025);

INSERT INTO applicants (app_number, full_name, email, phone, dob, gender, city, state, category, 
jee_roll_number, jee_rank, jee_percentile, percentage_12th, docs_verified) VALUES
('A001', 'Rahul Patel', 'rahul@email.com', '9876543210', '2006-05-15', 'Male', 'Ahmedabad', 
'Gujarat', 'OPEN', 'JEE001', 450, 99.85, 95.60, TRUE),
('A002', 'Priya Shah', 'priya@email.com', '9876543211', '2006-08-22', 'Female', 'Surat', 
'Gujarat', 'OPEN', 'JEE002', 892, 99.72, 94.80, TRUE),
('A003', 'Amit Desai', 'amit@email.com', '9876543212', '2006-03-10', 'Male', 'Vadodara', 
'Gujarat', 'SC', 'JEE003', 1523, 98.95, 92.40, TRUE),
('A004', 'Sneha Modi', 'sneha@email.com', '9876543213', '2006-11-05', 'Female', 'Rajkot', 
'Gujarat', 'SEBC', 'JEE004', 3245, 97.88, 90.20, TRUE);

INSERT INTO colleges (college_code, college_name, college_type, city, state, phone, email, 
naac_grade, established_year) VALUES
('LDCE', 'LD College of Engineering', 'Government', 'Ahmedabad', 'Gujarat', 
'079-27545000', 'info@ldce.ac.in', 'A', 1948),
('SVNIT', 'SVNIT Surat', 'Autonomous', 'Surat', 'Gujarat', 
'0261-2201601', 'info@svnit.ac.in', 'A++', 1961),
('DDU', 'DDU Nadiad', 'Private', 'Nadiad', 'Gujarat', 
'0268-2520502', 'info@ddu.ac.in', 'A', 1968);

INSERT INTO courses (course_code, course_name, duration_years) VALUES
('CE', 'Computer Engineering', 4), ('IT', 'Information Technology', 4),
('ME', 'Mechanical Engineering', 4), ('EC', 'Electronics & Communication', 4);

INSERT INTO college_courses (college_id, course_id, academic_year, total_seats, tuition_fees) VALUES
(1, 1, 2025, 120, 50000), (1, 2, 2025, 60, 50000),
(2, 1, 2025, 150, 85000), (2, 4, 2025, 120, 85000),
(3, 1, 2025, 180, 120000);

INSERT INTO seat_matrix (cc_id, total_seats, open_seats, sc_seats, st_seats, sebc_seats, 
ews_seats, available_open, available_sc, available_st, available_sebc, available_ews) VALUES
(1, 120, 60, 10, 18, 24, 8, 60, 10, 18, 24, 8),
(2, 60, 30, 5, 9, 12, 4, 30, 5, 9, 12, 4),
(3, 150, 75, 12, 22, 31, 10, 75, 12, 22, 31, 10),
(4, 120, 60, 10, 18, 24, 8, 60, 10, 18, 24, 8),
(5, 180, 90, 15, 27, 36, 12, 90, 15, 27, 36, 12);

INSERT INTO counseling_rounds (round_number, round_name, academic_year, choice_filling_start, 
choice_filling_end, allotment_date, status) VALUES
(1, 'First Round', 2025, '2025-06-01', '2025-06-10', '2025-06-15', 'Completed');

INSERT INTO applicant_choices (applicant_id, round_id, cc_id, preference_order, choice_locked) VALUES
(1, 1, 3, 1, TRUE), (1, 1, 1, 2, TRUE),
(2, 1, 3, 1, TRUE), (2, 1, 1, 2, TRUE),
(3, 1, 1, 1, TRUE), (3, 1, 3, 2, TRUE);

INSERT INTO fee_payments (applicant_id, payment_type, amount, transaction_id, payment_mode) VALUES
(1, 'Registration', 1000, 'TXN001', 'Online'),
(2, 'Registration', 1000, 'TXN002', 'UPI'),
(3, 'Registration', 500, 'TXN003', 'Net Banking');

-- ============================================================
-- TEST QUERIES
-- ============================================================

-- SELECT * FROM vw_applicants;
-- -- SELECT * FROM vw_seat_availability;
-- -- CALL generate_merit_list(2025, 'Gujarat');
-- SELECT * FROM merit_list ORDER BY jee_rank;
-- CALL allocate_seats(1);
-- SELECT * FROM vw_allocations;