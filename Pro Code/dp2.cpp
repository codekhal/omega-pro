#include <iostream>
using namespace std;
int profit(int wt[],int val[],int n,int m)
{
    /*
    // 0 1 knapsack
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=m;w++)
        {
            if(wt[i-1]<=w)
            {
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }
                                                                                                                Weight of items, w[]=4 8 2
                                                                                                                value of items, v[]=7 8 3
                                                                                                                Capacity of knapsack, M=11
    return dp[n][m];*/

    //unbounded knapsack
    int dp[m+1]={0};

    for(int i=0;i<=m;i++)
    {
        for(int item=1;item<=n;item++)
        {
            if(wt[item-1]<=i)
            {
                dp[i]=max(val[item-1]+dp[i-wt[item-1]],dp[i]);
            }
        }
    }
    return dp[m];


}
int main() {
    int n;
    cin>>n;
    int w[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int m;
    cin>>m;
    cout<<profit(w,val,n,m);
}

