#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Define a class with some attributes
class Student {
public:
    string name;
    int age; 
    float grade;

    // Constructor
    Student() : name(""), age(0), grade(0.0f) {}

    Student(const string& name, int age, float grade) : name(name), age(age), grade(grade) {}

    // Overload the << operator for writing to a file
    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.name << "\n" << student.age << "\n" << student.grade << "\n";
        return os;
    }

    // Overload the >> operator for reading from a file
    friend istream& operator>>(istream& is, Student& student) {
        getline(is, student.name);
        is >> student.age;
        is >> student.grade;
        is.ignore();  // To ignore the leftover newline character
        return is;
    }
};

int main() {
    
    Student student1("Alice", 20, 85.5f);

    // Step 1: Store the object in a file
    ofstream outFile("student.dat");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    // Write the student object to the file
    outFile << student1;
    outFile.close();  // Close the file after writing

    // Step 2: Retrieve the object from the file
    Student student2;
    ifstream inFile("student.dat");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
 
    // Read the student object from the file
    inFile >> student2;
    inFile.close();  // Close the file after reading

    // Display the object data read from the file
    cout << "Student details read from file:\n";
    cout << "Name: " << student2.name << "\n";
    cout << "Age: " << student2.age << "\n";
    cout << "Grade: " << student2.grade << endl;
    return 0;
}

