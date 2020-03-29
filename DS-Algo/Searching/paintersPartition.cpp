// Given n boards of length {A1, A2, .. An} k painters available and each takes 1 unit time to paint 1 unit of board. 
// The problem is to find the minimum time to get this job done under the constraints that 
// any painter will only paint continuous sections of boards
// Using Binary Search which is more efficient as compared with other solution like DP.

// Input : k = 2, A = {10, 20, 30, 40} 
// Output : 60.
//          Here we can divide first 3 boards for
//          one painter and the last board for 
//          second painter.

const int mod = 10000003;

bool possibleToPaint(int numPainters, long long int time_per_unit, vector<int> &fence_lengths, long long int time_per_painter)
{
    int painter_used = 1;
    
    long long int curr_time = 0;
    
    for(auto lengths: fence_lengths)
    {
        if(lengths*time_per_unit > time_per_painter) // If it is not possible for painters to paint this amount of length.
            return false;
             
        curr_time += lengths*time_per_unit;  // Current time shall be less than equal to the total lengths covered by painters.
        
        if(curr_time > time_per_painter)  // If not then we increase the number of painters.
        {
            painter_used++;
            
            curr_time = lengths*time_per_unit; // And start the work of next painter from that current time.
        }
    }
    return painter_used <= numPainters;  // Returns true if the number of painters given are equal to the painters we needed for the mid fence work.
}

int Solution::paint(int A, int B, vector<int> &C) {
    
    long long int l = 1;
    
    long long int r = 0;
    
    for(auto lengths: C)
    {
        r += lengths;
    }
    
    r *= B;
    
    long long int ans = -1;
    while(l <= r)
    {
        long long int mid = l + (r-l) / 2;
        
        // Now we have to check that A painters paints only contigous boards and no
        // painter takes more than B units of time.
        
        if(possibleToPaint(A, B, C, mid))
        {
            ans = mid; // No painters should take more than mid units to paint.
                       // If it is possible than answer is mid and we check for more min possibility.
            r = mid - 1; 
        }
        else
            l = mid + 1; // If not possible then probably we need to give them more time.
    }
    
    return (ans % mod);
}