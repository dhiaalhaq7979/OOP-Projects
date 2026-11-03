// Polymorphism: one pointer type (Shape*) calls the right area() for each object at run time.
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual double area() const = 0;
    virtual const char* name() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double r) : r(r) {}
    double area() const override { return 3.14159265 * r * r; }
    const char* name() const override { return "Circle"; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() const override { return w * h; }
    const char* name() const override { return "Rectangle"; }
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    const char* name() const override { return "Triangle"; }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 3.0));
    shapes.push_back(std::make_unique<Triangle>(6.0, 5.0));

    double total = 0;
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& s : shapes) {
        std::cout << std::left << std::setw(10) << s->name() << " area = " << s->area() << '\n';
        total += s->area();
    }
    std::cout << "Total area = " << total << '\n';
    return 0;
}
