// Student Management System - console application
// Author: Dhia Alhaq Saleh Al-Hindrish
#include <iostream>
#include <limits>
#include <string>

#include "StudentManager.h"

static int readInt(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        if (std::cin.eof()) return -1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

static double readDouble(const std::string& prompt) {
    double value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        if (std::cin.eof()) return -1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

static std::string readLine(const std::string& prompt) {
    std::string text;
    std::cout << prompt;
    std::getline(std::cin, text);
    return text;
}

static void showMenu() {
    std::cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========\n"
              << "1. Add student\n"
              << "2. Display all students\n"
              << "3. Search student by ID\n"
              << "4. Search student by name\n"
              << "5. Update student\n"
              << "6. Delete student\n"
              << "7. Save to file\n"
              << "0. Exit\n";
}

int main() {
    StudentManager manager("students.csv");
    std::cout << "Loaded " << manager.loadFromFile() << " student(s) from students.csv\n";

    while (true) {
        showMenu();
        int choice = readInt("Enter your choice: ");
        if (choice == 0 || choice == -1) {
            manager.saveToFile();
            std::cout << "Data saved. Goodbye!\n";
            break;
        }
        switch (choice) {
            case 1: {
                int id = readInt("ID: ");
                std::string name = readLine("Name: ");
                std::string dept = readLine("Department: ");
                int sem = readInt("Semester (1-8): ");
                double cgpa = readDouble("CGPA (0-4): ");
                Student s(id, name, dept, sem, cgpa);
                if (s.getSemester() != sem || s.getCgpa() != cgpa)
                    std::cout << "Invalid semester or CGPA.\n";
                else if (manager.addStudent(s))
                    std::cout << "Student added successfully.\n";
                else
                    std::cout << "A student with this ID already exists.\n";
                break;
            }
            case 2:
                manager.displayAll();
                break;
            case 3: {
                const Student* s = manager.searchById(readInt("Enter ID: "));
                if (s) s->print();
                else std::cout << "Student not found.\n";
                break;
            }
            case 4: {
                auto list = manager.searchByName(readLine("Enter name (or part of it): "));
                if (list.empty()) std::cout << "No match.\n";
                for (const Student& s : list) s.print();
                break;
            }
            case 5: {
                int id = readInt("ID to update: ");
                std::string name = readLine("New name: ");
                std::string dept = readLine("New department: ");
                int sem = readInt("New semester: ");
                double cgpa = readDouble("New CGPA: ");
                std::cout << (manager.updateStudent(id, name, dept, sem, cgpa) ? "Student updated.\n"
                                                                                 : "Update failed (not found or invalid data).\n");
                break;
            }
            case 6:
                std::cout << (manager.deleteStudent(readInt("ID to delete: ")) ? "Student deleted.\n" : "Student not found.\n");
                break;
            case 7:
                std::cout << (manager.saveToFile() ? "Saved to students.csv\n" : "Could not save file.\n");
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    }
    return 0;
}
