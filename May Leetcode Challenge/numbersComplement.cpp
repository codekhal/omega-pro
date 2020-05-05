/* 
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Intution: Input + Complement = 111....11 in binary format

Solution 1:
N + bitwiseComplement(N) = 11....11 = X
Then bitwiseComplement(N) = X - N

Solution 2:
N ^ bitwiseComplement(N) = 11....11 = X
bitwiseComplement(N) = N ^ X

*/

int findComplement(int num) 
{
        
        int x = 1;
        
        while(num > x)
            x = x*2 + 1;
        
        return x - num;
}
