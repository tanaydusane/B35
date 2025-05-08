// Assignment no 5

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    int lbit, rbit;
};

class TBT {
    node* root;

public:
    node* head;

    TBT() {
        root = NULL;
    }

    node* getroot() {
        return root;
    }

    void createtree();
    void inorder(node* root);
};

void TBT::createtree() {
    char ans;
    node* new1, *curr;
    head = new node;
    head->data = -999;
    head->right = head;

    do {
        new1 = new node;
        new1->lbit = 0;
        new1->rbit = 0;
        cout << "\nEnter your data: ";
        cin >> new1->data;

        if (root == NULL) {
            root = new1;
            head->left = root;
            head->lbit = 1;
            root->left = head;
            root->right = head;
        } else {
            curr = root;
            int flag = 0;

            if (new1->data < curr->data) {
                while (flag == 0) {
                    if (curr->lbit == 0) {
                        new1->left = curr->left;
                        curr->left = new1;
                        curr->lbit = 1;
                        new1->right = curr;
                        flag = 1;
                    } else {
                        curr = curr->left;
                    }
                }
            } else if (new1->data > curr->data) {
                while (flag == 0) {
                    if (curr->rbit == 0) {
                        new1->right = curr->right;
                        curr->right = new1;
                        curr->rbit = 1;
                        new1->left = curr;
                        flag = 1;
                    } else {
                        curr = curr->right;
                    }
                }
            } else {
                cout << "\nData already exists!";
            }
        }

        cout << "\nDo you want to add more node? (y/n): ";
        cin >> ans;

    } while (ans == 'Y' || ans == 'y');
}

void TBT::inorder(node* root) {
    node* temp = root;
    int flag = 0;

    if (root == NULL) {
        cout << "\nTree is empty";
    } else {
        while (temp != head) {
            if (temp->lbit == 1 && flag == 0) {
                temp = temp->left;
            } else {
                cout << " " << temp->data;
                if (temp->rbit == 1) {
                    temp = temp->right;
                    flag = 0;
                } else {
                    temp = temp->right;
                    flag = 1;
                }
            }
        }
    }
}

int main() {
    TBT t;
    int ch;

    do {
        cout << "\n-------MENU-------";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                t.createtree();
                break;
            case 2:
                t.inorder(t.getroot());
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "\nInvalid Choice Entered!";
        }

    } while (ch != 3);

    return 0;
}
