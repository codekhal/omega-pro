vector<int> Solution::sieve(int A) {
    
    // So what we do in sieve is we take a list of size one greater than the number
    // we then mark each position at all indexes 1.
    // Here one denotes prime, zero denotes not prime.
    
    // Now what we do is we run a loop till n and we check if current position is marked
    // we check all multiples (i*j) in the next loop and mark them as 0.
    // We finally copy all the ones indexes in ans vector and sort it and return.
    
    // Optimization: we could run outer loop till sqrt(n) since if number is not marked till sqrt(n)
    // it wont get marked any further. Take n = 15 as an example.
    vector<int> primes(A+1,1);
    
    primes[0] = 0;
    primes[1] = 0;
    
    for(int i = 2;i<=sqrt(A);i++)
    {
        if(primes[i] == 1)
        {
            for(int j = 2;j*i<=A;j++)
            {
                   primes[i*j] = 0;
            }
        }
    }
    
    int n = primes.size();
    vector<int> ans;
    
    for(int i=0;i<n;i++)
    {
        if(primes[i] == 1)
            ans.push_back(i);
    }
    
    sort(ans.begin(),ans.end());
    
    return ans;
}

/* Time complexity: O(n*loglog(n))

since by mathematical derivation inner loop runs n/2+n/3+n/5+n/7... and so on.
Denominator is prime and this series comes out to be O(n*loglogn). */