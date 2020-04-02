// Given a right angled isosceles triangle. Find the maximum number of squares of size 2×2 units that can fit in it.

#include<bits/stdc++.h>
using namespace std;

int squares(int n)
{
    int base = n - 2;
    base /= 2;
    return base*(base+1)/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
	int t,n;
	cin >> t;
	while(t--)
	{
	  cin >> n;
	  cout << squares(n) << endl;
	}
	return 0;
}


// Link for contest: https://practice.geeksforgeeks.org/contest/special-21-day-1-mathematics/