// Various mathods for finding prime numbers.
// Method1: I call it Old School method
// We iterate through all numbers from 2 to n-1 and for every number check if it divides n.

bool checkPrimes(int n)
{
    if(n<=1)
        return false;

    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

// Optimised School method:
// Here we csn do following optimisations:
// 1. Instead of checking till n, we can check till √n.

//    Reason: If for a number n has a factor say a*b = n. 
//            One of the factor will be less than √n and other will be greater than √n. 
//            Hence if it has factor its better to check √n. No point in going beyond that.

// 2. Observing that all primes are of the form 6k ± 1.
//    Reason: It should be noted that not every number of the form 6K ± 1 is Prime.
//            However, if a number is prime then it must be of the form 6K + 1 OR 6K - 1.
// Every integer can be written in the form of 6n,6n+1,6n+2,6n+3,6n+46n,6n+1,6n+2,6n+3,6n+4 or 6n+5.
// It is quite evident that 6n is always divisible by 6, 6n+1 may be prime, 6n+2 will always be divisible by 2, 6n+3 by 3, and 6n+4 by 2. 6n+5 may be prime.
// Our candidates for checking prime are therefore 6n+1 and 6n+5. We can then see that 6n+5 = 6(n+1)−1 = 6x−1.

bool isPrime(int n)
{
    if(n <= 1) 
        return false;
    
    if(n <= 3) 
        return true;

    if(n%2 == 0 || n%3 == 0)
        return false;
    
    for(int i=5; i*i < n; i += 6)
    {
        if(n%i == 0 || n%(i+2) == 0) // "n%(i+2)" : Because you need to check whether n is divisible by 6K - 1 or 6K + 1 
            return false;           // (the difference between them is 2).
    }
    return true;

}