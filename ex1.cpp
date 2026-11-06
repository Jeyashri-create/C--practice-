#include <iostream>
using namespace std;

class Student{
    private:
    int rollNo;
    string name;

    public:
    //Constructor
    Student(int r, string n){
        rollNo = r;
        name = n;
        cout << "Student Object created." << endl;
    }
    //display function
    void display(){
        cout << "Student Roll no: " << rollNo << endl;
        cout << "Student Name: " << name << endl;
    }
    //Destructor
    ~Student(){
        cout << "Student Object destroyed." << endl;
    }
};

int main(){
    Student s1(42, "Akshathaa");
    s1.display();
    Student s2(57, "Subieksha");
    s2.display();
    return 0;
}