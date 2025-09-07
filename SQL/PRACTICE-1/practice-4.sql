CREATE DATABASE classroom;
USE classroom;

CREATE TABLE Students (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    marks INT,
    grade CHAR(1)
);

INSERT INTO Students (id, name, marks, grade) VALUES
(1, 'Alice', 85, 'A'),
(2, 'Bob', 70, 'B'),
(3, 'Charlie', 90, 'A'),
(4, 'David', 60, 'C'),
(5, 'Eva', 85, 'B');

SELECT * FROM Students WHERE grade = 'A';

SELECT * FROM Students WHERE marks BETWEEN 60 AND 90;

SELECT grade, count(id) FROM Students GROUP BY grade;

SELECT grade, avg(marks) FROM Students GROUP BY grade;

