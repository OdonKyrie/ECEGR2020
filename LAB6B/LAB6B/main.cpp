#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};

class Student
{
private:
	int  ID;
    string firstName;
    string lastName;
    float GPA;
	Student* next;

public:
	Student();
	Student(int id_in, string first_in, string last_in, float gpa_in);
	Student(Student &init);
	~Student();
	Student& operator=(Student const &s)
	{
		this->ID = s.ID;
		setFirstName(s.firstName);
		setLastName(s.lastName);
		this->GPA = s.GPA;
		//printf("Student Assignment Operator has been called.\n");
		return *this;
	}
	
	// Get methods
	int getID()
	{
		return ID;
	}
	float getGPA()
	{
		return GPA;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	Student* getNext()
	{
		return next;
	}

	// Set methods
	void setID(int id_in)
	{
		ID = id_in;
	}
	void setGPA(float gpa_in)
	{
		GPA = gpa_in;
	}
	void setFirstName(string first_in)
	{
		this->firstName = first_in;
	}
	void setLastName(string last_in)
	{
		this->lastName = last_in;
	}
	void setNext(Student* next_in)
	{
		next = next_in;
	}
};

Student* firstStudent = NULL;

Student :: Student()
{
	this->ID = 9999;
	this->firstName = "(null)";
	this->lastName = "(null)";
	this->GPA = 0.0;
	this->next = NULL;
	//printf("Student Default Constructor has been called.\n");
}

Student :: Student(int id_in, string first_in, string last_in, float gpa_in)
{
	this->ID = id_in;
	this->firstName = first_in;
	this->lastName = last_in;
	this->GPA = gpa_in;
	this->next = NULL;
	//printf("Student Constructor has been called for %s %s.\n", firstName, lastName);
}

Student :: Student(Student &init)
{
	ID = init.ID;
	GPA = init.GPA;
	firstName = "";
	lastName = "";
	setFirstName(init.firstName);
	setLastName(init.lastName);
	next = init.next;
	//printf("Student Copy Constructor has been called.\n");
}

Student :: ~Student()
{
	//printf("Student Destructor has been called for %s %s.\n", firstName, lastName);
}

void insertStudentNode(Student* student_in);
void deleteStudentNode(Student* student_in);
void readStudentRecords(void);
void readList(void);
//void freeList(void);
void saveList(void);
void removeStudent(int id_in);
void updateStudent(int id_in);
void menuDisplay(void); // Displays the OG menu.
void updateStudentMenu(string first, string last); // Displays the menu for the selected student to have their stuff updated.

int main()
{
	int user_in = 0;
	readStudentRecords();
	do // Begins the loop to trap the user in the program.
	{
		int id_input;
		string first_input;
		string last_input;
		float gpa_input = 0.0;
		int userID_in; // Variable to scan for user input later for 3 and 4
		Student* idCheck = firstStudent; 
		
		menuDisplay(); // Displays the OG menu.
		printf("\nWhat would you like to do? "); 
		cin >> user_in; 
		
		switch(user_in) 
		{
			case 1 : // 1) Lists all of the students
			{
				readList(); 
				break; 
			}
				
			case 2 : // 2) Adds a Student
			{
				printf("\nEnter the ID of one of the students: "); //enter an input.
				cin >> id_input; 
				while(idCheck != NULL) // repeats through the linked list.
				{
					if(id_input == idCheck->getID()) // Checks to see if the ID already exists.
					{
						printf("\nEntered ID is currently used by and existing student.Try another man."); // Let the user know that this ID already has an owner.
						idCheck = firstStudent; // Set the check back to the beginning of the linked list.
						printf("\nEnter the ID of the student: "); // tells user to enter an input.
						cin >> id_input; 
					}
					idCheck = idCheck->getNext(); 
				}
				
				printf("\nEnter the first name of the student: "); 
				cin >> first_input;
				
				printf("\nEnter the last name of the student: "); 
				cin >> last_input;
				
				printf("\nEnter the GPA of the student: "); 
				cin >> gpa_input; 
				while((gpa_input > 4.0) || (gpa_input < 1.0)) // within bounds
				{
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0.lets be realistic here."); 
					printf("\nEnter the GPA of the student: "); 
					cin >> gpa_input; 
				}
				
				Student* peterPtr = new Student(id_input, first_input, last_input, gpa_input);
				insertStudentNode(peterPtr); 
				break; 
			}
				
				
			case 3 : // 3) Removes el Student
			{
				printf("\nEnter the ID of the student you wish to delete: "); // input 
				cin >> userID_in; 
				removeStudent(userID_in);
				break; // Leaves the switch-case.
			}
				
				
			case 4 : // 4) Update Student
			{
				printf("\nEnter the ID of the student you wish to update: "); // input.
				cin >> userID_in; 
				updateStudent(userID_in); 
				break; // Leaves
			}
			
			case 5 : // 5) Quit
			{
				printf("\nExiting Student Program..."); 
				break; // Leave the switch-case.
			}
			
			default : // If there is an input that isn't any of the above listed cases.
				printf("\nInvalid input\n"); 
		}
	}while(user_in != 5); 
	saveList();
	
	return 0;
}

void insertStudentNode(Student* student_in)
{
	if(firstStudent == NULL)
	{
		firstStudent = student_in;
		return;
	}
	else if(firstStudent->getNext() == NULL)
	{
		if(firstStudent->getGPA() >= student_in->getGPA())
		{
			firstStudent->setNext(student_in);
			return;
		}
		else
		{
			Student* temp = firstStudent;
			firstStudent = student_in;
			firstStudent->setNext(temp);
			return;
		}
	}
	
	Student* node = firstStudent;
	
	while(node->getNext() != NULL)
	{
		Student* nextNode = node->getNext();
		
		if((node->getGPA() > student_in->getGPA()) && (student_in->getGPA() >= nextNode->getGPA()))
		{
			student_in->setNext(node->getNext());
			node->setNext(student_in);
			return;
		}
		else if(node->getGPA() <= student_in->getGPA())
		{
			student_in->setNext(node);
			firstStudent = student_in;
			return;
		}
		node = node->getNext();
	}
	node->setNext(student_in);
	student_in->setNext(NULL);
	return;
}

void deleteStudentNode(Student* student_in)
{
	Student* currentStudent = firstStudent;
	Student* prevStudent = NULL;
	
	if(firstStudent == student_in)
	{
		firstStudent = firstStudent->getNext();
		delete student_in;
		return;
	}
	
	while(currentStudent != NULL && currentStudent != student_in) // goes through list until student is found
	{
		prevStudent = currentStudent; 
		currentStudent = currentStudent->getNext(); 
	}
	
	if(currentStudent != NULL)
	{
		prevStudent->setNext(currentStudent->getNext());
	}
	
	delete student_in;
}

void readStudentRecords() // Reads the info.txt file and writes it into a linked list.
{
	ifstream readRecords;
	int totalStudents = 0;
	readRecords.open("info.txt");
	if(!readRecords.is_open())
	{
		cerr << "Could not open file: info.txt" << endl;
	}
	else
	{
		string temp = "";
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> totalStudents;
		cout << "\nNumber of Students: " << totalStudents << "\n";
		for(int i = 0; i < totalStudents; i++)
		{
			int read_id = 0;
			string read_first = "";
			string read_last= "";
			float read_gpa = 0.0;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> read_id;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> read_first;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> read_last;
			
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> read_gpa;
			
			Student* newStudent = new Student(read_id, read_first, read_last, read_gpa);
			insertStudentNode(newStudent);
		}
		readRecords.close();
		printf("info.txt successfully scanned bruh\n"); // Let user know the function worked.
	}
}

void readList() 
{
	Student* node = firstStudent; 
	printf("\n==========STUDENT LINKED LIST=========="); 
	while(node != NULL) 
	{
		printf("\n\nStudent ID: %d", node->getID());
		cout << "\nStudent First Name: " << node->getFirstName();
		cout << "\nStudent Last Name: " << node->getLastName();
		printf("\nStudent GPA: %f", node->getGPA());
		node = node->getNext(); // i++
	}
	printf("\n\n=======================================\n");
}

void freeList()
{
	Student* node = firstStudent;
	Student* nextNode = firstStudent->getNext();
	while(node != NULL)
	{
		delete node;
		node = nextNode;
		nextNode = nextNode->getNext();
	}
}

void saveList() //writes all the student details in the same format into the info.txt file.
{
	ofstream openRecords;
	openRecords.open("info.txt");
	Student* node = firstStudent; 
	int studentCount = 0; 
	while(node != NULL) 
	{
		studentCount++; 
		node = node->getNext(); 
	}
	if (!openRecords.is_open())
	{
		cout << "Unable to write file\n";
	}
	else
	{
		openRecords << "Number of students: " << studentCount; 
		node = firstStudent; 
		while(node != NULL) 
		{
			openRecords << "\n\nStudent ID: " << node->getID();
			openRecords << "\nStudent First Name: " << node->getFirstName();
			openRecords << "\nStudent Last Name: " << node->getLastName();
			openRecords << "\nStudent GPA: " << node->getGPA();
			node = node->getNext(); 
		}
		openRecords.close(); 
	}
}

void removeStudent(int id_in) 
{
	Student* node = firstStudent; 
	int check = 0; 
	while(node != NULL) 
	{
		if(id_in == node->getID()) 
		{
			string first = node->getFirstName();
			string last =  node->getLastName();
			deleteStudentNode(node); 
			check = 1; 
			cout << "\n" << first << " " << last << " was successfully deleted.";
			return; 
		}
		node = node->getNext(); 
	}
	if(check == 0)
	{
		printf("\nThere is no student associated with the given ID.try another one dude."); // Let the user know that the ID was no bueno
		return;
	}
	return; 
}

void updateStudent(int id_in) 
{
	Student* node = firstStudent; 
	Student* prevNode = node; 
	int check = 0; 
	int user_input = 0; 
	while(node != NULL)
	{
		if(id_in == node->getID()) 
		{
			do 
			{
				updateStudentMenu(node->getFirstName(), node->getLastName()); 
				cin >> user_input; 
				int new_id, old_id = 0;
				string new_first = "";
				string old_first = "";
				string new_last = "";
				string old_last = "";
				string temp = "";
				float new_gpa, old_gpa = 0.0;
				Student* idCheck = firstStudent;
				
				switch(user_input)
				{
					case 1 : // 1) Updates the ID
						cout << "\nEnter the new ID: "; 
						cin >> new_id; 
						while(idCheck != NULL) 
						{
							if(new_id == idCheck->getID()) 
							{
								printf("\nEntered ID is currently used by and existing student.try another one man"); 
								idCheck = firstStudent; 
								printf("\nEnter the ID of the student: "); 
								scanf("%d", &new_id); 
							}
							idCheck = idCheck->getNext(); 
						}
						old_id = node->getID(); 
						node->setID(new_id); 
						printf("\n%d was sucessfully updated to %d", old_id, new_id); 
						break; 
					case 2 : // 2) Updates First Name of selected student
						printf("\nEnter the new first name: "); 
						cin >> new_first;
						old_first = node->getFirstName(); 
						node->setFirstName(new_first); 
						cout << "\n" << old_first << " was sucessfully updated to " << new_first;
						break; 
					case 3 : // 3) Updates the Last Name
						printf("\nEnter the new last name: "); 
						cin >> new_last;
						old_last = node->getLastName(); 
						node->setLastName(new_last); 
						cout << "\n" << old_last<< " was sucessfully updated to " << new_last; 
						break; 
					case 4 : // 4) Updates the GPA
						printf("\nEnter the new GPA: "); 
						scanf("%f", &new_gpa); 
						while((new_gpa > 4.0) || (new_gpa < 1.0)) //in bounds
						{
							printf("\nPlease enter a GPA in the range of 4.0 and 1.0.lets be realistic here."); 
							printf("\nEnter the GPA of the student: "); 
							scanf("%f", &new_gpa);
						}
						old_gpa = node->getGPA(); 
						node->setGPA(new_gpa); 
						if(prevNode == node) 
						{
							node->setNext(NULL); 
							insertStudentNode(node); 
						}
						else 
						{
							prevNode->setNext(node->getNext()); 
							insertStudentNode(node);
						}
						printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa); 
						break; 
					
					case 5 : // 5) Quits
						break; 
					
					default :
						printf("\nInvalid input\n");
				}
			} while(user_input != 5); 
			return; 
		}
		prevNode = node; 
		node = node->getNext(); 
	}
	if(check == 0) 
	{
		printf("\nThere is no student associated with the given ID.try another one please."); 
		return; 
	}
}

void menuDisplay() // Displays the OG menu.
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

void updateStudentMenu(string first, string last)
{
	printf("\n====================UPDATE STUDENT MENU====================");
	cout << "\nWhat would you like to update about " << first << " " << last << "?";
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] GPA");
	
	printf("\n\n[5] Quit");
	printf("\n\n===========================================================");
	printf("\n\n");
}