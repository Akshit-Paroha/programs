#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
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
            pass = maskPassword();
            if (pass != "password" || username != "Admin") {
                cerr << "\nInvalid credentials! Please try again.\n";
            }
        }
    }

    string maskPassword() {
        string password;
        char ch;
        while ((ch = getch()) != '\r') {
            if (ch == '\b') {
                if (!password.empty()) {
                    cout << "\b \b";
                    password.pop_back();
                }
            } else {
                password.push_back(ch);
                cout << '*';
            }
        }
        cout << endl << endl;
        return password;
    }
};

class jewellery {
public:
    static int nextitem;
    string itemcode, itemname;
    int goldprice;
    double weight, stoneprice, finalprice, qty;
    int stone, karat, item;

    jewellery() {
        goldprice = 7700;
        item = nextitem;
        nextitem++;
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
        cout << "Enter gold purity:\n1) 23+\n2)22 \n3)21 \n4)20\n5)18\n6)lesser\nSelect Your option: ";
        cin >> karat;
        itemcode = "jw" + itemname + to_string(item);
        stoneprice = calculatestoneprice();
        finalprice = calculateprice();
        writefile();
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
            case 1: return 0.96;
            case 2: return 0.91;
            case 3: return 0.90;
            case 4: return 0.84;
            case 5: return 0.75;
            default: return 0.5;
        }
    }

    int calculateprice() {
        return calculatekarat() * goldprice * weight * qty + stoneprice;
    }

    void writefile() {
        ofstream ofile("details.txt");
        if (!ofile) {
            cerr << "Failed to open file!" << endl;
            return;
        }

        ofile << "Item Name: " << itemname << "|";
        ofile << "Item code: " << itemcode << "|";
        ofile << "Final price: " << finalprice << endl;
        ofile.close();
    }

    void readfile() {
        ifstream ifile("details.txt");
        if (!ifile) {
            cerr << "Failed to open file!" << endl;
            return;
        }
        string line;
        while (getline(ifile, line)) {
            cout << line << endl;
        }
        ifile.close();
    }

    static void setNextItem() {
        ifstream codeFile("itemcode.txt");
        nextitem = 1;

        if (codeFile) {
            string line;
            int lineCount = 0;

            while (getline(codeFile, line)) {
                lineCount++;
            }
            nextitem = lineCount + 1;
            codeFile.close();
        }
    }
};

int jewellery::nextitem = 101;

class inventory {
public:
    void writefile(jewellery& j) {
        ofstream ofile("inventory.txt", ios::app);
        if (!ofile) {
            cerr << "Failed to open file!" << endl;
            return;
        }

        ofile << j.itemname << "|";
        ofile << j.itemcode << "|";
        ofile << j.finalprice << endl;
        ofile.close();
    }

    void readfile() {
        ifstream ifile("inventory.txt");
        if (!ifile) {
            cerr << "Failed to open file!" << endl;
            return;
        }
        string line;
        while (getline(ifile, line)) {
            cout << line << endl;
        }
        ifile.close();
    }

    void searchitem() {
        ifstream i("inventory.txt");
        if (!i) {
            cerr << "Failed to open file" << endl;
            return;
        }
        string searchCode;
        string line;
        bool found = false;
        cout << "Enter the jewellery code to search: ";
        cin >> searchCode;
        while (getline(i, line)) {
            if (line.find(searchCode) != string::npos) {
                cout << "Item Name|Item Code|Price" << endl;
                cout << line << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Can't find the given item code in the file" << endl;
        }
        i.close();
    }
};

int main() {
    jewellery::setNextItem();

    admin* ptra = new admin;
    ptra->login();
    delete ptra;

    jewellery j;
    j.input();
    j.readfile();

    inventory inv;
    inv.writefile(j);
    inv.readfile();
    inv.searchitem();

    return 0;
}
