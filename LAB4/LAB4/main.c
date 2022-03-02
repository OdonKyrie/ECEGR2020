#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *filePtr; 

typedef struct student 
{
    int ID;
    char firstName[30];
    char lastName[30];
    float GPA;
	struct student* next; 
} Student; 

Student* firstStudent = NULL; 

Student* createStudentNode(int id_in, char first_in[30], char last_in[30], float gpa_in) 
{
	Student* newStudent = (Student*) malloc(sizeof(Student)); 
	
	if(newStudent != NULL) 
	{
		newStudent->ID = id_in;
		strcpy(newStudent->firstName, first_in);
		strcpy(newStudent->lastName, last_in);
		newStudent->GPA = gpa_in;
		newStudent->next = NULL;
	}
	
	return newStudent; 
}

void addStudentNode(Student* newStudent) 
{
	Student* currentStudent = firstStudent; 
	
	if(firstStudent == NULL) 
	{
		firstStudent = newStudent; 
		return; 
	}
	
	while(currentStudent->next != NULL) 
	{				   
		currentStudent = currentStudent->next; 
	}
	currentStudent->next = newStudent;
	newStudent->next = NULL;	  
}

void instertStudentNode(Student* newStudent)  
{
	Student* node = firstStudent; 
	
	while(node->next != NULL) 
	{
		Student* nextNode = node->next; 
		
		if((node->GPA > newStudent->GPA) && (newStudent->GPA >= nextNode->GPA)) 
		{									
			newStudent->next = node->next; 
			node->next = newStudent; 
			return; 
		}
		
		else if(node->GPA <= newStudent->GPA) 
		{				      
			newStudent->next = node; 
			firstStudent = newStudent; 
			return; 
		}
		
		node = node->next; 
	}
	
	node->next = newStudent; 
	newStudent->next = NULL; 
	return; 
	
}

void deleteStudentNode(Student* delStudent) 
{
	Student* currentStudent = firstStudent; 
	Student* prevSudent = NULL;
	
	if(firstStudent == delStudent) 
	{
		firstStudent = firstStudent->next; 
		free(delStudent); 
		return; 
	}
	
	while(currentStudent != NULL && currentStudent != delStudent) 
	{
		prevSudent = currentStudent; 
		currentStudent = currentStudent->next; 
	}
	
	if(currentStudent != NULL) 
	{
		prevSudent->next = currentStudent->next; 
	}						 
	
	free(delStudent);
}



void readStudentRecords(void); 

void readList(void); 
void freeList(void); 
void saveList(void); 

void removeStudent(int id_in); 
void updateStudent(int id_in); 

void menuDisplay(void); 
void updateStudentMenu(char first[30], char last[30]); 



int main()
{
	int user_in; 
	
	readStudentRecords(); 
	do 
	{

		int id_input;
		char first_input[30] = "";
		char last_input[30] = "";
		float gpa_input = 0.0;
		int userID_in; 
		Student* idCheck = firstStudent; 
		
		menuDisplay();
		printf("\nWhat would you like to do? "); 
		scanf("%d", &user_in); 
		
		switch(user_in) 
		{
			case 1 : // 1) List all students
				readList();
				break; 
				
			case 2 : // 2) Add Student
				printf("\nEnter the ID of the student: "); 
				scanf("%d", &id_input); 
				while(idCheck != NULL) 
				{
					if(id_input == idCheck->ID) 
					{
						printf("\nEntered ID is currently used by and existing student."); 
						idCheck = firstStudent; 
						printf("\nEnter the ID of the student: "); 
						scanf("%d", &id_input); 
					}
					idCheck = idCheck->next; 
				}
				
				printf("\nEnter the first name of the student: "); 
				scanf("%29s", first_input); 
				
				printf("\nEnter the last name of the student: "); 
				scanf("%29s", last_input); 
				
				printf("\nEnter the GPA of the student: "); 
				scanf("%f", &gpa_input); 
				while((gpa_input > 4.0) || (gpa_input < 1.0)) 
				{
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); 
					printf("\nEnter the GPA of the student: "); 
					scanf("%f", &gpa_input); 
				}
				
				Student* peterPtr = createStudentNode(id_input, first_input, last_input, gpa_input); 
				instertStudentNode(peterPtr); 
				break; 
				
			case 3 : // 3) Remove Student
				printf("\nEnter the ID of the student you wish to delete: "); 
				scanf("%d", &userID_in); 
				removeStudent(userID_in);
				break;
				
			case 4 : // 4) Update Student
				printf("\nEnter the ID of the student you wish to update: "); 
				scanf("%d", &userID_in); 
				updateStudent(userID_in); 
				break; 
			
			case 5 : // 5) Quit
				printf("\nExiting Student Program..."); 
				break; 
			
			default : 
				printf("\nInvalid input\n"); 
		}
	}while(user_in != 5); // Leave the do-while if option 5 is chosen.
	saveList(); 
	freeList(); 
}


void readStudentRecords() 
{

	char first_out[30], last_out[30];
	int numOut, id_out;
	float gpa_out;
	
	filePtr = fopen("info.txt", "r"); 
	fscanf(filePtr, "number of students: %d", &numOut); 
	
	for(int i=0; i<numOut; i++) 
	{
		fscanf(filePtr, "\nStudent ID: %d", &id_out);
		fscanf(filePtr, "\nFirst Name: %s", first_out);
		fscanf(filePtr, "\nLast Name: %s", last_out);
		fscanf(filePtr, "\nGPA: %f", &gpa_out);
		
		Student* piperPtr = createStudentNode(id_out, first_out, last_out, gpa_out); 
		addStudentNode(piperPtr); 
	}
	printf("info.txt successfully scanned\n"); 
}

