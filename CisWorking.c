#include <stdio.h>

double sinD(double x) {
    int i, n=10;
    float sum,t;
    x= x*(3.14159/180.0);
    t=x;
    sum=x;

    for (i=1;i<=n;i++) {
        t=((-1)*t*x*x)/(2*i*(2*i+1));
        sum+=t;
    }
    return sum;
}

double cosD(double x) {
    int i, n=20;
    float sum,t;
    x= x*(3.14159/180.0);
    t=x;
    sum=x;

    for (i=1;i<=n;i++) {
        t=t*(-1)*x*x/(2*i*(2*i-1));
        sum+=t;
    }
    return sum;
}
int main() {
    double x;
    printf("Enter x:");
    scanf("%lf",&x);
    printf("cos:%lf, sin:%lf",cosD(x), sinD(x));
    return 0;
}
