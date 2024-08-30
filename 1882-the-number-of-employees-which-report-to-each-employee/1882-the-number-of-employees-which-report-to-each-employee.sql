# Write your MySQL query statement below


-- SELECT reports_to, COUNT(age) AS reports_count , AVG(age) AS average_age 
-- FROM (SELECT reports_to, age FROM Employees  WHERE reports_to IS NOT NULL) newTable
-- GROUP BY reports_to

SELECT emp.employee_id , emp.name, anotherTable.reports_count, anotherTable.average_age
FROM (SELECT reports_to, COUNT(age) AS reports_count , ROUND(AVG(age)) AS average_age 
FROM (SELECT reports_to, age FROM Employees  WHERE reports_to IS NOT NULL) newTable
GROUP BY reports_to) anotherTable
JOIN Employees emp ON anotherTable.reports_to = emp.employee_id
ORDER BY emp.employee_id;