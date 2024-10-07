#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For getch()
using namespace std;

class admin
{
private:
    string username;
    string pass;

public:
    void login()
    {
        while (pass != "password" || username != "Admin")
        {
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            pass = maskPassword();
            if (pass != "password" || username != "Admin")
            {
                cout << "\nInvalid credentials! Please try again.\n";
            }
        }
    }

    string maskPassword()
    {
        string password;
        char ch;
        while ((ch = getch()) != '\r') // '\r' is the Enter key
        {
            if (ch == '\b') // '\b' is the Backspace key
            {
                if (!password.empty())
                {
                    cout << "\b \b"; // Moves cursor back, prints space, and moves back again
                    password.pop_back();
                }
            }
            else
            {
                password.push_back(ch);
                cout << '*';
            }
        }
        cout << endl; // Move to the next line after pressing Enter
        return password;
    }
};
