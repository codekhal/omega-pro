## Kadane's Algorithm

To better understand Kadane’s Algorithm, first, we would look at a quite popular programming problem, the Maximum Subarray Problem. 
<br>

> Those who cannot remember the past are condemned to repeat it. — Dynamic Programming.

![Input Array](https://miro.medium.com/max/980/1*li8Wlm3ZpInWLvpJ3yE9Iw.png)

Maximum Sum Subarray (In Yellow)

### Steps:
- We would start from the last element and calculate the sum of every possible subarray ending with the element A[n-1] .
- Then, we would calculate the sum of every possible subarray ending with A[n-2], A[n-3] and so on up to A[0].

Now let’s focus on the subarrays ending with the element A[4] (=-1) and A[5] (=2) shown in the figure below.

![Subproblems](https://miro.medium.com/max/1014/1*UrQhblF8B-6QoEC6E7kWow.png)

From the figure above, we see that the local_maximum[4] is equal to 3 which is the sum of the subarray [4, -1]. Now have a look at the subarrays ending with A[5]. You’ll notice that these subarrays can be divided into two parts, the subarrays ending with A[4] (highlighted with yellow) and the single element subarray A[5] (in green).

<br>
Let’s say somehow I know the local_maximum[4]. Then we see that to calculate the local_maximum[5], we don’t need to compute the sum of all subarrays ending with A[5] since we already know the result from arrays ending with A[4]. Note that if array [4, -1] had the maximum sum, then we only need to check the arrays highlighted with the red arrows to calculate local_maximum[5].
<br>
> local_maximum at index i is the maximum of A[i] and the sum of A[i] and local_maximum at index i-1.

This way, at every index i, the problem boils down to finding the maximum of just two numbers, A[i] and (A[i] + local_maximum[i-1]). Thus the maximum subarray problem can be solved by solving these sub-problems of finding local_maximums recursively.
<br>

Code: <br>
![Code](https://miro.medium.com/max/873/1*rgcPr2WFkToaDBknC9IXBA.png)

<br> <br>
[Credits](https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d)