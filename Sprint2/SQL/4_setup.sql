CREATE DATABASE school;

USE school;

CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    age INT,
    grade CHAR(2)
);

INSERT INTO students (name, age, grade)
VALUES ('Alice', 15, 'A'),
       ('Bob', 16, 'B'),
       ('Clara', 15, 'A');
