// Code Example Demonctrating Virtual Base class in C++

#include <iostream>
using namespace std;

/*
Inheritances are as follows :-
Student-->Test
Student-->Sports
Test-->Result
Sports-->Result
*/

class Student
{
protected:
    int roll_no;

public:
    void set_roll_no(int a)
    {
        roll_no = a;
    }
    void print_roll_no(void)
    {
        cout << "Your roll number is : " << roll_no << endl;
    }
};

// To avoid errors due to double occurence of variable roll_no
class Test : virtual public Student
{ // It is also right if we write public virtual
protected:
    float Maths, Physics;

public:
    void set_marks(float m1, float m2)
    {
        Physics = m1;
        Maths = m2;
    }
    void print_marks()
    {
        cout << "Your marks are : " << endl
             << "1. Physics : " << Physics << endl
             << "2. Maths : " << Maths << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float Sports_score;

public:
    void set_Sports_score(float sc)
    {
        Sports_score = sc;
    }
    void print_Sports_score()
    {
        cout << "Your PT score is : " << Sports_score << endl;
    }
};

class Result : public Test, public Sports
{
private:
    float total;

public:
    void displayResult()
    {
        total = Maths + Physics + Sports_score;
        print_roll_no();
        print_marks();
        print_Sports_score();
        cout << "Your total result is : " << total << endl;
    }
};

int main()
{
    cout << endl;

    Result shivkumar;
    shivkumar.set_roll_no(53);
    shivkumar.set_marks(90, 78);
    shivkumar.set_Sports_score(88);
    shivkumar.displayResult();
    cout << endl;
    return 0;
}