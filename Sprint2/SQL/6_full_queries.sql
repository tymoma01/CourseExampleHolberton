SELECT
  g.name AS genre,
  s.title,
  SUM(r.rate) AS total_rating,
  DENSE_RANK() OVER (
    PARTITION BY g.name
    ORDER BY SUM(r.rate) DESC
  ) AS rnk


FROM tv_shows s

JOIN tv_show_genres sg ON sg.show_id = s.id
JOIN tv_genres g ON g.id = sg.genre_id
LEFT JOIN tv_show_ratings r ON r.show_id = s.id

GROUP BY g.name, s.title
HAVING rnk <= 3

ORDER BY g.name, rnk, total_rating DESC; 



-- Subqueries
SELECT s.title
FROM tv_shows s
WHERE EXISTS (
  SELECT * FROM tv_show_ratings r WHERE r.show_id = s.id
);

-- JOIN tv_show_ratings as r on r.show_id = s.id

















-- UNION removes duplicates, UNION ALL keeps them
SELECT title FROM tv_shows WHERE title LIKE 'The %'
UNION ALL
SELECT title FROM tv_shows WHERE title LIKE '% %The%';
