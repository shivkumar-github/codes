// Multilevel Inheritance deep dive with examples

#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int r)
    {
        roll_number = r;
    }
    void get_roll_number()
    {
        cout << "The roll number is :" << roll_number << endl;
    }
};

class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }
    void get_marks()
    {
        cout << "The marks obtained in maths are :" << maths << endl;
        cout << "The marks obtained in physics are :" << physics << endl;
    }
};

class Result : public Exam
{
    float percentage;

public:
    void displayresult()
    {
        get_roll_number();

        cout << "Your percentage is :" << (maths + physics) / 2 << "%" << endl;
    }
};

int main()
{
    Result harry;
    harry.set_roll_number(420);
    harry.set_marks(99.9, 100);
    harry.displayresult();
    return 0;
}
/*
Notes:-
If we are inheriting B from A and C from B  [A ---> B ---> C]
1. A is the base class for A and B is base class for C
2. ABC is called inheritance path
*/