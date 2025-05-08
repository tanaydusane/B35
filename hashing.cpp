#include<iostream>
#define MAX 10
using namespace std;

class Hashing
{
    long int HT[MAX];
    
public:
    Hashing()
    {
        for(int i = 0; i < MAX; i++)
        {
            HT[i] = -1; // Initialize all slots to -1 (empty)
        }
    }

    int LP(long int key, int pos);
    int QP(long int key, int pos); // Quadratic probing
    void insert(long int key, int collisionType);
    void display();
};

int Hashing::LP(long int key, int pos)
{
    int i = pos;
    while (HT[i] != -1) // While position is occupied
    {
        i = (i + 1) % MAX;  // Linear Probing
        if (i == pos)
        {
            return -1;  // Table is full
        }
    }
    return i;
}

int Hashing::QP(long int key, int pos)
{
    int i = pos;
    int j = 1;
    while (HT[i] != -1) // While position is occupied
    {
        i = (pos + j * j) % MAX;  // Quadratic Probing
        if (i == pos)
        {
            return -1;  // Table is full
        }
        j++;  // Increase the square for next quadratic probe
    }
    return i;
}

void Hashing::insert(long int key, int collisionType)
{
    int pos = key % MAX; // Hashing function

    if (HT[pos] == -1)
    {
        HT[pos] = key;
        cout << "Key inserted at index " << pos << endl;
    }
    else if (collisionType == 1)  // Linear Probing
    {
        int t_pos = LP(key, pos); // Apply linear probing
        if (t_pos != -1)
        {
            HT[t_pos] = key;
            cout << "Key inserted at index " << t_pos << endl;
        }
        else
        {
            cout << "Hash table is full. Unable to insert key." << endl;
        }
    }
    else if (collisionType == 2) // Quadratic Probing
    {
        int t_pos = QP(key, pos); // Apply quadratic probing
        if (t_pos != -1)
        {
            HT[t_pos] = key;
            cout << "Key inserted at index " << t_pos << endl;
        }
        else
        {
            cout << "Hash table is full. Unable to insert key." << endl;
        }
    }
    else
    {
        cout << "Invalid collision type!" << endl;
    }
}

void Hashing::display()
{
    cout << "HASH TABLE\n";
    for (int i = 0; i < MAX; i++)
    {
        cout << "Index " << i << ": " << HT[i] << endl;
    }
}

int main()
{
    Hashing ha;
    int choice, collisionChoice;
    long int key;

    do {
        cout << "\nMenu:\n";
        cout << "1) Insert key\n";
        cout << "2) Display hash table\n";
        cout << "3) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                cout << "Choose collision handling method:\n";
                cout << "1) Linear Probing\n";
                cout << "2) Quadratic Probing\n";
                cin >> collisionChoice;

                if (collisionChoice == 1)
                {
                    ha.insert(key, 1);  // Linear Probing
                }
                else if (collisionChoice == 2)
                {
                    ha.insert(key, 2);  // Quadratic Probing
                }
                else
                {
                    cout << "Invalid choice for collision handling.\n";
                }
                break;

            case 2:
                ha.display();
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}

