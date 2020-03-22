/* To get the second highest salary from the database. */

select max(salary) from emp
where salary not in (select max(salary) from emp);