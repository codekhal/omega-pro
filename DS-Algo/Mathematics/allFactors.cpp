vector<int> Solution::allFactors(int A) {

    // Lets take Eg.
    // n = 36 - factors(1,2,3,4,6,9,12,18,36)
    //                    i            n/i
    
    // So we could optimise it by not running a whole loop what we could do is run till sqrt(n)
    // Then we handle case when n/i == i (i.e 6*6 = 36) we dont wanna add that twice in the list.
    
    vector<int> factors;
    
    for(int i=1;i<=sqrt(A);i++)
    {
        if(A % i == 0)
        {
            factors.push_back(i); // In case of 36: 1,2,3,4,6 gets pushed in vector
            
            if(i != sqrt(A))
                factors.push_back(A/i); // In case of 36: 36,18,12,9 get pushed in vector
        }
    }
    
    sort(factors.begin(),factors.end()); // we sort since this method does not sort our result
    return factors;
}