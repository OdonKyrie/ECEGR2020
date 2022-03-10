#include <iostream>
#include <cstring>

using namespace std;

enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};

class Student
{
private:
	int  ID;
    char* firstName;
    char* lastName;
    float GPA;

public:
	Student();
	Student(int id_in, char *first_inp, char *last_inp, float gpa_inp);
	Student(Student &init);
	~Student();
	Student& operator=(Student const &s)
	{
		this->ID = s.ID;
		setFirstName(s.firstName);
		setLastName(s.lastName);
		this->GPA = s.GPA;
		printf("Student Assignment Operator called.\n");
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
	char* getFirstName()
	{
		return firstName;
	}
	char* getLastName()
	{
		return lastName;
	}

	// Set methods
	void setID(int id_in)
	{
		ID = id_in;
	}
	void setGPA(float gpa_inp)
	{
		GPA = gpa_inp;
	}
	void setFirstName(char *first_inp)
	{
		free(firstName);
		firstName = (char*) malloc(sizeof(strlen(first_inp)+1));
		strcpy(firstName, first_inp);
	}
	void setLastName(char *last_inp)
	{
		free(lastName);
		lastName = (char*) malloc(sizeof(strlen(last_inp)+1));
		strcpy(lastName, last_inp);
	}
};

class Professor
{
private:
	int ID;
	char* firstName;
    char* lastName;
    float salary;
	bool tenured;
	Department department;

public:
	Professor();
	Professor(int id_in, char* first_inp, char* last_inp, float salary_in, bool ten_in, Department dep_in);
	Professor(Professor &init);
	~Professor();
	Professor& operator= (Professor const &p)
	{
		this->ID = p.ID;
		setFirstName(p.firstName);
		setLastName(p.lastName);
		this->salary = p.salary;
		this->tenured = p.tenured;
		this->department = p.department;
		printf("Professor Assignment Operator called.\n");
		return *this;
	}
	
	//Get methods
	int getID()
	{
		return ID;
	}
	char* getFirstName()
	{
		return firstName;
	}
	char* getLastName()
	{
		return lastName;
	}
	float getSalary()
	{
		return salary;
	}
	bool getTenured()
	{
		return tenured;
	}
	Department getDepartment()
	{
		return department;
	}
	
