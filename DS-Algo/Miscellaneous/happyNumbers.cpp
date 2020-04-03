// A happy number is a number defined by the following process: 

// Starting with any positive integer, replace the number by the sum of the squares of its digits, 
// and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
// Those numbers for which this process ends in 1 are happy numbers.
// Few happy numbers are: 1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100

// Input: 19
// Output: true
// Explanation: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// General Approach: The idea is simple, we repeated do sum of squares of digits. While doing so, we keep track of visited numbers using a hash. 
//                     If we reach 1, we return true. Else if we reach a visited a number, we return false.

// Observation: The cycle always contains 4. So we don’t need to keep track of all numbers. We can simply check for 4.

int sumDigitSquare(int n) 
{ 
    int sq = 0; 
    
    while (n) 
    { 
        int digit = n % 10; 
        sq += digit * digit; 
        n = n / 10; 
    } 
    return sq; 
}

bool isHappy(int n) {
    
    while(1)
    {
        
        if(n == 1)
            return true;
        
        n = sumDigitSquare(n);
        
        if (n == 4) 
            return false;
    }
    return false;
}
