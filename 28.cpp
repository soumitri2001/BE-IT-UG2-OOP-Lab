/*
Write a class for your Grade card. The grade card is given to each student of a department per semester. The
grade card typically contains the name of the department, name of the student, roll number, semester, a list of
subjects with their marks and a calculated CGPA. Create 60 such grade cards in a 3 rd semester with relevant data
and find the name and roll number of student having highest CGPA.
*/
// #include <time.h>

#include <iostream>
using namespace std;

const int no_of_subs = 5;
const int no_of_cards = 60;

string subs[no_of_subs] = {"OOP", "DSA", "COA", "DBMS", "Maths"};

class GradeCard
{
    string dept, name;
    double marks[no_of_subs];
    int roll, sem;
    double cgpa;

public:
    GradeCard();
    GradeCard(string d, string n, int r, int sem, double m[], double g);
    string getName();
    int getRoll();
    double getCgpa();
    GradeCard getTopper(GradeCard cards[]);
    void printGradeCard();
};

GradeCard::GradeCard()
{
    dept = name = "";
    sem = cgpa = roll = 0;
}

GradeCard::GradeCard(string d, string n, int r, int s, double m[], double g)
{
    dept = d;
    name = n;
    roll = r;
    sem = s;
    cgpa = g;
    for (int i = 0; i < no_of_subs; i++)
        marks[i] = m[i];
}

string GradeCard::getName()
{
    return this->name;
}

int GradeCard::getRoll()
{
    return this->roll;
}

double GradeCard::getCgpa()
{
    return this->cgpa;
}

GradeCard GradeCard::getTopper(GradeCard cards[])
{
    GradeCard topcard = GradeCard();
    double max_cgpa = 0.0;
    for (int i = 0; i < no_of_cards; i++)
    {
        if (cards[i].cgpa > max_cgpa)
        {
            max_cgpa = cards[i].cgpa;
            topcard = cards[i];
        }
    }
    return topcard;
}

void GradeCard::printGradeCard()
{
    cout << "Name: " << this->name << "\n";
    cout << "Department: " << this->dept << "\n";
    cout << "Roll: " << this->roll << "\n";
    cout << "Semester: " << this->sem << "\n";
    cout << "Marks in each subject:\n";
    for (int i = 0; i < no_of_subs; i++)
        cout << subs[i] << ": " << this->marks[i] << "\n";
    cout << "CGPA: " << this->cgpa << "\n";
}

int main()
{
    // setting seed for random nos
    // srand(time(0));
    // random data generation
    int sem = 1 + (rand() % 8); // random number between 1 and 8
    string dept = "Information Technology";
    GradeCard cards[no_of_cards];
    for (int i = 0; i < no_of_cards; i++)
    {
        string name = "StudentXXX" + to_string(i + 1);
        int roll = i + 1;
        double marks[no_of_subs];
        for (int j = 0; j < no_of_subs; j++)
            marks[j] = 1 + (rand() % 100);
        double cgpa = 10.0 * rand() / RAND_MAX;
        cards[i] = GradeCard(dept, name, roll, sem, marks, cgpa);
    }
    GradeCard gc = GradeCard();
    GradeCard topcard = gc.getTopper(cards);
    cout << "Departmental Topper\n";
    cout << "Name: " << topcard.getName() << "\n"
         << "Roll: " << topcard.getRoll() << "\n"
         << "CGPA: " << topcard.getCgpa() << "\n";
}