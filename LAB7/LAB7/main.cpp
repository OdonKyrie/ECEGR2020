#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <stdlib.h> 

using namespace std;

template <class DstType, class SrcType>
bool instanceof(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}

enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};

class Person
{
private:
	int ID;
    string firstName;
    string lastName;
	Person* next;
	
public:
	Person();
	Person(int id_in, string first_in, string last_in);
	Person(Person &init);
	virtual ~Person();
	Person& operator=(Person const &p)
	{
		this->ID = p.ID;
		setFirstName(p.firstName);
		setLastName(p.lastName);
		this->next = p.next;
		return *this;
	}
	
	int getID()
	{
		return ID;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	Person* getNext()
	{
		return next;
	}
	
	void setID(int id_in)
	{
		ID = id_in;
	}
	void setFirstName(string first_in)
	{
		this->firstName = first_in;
	}
	void setLastName(string last_in)
	{
		this->lastName = last_in;
	}
	void setNext(Person* next_in)
	{
		next = next_in;
	}
};

Person* firstPerson = NULL;

Person :: Person()
{
	this->ID = 9999;
	this->firstName = "(null)";
	this->lastName = "(null)";
	this->next = NULL;
}

Person :: Person(int id_in, string first_in, string last_in)
{
	this->ID = id_in;
	this->firstName = first_in;
	this->lastName = last_in;
	this->next = NULL;
}

Person :: Person(Person &init)
{
	this->ID = init.ID;
	this->firstName = "";
	this->lastName = "";
	setFirstName(init.firstName);
	setLastName(init.lastName);
	this->next = init.next;
}

Person :: ~Person()
{
}

class Student: public Person
{
private:
	float GPA;
	
public:
	Student();
	Student(int id_in, string first_in, string last_in, float gpa_in);
	Student(Student &init);
	~Student();
	float getGPA()
	{
		return GPA;
	}
	
	void setGPA(float gpa_in)
	{
		GPA = gpa_in;
	}
};

Student :: Student()
{
	this->setID(9999);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->GPA = 0.0;
	this->setNext(NULL);
}

Student :: Student(int id_in, string first_in, string last_in, float gpa_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	this->GPA = gpa_in;
	this->setNext(NULL);
}

Student :: Student(Student &init)
{
	this->setID(init.getID());
	this->setGPA(init.GPA);
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setNext(init.getNext());
}

Student :: ~Student()
{
}

class Employee: public Person
{
private:
	float salary;
	
public:
	Employee();
	Employee(int id_in, string first_in, string last_in, float salary_in);
	Employee(Employee &init);
	~Employee();
	float getSalary()
	{
		return salary;
	}
	
	void setSalary(float salary_in)
	{
		salary = salary_in;
	}
};

Employee :: Employee()
{
	this->setID(9999);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->salary = 0.0;
	this->setNext(NULL);
}

Employee :: Employee(int id_in, string first_in, string last_in, float salary_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	this->salary = salary_in;
	this->setNext(NULL);
}

Employee :: Employee(Employee &init)
{
	this->setID(init.getID());
	this->setSalary(init.salary);
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setNext(init.getNext());
}

Employee :: ~Employee()
{
}

class Professor: public Employee
{
private:
	bool tenured;
	Department department;
	
public:
	Professor();
	Professor(int id_in, string first_in, string last_in, float salary_in, bool ten_in, Department dep_in);
	Professor(Professor &init);
	~Professor();
	bool getTenured()
	{
		return tenured;
	}
	Department getDepartment()
	{
		return department;
	}
	
