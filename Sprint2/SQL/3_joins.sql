CREATE TABLE student (
    id INT AUTO_INCREMENT PRIMARY KEY,
    student_name VARCHAR(100)
);

CREATE TABLE courses (
    id INT AUTO_INCREMENT PRIMARY KEY,
    course_name VARCHAR(100)
);


CREATE TABLE enrollments (
    student_id INT,
    course_id INT,
    FOREIGN KEY (student_id) REFERENCES students(id),
    FOREIGN KEY (course_id) REFERENCES courses(id)
);


INSERT INTO courses (course_name)
VALUES ('Math'), ('Science');

INSERT INTO enrollments (student_id, course_id)
VALUES (2, 1), (1, 2), (1, 2);








SELECT students.name, courses.course_name
FROM students

JOIN enrollments ON students.id = enrollments.student_id
JOIN courses ON courses.id = enrollments.course_id;






-- INNER JOIN
SELECT s.name, t.score
FROM second_table AS t
JOIN first_table AS s ON s.id = t.id
ORDER BY t.score DESC;


-- Foreign key
CREATE TABLE IF NOT EXISTS scores (
  id INT AUTO_INCREMENT PRIMARY KEY,
  student_id INT NOT NULL,
  score INT NOT NULL,
  CONSTRAINT fk_scores_student
    FOREIGN KEY (student_id) REFERENCES first_table(id)
    ON DELETE CASCADE
);

-- Atomic update + rollback demo
START TRANSACTION;
UPDATE scores SET score = score + 1 WHERE student_id IN (1, 2);
ROLLBACK;
