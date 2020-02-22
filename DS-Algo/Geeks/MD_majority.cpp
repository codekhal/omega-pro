#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int t,n,a[99999];
    cin >> t;
    while (t--)
    {
        unordered_map <int,int> m;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
        }
        int count = 0;
        for (auto i = m.begin();i != m.end();i++)
        {
            if(i->second > n/2)
            {
                count = 1;
                cout << i->first << endl;
                break;
            }
        }
         if(count == 0)
            {
                cout << "-1" << endl;
            }
    }
    return 0;
}