	void setTenured(bool ten_in)
	{
		tenured = ten_in;
	}
	void setDepartment(Department dep_in)
	{
		department = dep_in;
	}
};

Professor :: Professor()
{
	this->setID(9999);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->setSalary(0.0);
	this->tenured = false;
	this->department = Unknown;
	this->setNext(NULL);
}

Professor :: Professor(int id_in, string first_in, string last_in, float salary_in, bool ten_in, Department dep_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	setSalary(salary_in);
	this->tenured = ten_in;
	this->department = dep_in;
	this->setNext(NULL);
}

Professor :: Professor(Professor &init)
{
	this->setID(init.getID());
	this->setSalary(init.getSalary());
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setTenured(init.tenured);
	this->setDepartment(init.department);
	this->setNext(init.getNext());
}

Professor :: ~Professor()
{
}

void readUniversityRecords(void);
void readList(void);
void saveList(void);
void insertNode(Person* person_in);
void deleteNode(Person* person_in);
void addToList();
void removeFromList(int id_in);
void updateList(int id_in);
void menuDisplay(void);
void addMenuDisplay(void);
void updateStudentMenu(string first, string last);
void updateProfessorMenu(string first, string last);
void updateEmployeeMenu(string first, string last);

int main()
{
	int user_in = 0;
	readUniversityRecords();
	do
	{
		int userID_in;
		
		menuDisplay();
		cout << "\nWhat operation would you like to perform? ";
		cin >> user_in;
		
		switch(user_in)
		{
			case 1 :
			{
				readList();
				break;
			}
			case 2 :
			{
				addToList();
				break;
			}
			case 3 : 
			{
				printf("\nEnter the ID of the person you want to delete: "); 
				cin >> userID_in; 
				removeFromList(userID_in);
				break; 
			}
			case 4 :
			{
				printf("\nEnter the ID of the person you want to update: "); 
				cin >> userID_in; 
				updateList(userID_in); 
				break; 
			}
			case 5 :
			{
				printf("\nExiting Seattle University Program..."); 
				break; 
			}
		}
		
	}while(user_in != 5);
	saveList();
}

void readUniversityRecords()
{
	ifstream readRecords;
	int totalPeople = 0;
	readRecords.open("SeattleUniversity.txt.");
	if(!readRecords.is_open())
	{
		cerr << "Could not open file: SeattleUniversity.txt" << endl;
	}
	else
	{
		string temp = "";
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> totalPeople;
		cout << "\nNumber of People: " << totalPeople << "\n";
		for(int i = 0; i < totalPeople; i++)
		{
			readRecords >> temp;
			if(temp == "Student")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_gpa = 0.0;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_gpa;
				
				Person* newStudent = new Student(read_id, read_first, read_last, read_gpa);
				insertNode(newStudent);
			}
			else if(temp == "Professor")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_salary = 0.0;
				bool read_ten = false;
				Department read_dep = Unknown;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_salary;
				readRecords >> temp;
				readRecords >> read_ten;
				readRecords >> temp;
				readRecords >> temp;
				if(temp == "English")
				{
					read_dep = English;
				}
				else if(temp == "Math")
				{
					read_dep = Math;
				}
				else if(temp == "Philsophy")
				{
					read_dep = Philosophy;
				}
				else if(temp == "Theology")
				{
					read_dep = Theology;
				}
				else if(temp == "Biology")
				{
					read_dep = Biology;
				}
				else if(temp == "Physics")
				{
					read_dep = Physics;
				}
				else if(temp == "Chemistry")
				{
					read_dep = Chemistry;
				}
				else if(temp == "Engineering")
				{
					read_dep = Engineering;
				}
				else
				{
					read_dep = Unknown;
				}
				
				Person* newProfesor = new Professor(read_id, read_first, read_last, read_salary, read_ten, read_dep);
				insertNode(newProfesor);
			}
			else if(temp == "Employee")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_salary = 0.0;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_salary;
				
				Person* newEmployee = new Employee(read_id, read_first, read_last, read_salary);
				insertNode(newEmployee);
			}
			else
			{
				
			}
		}
		readRecords.close();
		cout << "SeattleUniversity.txt has been successfully scanned" << endl;
	}
}

