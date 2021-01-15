/*
Write a class Employee having data member name, salary etc. Write proper constructors, methods to get/set
them and a virtual method printDetails() that prints all information of a person. Now write two classes Manager
and Clerk from Employee. Add ‘type’ and ‘allowance’ in the manager and Clerk respectively. Write
constructors, methods to get/set them and a override printDetails(). Now create a Manager and a Clerk object and
call printDetails() function on them to display their information.
Now Create an array of pointers to Employee and store addresses of two Employee, two Managers and two
Clerks. Call printDetails() on all elements (a loop may be used). Also find the total salary drawn by all
employees.
*/

#include <iostream>
using namespace std;

class Employee
{
protected:
    string name;
    double salary;

public:
    Employee(string n, double s)
    {
        name = n;
        salary = s;
    }
    string getName() { return name; }
    double getSalary() { return salary; }
    virtual void printDetails()
    {
        cout << "Name of employee: " << name << "\n";
        cout << "Salary of employee: " << salary << "\n";
    }
};

class Manager : public Employee
{
    string type;

public:
    Manager(string n, string t, double s) : Employee(n, s)
    {
        name = n;
        type = t;
        salary = s;
    }
    string getType() { return type; }
    void printDetails()
    {
        cout << "Name of manager: " << name << "\n";
        cout << "Type of manager: " << type << "\n";
        cout << "Salary of manager: " << salary << "\n";
    }
};

class Clerk : public Employee
{
    double allowance;

public:
    Clerk(string n, double s, double al) : Employee(n, s)
    {
        name = n;
        salary = s;
        allowance = al;
    }
    double getAllowance() { return allowance; }
    void printDetails()
    {
        cout << "Name of clerk: " << name << "\n";
        cout << "salary of clerk: " << salary << "\n";
        cout << "allowance of clerk: " << allowance << "\n";
    }
};

int main()
{

    Employee e1("Sudip", 200000), e2("Anirban", 250000);
    Manager m1("Srijit", "Production Manager", 450000), m2("Debaloy", "Manager Ops", 300000);
    Clerk c1("Ushnak", 100000, 5000), c2("Biren", 120000, 6000);

    Employee *E[6];

    E[0] = &e1;
    E[1] = &e2;

    E[2] = &m1;
    E[3] = &m2;

    E[4] = &c1;
    E[5] = &c2;

    for (int i = 0; i < 6; i++)
    {
        E[i]->printDetails();
        cout << "\n\n";
    }
}