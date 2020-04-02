// Given a string S containing letters and ‘#‘. The ‘#” represents a backspace. The task is to print the new string without ‘#‘

// Input: xy#z
// Output: xyz

// Approach:

// - Traverse the string S.
// - If any character except ‘#’ is found push it at back in deque.
// - if the character ‘#’ is found pop a character from back of deque.
// - Finally pop all elements from front of deque to make new string.

#include<bits/stdc++.h>
using namespace std;

string newString(string S) 
{ 
    deque<char> q; 
  
    for (int i = 0; i < S.length(); ++i) { 
  
        if (S[i] != '#') 
            q.push_back(S[i]); 
        else if (!q.empty()) 
            q.pop_back(); 
    } 
  
    // build final string 
    string ans = ""; 
  
    while (!q.empty()) { 
        ans += q.front(); 
        q.pop_front(); 
    } 
  
    // return final string 
    return ans; 
} 

int main(){

    string str;
    cin >> str;
    
    cout << newString(str);
    
  return 0;
}

// Time complexity: O(n) where, n is the length of the String