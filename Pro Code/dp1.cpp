#include <bits/stdc++.h>
using namespace std;
#define size 50

bool Vowel(char x)
{
	x = tolower(x);

	return(x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
}

int kDistinct(char str[], int n)
{
	int n = strlen(str);
	int result =-1;
	int c[size];
	memset(c,0,sizeof(c));
	for (int i = 0,j = -1; i < n; ++i)
	{
		int x = str[i];
		if(Vowel(x)) {
			if(++c[x] == 1)
				k--;
		}

		while(k < 0)
		{
			x = str[++j];
			if(Vowel(x))
			{
				if(++c[x] == 0)
					k++;
			}
		}
		if(k==0)
			result = max(result,i-j);
	}
	return result;
}
int main()
{
	char str[] = "geeks";
	int k = 2;
	
	cout << kDistinct(str,k);
	
	return 0;
}