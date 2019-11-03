const double Pi = 3.1415926535897932;

double sin(double x) {
    int i, n = 10;
    double sum, t;
    x = x * (Pi / 180.0);
    t = x;
    sum = x;

    for (i = 1; i <= n; i++) {
        t = ((-1) * t * x * x) / (2 * i * (2 * i + 1));
        sum = sum + t;
    }
    
    return sum;
}

double cos(double x) {
    int i, n = 20;
    double sum = 1, t = 1;
    x = x * (Pi / 180.0);

    for (i = 1; i <= n; i++) {
        t = t * (-1) * x * x / (2 * i * (2 * i - 1));
        sum += t;
    }
    return sum;
}

double tan(double x){
	return sin(x) / cos(x); 
}

double cot(double x){
	return cos(x) / sin(x); 
}
