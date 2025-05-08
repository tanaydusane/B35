#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node() {
        left = NULL;
        right = NULL;
        data = 0;
    }
};

class BST {
    node* root;

public:
    BST() : root(NULL) {}

    void insert();
    void Inorder(node* root);
    void Inorder() { Inorder(root); }

    void Preorder(node* root);
    void Preorder() { Preorder(root); }

    void Postorder(node* root);
    void Postorder() { Postorder(root); }

    void smallest();
    void search();
    void mirror(node* root);
    void mirror() { mirror(root); }

    int height(node* root);
    int height() { return height(root); } // Public wrapper for height
};

void BST::insert() {
    node* NN = new node();
    node* temp;
    int flag = 0;

    cout << "Enter data: ";
    cin >> NN->data;

    NN->left = NULL;
    NN->right = NULL;

    if (root == NULL) {
        root = NN;
    } else {
        temp = root;
        while (flag == 0) {
            if (NN->data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = NN;
                    flag++;
                } else {
                    temp = temp->left;
                }
            } else if (NN->data > temp->data) {
                if (temp->right == NULL) {
                    temp->right = NN;
                    flag++;
                } else {
                    temp = temp->right;
                }
            } else {
                cout << "Node already exists\n";
                flag++;
            }
        }
    }
}

void BST::Inorder(node* root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void BST::Preorder(node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void BST::Postorder(node* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

void BST::smallest() {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return;
    }
    node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    cout << "Smallest node = " << temp->data << endl;
}

void BST::search() {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return;
    }
    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;

    node* temp = root;
    while (temp != NULL) {
        if (key < temp->data) {
            temp = temp->left;
        } else if (key > temp->data) {
            temp = temp->right;
        } else {
            cout << "Node is found\n";
            return;
        }
    }
    cout << "Node is not found\n";
}

void BST::mirror(node* root) {
    if (root == NULL) {
        return;
    }
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int BST::height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int LH = height(root->left);
    int RH = height(root->right);

    return max(LH, RH) + 1;
}

int main() {
    BST tree;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Smallest Node\n";
        cout << "6. Search\n";
        cout << "7. Mirror Tree\n";
        cout << "8. Height of Tree\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.insert();
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.Inorder();
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.Preorder();
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.Postorder();
                cout << endl;
                break;
            case 5:
                tree.smallest();
                break;
            case 6:
                tree.search();
                break;
            case 7:
                cout << "Mirroring the tree...\n";
                tree.mirror();
                break;
            case 8:
                cout << "Height of the tree: " << tree.height() << endl;
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
