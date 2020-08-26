// Find nth fiboibonacci number:


// Non-DP (Dynamic Programming) Solution 
long long fibonacci(int n)
{

    if(n <= 1)
        return n;
        
    return (fibonacci(n-1) + fibonacci(n-2));
}

// Using DP(Let's not be afraid of DP, in DP the only thing we do is store prefix sum which is used in future function calls. That's it!)

long long fibonacci(int n)
{
    int fibo[n+2]; // Taking Size of static array with n+2

    fibo[0]=0;
    fibo[1]=1;

    for(int i=2;i<=n;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2]; // Storing sum so it could be reused for future computations.
    }

    return fibo[n];
}

// Time: O(n)
// Space: O(n), we are using an array to store values.