void readList() 
{
	Student* node = firstStudent; 
	printf("\n==========STUDENT LINKED LIST=========="); 
	while(node != NULL) 
	{
		printf("\n\nStudent ID: %d", node->ID);
		printf("\nStudent First Name: %s", node->firstName);
		printf("\nStudent Last Name: %s", node->lastName);
		printf("\nStudent GPA: %f", node->GPA);
		node = node->next; // i++
	}
	printf("\n\n=======================================");
}

void freeList() 
{
	Student* node = firstStudent;
	Student* nextNode = firstStudent->next; 
	while(node != NULL) 
	{
		deleteStudentNode(node);
		node = nextNode; 
		nextNode = nextNode->next; 
	}
}

void saveList() 
{
	filePtr = fopen("info.txt", "w+"); 
	Student* node = firstStudent; 
	int studentCount = 0; 
	while(node != NULL)
	{
		studentCount++; 
		node = node->next; 
	}
	
	fprintf(filePtr, "Number of students: %d ", studentCount); 
	node = firstStudent; 
	while(node != NULL) 
	{
		fprintf(filePtr, "\n\nStudent ID: %d", node->ID);
		fprintf(filePtr, "\nStudent First Name: %s", node->firstName);
		fprintf(filePtr, "\nStudent Last Name: %s", node->lastName);
		fprintf(filePtr, "\nStudent GPA: %f", node->GPA);
		node = node->next; // Iterate.
	}
	fclose(filePtr); // Close the file.
}

void removeStudent(int id_in)
{
	Student* node = firstStudent; 
	int check = 0; 
	while(node != NULL) 
	{
		if(id_in == node->ID) 
		{
			char first[30];
			char last[30];
			strcpy(first, node->firstName);
			strcpy(last, node->lastName);
			deleteStudentNode(node); 
			check = 1; 
			printf("\n%s %s was successfully deleted.", first, last); 
			return; // Leave the function.
		}
		node = node->next; // Iterate.
	}
	if(check == 0) // If the ID was not found.
	{
		printf("\nThere is no student associated with the given ID."); // Let the user know that the ID was invalid.
		return; // Leave the function.
	}
	return; // Leave the function.
}

void updateStudent(int id_in)
{
	Student* node = firstStudent; 
	Student* prevNode = node; 
	int check = 0; 
	int user_input = 0; 
	while(node != NULL) 
	{
		if(id_in == node->ID) 
		{
			do 
			{
				updateStudentMenu(node->firstName, node->lastName); 
				scanf("%d", &user_input); 
				int new_id, old_id;
				char new_first[30], old_first[30];
				char new_last[30], old_last[30];
				float new_gpa, old_gpa;
				Student* idCheck = firstStudent;
				
				switch(user_input) // Switch-case to check which case the user desired.
				{
					case 1 : // 1) Update ID
						printf("\nEnter the new ID: "); 
						scanf("%d", &new_id); 
						while(idCheck != NULL) 
						{
							if(new_id == idCheck->ID) // Checks to see if the ID already exists.
							{
								printf("\nEntered ID is currently used by and existing student."); 
								idCheck = firstStudent; 
								printf("\nEnter the ID of the student: "); 
								scanf("%d", &new_id); 
							}
							idCheck = idCheck->next; 
						}
						old_id = node->ID; 
						node->ID = new_id;
						printf("\n%d was sucessfully updated to %d", old_id, new_id); // Success message for the user.
						break; 
					case 2 : // 2) Update First Name
						printf("\nEnter the new first name: ");
						scanf("%29s", new_first); 
						strcpy(old_first, node->firstName); 
						strcpy(node->firstName, new_first); 
						printf("\n%s was sucessfully updated to %s", old_first, new_first); 
						break; 
					case 3 : // 3) Update Last Name
						printf("\nEnter the new last name: "); 
						scanf("%29s", new_last); 
						strcpy(old_last, node->lastName);
						strcpy(node->lastName, new_last);
						printf("\n%s was sucessfully updated to %s", old_last, new_last);
						break; 
					case 4 : // 4) Update GPA
						printf("\nEnter the new GPA: "); 
						scanf("%f", &new_gpa); 
						while((new_gpa > 4.0) || (new_gpa < 1.0)) 
						{
							printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); 
							printf("\nEnter the GPA of the student: "); 
							scanf("%f", &new_gpa); 
						}
						old_gpa = node->GPA; 
						node->GPA = new_gpa; 
						if(prevNode == node) 
						{
							node->next = NULL; 
							instertStudentNode(node); 
						}
						else 
						{
							prevNode->next = node->next; 
							instertStudentNode(node); 
						}
						printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa); 
						break; 
					
					case 5 : // 5) Quit
						break; 
					
					default : 
						printf("\nInvalid input\n");
				}
			} while(user_input != 5); 
			return; 
		}
		prevNode = node; 
		node = node->next; 
	}
	if(check == 0) 
	{
		printf("\nThere is no student associated with the given ID."); 
		return; 
	}
}

void menuDisplay() 
{
	printf("\n====================STUDENT MENU====================");
	
	printf("\n\n[1] List All Students");
	printf("\n[2] Add Student");
	printf("\n[3] Remove Student");
	printf("\n[4] Update Student");
	
	printf("\n\n[5] Quit");
	printf("\n\n====================================================");
	printf("\n\n");
}

void updateStudentMenu(char first[30], char last[30]) 
{
	printf("\n====================UPDATE STUDENT MENU====================");
	printf("\nWhat would you like to update about %s %s?", first, last);
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] GPA");
	
	printf("\n\n[5] Quit");
	printf("\n\n===========================================================");
	printf("\n\n");
}
