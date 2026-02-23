SELECT COUNT(*) AS total_students FROM students;


SELECT AVG(age) AS avg_age, MIN(age), MAX(age)
FROM students;



SELECT grade, COUNT(*) AS number_of_students
FROM students
GROUP BY grade;
