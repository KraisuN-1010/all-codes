CREATE DATABASE company;
USE company;
CREATE TABLE employeeInfo (
	id INT PRIMARY KEY,
	Name VARCHAR(50),
    Salary INT NOT NULL
);

INSERT INTO employeeInfo VALUES (1, "Uday", 1000000);
INSERT INTO employeeInfo VALUES (2, "Pari", 1000000);
INSERT INTO employeeInfo VALUES (3, "Jani", 1000000);

SELECT * FROM employeeInfo;
