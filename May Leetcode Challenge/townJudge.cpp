/*   
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3

*/

int findJudge(int N, vector<vector<int>>& trust) 
{    
    int n = trust.size();
    
    // We build an array of pairs. 
    // First will store elements that follows any other element we increase count by 1.
    // Second stores if there exist any element which follows it.
    // There are 2 cases in this, n-1 element follows judge.
    // And that judge do not follows anyone.
    
    // We return element when array.first == 0 and array.second == n-1.
    
    vector<pair<int,int>> followers(N+1,{0,0});
    
    for(int i=0;i<n;i++)
    {
        followers[trust[i][0]].first += 1;
        followers[trust[i][1]].second += 1;
    }
    
    for(int i=1;i<=N;i++)
    {
        // Check that arr[i].first ==0 and arr[i].second == n-1;
        
        if(followers[i].first == 0 and followers[i].second == N-1)
            return i;
    }
    return -1;
}


// Time Complexity: O(n) -> {n + n}
// Space: O(n)