// Input: abc
// Output: '_','a' 'ab' 'abc' 'ac' 'b' 'bc' 'c'

# include<bits/stdc++.h>
using namespace std;

void getPermute(string &str, vector<string> &v, int i=0, string curr = "")
{
    int n = str.length();
    
    if(i == n) // Base Case
    {
        v.push_back(curr);
        return;
    }
    
    getPermute(str,v,i+1,curr);
    getPermute(str,v,i+1,curr+str[i]);
}

vector <string> powerSet(string s)
{
   vector<string> v;
   getPermute(s, v);
   
   return v;
}
