/* Given a non-negative integer num represented as a string, remove k digits from the number 
so that the new number is the smallest possible.

Input: num = "1432219", k = 3
Output: "1219"

Input: num = "10200", k = 1
Output: "200"

*/

string removeKdigits(string num, int k) 
{
        
    // Maintaing the digits in acending order gives us the least 
    // possible number.
    
    
    /* Case 1: Without Zeroes -
        Most significant digit has more weightage and as soon as 
        value decreases from next index then we already has seen a 
        maxima. Therefore we have to process the string from left to 
        right and remove as soon as we find a dip.
        
        Note: High value digits at the end will have less impact as 
        compared to MSD. We focus as soon as we see 
        a peak and a valley (means value of the next index decreases)
        
        Case 2: With zeroes - Eg: "00052" & k = 1 then: "2"
        We neglet leading zeroes skip the zeroes in between and remove 
        the next peak we find.
        
        Case 3: If elements are in ascending order. 
        We remove last k elements then. Eg: "1 2 3" & k = 2 then: "1".

    */
    
    int n = num.size();
    
    stack<char> stk;
    
    for(char x : num)
    {
        while(!stk.empty() && k > 0 && stk.top() > x) // we found peak.
        {
            stk.pop();
            k--;
        }
        
        if(!stk.empty() || (x != '0'))
            stk.push(x);
    }
        
    // When values are in ascending order
    // Removing largest values from the top of stack

    while(!stk.empty() && k--)
        stk.pop();

    if(stk.empty())
        return "0";


    // Retrieve string from the stack

    while(!stk.empty())
    {
        // resusing nums
        num[n-1] = stk.top();

        stk.pop();

        n--;
    }
    
    return num.substr(n);
}

// Time Complexity: O(n)
// Space: O(n) , since we are using a stack.