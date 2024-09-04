//

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void displaypoint()
    {
        cout << "The point is (" << x << ", " << y << ")" << endl;
    }
    friend float calculatedist(Point p, Point q); 
};
float calculatedist(Point p, Point q){
    float sqrdistance=((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
float distance=sqrt(sqrdistance);
return distance;
}
//create a function (hint : make it a friend function) which interprates the distance between two points
int main()
{
    Point p(1, 1);
    p.displaypoint();
    Point q(4, 6);
    q.displaypoint();
    cout << "The distance between two points is : " << calculatedist(p,q) << endl;
    return 0;
}

// sqrt() is a function defined in the standard library <cmath>
// cmath also have other math functions like tan,sin,atan ( means arctan ), pow()