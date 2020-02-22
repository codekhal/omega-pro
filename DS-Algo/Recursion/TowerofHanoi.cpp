// C++ recursive function to solve tower of hanoi problem

#include<bits/stdc++.h>
using namespace std;

void TOH(int n, char Fr, char To, char Aux)
{
    if(n==1) // Base case for this problem, as soon as we find n=1 which means 
            // last disk which is the smallest of all is meant to move from First Rod to Last Rod.
    {
        cout << "Move disk 1 from " << Fr << " to " << To << endl;
        return;
    }

    TOH(n-1,Fr, Aux, To); // Recursively check, we assume that we have placed all the n-1 disks successfully at the 'Auxilliary_rod'
                          // and now To rod is our auxilliary_rod and we transfer largest disk remaining from 'Fr_rod' to 'To_rod'
    
    cout << "Move " << n << " disk from " << Fr << " to " << To << endl;

    TOH(n-1,Aux,To, Fr); // Also now 'Fr_rod' becomes empty and we make that our 'Aux_rod. and recursively put all the disks to 'To_rod'.
}

int main()
{
    int n = 4; // Lets take 4 disks
    
    TOH(n,'F','L','A');

    return 0;
}


// Understanding Algorithm using following Steps:

// Step 1: Move (n-1) disks from A --> B using C as auxiliary rod (Since moving n-1 disks we are creating another subproblem to solve)
// Step 2: Move nth disk from A --> C
// Step 3: Move rest (n-1) disks from B --> C using A as auxiliary rod 