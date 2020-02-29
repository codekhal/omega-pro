// Given a string we need to calculate all the lexicographically possible permutations using recursion(backtracking).
// Link to the recusion picture: https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif
// Link to the question: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// Time complexity: O(n*n!) [n! permutations and it requires O(n) time to print them]

# include<bits/stdc++.h>
using namespace std;

void permute(string S, int l, int r, set<string> &st) // Helper function to calculate all the permutations.
{
    if(l == r)
    {
        st.insert(S);  // insertion into set is always lexicographically sorted. And we insert all the swapped combination. 
    }
    else
    {
        for(int i=l; i<=r; i++)
        {
            swap(S[l],S[i]);  // swaping 
            
            permute(S,l+1,r,st);  // recursion
            
            swap(S[l],S[i]);    // backtrack
        }
    }
}
void permutation(string S)  // function to print all the sorted permutations of a string.
{
    int l = 0;
    int r = S.length()-1;
    set<string> st;
    
    permute(S, l, r, st);
    
    for(auto i = st.begin(); i != st.end(); i++)
    {
        cout << *i << " ";
    }
    
}

int main()
{
    int t;
    while(t--)
    {
        string str;
        cin >> str;
        permutation(str);
        cout << endl;
    }

    return 0;
}


// Method 2: without recursion, using STL

void permutation(string S)
{
sort(S.begin(),S.end());
do
{
    cout<<S<<" ";
} while(next_permutation(S.begin(),S.end()));
}

