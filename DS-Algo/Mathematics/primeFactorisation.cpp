// Eg. For 36: prime factors(2x2x3x3)
// Observation:  Every number can be represented as the factors of prime numbers. 
//               And all prime factors shall be less than sqrt(that number).
int main() 
{
    int n = 36;
    int cnt;

    // to reduce the time complexity we know that prime factors won't be greater than sqrt(n).
    for(int i=2;i<=sqrt(n);i++) 
    {
        if(n%i == 0)
        {
            cnt = 0; 
            while(n % i == 0) // We divide this number untill it can't be further divided by a particular prime number.
            {
                n /= i;
                cnt++;
            }
        cout << "Prime factor " << i << " with Frequency " << cnt;
        cout << endl;
        }
    }
}