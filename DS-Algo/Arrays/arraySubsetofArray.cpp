// Given two arrays: arr1[m] and arr2[n]. Find whether arr2[] is a subset of arr1[] or not. 
// Both the arrays are not in sorted order.

// Method 1 (Simple): Use two loops: The outer loop picks all the elements of arr2[] one by one. 
//                          The inner loop linearly searches for the element picked by the outer loop. 
//                          If all elements are found then return 1, else return 0.

bool isSubset(int arr1[], int arr2[],  
                        int m, int n) 
{ 
    int i = 0; 
    int j = 0; 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            if(arr2[i] == arr1[j]) 
                break; 
        } 
          
        /* If the above inner loop was not broken at all then arr2[i] is not present in arr1[] */
        if (j == m) 
            return 0; 
    } 
      
    /* If we reach here then all elements of arr2[] are present in arr1[] */
    return 1; 
}

// Time Complexity: O(m*n)

// Method 2 (Efficient): Use Sorting and Binary Search

// Method 3 (Better than 2nd): Use Sorting and Merging

// Sort both arrays: arr1[] and arr2[] which takes O(mLogm + nLogn)
// Use Merge type of process to see if all elements of sorted arr2[] are present in sorted arr1[].

bool CheckSubset(int arr1[], int m, int arr2[], int n) {

    if(m < n)
        return false;
    
    sort(arr1, arr1+m);
    sort(arr2, arr2+n);
    
    int i=0,j=0;
    
    while(i< n && j< m)
    {
        if(arr1[j] < arr2[i])
            j++;
        
        else if(arr1[i] == arr2[j])
        {
            j++;
            i++;
        }
        
        else if(arr1[j] > arr2[i])
            return false;
            
    }
    
    return  (i < n)? false : true;
}

// Time Complexity:  O(mLogm + nLogn) {Only if quick sort is not in it's worst case. Else it would be O(n^2)}