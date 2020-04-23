// We have a subarray and sum given.
// We need to find a subarray with sum equal to the gievn sum.

/* Approach: What we can do it we take 2 pointers. 

left & right. We traverse through the array and we keep on adding elements into curr_sum.
So if we find curr_sum less than sum we keep on incrementing right 
and if we find curr_sum greater than sum we increment left pointer.
Finally if we find curr_sum == sum we return indexes.