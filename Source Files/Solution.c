#include <stdio.h>

// !Warning! DON'T CHANGE THE ORDER!
#include "..\Headers\Exceptions.h"					// Exceptions
#include "..\Headers\PredefinedDesignations.h"		// Predefined Designations
#include "..\Headers\MathConstants.h"				// Mathematical constants
#include "..\Headers\CoreMath.h"					// Algebraic functions
#include "..\Headers\Strings.h"						// Operations on strings
#include "..\Headers\Logic.h"						// Main algorithm

int main(){
	// input block
	freopen("input.txt", "r", stdin);
		
	char s[N] = {0};
	gets(s);
	printf("%s\n", s);
	
	// set operation priority for the main algorithm logic
	operationPriority['+'] = operationPriority['-'] = -2;
	operationPriority['*'] = operationPriority['/'] = operationPriority['^'] = -1;
	
	// remove all spaces and print the string again 
	if(RemoveSpaces(s) == true){
		printf("\nNormalized form of the expression:\n%s\n\n", s);
	}
	
	// calculate the expression value
	double ans = calculate(s);
	
	// print the answer with the 15-digit precision
	printf("%.15lf", ans);
	
	return 0;
}

