#include <iostream>
using namespace std;

namespace MyApp{
    class Student{
        private:
        int id;
        string name;
        static int count;

        public:
        Student(int i, string n) : id(i), name(n){
            count ++;
            cout << "Constructor called for: " << this -> name << endl;
        }

        Student(const Student &s){
            this -> id = s.id;
            this -> name = s.name;
            count++;
            cout << "Copy Constructor called for: " << this -> name << endl;
        }

        ~Student(){
            count--;
            cout << "Destructor called for: " << this -> name << endl;
        }

        void display() const{
            cout << "ID: " << id << ", Name: " << name << " (Total: "<< count << ")\n";
        }

        static int getCount(){ return count;}
        friend void show(const Student& s);
    };
    int Student::count = 0;
    void show(const Student& s){
            cout << "[Friend] Name: " << s.name << ", ID: " << s.id << endl;
    }
}

int main(){
    MyApp::Student s1(101, "Chetan");
    s1.display();
    MyApp::Student s2 =s1;
    show(s1);
    cout << "Students created: " << MyApp::Student::getCount() << endl;
    return 0;
}