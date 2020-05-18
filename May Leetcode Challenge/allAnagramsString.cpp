/*

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc"

*/

vector<int> findAnagrams(string s, string p) 
{
    // if one string can be formed by rearranging the other then
    // then both are anagrams. Freq and size should exactly be same.
    
    vector<int> ans;
    
    if(s.length() < p.length())
        return ans;
    
    vector<int> charCount(26,0);
    
    for(char c : p)
        charCount[c - 'a'] += 1;
    
    int start = 0;
    
    for(int i=0;i<p.length();i++)
    {
        charCount[s[i] - 'a'] -= 1;
    }
    
    int mismatch = 0;
    
    for(int x : charCount)
    {
        if(x != 0)
            mismatch += 1;
    }
    
    if(mismatch == 0)
        ans.push_back(start);
    
    start++;
    
    while(start <= s.length() - p.length())
    {
        int idx1 = s[start - 1] - 'a';
        int idx2 = s[start + p.length() - 1] - 'a';
        charCount[idx1] += 1;
        
        if(charCount[idx1] == 1)
            mismatch += 1;
        
        else if(charCount[idx1] == 0)
            mismatch -= 1;
        
        charCount[idx2] -= 1;
        
        if(charCount[idx2] == -1)
            mismatch += 1;
        
        else if(charCount[idx2] == 0)
            mismatch -= 1;
        
        if(mismatch == 0)
            ans.push_back(start);
        start++;            
    }
    
        return ans;
    }
};

/*
let's develop an algorithm to solve this problem.

1. Find frequency of each character in p.
2. Now, we need to find all substrings of length p in s.
    This process can be efficiently done by using sliding window technique.
	Sliding Window Technique:-
	s = abcad, p = abc
	Take two pointers i and j. 
	Intially i and j point to starting position of string s. 
	s = a  b  c  a  d
        ^
	   i, j
	->  move j until j - i == len(p)
	s = a  b  c  a  d
        ^        ^
        i        j
	Now, the substring formed here is  abc, 
	it is anagram so, add i to result. and increment i.
	s = a  b  c  a  d
           ^     ^
           i     j
   Now, j at 3rd index, i at 1st index.
   3 - 1 < 3
   so, move j until j - i == len(p)
   s = a  b  c  a  d
          ^        ^
          i        j
    Now, substring formed here is bca.
	It is anagram. so, add i to result. and move i.
	Now, i is at 2nd index and j is at 4th index.
	4 - 2 < len(p) (3), so move j.
	 s = a  b  c  a  d
               ^        ^
               i        j
	Now, the substring formed here is cad.
	This is not anagram. Don't do anything.
	Now, we reached end. So, stop here.
	This is how we find substring using sliding window technique.
 	and check whether it is anagram or not.
	if it is anagram, then add starting index to result
3. return result.

TIME:- O(N)
SPACE:- O(N)
*/