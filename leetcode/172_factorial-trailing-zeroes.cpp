class Solution {
public:
    #define min(X, Y) (((X) < (Y)) ? (X) : (Y))

    int pot(int p, int n)
    {
        int c = 0;
        while (p <= n)
        {
            c += (n/p);
            p *= p;
        }
        return c;
    }
    
    int trailingZeroes(int n) {
        return min(pot(2,n), pot(5, n));
    }
};