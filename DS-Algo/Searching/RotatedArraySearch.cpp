// Given an array of integers A of size N and an integer B. Array A is rotated at some pivot unknown to you beforehand. 
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ). 
// You are given a target value B to search. If found in the array, return its index, otherwise return -1.

// Input 1:
//     A = [4, 5, 6, 7, 0, 1, 2, 3]
//     B = 4
// Output 1:
//     0
// Explanation 1:
//  Target 4 is found at index 0 in A.

// Solution: So here we have a pivot around which left part is sorted and right part is sorted.
//           For binary search we need to find the lowest number and apply binary search accordingly in left or right part to find the element.

int Solution::search(const vector<int> &A, int B) {
    
    int smallest_index = -1;  // We calculate smallest index
    
    int n = A.size();
    
    int l=0,r=n-1;
    
    while(l <= r)
    {
        int mid = l + (r-l) / 2;
        
        if(A[mid] > A[r])  // Smallest index has to be right to the greatest element of the array.
        {
            l = mid + 1;  // Here we have mid+1 as the smaller element than the mid. So probably it is the A[mid+1] is the smallest.
        }
        else           // but if not then we assign smallest index to mid for a while and traverse the left side for getting smallest.
        {
            smallest_index = mid; // Suppose we have got 1 then to get 0 we need to move leftwards.
            r = mid - 1; 
        }
    }
    
    l=0;
    r=n-1;
    
    while(l <= r)
    {
        int mid = l + (r-l) / 2;
        
        int updated_index = (mid + smallest_index) % n; //  We have our smallest element index. Now for the index of every number
                                                    // has been shifted by that (index + smallest index) % n. Eg.(4 + 3) % 7.
        if(A[updated_index] < B)  
            l = mid + 1;              // If we have number smaller than required we check right side. Else left side.
        
        else if(A[updated_index] > B)
            r = mid - 1;
        
        else
            return updated_index;
    }
    return -1;
    
}