/* 
Problem : Finding all factor combinations of a number and adding it to the result vector.
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findAllFactors;

void findingFactors(int start, int factor_product, int n, vector<int> result_list)
{
    if(start > n || factor_product > n)
        return;

    if(factor_product == n) // we found product of few factors equal to our required number.
    {
        findAllFactors.push_back(result_list); // result list of list
        return;
    }

    for(int i = start; i<n; i++)
    {
        if(i * factor_product > n)
            return;
        
        // if it properly divides n then it is one of the potential factor

        if(n % i == 0)
        {
            result_list.push_back(i); // pushing that particular factor into our list

            // we multiply all the possible combinations of factors and recursively check all the possibilities

            findingFactors(i,i*factor_product,n,result_list);

            // if we get what we want we backtrack to empty the vector 
            // so new combination of factors get stored in it.
            // Below line responsible forBacktraking

            result_list.pop_back();
        }
    }
}

int main()
{
    
// let's say we want to find all factor combinations of number 8.
    int n = 8;

    vector<int> result_list;

    findingFactors(2,1,n,result_list);

    for (int i = 0; i < findAllFactors.size(); i++) 
    {  
        for (int j = 0; j < findAllFactors[i].size(); j++)  
            cout << findAllFactors[i][j] << " ";  
        cout << endl; 
    } 
    return 0;
}