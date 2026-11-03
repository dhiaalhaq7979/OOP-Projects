#include "Student.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

Student::Student() : id(0), name(""), department(""), semester(1), cgpa(0.0) {}

Student::Student(int id, const std::string& name, const std::string& department, int semester, double cgpa)
    : id(id), name(name), department(department), semester(1), cgpa(0.0) {
    setSemester(semester);
    setCgpa(cgpa);
}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
std::string Student::getDepartment() const { return department; }
int Student::getSemester() const { return semester; }
double Student::getCgpa() const { return cgpa; }

void Student::setName(const std::string& newName) { name = newName; }
void Student::setDepartment(const std::string& newDepartment) { department = newDepartment; }

bool Student::setSemester(int newSemester) {
    if (newSemester < 1 || newSemester > 8) return false;
    semester = newSemester;
    return true;
}

bool Student::setCgpa(double newCgpa) {
    if (newCgpa < 0.0 || newCgpa > 4.0) return false;
    cgpa = newCgpa;
    return true;
}

std::string Student::toCsv() const {
    std::ostringstream out;
    out << id << ',' << name << ',' << department << ',' << semester << ','
        << std::fixed << std::setprecision(2) << cgpa;
    return out.str();
}

bool Student::fromCsv(const std::string& line, Student& out) {
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, ',')) parts.push_back(item);
    if (parts.size() != 5) return false;
    try {
        out = Student(std::stoi(parts[0]), parts[1], parts[2], std::stoi(parts[3]), std::stod(parts[4]));
    } catch (...) {
        return false;
    }
    return true;
}

void Student::print() const {
    std::cout << std::left << std::setw(6) << id << std::setw(22) << name << std::setw(18) << department
              << std::setw(10) << semester << std::fixed << std::setprecision(2) << cgpa << '\n';
}
