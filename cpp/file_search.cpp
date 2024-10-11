#include <iostream>
#include <fstream>  // For file handling
#include <cstring>
using namespace std;

class student {
    public:
        int roll;
        char name[20];
};

void addStudentData() {
    student s;

    // Input from the user
    cout << "Enter roll no.: ";
    cin >> s.roll;
    cin.ignore(); // Ignore the newline character left in the input buffer by cin
    cout << "Enter name: ";
    cin.getline(s.name, 20);

    // Writing data to the file in append mode
    ofstream outFile("student_data.txt", ios::app); // Open the file in append mode
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    // Write the student's data to the file
    outFile << s.roll << endl;
    outFile << s.name << endl;

    outFile.close(); // Close the file after writing
    cout << "Data appended to file successfully." << endl;
}

void searchStudentData(int roll_no) {
    student s;
    ifstream inFile("student_data.txt"); // Open the file for reading
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    bool found = false;  // Variable to check if the student is found

    // Read the data from the file and search for the student by roll number
    while (inFile >> s.roll) {
        inFile.ignore(); // Ignore the newline character
        inFile.getline(s.name, 20);

        if (s.roll == roll_no) {
            // If the roll number matches, display the student's details
            cout << "Student found:\n";
            cout << "Roll no.: " << s.roll << endl;
            cout << "Name: " << s.name << endl;
            found = true;
            break;  // Stop searching after finding the student
        }
    }

    if (!found) {
        cout << "No student found with roll no.: " << roll_no << endl;
    }

    inFile.close(); // Close the file after reading
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add new student data\n";
        cout << "2. Search student by roll number\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentData();  // Add new student data to the file
                break;
            case 2: {
                int roll_no;
                cout << "Enter roll no. to search: ";
                cin >> roll_no;
                searchStudentData(roll_no);  // Search for a specific student by roll number
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

