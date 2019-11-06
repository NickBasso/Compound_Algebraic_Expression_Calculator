#include <stdio.h>
#include "..\Headers\PredefinedDesignations.h"

double pow(double number, int exponent){
	if(exponent == 0){
		return 1.0;
	}
	
	double base = number;
	bool isNegative = false;
	
	if(exponent < 0){
		isNegative = true;
	}
	
	for(int i = 1; i < exponent; i++){
		number *= base;
	}
	
	if(isNegative == true){
		number = 1.0 / number;
	}
	
	return number;
}

main(){
	//printf("%lf", sin(10000));

	double a = 3, double b = 3;
	
	printf("%lf", pow(a, b));
	
	return 0;
}
