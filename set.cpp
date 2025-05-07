#include <iostream>
#include <process.h>
using namespace std;

class set {
public:
    int arr[5];
    int b[5];
    int c[10];
    int size;

public:
    set() {
        size = 0;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    void add(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element already present in the set " << endl;
                return;
            }
        }
        if (size < 5) {
            arr[size++] = key;
            cout << "Element added" << endl;
        } else {
            cout << "Set is full" << endl;
        }
    }

    void remove(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                cout << "Element removed " << endl;
                return;
            }
        }
        cout << "Element not found!" << endl;
    }

    void display() {
        if (size == 0) {
            cout << "Set is empty!" << endl;
            return;
        }
        cout << "Elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void contain(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found" << endl;
                return;
            }
        }
        cout << "Element not found!!" << endl;
    }

    void unionset() {
        cout << "Enter elements for set A: " << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Enter element " << i + 1 << " : ";
            cin >> arr[i];
        }
        cout << "Enter elements of set B: " << endl;
        for (int j = 0; j < 5; j++) {
            cout << "Enter element " << j + 1 << " : ";
            cin >> b[j];
        }
        int k = 0;
        for (int i = 0; i < 5; i++) {
            c[k] = arr[i];
            k++;
        }

        for (int j = 0; j < 5; j++) {
            bool flag = false;
            for (int i = 0; i < k; i++) {
                if (b[j] == c[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                c[k] = b[j];
                k++;
            }
        }
        cout << endl;
        cout << "Union of two sets: ";
        for (int i = 0; i < k; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }

    void intersection() {
        cout << "Enter elements for set A: " << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Enter element " << i + 1 << " : ";
            cin >> arr[i];
        }
        cout << "Enter elements of set B: " << endl;
        for (int j = 0; j < 5; j++) {
            cout << "Enter element " << j + 1 << " : ";
            cin >> b[j];
        }
        int k = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (arr[i] == b[j]) {
                    c[k] = arr[i];
                    k++;
                }
            }
        }
        cout << endl;
        cout << "Intersection of two sets: ";
        for (int i = 0; i < k; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }

    void difference() {
        int k = 0;
        for (int i = 0; i < 5; i++) {
            int flag = 0;
            for (int j = 0; j < 5; j++) {
                if (arr[i] == b[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                c[k] = arr[i];
                k++;
            }
        }
        cout << endl;
        cout << "Difference of the two sets: ";
        for (int i = 0; i < k; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }

    void subset() {
        cout << "Enter elements for set A: " << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Enter element " << i + 1 << " : ";
            cin >> arr[i];
        }
        cout << "Enter elements of set B: " << endl;
        for (int j = 0; j < 5; j++) {
            cout << "Enter element " << j + 1 << " : ";
            cin >> b[j];
        }

        bool isSubset = true;
        for (int i = 0; i < 5; i++) {
            bool found = false;
            for (int j = 0; j < 5; j++) {
                if (b[i] == arr[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                isSubset = false;
                break;
            }
        }
        if (isSubset) {
            cout << "Set B is a subset of Set A." << endl;
        } else {
            cout << "Set B is not a subset of Set A." << endl;
        }
    }
};

int main() {
    set s;
    int ch;
    int data;
    do {
        cout << "\n*****Menu***" << endl;
        cout << "1.Add an element \n2.Delete an element \n3.Display \n4.Is the element in collection? \n5.Find union of two sets \n6.Find intersection of two sets \n7.Find difference of two sets \n8.Check if Set B is a subset of Set A \n9.Exit \n";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter element to be added: " << endl;
            cin >> data;
            s.add(data);
            break;
        case 2:
            cout << "Enter element to be deleted: " << endl;
            cin >> data;
            s.remove(data);
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Enter the element you want to check: ";
            cin >> data;
            s.contain(data);
            break;
        case 5:
            s.unionset();
            break;
        case 6:
            s.intersection();
            break;
        case 7:
            s.difference();
            break;
        case 8:
            s.subset();
            break;
        case 9:
            cout << "Exiting...";
            exit(0);
        default:
            cout << "Invalid choice!!" << endl;
        }

    } while (ch != 9);
    return 0;
}
