double abs(double number){
	if(number < 0)
		return -number;
	else
		return number;
}

double pow(double number, int exponent){
	if(exponent == 0){
		return 1.0;
	}
	
	double base = number;
	bool isNegative = false;
	
	if(exponent < 0){
		isNegative = true;
		exponent = -exponent;
	}
	int i;
	for(i = 1; i < exponent; i++){
		number *= base;
	}
	
	if(isNegative == true){
		number = 1.0 / number;
	}
	
	return number;
}

double PowerOfTen(int times){
	int i = 0;
	double result = 1.0;
	
	for(i = 0; i < times; i++){
		result *= 10;
	}	
	
	return result;
}

double sin(double x) {
    int i, n = 1000;
    x = x * (180.0 / Pi);
    
    while(x > 360.0){
    	x = x - 360.0;
	}
	
    double sum, t;
    x = x * (Pi / 180.0);
    t = x;
    sum = x;

    for (i = 1; i <= n; i++){
        t = ((-1) * t * x * x) / (2 * i * (2 * i + 1));
        sum = sum + t;
    }
    
    return sum;
}

double cos(double x) {
    int i, n = 1000;
    x = x * (180.0 / Pi);
    
    while(x > 360.0){
    	x = x - 360;
	}
    
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

double sqrt(double n){ 
    double x = n; 
    double y = 1; 
    double e = 0.000000001; 							
    while (x - y > e) { 
        x = (x + y) / 2; 
        y = n / x; 
    } 

    return x; 
} 

