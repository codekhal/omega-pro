#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n,arr[99999];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 0; i < n-1; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
        }
        cout << endl;        
    }
    return 0;
}
