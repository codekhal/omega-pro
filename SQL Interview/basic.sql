-- Basic Commands in SQL

-- Create table with a single field as primary key

CREATE TABLE Students (
    ID INT NOT NULL
    Name VARCHAR(255)
    PRIMARY KEY (ID)
);

--  Create table with multiple fields as primary key 

CREATE TABLE Students (
    ID INT NOT NULL
    LastName VARCHAR(255)
    FirstName VARCHAR(255) NOT NULL,
    CONSTRAINT PK_Student
    PRIMARY KEY(ID, FirstName)
);

-- SELECT query in SQL

SELECT COUNT(studentId), country
FROM myDB.students
WHERE country != "INDIA"
GROUP BY country
HAVING COUNT(studentID) > 5;

/* 
WHERE clause: is used to filter records that are necessary, based on specific conditions.

ORDER BY clause: is used to sort the records based on some field(s) in ascending (ASC) or descending order (DESC). 

GROUP BY clause: is used to group records with identical data and can be used in conjuction with some aggregation functions
                to produce summarized results from the database.

HAVING clause: is used to filter records in combination with the GROUP BY clause. 
               
Note: It is different from WHERE, since WHERE clause cannot filter aggregated records. 
*/

-- Set a column as primary key

ALTER TABLE Students
ADD PRIMARY KEY (ID);

-- Set multiple columns as primary key Naming a Primary Key

ALTER TABLE Students
ADD CONSTRAINT PK_Student   /* Naming a Primary Key */
PRIMARY KEY(ID,FirstName);

-- Update Query

UPDATE myDB.students 		 /* action query */
SET fname = 'Captain', lname = 'America'
WHERE student_id = 1;


-- UNIQUE CONSTRAINT

CREATE TABLE Students ( 	 /* Create table with a single field as unique */
    ID INT NOT NULL UNIQUE
    Name VARCHAR(255)
);

CREATE TABLE Students ( 	 /* Create table with multiple fields as unique */
    ID INT NOT NULL
    LastName VARCHAR(255)
    FirstName VARCHAR(255) NOT NULL
    CONSTRAINT PK_Student
    UNIQUE (ID, FirstName)
);

ALTER TABLE Students 	 /* Set a column as unique */
ADD UNIQUE (ID);

-- Foreign Key: It essentially refer to the PRIMARY KEY in another table.

/* Create table with foreign key */

Create TABLE Students (
    ID INT NOT NULL PRIMARY KEY
    St_Name VARCHAR(255)
    LibraryID INT
    FOREIGN KEY(Library_id) references Library(LibraryID)
);

/* Add a new foreign key */

ALTER TABLE Students
ADD FOREIGN KEY (LibraryID)
REFERENCES Library (LibraryID);

-- Nested query (A query within another query): It is used to restrict or enhance the data to be queried by the main query, 
--                                              thus restricting or enhancing the output of the main query respectively.

/* For Eg. Fetch the contact information for students who have enrolled for the maths subject. */

SELECT name,age, email, address from myDb.contacts
where rollno. IN (SELECT rollno from myDb.Students where subject_name = 'Maths');