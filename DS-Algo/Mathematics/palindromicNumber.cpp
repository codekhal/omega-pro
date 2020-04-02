#include <bits/stdc++.h>
using namespace std;

const unsigned int mod = 1000000009;

int checkDivisible(string& str)
{
    int n = str.length();
    long long unsigned int digitSum = 0;

    for(int i=0;i<n;i++)
    {
        digitSum += (str[i] - '0');
    }
    
    return (digitSum % 9 == 0);
}

bool checkZero(string& str)
{
    int n = str.length();

    for(int i=0;i<n;i++)
    {
        if(str[i] == '0')
            return false;
    }
    return true;
}

bool checkPalindrome(string& s)
{
    int start = 0, end = s.size() - 1;
    while(start <= end)
    {
        if(s[start] != s[end])
        {
            return false;
        }

        start++;

        end--;
    }
    return true;
}

long long int getSum(int N){
    long long unsigned int start = pow(10, N-1);
    long long unsigned int end = pow(10,N) - 1;

    long long unsigned int sum = 0;

    for(long long unsigned int i=start;i<=end;i++)
    {
        string s = to_string(i);
        if(checkPalindrome(s))
        {
            if(checkDivisible(s))
            {
                if(checkZero(s))
                {
                    sum += i;
                }
            }
        }
    }
    return (sum % mod);
}
int main(){
    int N;
    cin>>N;
    long long unsigned int result;
    result = getSum(N);
    cout<<result;
    return 0;
}