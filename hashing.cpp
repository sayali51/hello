#include <iostream>
#include <string>
using namespace std;

struct node {
    int telephone;
    string name;
    struct node *next;
};

struct node1 {
    int telephone;
    string name;
};

class linear {
    node1* hashtable[10];

public:
    linear() {
        for (int i = 0; i < 10; i++) {
            hashtable[i] = NULL;
        }
    }

    void insert() {
        int telephone;
        string name;

        cout << "\nEnter the telephone: ";
        cin >> telephone;
        cout << "Enter the name: ";
        cin >> name;

        int loc = telephone % 10;
        node1* ptr = new node1;
        ptr->telephone = telephone;
        ptr->name = name;

        if (hashtable[loc] == NULL) {
            hashtable[loc] = ptr;
            cout << "Inserted at position!!" << endl;
        } else {
            while (hashtable[loc] != NULL) {
                loc = (loc + 1) % 10;
            }
            hashtable[loc] = ptr;
            cout << "Inserted at next position!!" << endl;
        }
    }

    void search() {
        int telephone, comparison = 0;
        cout << "\nEnter the search telephone: ";
        cin >> telephone;

        int loc = telephone % 10;
        int originalLoc = loc;

        while (hashtable[loc] != NULL) {
            comparison++;
            if (hashtable[loc]->telephone == telephone) {
                cout << "Found the telephone " << telephone << " at location " << loc << endl;
                cout << "Name: " << hashtable[loc]->name << endl;
                cout << "Total comparisons: " << comparison << endl;
                return;
            }
            loc = (loc + 1) % 10;
            if (loc == originalLoc) {
                break;
            }
        }

        cout << "Telephone " << telephone << " not found!" << endl;
    }

    void Display() {
        for (int i = 0; i < 10; i++) {
            if (hashtable[i] != NULL) {
                cout << "The telephone is: " << hashtable[i]->telephone << endl;
                cout << "Name is: " << hashtable[i]->name << endl;
            } else {
                cout << "---" << endl;
            }
        }
    }
};
class collision {
    node* hashtable[10];

public:
    collision() {
        for (int i = 0; i < 10; i++) {
            hashtable[i] = NULL;
        }
    }

    void insert() {
        int telephone;
        string name;

        cout << "Enter the telephone number: ";
        cin >> telephone;
        cout << "Enter the name: ";
        cin >> name;

        int loc = telephone % 10;
        node* ptr = new node;
        ptr->telephone = telephone;
        ptr->name = name;
        ptr->next = NULL;

        if (hashtable[loc] == NULL) {
            hashtable[loc] = ptr;
            cout << "Inserted successfully!" << endl;
        } else {
            node* ptr2 = hashtable[loc];
            while (ptr2->next != NULL) {
                ptr2 = ptr2->next;
            }
            ptr2->next = ptr;
            cout << "Inserted in linked list!" << endl;
        }
    }

    void search() {
        int telephone, comparisons = 0;
        cout << "Enter the telephone number to search: ";
        cin >> telephone;

        int loc = telephone % 10;
        node* ptr = hashtable[loc];

        while (ptr != NULL) {
            comparisons++;
            if (ptr->telephone == telephone) {
                cout << "Found search element: " << telephone << endl;
                cout << "Total comparisons: " << comparisons << endl;
                return;
            }
            ptr = ptr->next;
        }

        cout << "Telephone " << telephone << " not found." << endl;
        cout << "Total comparisons: " << comparisons << endl;
    }

    void Display() {
        for (int i = 0; i < 10; i++) {
            node* ptr = hashtable[i];
            if (ptr != NULL) {
                while (ptr != NULL) {
                    cout << "Telephone is: " << ptr->telephone << ", Name is: " << ptr->name << endl;
                    ptr = ptr->next;
                }
            } else {
                cout << "---" << endl;
            }
        }
    }
};
int main() {
    int choice, method;
    linear l1;
    collision c1;

    cout << "\nChoose Hashing Method:\n";
    cout << "1. Closed Hashing (Linear Probing)\n";
    cout << "2. Open Hashing (Chaining)\n";
    cout << "Enter your choice: ";
    cin >> method;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter a valid choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (method == 1) l1.insert();
                else if (method == 2) c1.insert();
                break;
            case 2:
                if (method == 1) l1.search();
                else if (method == 2) c1.search();
                break;
            case 3:
                if (method == 1) l1.Display();
                else if (method == 2) c1.Display();
                break;
            case 4:
                cout << "-- Exit --" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
