// Abstract class: Employee cannot be created directly; every subclass must define salary().
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Employee {
protected:
    std::string name;
public:
    explicit Employee(const std::string& name) : name(name) {}
    virtual double salary() const = 0;   // pure virtual -> Employee is abstract
    virtual std::string type() const = 0;
    void payslip() const { std::cout << type() << " | " << name << " | salary: " << salary() << " PKR\n"; }
    virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
    double monthly;
public:
    FullTimeEmployee(const std::string& name, double monthly) : Employee(name), monthly(monthly) {}
    double salary() const override { return monthly; }
    std::string type() const override { return "Full-time"; }
};

class PartTimeEmployee : public Employee {
    int hours;
    double rate;
public:
    PartTimeEmployee(const std::string& name, int hours, double rate) : Employee(name), hours(hours), rate(rate) {}
    double salary() const override { return hours * rate; }
    std::string type() const override { return "Part-time"; }
};

int main() {
    std::vector<std::unique_ptr<Employee>> staff;
    staff.push_back(std::make_unique<FullTimeEmployee>("Sara", 85000));
    staff.push_back(std::make_unique<PartTimeEmployee>("Usman", 60, 700));
    staff.push_back(std::make_unique<FullTimeEmployee>("Hamza", 92000));

    double total = 0;
    for (const auto& e : staff) {
        e->payslip();
        total += e->salary();
    }
    std::cout << "Total payroll: " << total << " PKR\n";
    return 0;
}