void readList()
{
	Person* node = firstPerson;
	printf("\n==========SEATTLE UNIVERSITY RECORDS==========");
	while(node != NULL)
	{
		if(instanceof<Student>(node))
		{
			Student* tempStudent = (Student*) node;
			cout << "\n\nStudent";
			cout << "\nID: " << tempStudent->getID();
			cout << "\nFirst Name: " << tempStudent->getFirstName();
			cout << "\nLast Name: " << tempStudent->getLastName();
			cout << "\nGPA: " << tempStudent->getGPA();
		}
		else if(instanceof<Professor>(node))
		{
			Professor* tempProfessor = (Professor*) node;
			cout << "\n\nProfessor";
			cout << "\nID: " << tempProfessor->getID();
			cout << "\nFirst Name: " << tempProfessor->getFirstName();
			cout << "\nLast Name: " << tempProfessor->getLastName();
			cout << "\nSalary: " << tempProfessor->getSalary();
			if(tempProfessor->getTenured())
			{
				cout << "\nTenured: Yes";
			}
			else
			{
				cout << "\nTenured: No";
			}
			 tempProfessor->getTenured();
			if(tempProfessor->getDepartment() == English)
			{
				cout << "\nDepartment: English";
			}
			else if(tempProfessor->getDepartment() == Math)
			{
				cout << "\nDepartment: Math";
			}
			else if(tempProfessor->getDepartment() == Philosophy)
			{
				cout << "\nDepartment: Philosophy";
			}
			else if(tempProfessor->getDepartment() == Theology)
			{
				cout << "\nDepartment: Theology";
			}
			else if(tempProfessor->getDepartment() == Biology)
			{
				cout << "\nDepartment: Biology";
			}
			else if(tempProfessor->getDepartment() == Physics)
			{
				cout << "\nDepartment: Physics";
			}
			else if(tempProfessor->getDepartment() == Chemistry)
			{
				cout << "\nDepartment: Chemistry";
			}
			else if(tempProfessor->getDepartment() == Engineering)
			{
				cout << "\nDepartment: Engineering";
			}
			else
			{
				cout << "\nDepartment: Unknown";
			}
		}
		else if(instanceof<Employee>(node))
		{
			Employee* tempEmployee = (Employee*) node;
			cout << "\n\nEmployee";
			cout << "\nID: " << tempEmployee->getID();
			cout << "\nFirst Name: " << tempEmployee->getFirstName();
			cout << "\nLast Name: " << tempEmployee->getLastName();
			cout << "\nSalary: " << tempEmployee->getSalary();
		}
		node = node->getNext(); 
	}
	printf("\n\n===========================================\n");
}

void saveList() 
{
	ofstream openRecords;
	openRecords.open("SeattleUniversity.txt");
	Person* node = firstPerson; 
	int personCount = 0; 
	while(node != NULL) 
	{
		personCount++; 
		node = node->getNext(); 
	}
	if (!openRecords.is_open())
	{
		cout << "Unable to write file\n";
	}
	else
	{
		openRecords << "Number of people: " << personCount; 
		node = firstPerson; 
		while(node != NULL) 
		{
			if(instanceof<Student>(node))
			{
				Student* tempStudent = (Student*) node;
				openRecords << "\n\nStudent";
				openRecords << "\nID: " << tempStudent->getID();
				openRecords << "\nFirst Name: " << tempStudent->getFirstName();
				openRecords << "\nLast Name: " << tempStudent->getLastName();
				openRecords << "\nGPA: " << tempStudent->getGPA();
			}
			else if(instanceof<Professor>(node))
			{
				Professor* tempProfessor = (Professor*) node;
				openRecords << "\n\nProfessor";
				openRecords << "\nID: " << tempProfessor->getID();
				openRecords << "\nFirst Name: " << tempProfessor->getFirstName();
				openRecords << "\nLast Name: " << tempProfessor->getLastName();
				openRecords << "\nSalary: " << tempProfessor->getSalary();
				openRecords << "\nTenured: " << tempProfessor->getTenured();
				if(tempProfessor->getDepartment() == English)
				{
					openRecords << "\nDepartment: English";
				}
				else if(tempProfessor->getDepartment() == Math)
				{
					openRecords << "\nDepartment: Math";
				}
				else if(tempProfessor->getDepartment() == Philosophy)
				{
					openRecords << "\nDepartment: Philosophy";
				}
				else if(tempProfessor->getDepartment() == Theology)
				{
					openRecords << "\nDepartment: Theology";
				}
				else if(tempProfessor->getDepartment() == Biology)
				{
					openRecords << "\nDepartment: Biology";
				}
				else if(tempProfessor->getDepartment() == Physics)
				{
					openRecords << "\nDepartment: Physics";
				}
				else if(tempProfessor->getDepartment() == Chemistry)
				{
					openRecords << "\nDepartment: Chemistry";
				}
				else if(tempProfessor->getDepartment() == Engineering)
				{
					openRecords << "\nDepartment: Engineering";
				}
				else
				{
					openRecords << "\nDepartment: Unknown";
				}
				
			}
			else if(instanceof<Employee>(node))
			{
				Employee* tempEmployee = (Employee*) node;
				openRecords << "\n\nEmployee";
				openRecords << "\nID: " << tempEmployee->getID();
				openRecords << "\nFirst Name: " << tempEmployee->getFirstName();
				openRecords << "\nLast Name: " << tempEmployee->getLastName();
				openRecords << "\nSalary: " << tempEmployee->getSalary();
			}
			
			node = node->getNext(); 
		}
		openRecords.close(); 
	}
}

