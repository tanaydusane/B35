#include<iostream>
using namespace std;

class Set_op
{
    int *set_elements;
    int cnt;
    int max_size;

public:
    Set_op(int size = 10);  
    ~Set_op();             
    void insert(int num);   
    void display();         
    void size();            
    int search(int x);      
    void remove();          
    void uni(Set_op &s1, Set_op &s2);
    void inter(Set_op &s1, Set_op &s2);
    void minus(Set_op &s1, Set_op &s2);
    void subset(Set_op &s1, Set_op &s2);
};

Set_op::Set_op(int size)
{
    max_size = size;
    set_elements = new int[max_size];
    cnt = 0;
}

Set_op::~Set_op()
{
    delete[] set_elements;
}

void Set_op::insert(int num) {
    
    if (cnt < max_size && search(num) == -1) {
        set_elements[cnt++] = num;
    }
}

void Set_op::display() {
    cout << "Elements of the set are: ";
    for (int i = 0; i < cnt; i++) {
        cout << set_elements[i] << " ";
    }
    cout << endl;
}

void Set_op::size() {
    cout << "Size of the set is: " << cnt << endl;
}

int Set_op::search(int x) {
    for (int i = 0; i < cnt; i++) {
        if (set_elements[i] == x) {
            return i;  
        }
    }
    return -1;
}

void Set_op::remove() {
    int num;
    cout << "Enter the element to be deleted: ";
    cin >> num;
    
    int index = search(num);
    if (index != -1) {
        
        for (int i = index; i < cnt - 1; i++) {
            set_elements[i] = set_elements[i + 1];
        }
        cnt--;  
        cout << "Element deleted successfully." << endl;
    } else {
        cout << "Element not found." << endl;
    }
}

void Set_op::uni(Set_op &s1, Set_op &s2) {
    
    for (int i = 0; i < s1.cnt; i++) {
        insert(s1.set_elements[i]);
    }
    for (int i = 0; i < s2.cnt; i++) {
        insert(s2.set_elements[i]);
    }
}

void Set_op::inter(Set_op &s1, Set_op &s2) {
    
    Set_op temp;
    for (int i = 0; i < s1.cnt; i++) {
        if (s2.search(s1.set_elements[i]) != -1) {
            temp.insert(s1.set_elements[i]);
        }
    }
    temp.display();
}

void Set_op::minus(Set_op &s1, Set_op &s2) {
    
    Set_op temp;
    for (int i = 0; i < s1.cnt; i++) {
        if (s2.search(s1.set_elements[i]) == -1) {
            temp.insert(s1.set_elements[i]);
        }
    }
    temp.display();
}

void Set_op::subset(Set_op &s1, Set_op &s2) {
    
    bool isSubset = true;
    for (int i = 0; i < s2.cnt; i++) {
        if (s1.search(s2.set_elements[i]) == -1) {
            isSubset = false;
            break;
        }
    }
    if (isSubset) {
        cout << "S2 is a subset of S1" << endl;
    } else {
        cout << "S2 is not a subset of S1" << endl;
    }
}

int main() {
    Set_op s1, s2, s3;
    int ch, no;

    do {
        cout << "****** MENU ******" << endl;
        cout << "1. Insert1" << endl;
        cout << "2. Insert2" << endl;
        cout << "3. Display" << endl;
        cout << "4. Size" << endl;
        cout << "5. Search" << endl;
        cout << "6. Remove" << endl;
        cout << "7. Union" << endl;
        cout << "8. Intersection" << endl;
        cout << "9. Minus" << endl;
        cout << "10. Subset" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch(ch) {
            case 1:
                cout << "Enter element to insert into set 1: ";
                cin >> no;
                s1.insert(no);
                break;
                
            case 2:
                cout << "Enter element to insert into set 2: ";
                cin >> no;
                s2.insert(no);
                break;
                
            case 3:
                cout << "Set 1: ";
                s1.display();
                cout << "Set 2: ";
                s2.display();
                break;
                
            case 4:
                s1.size();
                break;
                
            case 5:
                cout << "Enter the element to be searched: ";
                cin >> no;
                s1.search(no);
                break;
                
            case 6:
                s1.remove();
                break;
                
            case 7:
                s3.uni(s1, s2);
                cout << "Union of the sets: ";
                s3.display();
                break;
                
            case 8:
                cout << "Intersection of the sets: ";
                s3.inter(s1, s2);
                break;
                
            case 9:
                cout << "Minus of the sets: ";
                s3.minus(s1, s2);
                break;
                
            case 10:
                s3.subset(s1, s2);
                break;
                
            case 11:
                cout << "Exiting program." << endl;
                break;
                
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while(ch != 11);

    return 0;
}

