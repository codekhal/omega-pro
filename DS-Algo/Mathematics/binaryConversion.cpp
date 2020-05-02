string Solution::findDigitsInBinary(int A) {
    
    string result;  // Take a string variable
    if(A==0)
        return "0"; // If input is 0 return "0" in strings.
        
    int r;
    
    while(A > 0)
    {
        r = A % 2;   // Store the remainder (would be either 1 or 0)
        
        result += to_string(r);  // concat it to the result till now.
        
        A /= 2;
    }
    
    reverse(result.begin(),result.end()); // since we get remainders from the right number bits, reverse the result.
    
    return result;     // There is another function stoi() which converts string to its value in int.
}
