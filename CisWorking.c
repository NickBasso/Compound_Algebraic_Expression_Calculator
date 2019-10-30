#include <stdio.h>

double sinD(double x) {
    int i, n=10;
    float sum=1,t=1;
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
    int i, n=10;
    float sum=1,t=1;
    x= x*3.14159/180.0;

    for (i=1;i<=n;i++) {
        t=(t*(-1)*x*x)/(2*i*(2*i-1));
        sum+=t;
    }
    return sum;
}

double tanD(double x) {
    return sinD(x)/cosD(x);
}

double cotD(double x) {
    return cosD(x)/sinD(x);
}


int main() {
    double x;
    printf("Enter x:");
    scanf("%lf",&x);
    printf("cos:%lf, sin:%lf, tan:%lf, cot:%lf",cosD(x), sinD(x), tanD(x),cotD(x));
    return 0;
}
