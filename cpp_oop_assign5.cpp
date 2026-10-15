
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;

    static int count;

public:
    Student(int rollNo, string name) {
        this->rollNo = rollNo;
        this->name = name;
        count++;
    }

    // Inline function
    inline void showRollNo() {
        cout << "Roll Number: " << rollNo << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }

    // Static member function
    static void showCount() {
        cout << "Total Student Objects: " << count << endl;
    }

    // Friend class declaration
    friend class StudentViewer;
};

// Definition of static data member
int Student::count = 0;

// Friend class
class StudentViewer {
public:
    void showPrivateDetails(Student s) {
        cout << "Friend Class Access:" << endl;
        cout << "Name: " << s.name << endl;
        cout << "Roll Number: " << s.rollNo << endl;
    }
};

int main() {
    Student s1(50, "Samruddhi");
    Student s2(51, "Aarav");

    cout << "Student 1 Details:" << endl;
    s1.display();

    cout << endl << "Inline Function Example:" << endl;
    s1.showRollNo();

    cout << endl << "Static Member Function Example:" << endl;
    Student::showCount();

    cout << endl;
    StudentViewer viewer;
    viewer.showPrivateDetails(s2);

    return 0;
}
