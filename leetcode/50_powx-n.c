#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n) {
    double temp;
    int sign;

    if (n == 0)
        return 1.0;
    if (n == 1)
        return x;
    if (n == -1)
        return 1.0 / x;

    sign = (n>0)? 1 : -1;
    temp = myPow(x, n/2);
    temp *= temp;

    if (n % 2)
        return temp * myPow(x, sign);
    else
        return temp;

}


int main(void) {
    double x;
    int n;
    printf("enter the x:\n");
    scanf("%f", &x);
    printf("enter the n:\n");
    scanf("%d", &n);


	printf("%lf\n", myPow(x, n));

	return 0;
}
