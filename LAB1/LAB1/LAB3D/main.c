//contains D and E
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char N[100];
char menu_options;
int a = 1;
char joe;

void carry(char *N){
	do{
		printf("Choose your option man:\n");
		menu_options = getchar();
		joe = getchar();
		switch(menu_options){
			case 'A':
				VowelCount(N);
				break;
			case 'B': 
				ConsCount(N);
				break;
			case 'C':
				UpperCase(N);
				break;
			case 'D':
				LowerCase(N);
				break;
			case 'E':
				printf("%s",N);
				break;
			case 'F':
				printf("Enter the string: \n");
				fgets(N, 100, stdin);
				break;
			case 'R':
				printf("Reverse string is: %s\n", strrev(N));
				break;
			case 'M':
				menu();
				break;
			case 'X':
				--a;
				break;
		}
		
	}while(a);
}

int VowelCount(char *N){
	int count = 0;
	int c = 0;
	for(c = 0; N[c] != '\0';c++){
		if(N[c] == 'a' || N[c] == 'A' || N[c] == 'e' || N[c] == 'E' || N[c] == 'i' || N[c] == 'I' || N[c] =='o' || N[c]=='O' || N[c] == 'u' || N[c] == 'U'){
			count++;
		}
	}
	printf("\nNumber of vowels in the string: %d\n" , count);
	return count;
}

int ConsCount(char *N){
	int count = 0;
	int c = 0;
	for(c = 0; N[c] != '\0';c++){
		if(N[c] != 'a' || N[c] != 'A' || N[c] != 'e' || N[c] != 'E' || N[c] != 'i' || N[c] != 'I' || N[c] !='o' || N[c]!='O' || N[c] != 'u' || N[c] != 'U'){
			count++;
		}
	}
	printf("\nNumber of Consonant's in the string: %d\n" , count);
	return count;
}

void UpperCase(char *N){
	puts(strupr(N));
}

void LowerCase(char *N){
	puts(strlwr(N));
}

void printAgain(char *N){
	printf("Enter the string: \n");
	fgets(N, 100, stdin);
}

void menu(){
	printf("A) Count the number of vowels in the string\n");
	printf("B) Count the number of consonants in the string\n");
	printf("C) Convert the string to uppercase\n");
	printf("D) Convert the string to lowercase\n");
	printf("E) Display the current string\n");
	printf("F) Enter another string\n");
	printf("R) Reverse the string\n\n");
	printf("M) Display this menu\n");
	printf("X) Exit the program\n");
	
}

int main(){
	printf("Enter the string please\n");
	fgets(N, 100, stdin);

	menu();
	carry(N);
	return 0;
}
