# Write your MySQL query statement below
-- SELECT managerId
-- FROM Employee
-- GROUP BY managerId
-- HAVING COUNT(managerId) >= 5;

SELECT e.name
FROM (SELECT managerId FROM Employee GROUP BY managerId HAVING COUNT(managerId) >= 5) newTable
JOIN Employee e ON  e.id = newTable.managerId;