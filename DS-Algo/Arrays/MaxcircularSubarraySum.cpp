// Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number. 

// If only linear sum would have been given then kadane's algorithm would have worked for us. 
// But here we have to also consider wrapping sum (circular fashion sum). Examples: {10, -12, 11}

// Solution:  

// Step1: What we do is we find normal max subarray sum using kadane algorithm. Now only thing remaining is to consider
//        wrapping sum too.

// Note: Wrapping of contributing elements implies non wrapping of non contributing elements, 
//       so find out the sum of non contributing elements and subtract this sum from the total sum.

// Step2: To find out the sum of non contributing, invert sign of each element and then run Kadane’s algorithm.
//        Our array is like a ring and we have to eliminate the maximum continuous negative that implies 
//        maximum continuous positive in the inverted arrays. 

int kadane(int a[],int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for(int i=0;i<n;i++)
    {
        max_ending_here += a[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
  
int  maxMoney(int arr[], int num)
{
    
    int total = kadane(arr,num);
    
    int max_circular_sum=0;
    for(int i=0;i<num;i++)
    {
        max_circular_sum += arr[i];
        arr[i] = - arr[i];
    }
    
    max_circular_sum += kadane(arr,num);
    
    return (max_circular_sum > total) ? max_circular_sum : total;
}