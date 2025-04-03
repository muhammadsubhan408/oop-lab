#include <iostream>
#include <vector>
#include <math.h>
#define pi 3.142
using namespace std;
class Shape
{
public:
    string position;
    string color;
    double borderThickness;
    Shape(string p, string c, double t) : position(p), color(c), borderThickness(t) {};
    virtual void draw() = 0;
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;
};
class Circle : public Shape
{
public:
    double radius;
    double cx, cy;
    Circle(string p, string c, double t, double r, double cx, double cy) : Shape(p, c, t), radius(r), cx(cx), cy(cy) {};
    void draw() override
    {
        cout << "drawing a circle" << endl;
    }
    void calculateArea()
    {
        double area = pi * radius * radius;
        cout << "area:" << area << endl;
    }
    void calculatePerimeter()
    {
        double perimeter = 2 * pi * radius;
        cout << "perimeter:" << perimeter << endl;
    }
};
class Rectangle : public Shape
{
public:
    double width;
    double height;
    double cx, cy;
    Rectangle(string p, string c, double t, double w, double h, double cx, double cy) : Shape(p, c, t), width(w), height(h), cx(cx), cy(cy) {};
    void draw() override
    {
        cout << "drawing a rectangle" << endl;
    }
    void calculateArea()
    {
        double area = width * height;
        cout << "area:" << area << endl;
    }
    void calculatePerimeter()
    {
        double perimeter = 2 * (width + height);
        cout << "perimeter:" << perimeter << endl;
    }
};
// im assumin this to be equilateral for sake of simplicity
class Triangle : public Shape
{
public:
    double base;
    double height;
    Triangle(string p, string c, double t, double b, double h) : Shape(p, c, t), base(b), height(h) {};
    void draw() override
    {
        cout << "drawing a Triangle" << endl;
    }
    void calculateArea()
    {
        double area = 0.5 * base * height;
        cout << "area:" << area << endl;
    }
    void calculatePerimeter()
    {
        double perimeter = 3 * base; // all sides are equal for equilateral
        cout << "perimeter:" << perimeter << endl;
    }
};
class Polygon : public Shape
{
public:
    vector<double> sides;
    Polygon(string p, string c, double t, vector<double> sides) : Shape(p, c, t), sides(sides) {};
    void draw() override
    {
        cout << "drawing a Polygon" << endl;
    }
    void calculateArea()
    {
        double n = sides.size(); // number of sides
        double s = sides[0];     // assuming all sides are same
        // area=(n*sides*2/4*tan(pio/n))
        double area = (n * s * s) / (4 * tan(pi / n));
        cout << "area:" << area << endl;
    }
    void calculatePerimeter()
    {
        double n = sides.size();
        double perimeter = 0;
        for (int i = 0; i < n; i++)
        
        {
            perimeter += sides[i];
        }
        cout << "perimeter:" << perimeter << endl;
    }
};
int main()
{
    Circle circle("Circle1", "Red", 1.5, 5.0, 0.0, 0.0);
    circle.draw();
    circle.calculateArea();
    circle.calculatePerimeter();
    Rectangle rect("Rectangle1", "Blue", 2.0, 4.0, 6.0, 0.0, 0.0);
    rect.draw();
    rect.calculateArea();
    rect.calculatePerimeter();
    Triangle triangle("Triangle1", "Green", 1.0, 3.0, 4.0);
    triangle.draw();
    triangle.calculateArea();
    triangle.calculatePerimeter();
    vector<double> pentagonSides = {5.0, 5.0, 5.0, 5.0, 5.0};
    Polygon polygon("Polygon1", "Yellow", 1.0, pentagonSides);
    polygon.draw();
    polygon.calculateArea();
    polygon.calculatePerimeter();

    return 0;
    return 0;
}
