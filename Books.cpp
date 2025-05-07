#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    Node* createNode(string prompt) {
        string value;
        cout << prompt;
        getline(cin, value);
        if (value == "-1") {  
            return NULL;
        }
        return new Node(value);
    }

    Node* createTree(string level) {
        Node* newNode = createNode("Enter " + level + " (enter -1 for no " + level + "): ");
        if (!newNode) {
            return NULL;
        }
        cout << "Adding left child(Chapters) to " << newNode->data << endl;
        newNode->left = createTree("child of " + newNode->data);

        cout << "Adding right sibling to " << newNode->data << endl;
        newNode->right = createTree("sibling of " + newNode->data);

        return newNode;
    }

    void displayTree(Node* root, int level = 0) {
        if (!root) {
            return;
        }
       
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        cout << root->data << endl;

        displayTree(root->left, level + 1);  
        displayTree(root->right, level);    
    }
};

int main() {
    string choice;
    do {
        Tree bookTree;

        cout << "\nCreate your book tree!" << endl;
        bookTree.root = bookTree.createTree("Book Name");

        cout << "\nDisplaying the book structure:\n";
        bookTree.displayTree(bookTree.root);

        cout << "\nDo you want to create another tree? (yes/no): ";
        getline(cin, choice);

    } while (choice == "yes" || choice == "Yes");

    return 0;
}

