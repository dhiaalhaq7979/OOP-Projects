#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <string>
#include <vector>

#include "Student.h"

// Keeps all students in memory and saves / loads them from a CSV file.
class StudentManager {
private:
    std::vector<Student> students;
    std::string fileName;

    int findIndex(int id) const;

public:
    explicit StudentManager(const std::string& fileName);

    bool addStudent(const Student& s);
    bool deleteStudent(int id);
    bool updateStudent(int id, const std::string& name, const std::string& department, int semester, double cgpa);
    const Student* searchById(int id) const;
    std::vector<Student> searchByName(const std::string& text) const;
    void displayAll() const;
    int count() const;

    bool saveToFile() const;
    int loadFromFile();
};

#endif
