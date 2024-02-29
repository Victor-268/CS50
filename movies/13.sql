SELECT people.name
FROM people
JOIN stars ON stars.person_id = people.id
WHERE stars.movie_id IN
(
    SELECT id
    FROM movies
    JOIN stars ON movies.id = stars.movie_id
    WHERE stars.person_id =
    (
        SELECT id
        FROM people
        WHERE name = 'Kevin Bacon' AND birth = 1958
    )
) AND people.name != 'Kevin Bacon';
