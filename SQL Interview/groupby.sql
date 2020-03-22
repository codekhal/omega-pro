-- So here we want to get highest salary of employees department wise.

select max(salary), departno from emp
group by departno;

-- To get the minimum salary department wise

select min(salary), departno from emp
group by departno;

-- Note: With group by Query one shall only include aggregate function followed by the column we want to group by.

-- To get the count of employees present in departments

select count(*), departno from emp
group by departno;