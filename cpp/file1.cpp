#include <iostream>
#include <fstream>  // Include fstream for file operations
#include <string>   // Include string for working with text

int main() {
    // Step 1: Writing to a file
    std::ofstream outputFile("example.txt");  // Create and open a text file for writing
    if (!outputFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;  // Exit the program if file cannot be opened
    }

    // Writing data to the file
    outputFile << "Hello, this is a file management example in C++!\n";
    outputFile << "You are learning file handling." << std::endl;
    outputFile.close();  // Close the file after writing

    // Step 2: Reading from a file
    std::ifstream inputFile("example.txt");  // Open the same file for reading
    if (!inputFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;  // Exit if file cannot be opened
    }

    // Reading data from the file
    std::string line;
    std::cout << "Contents of the file:\n";
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;  // Print each line to the console
    }
    inputFile.close();  // Close the file after reading

    return 0;  // End of the program
}

