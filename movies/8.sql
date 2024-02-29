SELECT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
WHERE movie_id =
(
    SELECT id
    FROM movies
    WHERE title = 'Toy Story'
);
