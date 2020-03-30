// Find the contiguous subarray within an array, A of length N which has the largest sum.

// Input 1:
//     A = [1, 2, 3, 4, -10]

// Output 1:
//     10

// A use case of kadane's Algorithm

int Solution::maxSubArray(const vector<int> &A) {
    
    // we want maxmimum sum based on contigous subarray.
    
    // lets calculate prefix sum
    int psum = 0;
    
    // a global answer variable
    int ans = INT_MIN;
    
    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
        psum = max(psum,0);
        
        // This should be answer till now
        psum += A[i];
        
        // But we need to return a global varibale so we return max of ans and prefix sum.
        ans = max(ans,psum);
    }
    
    // We aren't missing any edge cases. Array size min would be 1
    return ans;
}

// If array is empty or all elements are negative. Question is a use case of kadane's algo.

int Solution::maxSubArray(const vector<int> &A) {
    int max_sum = A[0]; // Stores
    int cum_sum = 0;

    for(int i = 0; i < A.size(); i++) {
        cum_sum = max(A[i], cum_sum+A[i]);
        max_sum = max(cum_sum, max_sum);
    }
    return max_sum;
}
