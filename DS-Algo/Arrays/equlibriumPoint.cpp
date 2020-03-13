// Simple solution O(n^2) Approach but inefficient

int findEquilibrium(int A[], int n)
{
  int i,j;
  int sumLeft,sumRight;
  
  for(i=0;i<n;i++)
  {
      sumLeft = 0;
      for(j=0;j<i;j++)
      {
          sumLeft += A[j];
      }
      //cout << sumLeft << " ";
      
      sumRight = 0;
      for(j=i+1;j<n;j++)
      {
          sumRight += A[j];
      }
      //cout << sumRight << " ";
      
      if(sumLeft == sumRight)
        return i;
  }
  return -1;
}

// We can think of a solution of reducing one loop. We are calculating left and right sum.
// Let's calculate total sum of the array and subtract the left sum from it. We will not need to calculate right sum then.
// sum = sum - arr[i] will help us calculate the right sum.

// Efficient Solution O(n)

int findEquilibrium(int A[], int n)
{
  int i,j;
  int sum=0, leftsum;
  
  for(i=0;i<n;i++)
  {
    sum += A[i];   
  }
  
  leftsum = 0;
  for(int i=0;i<n;i++)
  {
      sum = sum - A[i];
     
      if(sum == leftsum)
        return i;
  
      else
        leftsum += A[i];
  }

  return -1;
}