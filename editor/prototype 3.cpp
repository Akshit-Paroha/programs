#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For getch() to mask password input
using namespace std;

class admin {
private:
    string username;
    string pass;

public:
    void login() {
        while (pass != "password" || username != "Admin") {
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            pass = maskPassword(); // Call to the masking function
            if (pass != "password" || username != "Admin") {
                cout << "\nInvalid credentials! Please try again.\n";
            }
        }
    }

    string maskPassword() {
        string password;
        char ch;
        while ((ch = getch()) != '\r') { // '\r' is the Enter key
            if (ch == '\b') { // Handle backspace
                if (!password.empty()) {
                    cout << "\b \b"; // Erase the last star
                    password.pop_back(); // Remove the last character from the password string
                }
            } else {
                password.push_back(ch); // Add the character to the password
                cout << '*'; // Show a star for each character
            }
        }
        cout << endl; // Move to the next line after pressing Enter
        return password; // Return the complete password
    }
};

class jewellery {
public:
    static int nextitem;
    string itemcode, itemname;
    int goldprice; // Current price of gold per gram in INR
    double weight, stoneprice, finalprice, qty;
    int stone, karat, item;

    jewellery() {
        goldprice = 7700;
        item = nextitem++;
    }

    void input() {
        cout << "Enter jewellery name: ";
        cin >> itemname;
        cout << "Enter gold weight of jewellery in grams: ";
        cin >> weight;
        cout << "Select your stone:\n1) Diamond\n2) Emerald\n3) Ruby\n4) Opal\n5) No stone\n";
        cin >> stone;
        cout << "Enter quantity: ";
        cin >> qty;
        cout << "Enter gold purity:\n1) 23+\n2) 18\n3) Lesser: ";
        cin >> karat;
        itemcode = "jw" + itemname + to_string(item);
        stoneprice = calculatestoneprice();
        finalprice = calculateprice();
    }

    double calculatestoneprice() {
        switch (stone) {
        case 1: return 25000;
        case 2: return 15000;
        case 3: return 20000;
        case 4: return 10000;
        default: return 0;
        }
    }

    double calculatekarat() {
        switch (karat) {
        case 1: return 0.95;
        case 2: return 0.75;
        default: return 0.5;
        }
    }

    int calculateprice() {
        return calculatekarat() * goldprice * weight * qty + stoneprice;
    }

    void displaydetails() {
        cout << "\nJewellery Name: " << itemname << endl;
        cout << "Jewellery Code: " << itemcode << endl;
        cout << "Price: " << finalprice << " INR" << endl;
    }

    void writefile() {
        ofstream ofile("details.txt", ios::app);
        if (!ofile) {
            cerr << "Failed to open file!" << endl;
        } else {
            ofile << "Jewellery Name: " << itemname << endl;
            ofile << "Jewellery Code: " << itemcode << endl;
            ofile << "Price: " << finalprice << " INR" << endl;
            ofile.close();
        }
    }
};

int jewellery::nextitem = 1001;

int main() {
    admin* ptra = new admin;
    ptra->login();
    delete ptra;

    jewellery j;
    j.input();
    j.displaydetails();
    j.writefile();

    return 0;
}
