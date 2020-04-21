/* Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. 
We define the validity of a string by these rules:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
- An empty string is also valid.

Eg. Input:  "()"  Output: True
    Input: "(*))" Output: True
*/


bool checkValidString(string s) 
{
    
    // we use two stack one to maintain '(' and other for '*'
    
    stack<int> open,star;
    int n = s.length();
    
    for(int i=0;s[i] != '\0';i++)
    {
        if(s[i] == '(')
            open.push(i);
        
        else if(s[i] == '*')
            star.push(i);
        
        // case when ')'
        else
        {
            if(!open.empty())
                open.pop();
            
            else if(!star.empty())
                star.pop();
            
            else
                return false;
        }
    }
    // Till here we procced all the closing brackets. Now we may have opening brakets left.
    
    while(!open.empty()) // if we have remaining opening brackets
    {
        if(star.empty())
            return false;
        
        // if index of star is greater than opening braket then only we can process opening
        // brakets further, since "( *" makes sence no the other way round.
        else if(star.top() > open.top())
        {
            star.pop();
            open.pop(); 
        }
        
        else   // if we have case: " * (" it can't be balanced.
            return false;
    }
    
    return true; // we don't care if more stars are left since they are harmless
        
}