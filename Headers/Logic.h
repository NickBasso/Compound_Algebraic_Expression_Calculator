int operationPriority[255] = {0};

char isInBrackets();
double calculateInBrackets();
char isAlgebraicFunction();
double calculateAlgebraicExpression();

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
			case '^' : return pow(calculate(s), calculate(s + pos + 1));
		}
	}
	else if(isInBrackets(s, i) == true){
		return calculateInBrackets(s, i);
	}
	else if(isAlgebraicFunction(s) == true){
		return calculateAlgebraicExpression(s);
	}
	else if(isNumber(s) == true){
		return StringToDouble(s);
	}
	else{
		Throw_Exception();
	}
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
	if(s[0] == 's' && s[1] == 'q' && s[2] == 'r' && s[3] == 't'){
		return true;
	}
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

double calculateAlgebraicExpression(char *s){
	if(s[0] == 's' && s[1] == 'q' && s[2] == 'r' && s[3] == 't'){
		return sqrt(calculate(s + 4));
	}
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
