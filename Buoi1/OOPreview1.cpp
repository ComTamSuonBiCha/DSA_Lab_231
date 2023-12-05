#include<algorithm>
#include<math.h>
class Point
{
private:
    double x, y;

public:
    Point()
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero x-y coordinate
         */
        x = 0;
        y = 0;
    }

    Point(double x, double y) : x(x) , y(y)
    {
        /*  
         * STUDENT ANSWER
         */
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */
        this->x=x;
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
        this->y=y;
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
        return x;
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
        double ans = sqrt(pow(pointA.getX()-this->getX(),2) + pow(pointA.getY()-this->getY(),2));
    }
};