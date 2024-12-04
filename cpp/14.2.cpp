#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void openFile(const string &fileName)
{
    ifstream file(fileName); // Use the provided file name

    if (!file.is_open())
    {
        throw runtime_error("File could not be opened or does not exist!");
    }

    string line;
    cout << "File opened successfully! Reading file content:\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

int main()
{
    string fileName;
    cout << "Enter the file name to open: ";
    cin >> fileName;

    try
    {
        openFile(fileName);
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "An unexpected error occurred while opening the file!" << endl;
    }

    return 0;
}
