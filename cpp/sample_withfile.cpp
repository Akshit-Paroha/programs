#include <iostream>
#include <fstream>  // For file handling
#include <cstring>
using namespace std;

class student {
    public:
        int roll;
        char name[20];
};

int main() {
    student s;

    // Input from the user
    cout << "Enter roll no.: ";
    cin >> s.roll;
    cin.ignore(); // Ignore the newline character left in the input buffer by cin
    cout << "Enter name: ";
    cin.getline(s.name, 20);

    // Writing data to the file
    ofstream outFile("student_data.txt"); // Open the file for writing
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << s.roll << endl; // Write the roll number to the file
    outFile << s.name << endl; // Write the name to the file
    outFile.close();           // Close the file after writing

    // Inform the user
    cout << "Data written to file successfully." << endl;

    // Now let's read the data back from the file
    student s_read; // Create another student object to hold the read data
    ifstream inFile("student_data.txt"); // Open the file for reading
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    inFile >> s_read.roll;       // Read the roll number from the file
    inFile.ignore();             // Ignore the newline character left in the input buffer by >> 
    inFile.getline(s_read.name, 20); // Read the name from the file
    inFile.close();              // Close the file after reading

    // Display the data read from the file
    cout << "\nData read from file:\n";
    cout << "Roll no.: " << s_read.roll << endl;
    cout << "Name: " << s_read.name << endl;

    return 0;
}

