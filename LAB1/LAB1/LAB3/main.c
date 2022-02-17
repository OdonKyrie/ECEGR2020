#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//declarations
int theArray[10] = {1,2,3,4,5,6,7,8,9,10};

 typedef struct student
{
    int  ID;
    char firstName[30];
    char lastName[30];
    float GPA;
} Student;

Student* Creatingstu(void){
	//taking in the information
	int  Identity;
	int i; 
    char letter[30];
    char lastletter[30];
    float digit;
	Student* Stuadd = (Student*)malloc(sizeof(Student));
    
	
	printf("What is the studentID?\n");
	scanf("%d", &Identity);
	Stuadd ->ID = Identity;
	printf("What is the first name?\n");
	scanf("%s", letter);
	strcpy(Stuadd->firstName,letter);
	printf("What is the last name?\n");
	scanf("%s", lastletter);
	strcpy(Stuadd->lastName,lastletter);
	printf("What is the GPA?\n");
	scanf("%f", &digit);
	Stuadd ->GPA = digit;
	return Stuadd;

}
void readFile(Student** array){
	int SUID = 0;
	char firstname[30] = "";
	char lastname[30] = "";
	float gr;
	int studentnumb = 0;
	float averageGPA = 0.0;
	char c;
	Student* pointer = (Student*)malloc(sizeof(Student));
	FILE *GPAFile;
	GPAFile = fopen("info.txt", "r"); 
	
	if(GPAFile == NULL){
		printf("File does not exist\n"); 
		return NULL;
	}
	
	fscanf(GPAFile, "number of students: %d\n", &studentnumb);
	printf("Number of Student: %d\n", studentnumb);
	
	for(int i = 0; i < studentnumb; i++){
		fscanf(GPAFile, "Student ID: %d\n", &SUID ); 
		fscanf(GPAFile, "First Name: %s\n", firstname);
		fscanf(GPAFile, "Last Name: %s\n", lastname);
		fscanf(GPAFile, "GPA: %f\n", &gr);
		
		pointer -> ID = SUID; 
		strcpy(pointer -> firstName,firstname); 
		strcpy(pointer -> firstName,lastname);
		pointer -> GPA = gr;  
		
		printf("Student ID: %d\n", SUID); 
		printf("First Name: %s\n", firstname);
		printf("Last Name: %s\n", lastname);
		printf("GPA: %f\n", gr);
		
		array[i] = pointer; 
		averageGPA += gr; 
	}
	averageGPA /= studentnumb; 
	printf("There are %d students and the average GPA is: %f\n", studentnumb, averageGPA);
}
int main()
{
//Part A
    ReverseArray();
//Part B
    struct student temp;

    int numStudents = 0;
    printf("\nHow many students in the class?\n");
    scanf("%d", &numStudents);
	Student **library = (Student*)malloc(numStudents*sizeof(Student));
    //struct student arr_stu[80] = {};
	for(int i = 0; i < numStudents; i++){
		printf("Student %d Details: \n", i+1);
		library[i] = Creatingstu();
	}

//sort by highest GPA
     for (int i = 0; i < numStudents; i++) {     
        for (int j = i+1; j < numStudents; j++) {     
           if(library[i]->GPA < library[j]->GPA) {    
               Student* temp = library[i];    
               library[i] = library[j];    
               library[j] = temp;    
           }     
        }     
    }    
    /*for(int i = 0; i < numStudents; i++)
    {
        printf("%.2f ", arr_stu[i].GPA);
    }*/
	FILE *fileopen;
	fileopen = fopen("info.txt","wt");
	fprintf(fileopen,"number of students: %d\n", numStudents);
	for(int i = 0; i < numStudents; i++){
		//fprintf(fileopen,"Student %d Details: \n", i+1);
		fprintf(fileopen,"Student ID: %d\n", library[i]->ID);
		fprintf(fileopen,"First Name: %s\n", library[i]->firstName);
		fprintf(fileopen,"Last Name: %s\n", library[i]->lastName);
		fprintf(fileopen,"GPA: %f\n", library[i]->GPA);
										}
	fclose(fileopen);
	free(library);
	
	Student** inf = (Student**)malloc(numStudents*sizeof(Student*));
	readFile(inf);
	free(inf);
}
//part A
void ReverseArray(void)
{
    int retAr[10] = {0,0,0,0,0,0,0,0,0,0};
    
    int end = 9;
    for(int i = 0; i < 10; i++)
    {
        retAr[i] = theArray[end];
        end--;
        printf("%d ", retAr[i]);
    }
}
//part b NA (done in Int main)

//part c NA (done in Int main)

//part d 
