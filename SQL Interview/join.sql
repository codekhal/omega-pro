-- Join: Clause is used to combine records (rows) from two or more tables in a SQL database based on a related column between the two.
-- 4 different types of JOINs in SQL

/* Inner Join: Retrieves records that have matching values in both tables involved in the join. This is the widely used join. */

SELECT *
FROM Table_A
JOIN Table_B;

/* Left Join: Retrieves all the records/rows from the left and the matched records/rows from the right table. */

SELECT *
FROM Table_A A
LEFT JOIN Table_B B
ON A.col = B.col;

/* RIGHT JOIN: Retrieves all the records/rows from the right and the matched records/rows from the left table. */

SELECT *
FROM Table_A A
RIGHT JOIN Table_B B
ON A.col = B.col;

/* FULL (OUTER) JOIN: Retrieves all the records where there is a match in either the left or right table.  */

SELECT *
FROM Table_A A
FULL JOIN Table_B B
ON A.col = B.col;

-- Self-Join: Case of regular join where a table is joined to itself based on some relation between its own column(s). 
--            Self-join uses the INNER JOIN or LEFT JOIN clause and a table alias is used to assign different names to the table within the query. 

SELECT A.CustomerName AS CustomerName1, B.CustomerName AS CustomerName2, A.City
FROM Customers A, Customers B
WHERE A.CustomerID <> B.CustomerID
AND A.City = B.City
ORDER BY A.City;

-- Cross-Join: defined as a cartesian product of the two tables included in the join. The table after join contains the same number of rows as in the cross-product 
--             of number of rows in the two tables. If a WHERE clause is used in cross join then the query will work like an INNER JOIN. 

SELECT stu.name, sub.subject 
FROM students AS stu
CROSS JOIN subjects AS sub;
