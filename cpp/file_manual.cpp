#include <iostream>
#include <fstream>
using namespace std;
int main() {
 ofstream outFile("data.txt",ios::app); // Creating and opening a file for writing
 if (!outFile) {
 cout << "File could not be opened." << endl;
 return 1;
 }
 string name;
 int age;
 string address;
 cout << "Enter your name: ";
 getline(cin, name);
 cout << "Enter your age: ";
 cin >> age;
 cin.ignore(); // Ignore the newline character left by cin
 cout << "Enter your address: ";
 getline(cin, address);
 outFile << "Name: " << name << endl;
 outFile << "Age: " << age << endl;
 outFile << "Address: " << address << endl;
 outFile.close(); // Closing the file
 cout << "Data written to file successfully." << endl;
 return 0;
}

