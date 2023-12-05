#include<algorithm>
#include<math.h>
#include<iostream>
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
        return ans;
    }
};
class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero center's x-y and radius
         */
        center.setX(0);
        center.setY(0);
        radius = 0;
    }

    Circle(Point center, double radius) : center(center) , radius(radius)
    {
        /*  
         * STUDENT ANSWER
         */
    }

    Circle(const Circle &circle)
    {
        /*  
         * STUDENT ANSWER
         */
        center = circle.getCenter();
        radius = circle.getRadius();
    }
    
    void setCenter(Point point)
    {
        /*  
         * STUDENT ANSWER
         */
        center = point;
    }

    void setRadius(double radius)
    {
        /*  
         * STUDENT ANSWER
         */
        this->radius = radius;
    }

    Point getCenter() const
    {
        /*  
         * STUDENT ANSWER
         */
        return this->center;
    }

    double getRadius() const
    {
        /*  
         * STUDENT ANSWER
         */
        return this->radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};