void insertNode(Person* person_in)
{
	if(firstPerson == NULL)
	{
		firstPerson = person_in;
		return;
	}
	else if(firstPerson->getNext() == NULL)
	{
		if(firstPerson->getID() >= person_in->getID())
		{
			firstPerson->setNext(person_in);
			return;
		}
		else
		{
			Person* temp = firstPerson;
			firstPerson = person_in;
			firstPerson->setNext(temp);
			return;
		}
	}
	
	Person* node = firstPerson;
	
	while(node->getNext() != NULL)
	{
		Person* nextNode = node->getNext();
		
		if((node->getID() > person_in->getID()) && (person_in->getID() >= nextNode->getID()))
		{
			person_in->setNext(node->getNext());
			node->setNext(person_in);
			return;
		}
		else if(node->getID() <= person_in->getID())
		{
			person_in->setNext(node);
			firstPerson = person_in;
			return;
		}
		node = node->getNext();
	}
	node->setNext(person_in);
	person_in->setNext(NULL);
	return;
}

void deleteNode(Person* person_in)
{
	Person* currentPerson = firstPerson;
	Person* prevPerson = NULL;
	
	if(firstPerson == person_in)
	{
		firstPerson = firstPerson->getNext();
		delete person_in;
		return;
	}
	
	while(currentPerson != NULL && currentPerson != person_in) 
	{
		prevPerson = currentPerson;
		currentPerson = currentPerson->getNext(); 
	}
	
	if(currentPerson != NULL)
	{
		prevPerson->setNext(currentPerson->getNext());
	}
	
	delete person_in;
}

void addToList()
{
	int user_input = 0;
	do
	{
		int id_input;
		string first_input, last_input;
		float gpa_input, salary_input;
		bool ten_input;
		Department dep_input;
		string temp;
		Person* idCheck = firstPerson;
		
		addMenuDisplay();
		cout << "\nWho would you like to add? ";
		cin >> user_input;
		
		switch(user_input)
		{
			case 1 :
			{
				printf("\nEnter the ID of the student please: "); 
				cin >> id_input; 
				while(idCheck != NULL) 
				{
					if(id_input == idCheck->getID()) 
					{
						printf("\nEntered ID is currently used by and existing person.Try another please"); 
						idCheck = firstPerson; 
						printf("\nEnter the ID of the student please: "); 
						cin >> id_input; 
					}
					idCheck = idCheck->getNext();
				}
				
				printf("\nEnter the first name of the student please: ");
				cin >> first_input;
				
				printf("\nEnter the last name of the student please: "); 
				cin >> last_input;
				
				printf("\nEnter the GPA of the student please: "); 
				cin >> gpa_input; 
				while((gpa_input > 4.0) || (gpa_input < 1.0)) 
				{
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0.The current value is invalid."); 
					printf("\nEnter the GPA of the student please: "); 
					cin >> gpa_input; 
				}
				
				Person* peterPtr = new Student(id_input, first_input, last_input, gpa_input);
				insertNode(peterPtr);
				break;
			}
			case 2 :
			{
				printf("\nEnter the ID of the professor please: "); 
				cin >> id_input; 
				while(idCheck != NULL)
				{
					if(id_input == idCheck->getID()) 
					{
						printf("\nEntered ID is currently used by an existing person. Please try another."); 
						idCheck = firstPerson; 
						printf("\nEnter the ID of the professor please: "); 
						cin >> id_input; 
					}
					idCheck = idCheck->getNext(); 
				}
				
				printf("\nEnter the first name of the professor please: "); 
				cin >> first_input;
				
				printf("\nEnter the last name of the professor please: "); 
				cin >> last_input;
				
				printf("\nEnter the salary of the professor please: "); 
				cin >> salary_input;
				
				cout << "\nAre they tenured? yes/no ";
				cin >> temp;
				string yes = "yes";
				string no = "no";
				if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
					ten_input = true;
				else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
					ten_input = false;
				else
				{
					bool check = true;
					while(check)
					{
						cout << "\nPlease indicate yes or no: ";
						cin >> temp;
						if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
						{
							ten_input = true;
							check = false;
						}
							
						else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
						{
							ten_input = false;
							check = false;
						}
					}
				}
				
				cout << "\nEnter the department of the professor please: ";
				cin >> temp;
				
				if(temp == "English"){dep_input = English;}
				else if(temp == "Math"){dep_input = Math;}
				else if(temp == "Philsophy"){dep_input = Philosophy;}
				else if(temp == "Theology"){dep_input = Theology;}
				else if(temp == "Biology"){dep_input = Biology;}
				else if(temp == "Physics"){dep_input = Physics;}
				else if(temp == "Chemistry"){dep_input = Chemistry;}
				else if(temp == "Engineering"){dep_input = Engineering;}
				else{dep_input = Unknown;}
				
				Person* peterPtr = new Professor(id_input, first_input, last_input, salary_input, ten_input, dep_input);
				insertNode(peterPtr);
				break;
			}
			case 3 :
			{
				printf("\nEnter the ID of the employee please: "); 
				cin >> id_input;
				while(idCheck != NULL) 
				{
					if(id_input == idCheck->getID()) 
					{
						printf("\nEntered ID is currently used by an existing person.Try another"); 
						idCheck = firstPerson; 
						printf("\nEnter the ID of the employee: ");
						cin >> id_input; 
					}
					idCheck = idCheck->getNext(); 
				}
				
				printf("\nEnter the first name of the employee please: "); 
				cin >> first_input;
				
				printf("\nEnter the last name of the employee please: "); 
				cin >> last_input;
				
				printf("\nEnter the salary of the employee please: "); 
				cin >> salary_input;
				
				Person* peterPtr = new Employee(id_input, first_input, last_input, salary_input);
				insertNode(peterPtr);
				break;
			}
			
			case 4 : // 5) Quit
				break; 
				
			default : 
				printf("\nInvalid input. Try another\n"); 
		}
	}while(user_input != 4);
}

