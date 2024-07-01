-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description, id
FROM crime_scene_reports
WHERE street = "Humphrey Street"
AND month = 7
AND day = 28;

SELECT transcript
FROM interviews
WHERE month = 7
and day = 28;

SELECT people.name, people.passport_number, people.phone_number, people.license_plate
FROM people
JOIN bank_accounts on bank_accounts.person_id = people.id
WHERE bank_accounts.person_id IN
(
SELECT person_id
FROM bank_accounts
JOIN atm_transactions on atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.account_number IN
(
SELECT account_number
FROM atm_transactions
WHERE atm_location = "Leggett Street"
and month = 7
and day = 28
)
)
AND people.license_plate IN
(
SELECT license_plate
FROM bakery_security_logs
WHERE month = 7
and day = 28
and hour = 10
and minute > 15
and minute < 25
)
AND people.phone_number IN
(
SELECT caller
FROM phone_calls
WHERE day = 28
and month = 7
and duration < 60);

SELECT passengers.passport_number, id, origin_airport_id, destination_airport_id, hour
FROM flights
JOIN passengers on passengers.flight_id = flights.id
WHERE month = 7
AND day = 29
AND passengers.passport_number IN ('5773159633', '3592750733');

SELECT city
FROM airports
JOIN flights on flights.destination_airport_id = airports.id
WHERE destination_airport_id = 4;

SELECT caller, receiver
FROM phone_calls
WHERE day = 28
and month = 7
and duration < 60
and caller = "(367) 555-5533";

SELECT name
FROM people
WHERE phone_number = "(375) 555-8161";

