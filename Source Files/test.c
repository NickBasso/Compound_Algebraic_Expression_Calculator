#include <stdio.h>
#include <stdlib.h>
#include "coreMath.h"

#define N 1000

int operationPriority[255] = {0};

double calculate(char *s, int size){
	int i = 0, curPr = 0, pos = 0;
	char operation = 0;
	
	while(s[i] != '\0' && i < size){
		if(operationPriority[s[i]] >= curPr){
			curPr = operationPriority[s[i]];
			operation = s[i];
			pos = i;
		}	
		
		i++;
	}
	
	char temp[N] = {0};
	
	if(curPr == 0){
		for(i = 0; i < strlen(s); i++)
		temp[i] = s[i];
	}
	else{
		for(i = 0; i < pos; i++)
		temp[i] = s[i];
	}	
	
	double x = atof(temp);
	
	switch(operation){
		case '+' : return calculate(temp, pos) + calculate(s + pos + 1, N);
		case '-' : return calculate(temp, pos) - calculate(s + pos + 1, N);
		case '*' : return calculate(temp, pos) * calculate(s + pos + 1, N);
		case '/' : return calculate(temp, pos) / calculate(s + pos + 1, N);
		case  0  : return atof(temp);
	}
}

int main(){
	// input block
	freopen("input.txt", "r", stdin);	
	char s[N] = {0};
	gets(s);
	printf("%s\n", s);
	
	double x = atof(s);
	
	operationPriority['+'] = operationPriority['-'] = 1;
	operationPriority['*'] = operationPriority['/'] = 2;
	
	printf("%lf", calculate(&s[0], N));
	
	return 0;
}
