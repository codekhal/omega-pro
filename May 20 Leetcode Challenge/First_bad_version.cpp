/* Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
   which causes all the following ones to be bad.

   Given an API bool isBadVersion(version) which will return whether version is bad.
   Given n = 5, and version = 4 is the first bad version.

    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true

    Then 4 is the first bad version. 
*/

class Solution {
public:
    int firstBadVersion(int n) {
        
        // We could simply apply binary search.
        // This problem is similar to finding pivot when arrays are sorted.
        
        long int start = 1;
        long int end = n;
        long int result = end;
        
        while(start <= end)
        {
            long int mid = start + (end - start) / 2;
            
            if(isBadVersion(mid)) // Returns True when version is bad.
            {                     // So in that case check left side .
                end = mid - 1;
                result = mid;
            }
            else    // else check for the right side.
                start = mid + 1;
        }
        
        return result;
    }
};

// Time Complexity: O(logn)