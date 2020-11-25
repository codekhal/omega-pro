/* Brute force solution is to find all the lexicographical permutations and 
find the current permutation. Answer will be the next permutation in the list we have. 
If it is the last permutation then 1st permutation is our answer.
    
Optimised O(n) Solution:
    Input: [1,5,8,4,7,6,5,3,1]
    OutPut:[1,5,8,5,1,3,4,6,7]

    Algo:
    Step 1: Traverse from behind and try to find the break point, i.e where nums[i] < nums[i+1].
    Step 2: Find the element which is greater than the current break point from behind. 
            That will contribute to the next permutation, since all smaller number would have been there in previous permuations. 
            nums[i] <= nums[j] (skip these).
    Step 3: Swap these 2 numbers.
    Step 4: Reverse (i + 1) to n-1th elements for gettting smallest next permuatation.
    
*/

void nextPermutation(vector<int>& nums) {
    // finding the break point
    int n = nums.size();
    
    if(n == 0 || n == 1)
        return;
    
    int i = n-2;
    while(i>= 0 && nums[i+1] <= nums[i])
    {
        i--;
    }
            
// found a break point or array is decreasingly sorted
// if break point found then, finding number which is just greater than the break point. 
    int j = n-1;
    
    if(i >= 0)
    {
        while(j >= 0 && nums[j] <= nums[i])
            j--;

        // if we found the just greater number, swap
        swap(nums[i], nums[j]);
    }
            
// for gettting just the next permutation sort the i+1th elements
// Even if array is decresingly sorted, i becomes '-1' and we reverse the whole array.
    
    reverse(nums.begin() + i + 1, nums.end());
}