# Write your MySQL query statement below
-- SELECT s.product_id, MIN(s.year) AS first_year
-- FROM Sales s
-- JOIN Product p ON p.product_id = s.product_id 
-- GROUP BY s.product_id; 

SELECT newTable.product_id, s.year AS first_year, s.quantity, s.price
FROM (SELECT s.product_id, MIN(s.year) AS my_year FROM Sales s JOIN Product p ON p.product_id = s.product_id GROUP BY s.product_id) newTable
JOIN Sales s on s.year = newTable.my_year AND newTable.product_id =  s.product_id;
