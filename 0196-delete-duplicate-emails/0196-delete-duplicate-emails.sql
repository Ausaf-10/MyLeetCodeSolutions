-- Step 1: Find the smallest id for each email
-- Step 2: Delete all rows where id is not in the smallest ids




DELETE FROM Person
WHERE id NOT IN(
    SELECT keep_id 
    FROM (SELECT MIN(id) AS keep_id
            FROM Person
            GROUP BY email
    ) AS subquery
);