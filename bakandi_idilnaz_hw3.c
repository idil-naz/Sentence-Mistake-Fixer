#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void RuleOne(char sentence[], int n);
void RuleTwo(char sentence[], int n);
int punctuationCheck(char punct);		//Function prototypes

int main(){
	
	char sentence[100]; //The sentence that the user will input
	int n; //A variable that is equal to the string length
	
	printf("Enter a sentence: ");
	gets(sentence);
	n = strlen(sentence);

	RuleOne(sentence, n); //Calling the functions
	RuleTwo(sentence, n);
	
	printf("\n\nFixed version of the string: ");
	printf("\n");
	puts(sentence); //The final form of the string
	
	return 0;

}

void RuleOne(char sentence[100], int n){ //There must not be any duplicate letters for the inputs that the user enter.

	for(int i=n; i>0; i--){ //Loops through the string
		while(sentence[i] == sentence[i-1] || (abs(sentence[i] - sentence[i-1])== 32)){ //Checks if two letters next to each other are lower/upper case versions of one another.
		/*In ASCII, lower case and upper case letters have a 32 difference between themm (Ex: a: 97 A:65, 97-65 = 32)*/
		
			memmove(&sentence[i], &sentence[i+1], n-i); //Moves every char in the string to the left
		}
	}
	printf("\n\nFixed duplicates: ");
	printf("\n");
	puts(sentence); //Prints the string
}
	
void RuleTwo(char sentence[], int n){ //Eliminate unnecessary space characters and puntuation rule
	
	for(int i=0; i<n+1; i++){
		if((punctuationCheck(sentence[i]) == 1) && sentence[i+1] != ' '){ //If the char is a punctuation mark (checked using the below function) AND has a space on the right side.
			for(int j=n+1; j>i; j--){
				sentence[j+1] = sentence[j]; //The space is removed
			}
			sentence[i+1] = ' ';
		}
		
		if((punctuationCheck(sentence[i]) == 1) && sentence[i-1] == ' '){ //If the char is a punctuation mark (checked using the below function) but has a space on the left side.
			memmove(&sentence[i-1], &sentence[i], n-i-1); //Moves the string up
		}
	}
	printf("\n\nFixed spaces: ");
	printf("\n");
	puts(sentence); //Prints the string
	
}

int punctuationCheck(char punct){ //A function that checks if a char in the string is a punctuation mark. The function returns 1 if it is a punctuation mark.
	
	if(punct == '.') return 1;
	else if(punct == ',') return 1;
	else if(punct == ':') return 1;
	else if(punct == ';') return 1;
	else if(punct == '-') return 1;
	else if(punct == 39) return 1; //I could not write ''' so i wrote the ' character in its ASCII equivalent.
	else if(punct == '?') return 1;
	else if(punct == '!') return 1;
	else if(punct == '(') return 1;
	else if(punct == ')') return 1;
	else if(punct == '[') return 1;
	else if(punct == ']') return 1;
	else return 0;
	
}






