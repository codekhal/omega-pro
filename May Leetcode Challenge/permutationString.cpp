/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Approach 1: Sort both the strings and check if hey are equal

Time: O(nlogn)

Can we do it in O(n)?

Yes, by using sliding window approach.
*/

bool ispermutation(vector<int> s1, vector<int> s2)
{
    // Finds if values at indexes of s1 and s2 are equal.
    for(int i=0;i<s1.size();i++) 
    {
        if(s1[i] != s2[i])
            return false;
    }
    
    return true;
}

bool checkInclusion(string s1, string s2) {
    
    int n = s1.length();
    int m = s2.length();
    
    if(m == NULL || m == 0 || n > m)
        return false;
    
    vector<int> countFreq(26,0);
    vector<int> countPatternFreq(26,0);
    
    for(int i=0;i<n;i++) // we only wanna fill values tll our length s1
    {
        countFreq[s2[i] - 'a']++;
        countPatternFreq[s1[i] - 'a']++;
    }
    
    for(int i=0;i< (m - n);i++) //we take care of n elements beforehand
    {
        if(ispermutation(countPatternFreq,countFreq))
            return true;
        
        countFreq[s2[i]-'a']--; //removing first element
        countFreq[s2[i + n]-'a']++; // adding next element
    }
    
    if(ispermutation(countPatternFreq, countFreq))
        return true;
    
    return false;
}

// Time: O(n), length of larger string.
// Space: O(26 + 26) or O(1)