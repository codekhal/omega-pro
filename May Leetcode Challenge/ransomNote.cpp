/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

My Appraoch: We could simply add all the magazine letters in Hash Map. Since search will then be O(1).

Other Approach can be using string algorithms such as KMP or Z-algorithm.

*/

bool canConstruct(string ransomNote, string magazine) 
{
        
        int m = ransomNote.length();
        int n = magazine.length();
        
        unordered_map<char,int> ransom;
        
        // populate the hash map
        
        for(auto x: magazine)
        {
            ransom[x] += 1;
        }
        
        // Compare all the values in ransom note with the ones in the hash map we have.
        for(auto val: ransomNote)
        {
            if(ransom.find(val) == ransom.end()) // If not found then it ransom note can't be made from the magazine.
                return false;
            
            int count = ransom[val];
            
            if(count == 0)
                return false;
            
            ransom[val] = count - 1; // as we encounter one letter, we reduce its count since to check the pattern.
        }
        return true;
        
}