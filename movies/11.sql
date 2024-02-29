SELECT DISTINCT title
FROM movies
JOIN stars on stars.movie_id=movies.id
JOIN ratings on stars.movie_id=ratings.movie_id
WHERE stars.person_id =
(
    SELECT id
    FROM people
    WHERE name = "Chadwick Boseman"
)
ORDER BY rating DESC
LIMIT 5;
