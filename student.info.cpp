#include <iostream>
#include <fstream>
using namespace std;

class student
{
    char name[20];
    char grade;
    float marks;

public:
    void getdata(void);
    void display(void);
};

void student::getdata(void)
{
    char ch;
    cin.get(ch); // to consume leftover newline
    cout << "Enter the name: ";
    cin.getline(name, 20);
    cout << "Enter the grade: ";
    cin >> grade;
    cout << "Enter the mark: ";
    cin >> marks;
    cout << "\n";
}

void student::display(void)
{
    cout << "Name: " << name << "\tGrade: " << grade << "\tMarks: " << marks << "\n";
}

int main()
{
    char fname[20];
    student cse[3];
    fstream fio;

    cout << "Enter file name: ";
    cin.getline(fname, 20);

    fio.open(fname, ios::in | ios::out | ios::binary | ios::trunc);
    if (!fio)
    {
        cout << "Error opening the file!\n";
        return 0;
    }

    cout << "Enter details for the three students:\n\n";
    for (int i = 0; i < 3; i++)
    {
        cse[i].getdata();
        fio.write((char *)&cse[i], sizeof(cse[i]));
    }

    fio.seekg(0);
    cout << "\nThe contents of the " << fname << " file are shown below:\n";

    for (int i = 0; i < 3; i++)
    {
        fio.read((char *)&cse[i], sizeof(cse[i]));
        cse[i].display();
    }

    fio.close();
    return 0;
}

