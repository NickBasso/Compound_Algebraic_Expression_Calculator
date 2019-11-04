#include <stdio.h>

double StringToDouble(char *s){
	/*132
	1 * 0 + 2
	1 * 10 + 3
	1 * 100 + 1*/
	
	int i = 0;
	int dots = 0;
	
	while(s[i] >= '0' && s[i] <= '9' || s[i] == ' '){
		if(s[i] == '.'){
			dots++;
		}
			
		i++;
	}
	
	int length = i;
	
	if(dots > 1){
		printf("WRONG\n");
		return 0;
	}
	
	double number = 0.0;
	double curDigit;
	
	int k = 0;
	int j;
	
	for(i = length - 1; i >= 0; i--){
		curDigit = (s[i] - '0') % 10;
		
		int powerOfTen = 1;
		
		for(j = 0; j < k; j++)
			powerOfTen *= 10;
			
		number += powerOfTen * curDigit;
		
		k++;
	}
	
	return number;
}

main(){
	//printf("%lf", sin(10000));
	
	char s[10] = "213--";
	
	printf("%lf", StringToDouble(s));
	
	return 0;
}
