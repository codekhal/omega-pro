// Tyipical Binary Search Program
// Searches x in arr[low..high].  If x is present, then returns its index, else -1
int binarySearch(int arr[], int low, int high, int x)
{
    if(high >= low)                        ======> O(1)
    {
        int mid = low + (high - low)/2;    ======> O(1)
        if (x == arr[mid])                 ======> O(1)
            return mid;
        if (x> arr[mid])
            return binarySearch(arr, (mid + 1), high); ======> T(n/2)
        else
            return binarySearch(arr, low, (mid -1));   ======> T(n/2)
    }

    return -1;
}

// In Binary Search, we first compare the given element x with middle of the array. If x matches with middle element, then we return middle index. Otherwise, we either recur for left half of array or right half of array.

// So recurrence is T(n) = T(n/2) + O(1)

// Time Complexity:

//  Best Case: O(1)

//  Average Case: O(logn)

//  Worst Case: T(n) = T(n/2) + c  ; By using master Theorem: O(logn)