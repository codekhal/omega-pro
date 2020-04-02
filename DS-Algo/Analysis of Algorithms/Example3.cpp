int fun1(int n) 
{ 
    if (n <= 1) return n; 
    return 2*fun1(n-1); 
} 

// T(n) = T(n-1) + C which is O(n)


int fun2(int n) 
{ 
    if (n <= 1) return n; 
    return fun2(n-1) + fun2(n-1); 
} 

// T(n) = 2T(n-1) + C which is O(2^n)