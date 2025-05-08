#include <iostream>
#include <fstream>
using namespace std;

class student
{
public:	
    char name[20];
    char grade;
    float marks;

public:
    void getdata();
    void display();
};

void student::getdata()
{
    cin.ignore();  // ? Flush leftover newline from previous input
    cout << "Enter the name: ";
    cin.getline(name, 20);
    cout << "Enter the grade: ";
    cin >> grade;
    cout << "Enter the marks: ";
    cin >> marks;
    cout << "\n";
}

void student::display()
{
    cout << "Name: " << name << "\tGrade: " << grade << "\tMarks: " << marks << "\n";
}

int main()
{
    char fname[20];
    student cse[3];
    fstream fio;

    cout << "Enter file name: ";
    cin.getline(fname, 20);  // ? First input is safe to use getline

    fio.open(fname, ios::in | ios::out  | ios::trunc);
    if (!fio)
    {
        cout << "Error opening the file!\n";
        return 0;
    }

    cout << "Enter details for the three students:\n\n";
    for (int i = 0; i < 3; i++)
    {
        cse[i].getdata();
        fio << cse[i].name << " " << cse[i].grade << " " << cse[i].marks << endl;

    }

    fio.seekg(0); // ? Rewind file to read from start
    cout << "\nThe contents of the " << fname << " file are shown below:\n";

    for (int i = 0; i < 3; i++)
    {
        fio >> cse[i].name >> cse[i].grade >> cse[i].marks;

        cse[i].display();
    }

    fio.close();
    return 0;
}
