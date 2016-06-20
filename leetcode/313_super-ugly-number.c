int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int a[1000000];
    int ptr[100];	// a heap will be better
    int prd[100];
    int count, x;
    int old;
    
    // initial
    a[0] = 1;
    for (int i = 0; i < primesSize; i++)
    {
        ptr[i] = 0;
        prd[i] = primes[i];
    }
    count = 1;
    x = 1;
    old = 1;
   
    // process
    while (count <= n)
    {
        int xp = 0;
        int min = prd[0];
        for (int i = 0; i < primesSize; i++)
        {
            if (prd[i] < min)
            {
                xp = i;
                min = prd[i];
            }
        }
        
        if (min != old)
        {
            a[x] = min;
            old = a[x];
            count++;
            x++;
        }
        
        ptr[xp]++;
        prd[xp] = primes[xp] * a[ptr[xp]];
    }
    
    return a[n - 1];
    
}