void removeFromList(int id_in)
{
	Person* node = firstPerson;
	while(node != NULL) 
	{
		if(id_in == node->getID()) 
		{
			string first = node->getFirstName();
			string last =  node->getLastName();
			deleteNode(node); 
			cout << "\n" << first << " " << last << " was successfully deleted."; 
			return; 
		}
		node = node->getNext(); 
	}
	cout << "\nThere is no person associated with the given ID. Try another";
}

void updateList(int id_in)
{
	Person* node = firstPerson;
	int user_input = 0;
	while(node != NULL)
	{
		if(id_in == node->getID())
		{
			if(instanceof<Student>(node))
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
					Person* idCheck = firstPerson;
					Student* tempStudent = (Student*) node;
					
					switch(user_input) 
					{
						case 1 : // 1) Update ID
							cout << "\nEnter the new ID: "; 
							cin >> new_id; 
							while(idCheck != NULL) 
							{
								if(new_id == idCheck->getID()) 
								{
									printf("\nEntered ID is currently used by and existing student.Try another"); 
									idCheck = firstPerson; 
									printf("\nEnter the ID of the student please: "); 
									scanf("%d", &new_id); 
								}
								idCheck = idCheck->getNext(); 
							}
							old_id = tempStudent->getID(); 
							tempStudent->setID(new_id); 
							node = tempStudent;
							printf("\n%d was sucessfully updated to %d", old_id, new_id); 
							break; 
						case 2 : // 2) Update First Name
							printf("\nEnter the new first name please: "); 
							cin >> new_first;
							old_first = tempStudent->getFirstName(); 
							tempStudent->setFirstName(new_first); 
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;
							node = tempStudent;
							break; 
						case 3 : // 3) Update Last Name
							printf("\nEnter the new last name please: "); 
							cin >> new_last;
							old_last = tempStudent->getLastName();
							tempStudent->setLastName(new_last); 
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last; 
							node = tempStudent;
							break; 
						case 4 : // 4) Update GPA
							printf("\nEnter the new GPA please: "); 
							scanf("%f", &new_gpa); 
							while((new_gpa > 4.0) || (new_gpa < 1.0)) 
							{
								printf("\nPlease enter a GPA in the range of 4.0 and 1.0.What has been inputted is invalid."); 
								printf("\nEnter the GPA of the student please: "); 
								scanf("%f", &new_gpa); 
							}
							old_gpa = tempStudent->getGPA(); 
							tempStudent->setGPA(new_gpa); 
							node = tempStudent;
							printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa); 
							break; 
						
						case 5 : // 5) Quit
							break; 
						
						default : 
							printf("\nInvalid input. Try another\n");
					}
				}while(user_input != 5);
				return;
			}
			else if(instanceof<Professor>(node))
			{
				do
				{
					updateProfessorMenu(node->getFirstName(), node->getLastName()); 
					cin >> user_input;
					int new_id, old_id = 0;
					string new_first = "";
					string old_first = "";
					string new_last = "";
					string old_last = "";
					string temp, temp2 = "";
					float new_salary, old_salary = 0.0;
					bool new_ten, old_ten = false;
					Department new_dep;
					Person* idCheck = firstPerson;
					Professor* tempProfessor = (Professor*) node;
					
					switch(user_input) 
					{
						case 1 : // 1) Update ID
						{
							cout << "\nEnter the new ID please: "; 
							cin >> new_id; 
							while(idCheck != NULL) 
							{
								if(new_id == idCheck->getID()) 
								{
									printf("\nEntered ID is currently used by and existing student."); 
									idCheck = firstPerson; 
									printf("\nEnter the ID of the student please: "); 
									scanf("%d", &new_id); 
								}
								idCheck = idCheck->getNext(); 
							}
							old_id = tempProfessor->getID(); 
							tempProfessor->setID(new_id); 
							node = tempProfessor;
							printf("\n%d was sucessfully updated to %d", old_id, new_id); 
							break; 
						}

						case 2 : // 2) Update First Name
						{
							printf("\nEnter the new first name please: "); 
							cin >> new_first;
							old_first = tempProfessor->getFirstName(); 
							tempProfessor->setFirstName(new_first); 
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;
							node = tempProfessor;
							break; 
						}

						case 3 : // 3) Update Last Name
						{
							printf("\nEnter the new last name please: "); 
							cin >> new_last;
							old_last = tempProfessor->getLastName(); 
							tempProfessor->setLastName(new_last); 
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last; 
							node = tempProfessor;
							break; 
						}
						case 4 : // 4) Update GPA
						{
							printf("\nEnter the new Salary: "); 
							scanf("%f", &new_salary); 
							tempProfessor->setSalary(new_salary); 
							node = tempProfessor;
							printf("\n%f was sucessfully updated to %f", old_salary, new_salary); 
							break; 
						}
						
						case 5 : 
						{
							cout << "\nAre they a tenured staff member? yes or no ";
							cin >> temp;
							string yes = "yes";
							string no = "no";
							if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
								new_ten = true;
							else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
								new_ten = false;
							else
							{
								bool check = true;
								while(check)
								{
									cout << "\nPlease indicate yes or no: ";
									cin >> temp;
									if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
									{
										new_ten = true;
										check = false;
									}
										
									else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
									{
										new_ten = false;
										check = false;
									}
								}
							}
							old_ten = tempProfessor->getTenured();
							tempProfessor->setTenured(new_ten);
							node = tempProfessor;
							if(new_ten == old_ten)
								cout << "\nNo change was made because the value entered was the same as the current value";
							else
								cout << "\nTenured was updated";
							break;
						}
						
						case 6 :
						{
							cout << "\nEnter the department of the professor: ";
							cin >> temp;
							
							if(temp == "English"){new_dep = English;}
							else if(temp == "Math"){new_dep = Math;}
							else if(temp == "Philsophy"){new_dep = Philosophy;}
							else if(temp == "Theology"){new_dep = Theology;}
							else if(temp == "Biology"){new_dep = Biology;}
							else if(temp == "Physics"){new_dep = Physics;}
							else if(temp == "Chemistry"){new_dep = Chemistry;}
							else if(temp == "Engineering"){new_dep = Engineering;}
							else{new_dep = Unknown;}
							
							if(tempProfessor->getDepartment() == English)
							{
								temp2 = "English";
							}
							else if(tempProfessor->getDepartment() == Math)
							{
								temp2 = "Math";
							}
							else if(tempProfessor->getDepartment() == Philosophy)
							{
								temp2 = "Philosophy";
							}
							else if(tempProfessor->getDepartment() == Theology)
							{
								temp2 = "Theology";
							}
							else if(tempProfessor->getDepartment() == Biology)
							{
								temp2 = "Biology";
							}
							else if(tempProfessor->getDepartment() == Physics)
							{
								temp2 = "Physics";
							}
							else if(tempProfessor->getDepartment() == Chemistry)
							{
								temp2 = "Chemistry";
							}
							else if(tempProfessor->getDepartment() == Engineering)
							{
								temp2 = "Engineering";
							}
							else
							{
								temp2 = "Unknown";
							}
							tempProfessor->setDepartment(new_dep);
							node = tempProfessor;
							cout << "\n" << temp2 << " was successfully updated to " << temp;
							break;
						}
						
						case 7 :
						{
							break;
						}
						
						default : 
							printf("\nInvalid input\n");
					}
				}while(user_input != 7);
				return;
			}
			else if(instanceof<Employee>(node))
			{
				do
				{
					updateEmployeeMenu(node->getFirstName(), node->getLastName()); 
					cin >> user_input; 
					int new_id, old_id = 0;
					string new_first = "";
					string old_first = "";
					string new_last = "";
					string old_last = "";
					string temp = "";
					float new_salary, old_salary = 0.0;
					Person* idCheck = firstPerson;
					Employee* tempStudent = (Employee*) node;
					
					switch(user_input) 
					{
						case 1 : // 1) Update ID
							cout << "\nEnter the new ID: "; 
							cin >> new_id; 
							while(idCheck != NULL) 
							{
								if(new_id == idCheck->getID()) 
								{
									printf("\nEntered ID is currently used by and existing student.Please try another"); 
									idCheck = firstPerson; 
									printf("\nEnter the ID of the student please: "); 
									scanf("%d", &new_id); 
								}
								idCheck = idCheck->getNext(); 
							}
							old_id = tempStudent->getID(); 
							tempStudent->setID(new_id);
							node = tempStudent;
							printf("\n%d was sucessfully updated to %d", old_id, new_id); 
							break;
						case 2 : // 2) Update First Name
							printf("\nEnter the new first name please: ");
							cin >> new_first;
							old_first = tempStudent->getFirstName(); 
							tempStudent->setFirstName(new_first); 
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;
							node = tempStudent;
							break; 
						case 3 : // 3) Update Last Name
							printf("\nEnter the new last name please: "); 
							cin >> new_last;
							old_last = tempStudent->getLastName(); 
							tempStudent->setLastName(new_last); 
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last; 
							node = tempStudent;
							break; 
						case 4 : // 4) Update GPA
							printf("\nEnter the new Salary please: "); 
							scanf("%f", &new_salary); 
							
							old_salary = tempStudent->getSalary(); 
							tempStudent->setSalary(new_salary);
							node = tempStudent;
							printf("\n%f was sucessfully updated to %f", old_salary, new_salary); 
							break; 
						
						case 5 : // 5) Quit
							break; 
						
						default : 
							printf("\nInvalid input\n");
					}
				}while(user_input != 5);
				return;
			}
		}
		node = node->getNext();
	}
	cout << "\nThere is no person associated with the given ID.";
}