	//Set methods
	void setID(int id_in)
	{
		ID = id_in;
	}
	void setFirstName(char *first_inp)
	{
		free(firstName);
		firstName = (char*) malloc(sizeof(strlen(first_inp)+1));
		strcpy(firstName, first_inp);
	}
	void setLastName(char *last_inp)
	{
		free(lastName);
		lastName = (char*) malloc(sizeof(strlen(last_inp)+1));
		strcpy(lastName, last_inp);
	}
	void setSalary(float salary_in)
	{
		salary = salary_in;
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

class Employee
{
private:
	int  ID;
    char *firstName;
    char *lastName;
    float salary;
	
public:
	Employee();
	Employee(int id_in, char* first_inp, char* last_inp, float salary_in);
	Employee(Employee &init);
	~Employee();
	Employee& operator= (Employee const &e)
	{
		this->ID = e.ID;
		setFirstName(e.firstName);
		setLastName(e.lastName);
		this->salary = e.salary;
		printf("Employee Assignment Operator has been called.\n");
		return *this;
	}
	
	//using Get 
	int getID()
	{
		return ID;
	}
	char* getFirstName()
	{
		return firstName;
	}
	char* getLastName()
	{
		return lastName;
	}
	float getSalary()
	{
		return salary;
	}
	
	//Using Set
	void setID(int id_in)
	{
		ID = id_in;
	}
	void setFirstName(char *first_inp)
	{
		free(firstName);
		firstName = (char*) malloc(sizeof(strlen(first_inp)+1));
		strcpy(firstName, first_inp);
	}
	void setLastName(char *last_inp)
	{
		free(lastName);
		lastName = (char*) malloc(sizeof(strlen(last_inp)+1));
		strcpy(lastName, last_inp);
	}
	void setSalary(float salary_in)
	{
		salary = salary_in;
	}
};

Student :: Student()
{
	//should display uknown 
	this->ID = 1458;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this->firstName, (char*) "<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this->lastName, (char*) "<unknown>");
	this->GPA = 3.2;
	printf("Student Default Constructor has been called.\n");
}

Student :: Student(int id_in, char* first_inp, char* last_inp, float gpa_inp)
{
	this->ID = id_in;
	this->firstName = (char*) malloc(sizeof(strlen(first_inp)+1));
	strcpy(this->firstName, first_inp);
	this->lastName = (char*) malloc(sizeof(strlen(last_inp)+1));
	strcpy(this->lastName, last_inp);
	this->GPA = gpa_inp;
	printf("Student Constructor has been called for %s %s.\n", firstName, lastName);
}

Student :: Student(Student &init)
{
	ID = init.ID;
	GPA = init.GPA;
	if(init.firstName)
	{
		setFirstName(init.firstName);
	}
	if(init.lastName)
	{
		setLastName(init.lastName);
	}
	printf("Student Copy Constructor has been called.\n");
}

Student :: ~Student()
{
	printf("Student Destructor has been called for %s %s.\n", firstName, lastName);
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
}

Professor :: Professor()
{
	this->ID = 13954;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this->firstName, (char*) "<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this->lastName, (char*) "<unknown>");
	salary = 0.0;
	tenured = false;
	department = Unknown;
	printf("Professor Default Constructor has been called.\n");
}

Professor :: Professor(int id_in, char* first_inp, char* last_inp, float salary_in, bool ten_in, Department dep_in)
{
	this->ID = id_in;
	firstName = (char*) malloc(sizeof(strlen(first_inp)+1));
	strcpy(firstName, first_inp);
	lastName = (char*) malloc(sizeof(strlen(last_inp)+1));
	strcpy(lastName, last_inp);
	this->salary = salary_in;
	this->tenured = ten_in;
	this->department = dep_in;
	printf("Professor Constructor has been called for %s %s.\n", firstName, lastName);
}

Professor :: Professor(Professor &init)
{
	ID = init.ID;
	if(init.firstName)
	{
		firstName = (char*) malloc(sizeof(strlen(init.firstName)+1));
		strcpy(firstName, init.firstName);
	}
	if(init.lastName)
	{
		lastName = (char*) malloc(sizeof(strlen(init.lastName)+1));
		strcpy(lastName, init.lastName);
	}
	salary = init.salary;
	tenured = init.tenured;
	department = init.department;
	printf("Professor Copy Constructor has been called.\n");
}

Professor :: ~Professor()
{
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
	printf("Professor Destructor has been called.\n");
}

Employee :: Employee()
{
	this->ID = 78934;
	this->firstName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this->firstName, (char*) "<unknown>");
	this->lastName = (char*) malloc(sizeof(strlen((char*) "<unknown>")+1));
	strcpy(this->lastName, (char*) "<unknown>");
	salary = 0.0;
	printf("Employee Default Constructor has been called.\n");
}

Employee :: Employee(int id_in, char* first_inp, char* last_inp, float salary_in)
{
	this->ID = id_in;
	firstName = (char*) malloc(sizeof(strlen(first_inp)+1));
	strcpy(firstName, first_inp);
	lastName = (char*) malloc(sizeof(strlen(last_inp)+1));
	strcpy(lastName, last_inp);
	this->salary = salary_in;
	printf("Employee Constructor has been called for %s %s.\n", firstName, lastName);
}

Employee :: Employee(Employee &init)
{
	ID = init.ID;
	if(init.firstName)
	{
		firstName = (char*) malloc(sizeof(strlen(init.firstName)+1));
		strcpy(firstName, init.firstName);
	}
	if(init.lastName)
	{
		lastName = (char*) malloc(sizeof(strlen(init.lastName)+1));
		strcpy(lastName, init.lastName);
	}
	salary = init.salary;
	printf("Employee Copy Constructor has been called.\n");
}

Employee :: ~Employee()
{
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
	printf("Employee Destructor has been called.\n");
}

int main() 
{
	Student student1(2424, (char*) "Joe", (char*) "Ma", 1.0);
	printf("%d\n", student1.getID());
	printf("%s %s\n", student1.getFirstName(), student1.getLastName());
	printf("%f\n", student1.getGPA());
	/*Student student2 = student1;
	Student student3 = student2;
	printf("%d\n", student3.getID());
	printf("%s %s\n", student3.getFirstName(), student3.getLastName());
	printf("%f\n", student3.getGPA());
	printf("%d\n", student2.getID());
	printf("%s %s\n", student2.getFirstName(), student2.getLastName());
	printf("%f\n", student2.getGPA());
	if((student1.getID() == student2.getID()) && (student2.getGPA() == student3.getGPA()))
	{
		printf("All three students are the same.\n");
	}
	
	student3.setFirstName((char*) "Nate");
	student3.setLastName((char*) "Dawg");
	printf("%s %s\n", student3.getFirstName(), student3.getLastName());
	student2.setFirstName((char*) "Naruto");
	student2.setLastName((char*) "Uzumaki");
	printf("%s %s\n", student2.getFirstName(), student2.getLastName());*/
}
