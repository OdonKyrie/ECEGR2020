
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
//Declaraitions
void Pyramid( int lines );
long factorial(long num);
int isPalindrome(long value);
long ReverseNumber(long aNumber);
int HighestBitSet( int value);
void ReverseIt( void );
void ReverseItAgain( void );

int main(){ 
	//part A
long num = 14;
long w = factorial(num);
printf("\n the Factorial is %lu is %lu\n",num,w);
num = 13;
w = factorial(num);
printf("\n the Factorial is %lu is %lu \n",num,w);
num = 12;
w = factorial(num);
printf("\n the Factorial is %lu is %lu \n",num,w);
num = 11;
w = factorial(num);
printf("\n the Factorial is %lu is %lu \n",num,w);
num = 10;
w = factorial(num);
printf("\n the Factorial is %lu is %lu \n",num,w);
num = 9;
w = factorial(num);
printf("\n the Factorial is %lu is %lu \n",num,w);
//partB
long z = 123 ;
long y =  isPalindrome(z);
printf("\n %lu \n",y);
z = 121 ;
y = isPalindrome(z);
printf("\n %lu \n",y);
z = 322223 ;
y = isPalindrome(z);
printf("\n %lu \n",y);
z = 121324 ;
y = isPalindrome(z);
printf("\n %lu \n",y);
z = 121224 ;
y = isPalindrome(z);
printf("\n %lu \n",y);
//partC
	int value ;
	scanf("%i",&value);
	HighestBitSet(value);
	scanf("%i",&value);
	HighestBitSet(value);
	scanf("%i",&value);
	HighestBitSet(value);
	scanf("%i",&value);
	HighestBitSet(value);
	scanf("%i",&value);
	HighestBitSet(value);
//part D
ReverseIt();
//part E
ReverseItAgain();
//partf
scanf("%i",&value);
Pyramid(value);
scanf("%i",&value);
Pyramid(value);
scanf("%i",&value);
Pyramid(value);
scanf("%i",&value);
Pyramid(value);
scanf("%i",&value);
Pyramid(value);

}
//PartA
long factorial(long num){
	long storage = num;
	long factorial_son = 1;
	
	for (long i = 1; i <= storage; i++){
		factorial_son = factorial_son*num;
		num = num-1;
	}
	return factorial_son;
}

//PartB
int isPalindrome(long value){
	long reverse = ReverseNumber(value);
	if (reverse == value){
		return 1;
	}
	else{
		return 0;
	}
}

//Using reverse a number
long ReverseNumber(long aNumber)
{
    int neg = 0;
    if(aNumber < 0)
    {
        aNumber = aNumber * -1;
        neg = 1;
        //printf("isneg");
    }


    //printf("%d\n", aNumber);
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

   
	return reverse;
}

//Part C
int HighestBitSet( int value){
    int i = 0;
    int highestIn = -1;
	int a[10];
	int y = value;
    while(value) {
        a[i] = value % 2; //? i : highestIn;
        value /= 2;
        highestIn++;
		i++;
    }
	 printf("Highest bit set of %d is %d\n", y, highestIn);
	for(i=i-1;i>=0;i--){
        printf("%d",a[i]);
	}
	printf("\n");
return highestIn;
}
//Part D
void ReverseIt( void ){
        float arr[5];
        int i;  
        FILE *fptr;  
        fptr = fopen("Hello.txt", "w"); 
        if (fptr == NULL) 
        {
    printf("Failed to create the file.\n");
        }
        printf("Enter 5 Floating point numbers :\n");
        for(i=0;i<5;i++){
                scanf("%f",&arr[i]); 
                fprintf(fptr,"%f ",arr[i]);  
        }
        printf("Floating point numbers in reverse order\n");
        for(i=4;i>=0;i--){
                printf("%f ",arr[i]); 
                fprintf(fptr,"%f ",arr[i]);  

        }
        printf("\nData successfully entered into file\n");
        fclose(fptr); 
}
//Part E
void ReverseItAgain( void ){
        float num;   
        FILE *fptr; 
        fptr = fopen("Hello.txt", "r"); 
    printf("\nReading the Data from file:\n");
        while(!feof(fptr))
    {
      fscanf(fptr,"%f",&num);
      printf("%f\n",num);
    }
        fclose(fptr); 
}
//PartF
void Pyramid( int lines ){
        int i,k,s; 
		k = 0;
        for (i = 1; i <= lines; ++i, k = 0)  
        {
      for (s = 1; s <= lines - i; ++s)  
          {
         printf("  ");
      }
      while (k != 2 * i - 1)
          {
         printf("* ");
         ++k;
      }
      printf("\n"); 
   }
}

