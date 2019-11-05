double StringToDouble(char *s){	
	int i = 0;
	int dots = 0;
	int dotPosition = -1;
	
	while((s[i] >= '0' && s[i] <= '9') ^ s[i] == '.'){
		if(s[i] == '.'){
			dots++;
			dotPosition = i;
		}
			
		i++;
	}
	
	int length = i;
	
	if(dots == 0){
		dotPosition = length;
	}
	
	double number = 0.0;
	double integralPart = 0.0;
	double fractionalPart = 0.0;
	double curDigit;
	
	int k = 0;
	int j;
	
	for(i = length - 1; i > dotPosition; i--){
		curDigit = (s[i] - '0') % 10;
			
		fractionalPart += PowerOfTen(k) * curDigit;
		
		k++;
	}
	
	k = 0;
	
	for(i = dotPosition - 1; i >= 0; i--){
		curDigit = (s[i] - '0') % 10;

		integralPart += PowerOfTen(k) * curDigit;
		
		k++;
	}
	
	number = integralPart + fractionalPart / PowerOfTen(length - dotPosition - 1);
	
	return number;
}

int StringLength(char *s){
	int i = 0;
	
	while(s[i] != '\0'){
		i++;
	}
	
	return i;
}

bool RemoveSpaces(char *s){
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
	
	i = 0;
	while(s[i] != '\0'){
		i++;
	}
	
	if(i != len){
		return true;
	}
	else{
		return false;
	}
}

char isNumber(char *s){
	int dotsCount = 0;
	
	if(s[0] >= '0' && s[0] <= '9'){
		int i = 0;
		
		while((s[i] >= '0' && s[i] <= '9') || s[i] == '.'){
			i++;
		}
		
		if(dotsCount < 2){
			return true;
		}			
	}
	else if(s[0] == 0){
		return true;
	}
	else{
		return false;
	}
}
