#include <stdio.h>
#include "..\Headers\PredefinedDesignations.h"

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

	double a = 2.45, b = -3;
	
	printf("%.12lf", pow(a, b));
	
	return 0;
}
