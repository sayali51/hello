#include <iostream>
using namespace std;

class node {
public:
    string keyword;
    string meaning;
    node* left;
    node* right;

    node(string key, string mean) {
        keyword = key;
        meaning = mean;
        left = right = NULL;
    }
};

class tree {
public:
    node* root;

    tree() {
        root = NULL;
    }

    void create() {
        char ans = 'y';
        while (ans == 'y' || ans == 'Y') {
            string key, mean;
            cout << "Enter word: ";
            cin >> key;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, mean);

            root = insert(root, key, mean);

            cout << "Do you want to enter more words? (y/n): ";
            cin >> ans;
        }
    }

    node* insert(node* root, string key, string mean) {
        if (root == NULL)
            return new node(key, mean);

        if (key < root->keyword)
            root->left = insert(root->left, key, mean);
        else if (key > root->keyword)
            root->right = insert(root->right, key, mean);

        return root;
    }

    void search(string key) {
        node* temp = root;
        int comparisons = 0;

        while (temp != NULL) {
            comparisons++;  // Count each comparison
            if (temp->keyword == key) {
                cout << "Word found: " << temp->keyword << " --> " << temp->meaning << endl;
                cout << "Number of comparisons: " << comparisons << endl;
                return;
            }
            if (key < temp->keyword)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << "Word not found!" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    }

    void update(string key) {
        node* temp = root;
        while (temp != NULL) {
            if (temp->keyword == key) {
                cout << "Enter the updated meaning: ";
                cin.ignore();
                getline(cin, temp->meaning);
                cout << "Word: " << temp->keyword << " Updated meaning: " << temp->meaning << endl;
                return;
            }
            if (key < temp->keyword)
                temp = temp->left;
            else
                temp = temp->right;
        }
        cout << "Word not found!" << endl;
    }

    node* find_min(node* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    node* del(node* root, string key) {
        if (root == NULL)
            return NULL;

        if (key < root->keyword) {
            root->left = del(root->left, key);
        } else if (key > root->keyword) {
            root->right = del(root->right, key);
        } else {
            if (root->left == NULL) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                node* temp = root->left;
                delete root;
                return temp;
            }

            node* temp = find_min(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = del(root->right, temp->keyword);
        }
        return root;
    }

    void inorder(node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->keyword << " --> " << root->meaning << endl;
        inorder(root->right);
    }

    void reverse_inorder(node* root) {
        if (root == NULL)
            return;
        reverse_inorder(root->right);
        cout << root->keyword << " --> " << root->meaning << endl;
        reverse_inorder(root->left);
    }

    void displayAscending() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        cout << "\nDictionary in Ascending Order:\n";
        inorder(root);
    }

    void displayDescending() {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        cout << "\nDictionary in Descending Order:\n";
        reverse_inorder(root);
    }
};

int main() {
    tree t;
    int choice;
    string key;

    while (true) {
        cout << "\n---------- MENU ----------\n";
        cout << "\n1. Insert words\n";
        cout << "2. Search for a word\n";
        cout << "3. Update a word's meaning\n";
        cout << "4. Delete a word\n";
        cout << "5. Display in Ascending Order\n";
        cout << "6. Display in Descending Order\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t.create();
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> key;
                t.search(key);
                break;
            case 3:
                cout << "Enter word to update: ";
                cin >> key;
                t.update(key);
                break;
            case 4:
                cout << "Enter word to delete: ";
                cin >> key;
                t.root = t.del(t.root, key);
                cout << "Word deleted successfully!" << endl;
                break;
            case 5:
                t.displayAscending();
                break;
            case 6:
                t.displayDescending();
                break;
            case 7:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 7.\n";
        }
    }
}

