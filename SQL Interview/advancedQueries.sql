-- UNION, MINUS and INTERSECT commands

/* 
The UNION operator: combines and returns the result-set retrieved by two or more SELECT statements.
The MINUS operator: is used to remove duplicates from the result-set obtained by the second SELECT query from the result-set 
                    obtained by the first SELECT query and then return the filtered results from the first.
The INTERSECT clause: combines the result-set fetched by the two SELECT statements where records from one match the other 
                      and then returns this intersection of result-sets. 
*/

-- Union
SELECT name FROM Students 	 /* Fetch the union of queries */
UNION
SELECT name FROM Contacts;

SELECT name FROM Students 	 /* Fetch the union of queries with duplicates*/
UNION ALL
SELECT name FROM Contacts;

-- Minus
SELECT name FROM Students 	 /* Fetch names from students that aren't present in contacts */
MINUS	
SELECT name FROM Contacts;

-- Intersect
SELECT name FROM Students 	 /* Fetch names from students that are present in contacts as well*/
INTERSECT
SELECT name FROM Contacts;

-- ** Index **: database index is a data structure that provides quick lookup of data in a column or columns of a table. 
--        It enhances the speed of operations accessing data from a database table
--        at the cost of additional writes and memory to maintain the index data structure. 

CREATE INDEX index_name 	        /* Create Index */
ON table_name (column_1, column_2);

DROP INDEX index_name;              /* Drop Index */