
#include<stdio.h>
int IsVowel( char aLetter)
{
	//printf("enter a letter\n");
	//scanf("%c",aLetter);
    if(!isalpha(aLetter))
    {
        printf("Error that is not an ASCII letter");
		return 0;
    }
    if(aLetter == 'A' || aLetter == 'E' || aLetter == 'I' || aLetter == 'O' || aLetter == 'U' || aLetter == 'a' || aLetter == 'e' || aLetter == 'i' || aLetter == 'o' || aLetter == 'u' )
    {
		printf("that is a vowel\n");
        return 1;
    }
    else
    {
        return 0;
    }
	return 0;

}
int main()
{
    int num1, num2, num3;  
    float fraction;     
    char character;
    char str[50];   // char array of size 50
	sizeofvariable();
	IsLeapYear(2000);
	IsVowel('a');
	ReverseNumber(12345);
    printf("Enter two numbers\n");
    
    // Taking integer as input from user
    scanf(" %d%i", &num1, &num2);
    printf("\n\nThe two numbers You have entered are %d and %i\n\n", num1, num2);

    // Taking float or fraction as input from the user
    printf("\n\nEnter a Decimal number\n");
    scanf(" %f", &fraction); 
    printf("\n\nThe float or fraction that you have entered is %f", fraction);

    // Taking Character as input from the user
    printf("\n\nEnter a Character\n");
    scanf(" %c",&character);
    printf("\n\nThe character that you have entered is %c and the ASCII number is %d", character, character);
    getchar();

    printf("\n\nEnter your complete name:\n\n\n");

    gets(str);
    printf("\n\nWelcome to ECEGR 2020  %s\n\n\n", str);

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
  
    scanf("%c",&character);
    return 0;
}


	void sizeofvariable(void)
{
	char c;
	short s;
	int i;
	unsigned int ui;
	unsigned int ul;
	float f;
	double d;
	long double ld;
	void *ptr;
	
	printf("%d\n",sizeof(c));
	printf("%d\n",sizeof(s));
	printf("%d\n",sizeof(i));
	printf("%d\n",sizeof(ui));
	printf("%d\n",sizeof(ul));
	printf("%d\n",sizeof(f));
	printf("%d\n",sizeof(d));
	printf("%d\n",sizeof(ld));
	printf("%d\n",sizeof(ptr));

}

int IsLeapYear(int aYear)
{
    if(aYear<1752)
    {
		printf("not a leap year bruh\n");
        return 0;
    }
    if(aYear % 400 == 0)
    {
		printf("this is a leap year\n");
        return 1;
    }
    if(aYear % 100 == 0 && aYear != 2000)
    {
		printf("not a leap year bruh\n");
        return 0;
    }
    if(aYear % 4 == 0)
		
    {
		printf("this is a leap year\n");
        return 1;
    }
return 0;
}



void ReverseNumber(long aNumber)
{
    int neg = 0;
    if(aNumber < 0)
    {
        aNumber = aNumber * -1;
        neg = 1;
        printf("isneg");
    }


    printf("%d\n", aNumber);
    long original = aNumber;
    long number = 0;
    long reverse = 0;


    while(aNumber != 0)
    {
        number = aNumber%10;
        reverse = reverse*10 + number;
        aNumber/=10;
    }

    if(neg)
    {
        original = original * -1;
        reverse = reverse * -1;
    }

    printf("Original number is: %ld    Reversed number is %ld\n", original, reverse);
}
