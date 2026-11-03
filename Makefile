CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SMS_SRC = student-management-system/main.cpp student-management-system/Student.cpp student-management-system/StudentManager.cpp
DEMOS = encapsulation inheritance polymorphism abstract

all: build/sms $(addprefix build/,$(DEMOS))

build/sms: $(SMS_SRC)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SMS_SRC) -o $@

build/encapsulation: oop-concepts/01_encapsulation_bank_account.cpp
	mkdir -p build && $(CXX) $(CXXFLAGS) $< -o $@
build/inheritance: oop-concepts/02_inheritance_vehicles.cpp
	mkdir -p build && $(CXX) $(CXXFLAGS) $< -o $@
build/polymorphism: oop-concepts/03_polymorphism_shapes.cpp
	mkdir -p build && $(CXX) $(CXXFLAGS) $< -o $@
build/abstract: oop-concepts/04_abstract_class_employees.cpp
	mkdir -p build && $(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf build
