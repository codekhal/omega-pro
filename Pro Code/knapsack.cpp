#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity,int value[],int weight[], int n)
{
    int result[20][20];
    for(int i = 0; i < n+1; i++)
    {     
        for(int j = 0; j < capacity+1; j++)
        {
            if(i==0 || j==0)
            {
                result[i][j] = 0;
            }
            else if(weight[i-1] <= j) 
            {
                result[i][j] = max(result[i-1][j], result[i-1][j-weight[i-1]]+value[i]);
            }
            else
            {
                result[i][j] = result[i-1][j];
            }
            
        }
        
    }
    return result[n][capacity];
}

int main()
{
    int capacity, n;
    int value[5],weight[5];
    cin >> n >> capacity;
    for(int i=0;i<n;i++)
    {
        cin >> value[i];
    }
    for(int i = 0; i < n ; i++)
    {
        cin >> weight[i];
    }
    cout << knapsack(capacity,value,weight,n);
    return 0;
}
