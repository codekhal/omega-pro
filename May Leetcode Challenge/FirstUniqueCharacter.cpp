/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
s = "leetcode"
return 0

s = "loveleetcode",
return 2

Note: We may assume the string contain only lowercase letters.
Asked in Amazon, simplest of all.
*/

int firstUniqChar(string s) {
        unordered_map<char,int>my_map; // We could use hashMap to store the char 
                                      // and its corresponding count value.
        
        for(int i=0;i<s.length();i++)
        {
            my_map[s[i]] += 1; // Populating the hashmap
        }
        
        // We find the first value equal to 1 and return that index.
        for(int i=0;i<s.length();i++)
        {
            if(my_map[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

// Time Complexity: O(n) ,where n is the size of the string

/* Alternate method: 

In order to reduce the space complexity we could take an int array of size 26 and 
and increase the count at the particular letter's index as we find the character.

    int count[26] = {0};

    for(char x : s)
    {
        count[x - 'a'] += 1; // Getting the index value of the particular char by sub it from 
                             // 'a'. 
    }

    As we have the count for all the chars we need to find first char with count = 1;

    for(int i=0;i<s.length();i++)
    {
        if(count[s[i] - 'a'] == 1) return i;
    }
    
    return -1;
*/
