/*
Write a class Person having data member name, age, height etc. Write proper constructors, methods to get/set
them and a method printDetails() that prints all information of a person. Now write another class Student from
Person and add data members roll, year of admission etc. Write constructors, methods to get/set them and a
override printDetails(). Now create a Person and a Student object and call printDetails() function on them to
display their information.
*/

#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    float height;

public:
    Person(string n, int a, float h)
    {
        name = n;
        age = a;
        height = h;
    }
    string getName() { return name; }
    int getAge() { return age; }
    float getHeight() { return height; }
    virtual void printDetails()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Height: " << height << "\n";
    }
};

class Student : public Person
{
    int roll, year;

public:
    Student(string n, int a, float h, int r, int yr) : Person(n, a, h)
    {
        name = n;
        age = a;
        height = h;
        roll = r;
        year = yr;
    }
    int getRoll() { return roll; }
    int getYear() { return year; }
    void printDetails()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Height: " << height << "\n";
        cout << "Roll: " << roll << "\n";
        cout << "Year of admission: " << year << "\n";
    }
};

int main()
{

    Person p = Person("Soumitri", 19, 6.1);
    p.printDetails();

    cout << "\n\n";

    Student s = Student("Soumitri", 19, 6.1, 83, 2019);
    s.printDetails();

    cout << "\n\n";

    Person *P[4];

    Person p1("Byomkesh", 89, 6.2), p2("Feluda", 56, 6.0);
    Student s1("Andrew", 23, 5.7, 57, 2016), s2("Gareth", 21, 6.4, 96, 2017);

    P[0] = &p1;
    P[1] = &p2;
    P[2] = &s1;
    P[3] = &s2;

    for (int i = 0; i < 4; i++)
    {
        P[i]->printDetails();
        cout << "\n\n";
    }
}
