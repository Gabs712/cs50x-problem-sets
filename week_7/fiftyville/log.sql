-- Get report from crime.
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2021 AND street = 'Humphrey Street';

-- Get interviews from the day that metions the bakery
SELECT name, transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2021 AND transcript LIKE '%bakery%';

-- Suspected atm accounts
SELECT account_number, amount FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- Suspected license plates
SELECT license_plate FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10
AND minute BETWEEN 15 AND 25 AND activity = 'exit';

-- Earliest flight to the next day, which is New Work
SELECT city FROM flights JOIN airports
ON airports.id = flights.destination_airport_id
WHERE day = 29 AND month = 7 AND year = 2021
ORDER BY hour, minute LIMIT 1;

-- Suspected thief Phone Numbers
SELECT caller FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021
AND duration <= 60;

-- Suspected accomplice Phone Numbers
SELECT receiver FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021
AND duration <= 60;

-- Suspected passport numbers
SELECT passport_number FROM passengers WHERE flight_id = (SELECT flights.id FROM flights JOIN airports
ON airports.id = flights.destination_airport_id
WHERE day = 29 AND month = 7 AND year = 2021
ORDER BY hour, minute
LIMIT 1);



-- Thief
SELECT * FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021
AND duration <= 60)
AND license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10
AND minute BETWEEN 15 AND 25 AND activity = 'exit')
AND passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id = (SELECT flights.id FROM flights JOIN airports
ON airports.id = flights.destination_airport_id
WHERE day = 29 AND month = 7 AND year = 2021
ORDER BY hour, minute
LIMIT 1))
AND id IN (SELECT person_id FROM bank_accounts JOIN atm_transactions ON
bank_accounts.account_number = atm_transactions.account_number WHERE
day = 28 AND month = 7 AND year = 2021 AND atm_location = 'Leggett Street');

-- Suspect accomplieces that match
SELECT * FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021
AND duration <= 60)
;


-- matching call between thief and accomplice
SELECT * FROM phone_calls WHERE caller IN

(SELECT phone_number FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021
AND duration < 60)
AND license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10
AND minute BETWEEN 15 AND 25 AND activity = 'exit')
AND passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id = (SELECT flights.id FROM flights JOIN airports
ON airports.id = flights.destination_airport_id
WHERE day = 29 AND month = 7 AND year = 2021
ORDER BY hour, minute
LIMIT 1))
AND id IN (SELECT person_id FROM bank_accounts JOIN atm_transactions ON
bank_accounts.account_number = atm_transactions.account_number WHERE
day = 28 AND month = 7 AND year = 2021 AND atm_location = 'Leggett Street'))

AND receiver IN

(SELECT phone_number FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021
AND duration < 60)
);

-- find owners from the suspected numbers
SELECT name FROM people WHERE phone_number = '(367) 555-5533' OR
phone_number = '(375) 555-8161';