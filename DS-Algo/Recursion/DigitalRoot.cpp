// DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.
// Eg: DigitalRoot(191)=1+9+1=>11=>1+1=>2

// We can think it as calculating sum of digits of a number twice, Until it becomes less than 10.

// Best Solution
int digitalRoot(int n)
{
    if(n < 10)
        return n;
    
    return (digitalRoot(n%10 + n/10));
}