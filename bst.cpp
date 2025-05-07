#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class bst {
public:
    node* root;
    
    bst() {
        root = NULL;
    }
    
    void create(node*& root) {
        int total, data;
        cout << "Enter the total number of elements: ";
        cin >> total;
        for (int i = 0; i < total; i++) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> data;
            insert(root, data);
        }
    }
    
    void insert(node*& root, int data) {
        if (root == NULL) {
            root = new node;
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        }
        else if (data < root->data) {
            insert(root->left, data);
        }
        else if (data > root->data) {
            insert(root->right, data);
        }
    }
    
    int findmax(node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;  // Simply return the value.
	}
	
	int findmin(node* root) {
	    if (root == NULL) {
	        cout << "Tree is empty." << endl;
	        return -1;
	    }
	    while (root->left != NULL) {
	        root = root->left;
	    }
	    return root->data;  // Simply return the value.
	}


    void search(node* root, int value) {
        while (root != NULL) {
            if (root->data == value) {
                cout << "Value " << value << " found in the tree." << endl;
                return;
            }
            else if (value < root->data) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        cout << "Value " << value << " not found in the tree." << endl;
    }

    void mirror(node*& root) {
        if (root == NULL) {
            return;
        }
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
    }

    int height(node* root) {
        if (root == NULL) {
            return 0;
        }
        int hl = height(root->left);
        int hr = height(root->right);
        return max(hl, hr) + 1;
    }

    void Display(node* root) {
        if (root != NULL) {
            Display(root->left);
            cout << root->data << " ";
            Display(root->right);
        }
    }
};
int main() {
    bst B;
    int data;
    int value;
    int choice;

    do {
        cout << "\n---Menu---" << endl;
        cout << "1. Create BST" << endl;
        cout << "2. Insert node" << endl;
        cout << "3. Find Maximum" << endl;
        cout << "4. Find Minimum" << endl;
        cout << "5. BST (Inorder)" << endl;
        cout << "6. Search value" << endl;
        cout << "7. Mirror BST" << endl;
        cout << "8. Height of BST" << endl;
        cout << "9. End" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                B.create(B.root);
                break;

            case 2:
                cout << "Enter the number to be inserted: ";
                cin >> data;
                B.insert(B.root, data);
                break;

            case 3:
			    int max_value;
			    max_value = B.findmax(B.root);
			    if (max_value != -1) {
			        cout << "Maximum value: " << max_value << endl;
			    }
			    break;
			
			case 4:
			    int min_value;
			    min_value = B.findmin(B.root);
			    if (min_value != -1) {
			        cout << "Minimum value: " << min_value << endl;
			    }
			    break;

            case 5:
                cout << "BST (Inorder): ";
                B.Display(B.root);
                cout << endl;
                break;

            case 6:
                cout << "Enter the value to be searched: ";
                cin >> value;
                B.search(B.root, value);
                break;

            case 7:
                B.mirror(B.root);
                cout << "BST mirrored. Inorder traversal after mirroring: ";
                B.Display(B.root);
                cout << endl;
                break;

            case 8:
                cout << "Height of BST: " << B.height(B.root) << endl;
                break;

            case 9:
                cout << "END" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 9);

    return 0;
}

