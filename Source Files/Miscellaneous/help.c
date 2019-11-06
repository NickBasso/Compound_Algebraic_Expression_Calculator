#include <stdio.h>
#include "..\Headers\PredefinedDesignations.h"

<<<<<<< HEAD
double pow(double number, int exponent){
	if(exponent == 0){
		return 1.0;
=======
double powerOfTen(int times){
	int i = 0;
	double result = 1.0;
	
	for(i = 0; i < times; i++){
		result *= 10;
	}	
	
	return result;
}

double StringToDouble(char *s){
	/*132
	1 * 0 + 2
	1 * 10 + 3
	1 * 100 + 1*/
	
	int i = 0;
	int dots = 0;
	int dotPosition = -1;
	
	while((s[i] >= '0' && s[i] <= '9') ^ s[i] == '.'){
		if(s[i] == '.'){
			dots++;
			dotPosition = i;
		}
			
		i++;
>>>>>>> ea7f6e3b3a67107b4f239ca25757204579c36f39
	}
	
	double base = number;
	bool isNegative = false;
	
<<<<<<< HEAD
	if(exponent < 0){
		isNegative = true;
	}
	
	for(int i = 1; i < exponent; i++){
		number *= base;
	}
	
	if(isNegative == true){
		number = 1.0 / number;
=======
	if(dots == 0){
		dotPosition = length;
	}
	
	/*if(dots > 1){
		printf("WRONG\n");
		return 0;
	}*/
	
	double number = 0.0;
	double integralPart = 0.0;
	double fractionalPart = 0.0;
	double curDigit;
	
	int k = 0;
	int j;
	
	for(i = length - 1; i > dotPosition; i--){
		curDigit = (s[i] - '0') % 10;
			
		fractionalPart += powerOfTen(k) * curDigit;
		
		k++;
	}
	
	k = 0;
	
	for(i = dotPosition - 1; i >= 0; i--){
		curDigit = (s[i] - '0') % 10;

		integralPart += powerOfTen(k) * curDigit;
		
		k++;
>>>>>>> ea7f6e3b3a67107b4f239ca25757204579c36f39
	}
	
	number = integralPart + fractionalPart / powerOfTen(length - dotPosition - 1);
	
	return number;
}

int StringLength(char *s){
	int i = 0;
	
	while(s[i] != '\0'){
		i++;
	}
	
	return i;
}

void RemoveSpaces(char *s){
	int i = 0;
	int len = StringLength(s);
	
	for(i = 0; i < len; i++){
		if(s[i] == ' '){
			int j = i + 1;
			
			while(s[j] == ' '){
				j++;
			}
			
			s[i] = s[j];
			s[j] = ' ';
		}
	}
}

main(){
	//printf("%lf", sin(10000));

	double a = 3, double b = 3;
	
<<<<<<< HEAD
	printf("%lf", pow(a, b));
=======
	char s[100] = "21  3.44   44  4 4 4  4        4";
	printf("%s\n", s);
	/*double d;
	scanf("%lf", &d);
	printf("%.10lf\n", d);
	d = 12;
	printf("%.10lf\n", d);*/
	
	//printf("%.10lf", StringToDouble(s));
	RemoveSpaces(s);
	printf("%s\n", s);
>>>>>>> ea7f6e3b3a67107b4f239ca25757204579c36f39
	
	return 0;
}
