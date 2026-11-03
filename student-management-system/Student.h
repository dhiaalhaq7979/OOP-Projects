#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// A single student record. Data members are private (encapsulation);
// other code can only read or change them through the public methods.
class Student {
private:
    int id;
    std::string name;
    std::string department;
    int semester;
    double cgpa;

public:
    Student();
    Student(int id, const std::string& name, const std::string& department, int semester, double cgpa);

    int getId() const;
    std::string getName() const;
    std::string getDepartment() const;
    int getSemester() const;
    double getCgpa() const;

    void setName(const std::string& newName);
    void setDepartment(const std::string& newDepartment);
    bool setSemester(int newSemester);   // returns false if the value is invalid
    bool setCgpa(double newCgpa);        // returns false if the value is invalid

    std::string toCsv() const;
    static bool fromCsv(const std::string& line, Student& out);
    void print() const;
};

#endif