void menuDisplay() 
{
	printf("\n====================SEATTLE UNIVERSITY MENU====================");
	
	printf("\n\n[1] List");
	printf("\n[2] Add");
	printf("\n[3] Remove");
	printf("\n[4] Update");
	
	printf("\n\n[5] Quit");
	printf("\n\n=======================================================");
	printf("\n\n");
}

void addMenuDisplay() 
{
	printf("\n======================ADD MENU======================");
	
	printf("\n\n[1] Student");
	printf("\n[2] Professor");
	printf("\n[3] Employee");
	
	printf("\n\n[4] Quit");
	printf("\n\n====================================================");
	printf("\n\n");
}

void updateStudentMenu(string first, string last)
{
	printf("\n====================UPDATE SEATTLE UNIVERSITY STUDENT MENU====================");
	cout << "\nWhat would you like to update about " << first << " " << last << "?";
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] GPA");
	
	printf("\n\n[5] Quit");
	printf("\n\n===========================================================");
	printf("\n\n");
}

void updateProfessorMenu(string first, string last) 
{
	printf("\n====================UPDATE SEATTLE UNIVERSITY PROFESSOR MENU====================");
	cout << "\nWhat would you like to update about " << first << " " << last << "?";
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] Salary");
	printf("\n[5] Tenured");
	printf("\n[6] Department");
	
	printf("\n\n[7] Quit");
	printf("\n\n=============================================================");
	printf("\n\n");
}

void updateEmployeeMenu(string first, string last) 
{
	printf("\n====================UPDATE SEATTLE UNIVERSITY EMPLOYEE MENU====================");
	cout << "\nWhat would you like to update about " << first << " " << last << "?";
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] Salary");
	
	printf("\n\n[5] Quit");
	printf("\n\n============================================================");
	printf("\n\n");
}
