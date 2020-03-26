/* In order to print the alternate records or rows we specify something called rownum. */

-- Even Records
SELECT * FROM EMPLOYEE 
WHERE id IN(SELECT id FROM EMPLOYEE WHERE id%2 = 0);

--Odd Records
SELECT * FROM EMPLOYEE 
WHERE id IN(SELECT id FROM EMPLOYEE WHERE id%2 <> 0);