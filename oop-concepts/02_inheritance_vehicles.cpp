// Inheritance: Car and Motorbike reuse everything from Vehicle and add their own details.
#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;
    int year;

public:
    Vehicle(const std::string& brand, int year) : brand(brand), year(year) {}
    void showBasic() const { std::cout << brand << " (" << year << ")"; }
};

class Car : public Vehicle {
    int doors;

public:
    Car(const std::string& brand, int year, int doors) : Vehicle(brand, year), doors(doors) {}
    void show() const {
        std::cout << "Car: ";
        showBasic();
        std::cout << ", doors: " << doors << '\n';
    }
};

class Motorbike : public Vehicle {
    int engineCc;

public:
    Motorbike(const std::string& brand, int year, int engineCc) : Vehicle(brand, year), engineCc(engineCc) {}
    void show() const {
        std::cout << "Motorbike: ";
        showBasic();
        std::cout << ", engine: " << engineCc << " cc\n";
    }
};

int main() {
    Car car("Toyota Corolla", 2022, 4);
    Motorbike bike("Honda CG", 2021, 125);
    car.show();
    bike.show();
    return 0;
}
