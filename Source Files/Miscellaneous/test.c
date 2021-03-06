#include <stdio.h>
#include <stdlib.h>
#include "..\Trigonometric Functions\CoreMath.h"

#define N 1000
#define bool char
#define true 1
#define false 0

int operationPriority[255] = {0};

void Throw_Exception();

char isInBrackets(char *s, int size);
double calculateInBrackets(char *s, int size);

char isAlgebraicFunction(char *s);
double calculateAlgebraicFunction(char *s);

char isNumber(char *s);
double convertToNumber(char *s);


double calculate(char *s){
	int i = 0;
	int curPr = 0;
	int pos = 0;
	int bracketsCounter = 0;
	char operation = 0;
	
	while(s[i] != 0){
		if(s[i] == '(')
			bracketsCounter++;
		if(s[i] == ')')
			bracketsCounter--;
		
		if(bracketsCounter == 0 && operationPriority[s[i]] <= curPr){
			curPr = operationPriority[s[i]];
			pos = i;
		}	
		
		i++;
	}
	
	if(curPr < 0){
		operation = s[pos];
		s[pos] = 0;
		
		switch(operation){
			case '+' : return calculate(s) + calculate(s + pos + 1);
			case '-' : return calculate(s) - calculate(s + pos + 1);
			case '*' : return calculate(s) * calculate(s + pos + 1);
			case '/' : return calculate(s) / calculate(s + pos + 1);
		}
	}
	else if(isInBrackets(s, i) == true){
		return calculateInBrackets(s, i);
	}
	else if(isAlgebraicFunction(s) == true){
		return calculateAlgebraicFunction(s);
	}
	else if(isNumber(s) == true){
		return convertToNumber(s);
	}
	else{
		Throw_Exception();
	}
	
	
	/*else if(s[0] == '(' && s[i - 1] == ')'){
		s[0] = 0;
		s[i - 1] = 0;
		return calculate(s + 1);
	}	
	else if(s[0] == 's' && s[1] == 'i' && s[2] == 'n'){
		return sin(calculate(s + 3));
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 's'){
		return cos(calculate(s + 3));
	}
	else if(s[0] == 't' && s[1] == 'a' && s[2] == 'n'){
		return tan(calculate(s + 3));
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 't'){
		return cot(calculate(s + 3));
	}
	else if(s[0] >= '0' && s[0] <= '9'){
		i = 0;
		
		while((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
			i++;
			
		return atof(s);
	}
	else if(s[0] == 0){
		return 0.0;
	}
	else{
		Throw_Exception();
	}*/
}

int main(){
	// input block
	freopen("input.txt", "r", stdin);	
	char s[N] = {0};
	gets(s);
	printf("%s\n", s);
	
	double x = atof(s);
	
	operationPriority['+'] = operationPriority['-'] = -2;
	operationPriority['*'] = operationPriority['/'] = -1;
	
	printf("%lf", calculate(&s[0]));
	
	return 0;
}

void Throw_Exception(){
	puts("Incorrect algebraic expression entered!");
	exit(0);
}

char isInBrackets(char *s, int size){
	if(s[0] == '(' && s[size - 1] == ')'){
		return true;
	}
	else{
		return false;
	}
}

double calculateInBrackets(char *s, int size){
	s[0] = 0;
	s[size - 1] = 0;
	return calculate(s + 1);
}

char isAlgebraicFunction(char *s){
	if(s[0] == 's' && s[1] == 'i' && s[2] == 'n'){
		return true;
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 's'){
		return true;
	}	
	else if(s[0] == 't' && s[1] == 'a' && s[2] == 'n'){
		return true;
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 't'){
		return true;
	}
	else{
		return false;
	}
}

double calculateAlgebraicFunction(char *s){
	if(s[0] == 's' && s[1] == 'i' && s[2] == 'n'){
		return sin(calculate(s + 3));
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 's'){
		return cos(calculate(s + 3));
	}	
	else if(s[0] == 't' && s[1] == 'a' && s[2] == 'n'){
		return tan(calculate(s + 3));
	}
	else if(s[0] == 'c' && s[1] == 'o' && s[2] == 't'){
		return cot(calculate(s + 3));
	}
}

char isNumber(char *s){
	if(s[0] >= '0' && s[0] <= '9'){
		int i = 0;
		
		while((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
			i++;
			
		return true;
	}
	else if(s[0] == 0){
		return true;
	}
	else{
		return false;
	}
}

double convertToNumber(char *s){
	return atof(s);
}
