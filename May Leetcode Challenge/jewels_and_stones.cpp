/* You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, 
so "a" is considered a different type of stone from "A".

Input: J = "aA", S = "aAAbbbb"
Output: 3

*/

class Solution {
public:
    
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> jewels; // Using Hash Map to store the char and its count
        
        for(int i=0;i<J.length();i++)
        {
            jewels[J[i]] += 1; // Populating the Hash Map
        }
        
        int count = 0;
        for(int i=0;i<S.length();i++)
        {
            if(jewels.find(S[i]) != jewels.end()) // If value exist in Hashmap then increase
                count++;                          // count. Finally return count.
        }
        
        return count;
    }
};

// Time Complexity: O(J) + O(S) , where J and S are string sizes. 