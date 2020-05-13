/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find this single element that appears only once.

Input: [1,1,2,3,3,4,4,8,8]
Output: 2

*/
int singleNonDuplicate(vector<int>& nums) 
{
    
    int ans = 0;
    for(int bits=0;bits<32;bits++) // We go through all the bits
    {
        int countSetbits = 0; // Intialise countsetbits = 0 for every
        for(auto x : nums)    // bit. Traversing each element,
        {
            if((x >> bits) & 1) // check that bit is set then increment
                countSetbits++;
        }
        if(countSetbits % 2 != 0) // If not a multiple of 2
            ans |= (1 << bits); // means that bit occured in required
    }                           // number.
    
    return ans;
}

// Time Compelxity: O(logn)
// Spcae: O(1)


/* Great Aproach:

int lo = 0, hi = nums.length - 1;
    while (lo < hi) 
    {
        int mid = (lo + hi) >>> 1;

        // Remeber: odd XOR 1 -> odd - 1; and even XOR 1 -> even + 1;
        
        if (nums[mid] == nums[mid ^ 1]) // Great Line
            lo = mid + 1;
        else
            hi = mid;
    }
    return nums[lo];
*/