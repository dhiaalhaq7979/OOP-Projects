#include "StudentManager.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>

StudentManager::StudentManager(const std::string& fileName) : fileName(fileName) {}

int StudentManager::findIndex(int id) const {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) return static_cast<int>(i);
    }
    return -1;
}

bool StudentManager::addStudent(const Student& s) {
    if (findIndex(s.getId()) != -1) return false;   // IDs must be unique
    students.push_back(s);
    return true;
}

bool StudentManager::deleteStudent(int id) {
    int index = findIndex(id);
    if (index == -1) return false;
    students.erase(students.begin() + index);
    return true;
}

bool StudentManager::updateStudent(int id, const std::string& name, const std::string& department, int semester,
                                   double cgpa) {
    int index = findIndex(id);
    if (index == -1) return false;
    Student& s = students[index];
    if (!s.setSemester(semester) || !s.setCgpa(cgpa)) return false;
    s.setName(name);
    s.setDepartment(department);
    return true;
}

const Student* StudentManager::searchById(int id) const {
    int index = findIndex(id);
    return index == -1 ? nullptr : &students[index];
}

static std::string toLower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return std::tolower(c); });
    return text;
}

std::vector<Student> StudentManager::searchByName(const std::string& text) const {
    std::vector<Student> found;
    std::string key = toLower(text);
    for (const Student& s : students) {
        if (toLower(s.getName()).find(key) != std::string::npos) found.push_back(s);
    }
    return found;
}

void StudentManager::displayAll() const {
    if (students.empty()) {
        std::cout << "No students found.\n";
        return;
    }
    std::cout << "ID    Name                  Department        Semester  CGPA\n";
    std::cout << "----  --------------------  ----------------  --------  ----\n";
    for (const Student& s : students) s.print();
}

int StudentManager::count() const { return static_cast<int>(students.size()); }

bool StudentManager::saveToFile() const {
    std::ofstream file(fileName);
    if (!file) return false;
    file << "id,name,department,semester,cgpa\n";
    for (const Student& s : students) file << s.toCsv() << '\n';
    return true;
}

int StudentManager::loadFromFile() {
    std::ifstream file(fileName);
    if (!file) return 0;
    students.clear();
    std::string line;
    std::getline(file, line);   // skip the header
    while (std::getline(file, line)) {
        Student s;
        if (!line.empty() && Student::fromCsv(line, s)) students.push_back(s);
    }
    return count();
}
