# Write your MySQL query statement below

# COUNT OF THE PRODUCT KEY!
-- SELECT COUNT(product_key) AS TotalCount
-- FROM Product;

-- SELECT customer_id, COUNT(DISTINCT product_key) AS MyCount
-- FROM Customer
-- GROUP BY customer_id;

SELECT newTable.customer_id
FROM (SELECT customer_id, COUNT(DISTINCT product_key) AS MyCount FROM Customer GROUP BY customer_id) newTable
WHERE newTable.MyCount = (SELECT COUNT(product_key) AS TotalCount FROM Product);


