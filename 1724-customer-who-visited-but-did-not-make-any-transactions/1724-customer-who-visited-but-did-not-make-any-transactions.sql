# Write your MySQL query statement below
-- SELECT v.*, t.*
-- FROM Visits v
-- LEFT JOIN Transactions t ON t.visit_id = v.visit_id;

-- SElECT newTable.customer_id, newTable.transaction_id
-- FROM (SELECT v.customer_id, t.* FROM Visits v LEFT JOIN Transactions t ON t.visit_id = v.visit_id) newTable
-- WHERE newTable.transaction_id IS NULL;

SELECT anotherTable.customer_id, COUNT(anotherTable.customer_id) AS count_no_trans 
FROM (SElECT newTable.customer_id, newTable.transaction_id FROM (SELECT v.customer_id, t.* FROM Visits v LEFT JOIN Transactions t ON t.visit_id = v.visit_id) newTable WHERE newTable.transaction_id IS NULL) anotherTable
GROUP BY anotherTable.customer_id;



-- SELECT newTable.customer_id, COUNT(newTable.transaction_id)
-- FROM (SELECT v.*, t.* FROM Visits v LEFT JOIN Transactions t ON t.visit_id = v.visit_id) newTable
-- GROUP BY newTable.customer_id
-- HAVING 