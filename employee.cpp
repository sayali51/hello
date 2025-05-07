#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    int empID;
    char name[50];
    char designation[50];
    double salary;
};

class EmployeeDatabase {
private:
    string fileName = "employee.dat";

public:
    void addEmployee() {
        Employee emp;
        cout << "Enter Employee ID: ";
        cin >> emp.empID;
        cin.ignore();  // Flush newline from buffer

        cout << "Enter Employee Name: ";
        cin.getline(emp.name, 50);

        cout << "Enter Employee Designation: ";
        cin.getline(emp.designation, 50);

        cout << "Enter Employee Salary: ";
        cin >> emp.salary;

        ofstream file(fileName.c_str(), ios::app | ios::binary);

        if (!file) {
            cout << "Error opening file to write!" << endl;
            return;
        }
        file.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        file.close();

        cout << "Employee added successfully." << endl;
    }

    void deleteEmployee() {
        int empID;
        cout << "Enter Employee ID to delete: ";
        cin >> empID;
        
 		ifstream infile(fileName.c_str(), ios::binary);
        if (!infile) {
            cout << "Error opening file to read!" << endl;
            return;
        }

        ofstream outfile("temp.dat", ios::binary);
        if (!outfile) {
            cout << "Error opening temp file to write!" << endl;
            return;
        }

        Employee emp;
        bool found = false;

        while (infile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
            if (emp.empID == empID) {
                found = true;  // Skip writing this employee
            } else {
                outfile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
            }
        }

        infile.close();
        outfile.close();

        if (found) {
            remove(fileName.c_str());
            rename("temp.dat", fileName.c_str());
            cout << "Employee with ID " << empID << " deleted successfully." << endl;
        } else {
            cout << "Employee with ID " << empID << " not found." << endl;
            remove("temp.dat");  // Clean up temp file
        }
    }

    void displayEmployee() {
        int empID;
        cout << "Enter Employee ID to display: ";
        cin >> empID;

        ifstream file(fileName.c_str(), ios::binary);
        if (!file) {
            cout << "Error opening file to read!" << endl;
            return;
        }

        Employee emp;
        bool found = false;

        while (file.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
            if (emp.empID == empID) {
                cout << "\nEmployee ID: " << emp.empID << endl;
                cout << "Employee Name: " << emp.name << endl;
                cout << "Employee Designation: " << emp.designation << endl;
                cout << "Employee Salary: " << emp.salary << endl;
                found = true;
                break;
            }
        }

        file.close();

        if (!found) {
            cout << "Employee with ID " << empID << " not found." << endl;
        }
    }
};

int main() {
    EmployeeDatabase db;
    int choice;

    while (true) {
        cout << "\nEmployee Database Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                db.addEmployee();
                break;
            case 2:
                db.deleteEmployee();
                break;
            case 3:
                db.displayEmployee();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

