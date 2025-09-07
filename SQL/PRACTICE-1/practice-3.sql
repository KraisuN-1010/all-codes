CREATE DATABASE consumers;

USE consumers;

-- Create the customers table with payment amount
CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    customer VARCHAR(50) NOT NULL,
    mode VARCHAR(20) NOT NULL,
    city VARCHAR(30) NOT NULL,
    payment_amount DECIMAL(10,2) NOT NULL
);

-- Insert all the customer data with random payment amounts
INSERT INTO customers (customer_id, customer, mode, city, payment_amount) VALUES
(101, 'Olivia Barrett', 'Netbanking', 'Portland', 1250.75),
(102, 'Ethan Sinclair', 'Credit Card', 'Miami', 2890.50),
(103, 'Maya Hernandez', 'Credit Card', 'Seattle', 675.25),
(104, 'Liam Donovan', 'Netbanking', 'Denver', 1875.00),
(105, 'Sophia Nguyen', 'Credit Card', 'New Orleans', 3420.80),
(106, 'Caleb Foster', 'Debit Card', 'Minneapolis', 540.30),
(107, 'Ava Patel', 'Debit Card', 'Phoenix', 950.65),
(108, 'Lucas Carter', 'Netbanking', 'Boston', 2100.40),
(109, 'Isabella Martinez', 'Netbanking', 'Nashville', 1680.90),
(110, 'Jackson Brooks', 'Credit Card', 'Boston', 2250.15);

SELECT mode, SUM(payment_amount) FROM customers GROUP BY mode;

