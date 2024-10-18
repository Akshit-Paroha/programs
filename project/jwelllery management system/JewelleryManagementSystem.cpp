#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class admin
{
protected:
    string username;
    string pass;

public:
    virtual void login()
    {
        while (pass != "password" || username != "Admin")
        {
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            pass = maskPassword();
            if (pass != "password" || username != "Admin")
            {
                cerr << "\nInvalid credentials! Please try again.\n";
            }
        }
    }

    string maskPassword()
    {
        string password;
        char ch;
        while ((ch = getch()) != '\r')
        {
            if (ch == '\b')
            {
                if (!password.empty())
                {
                    cout << "\b \b";
                    password.pop_back();
                }
            }
            else
            {
                password.push_back(ch);
                cout << '*';
            }
        }
        cout << endl<< endl;
        return password;
    }

    virtual ~admin() {}
};

class jewellery : public admin
{
public:
    string itemcode, itemname;
    int goldprice;
    double weight, stoneprice, finalprice, qty;
    int stone, karat;

    jewellery()
    {
        goldprice = 7700;
    }

    void input()
    {
        cout << "Enter jewellery name: ";
        cin >> itemname;
        cout << "Enter gold weight of jewellery in grams: ";
        cin >> weight;
        cout << "Select your stone:\n1) Diamond\n2) Emerald\n3) Ruby\n4) Opal\n5) No stone\n";
        cin >> stone;
        cout << "Enter quantity: ";
        cin >> qty;
        cout << "Enter gold purity:\n1) 23+\n2) 22\n3) 21\n4) 20\n5) 18\n6) lesser\nSelect Your option: ";
        cin >> karat;

        int lineCount = countLines("itemcode.txt");
        itemcode = "jw" + itemname + to_string(lineCount + 1);
        stoneprice = calculatestoneprice();
        finalprice = calculateprice();
    }

    double calculatestoneprice()
    {
        switch (stone)
        {
        case 1:
            return 25000;
        case 2:
            return 15000;
        case 3:
            return 20000;
        case 4:
            return 10000;
        default:
            return 0;
        }
    }

    double calculatekarat()
    {
        switch (karat)
        {
        case 1:
            return 0.96;
        case 2:
            return 0.91;
        case 3:
            return 0.90;
        case 4:
            return 0.84;
        case 5:
            return 0.75;
        default:
            return 0.5;
        }
    }

    double calculateprice()
    {
        return calculatekarat() * goldprice * weight * qty + stoneprice *1.08; //1.08 multiplied for 3% tax and 5% making charges
    }

    void display()
    {
        cout << "Item Name: " << itemname << endl;
        cout << "Item Code: " << itemcode << endl;
        cout << "Gold Weight: " << weight << " grams" << endl;
        cout << "Quantity: " << qty << endl;
        cout << "Final Price: " << finalprice << endl;
    }

    int countLines(const string &filename)
    {
        ifstream file(filename);
        int count = 100;
        string line;
        while (getline(file, line))
        {
            ++count;
        }
        return count;
    }
};

class inventory : public jewellery
{
public:
    void addItem()
    {
        input();
        ofstream ofile("inventory.txt", ios::app);
        ofstream codeFile("itemcode.txt", ios::app);
        if (!ofile || !codeFile)
        {
            cerr << "Failed to open file!" << endl;
            return;
        }
        ofile << itemname << "|" << itemcode << "|" << finalprice << "|" << qty << endl;
        codeFile << itemcode << endl;
        ofile.close();
        codeFile.close();

        cout << "\nItem added to inventory:\n";
        display();
    }

    void readfile()
    {
        ifstream ifile("inventory.txt");
        if (!ifile)
        {
            cerr << "Failed to open file!" << endl;
            return;
        }
        string line;
        while (getline(ifile, line))
        {
            cout << line << endl;
        }
        ifile.close();
    }

    void searchitem()
    {
        ifstream i("inventory.txt");
        if (!i)
        {
            cerr << "Failed to open file" << endl;
            return;
        }
        string searchCode;
        cout << "Enter the jewellery code to search: ";
        cin >> searchCode;
        string line;
        bool found = false;
        while (getline(i, line))
        {
            if (line.find(searchCode) != string::npos)
            {
                cout << "Item Name|Item Code|Price|Quantity" << endl;
                cout << line << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Can't find the given item code in the file" << endl;
        }
        i.close();
    }
};

class customer : public admin
{
public:
    string residentialAddress;

    void getCustomerDetails(double totalAmount, const string &itemName, const string &itemCode, double itemPrice)
    {
        string customerName, contactNumber;
        cout << "\nEnter customer name: ";
        cin >> customerName;
        cout << "Enter contact number: ";
        cin >> contactNumber;
        cout << "Enter residential address: ";
        cin.ignore();
        getline(cin, residentialAddress);

        ofstream customerFile(customerName + "_details.txt", ios::app);
        customerFile << "Customer Name: " << customerName << endl;
        customerFile << "Contact Number: " << contactNumber << endl;
        customerFile << "Residential Address: " << residentialAddress << endl;
        customerFile << "Purchased Item: " << itemName << endl;
        customerFile << "Item Code: " << itemCode << endl;
        customerFile << "Item Price: " << itemPrice << endl;
        customerFile << "Total Purchase Amount: " << totalAmount << endl;
        customerFile << "------------------------" << endl;
        customerFile.close();
    }

    void viewCustomerDetails()
    {
        string customerName;
        cout << "Enter the customer's name to view details: ";
        cin >> customerName;

        ifstream customerFile(customerName + "_details.txt");
        if (!customerFile)
        {
            cerr << "Failed to open customer details file!" << endl;
            return;
        }
        string line;
        while (getline(customerFile, line))
        {
            cout << line << endl;
        }
        customerFile.close();
    }
};

class sales : public jewellery, public customer
{
public:

    void createBill(inventory &inv, customer &cust)
    {
        char choice;
        ofstream billFile("salesrecord.txt", ios::app);
        double totalAmount = 0;
        jewellery j;
        do
        {
            int option;
            cout << "\n1. Select item from inventory\n2. Add a customized item\nChoose an option: ";
            cin >> option;

            switch (option)
            {
            case 1:
            {
                inv.readfile();
                cout << "\nEnter the code of the item you want to add: ";
                string code;
                cin >> code;
                ifstream ifile("inventory.txt");
                string line;
                bool found = false;
                while (getline(ifile, line))
                {
                    if (line.find(code) != string::npos)
                    {
                        size_t pos = 0;
                        string itemName, itemCode;
                        double price;
                        int qty;

                        pos = line.find('|');
                        itemName = line.substr(0, pos);
                        line.erase(0, pos + 1);

                        pos = line.find('|');
                        itemCode = line.substr(0, pos);
                        line.erase(0, pos + 1);

                        pos = line.find('|');
                        price = stod(line.substr(0, pos));
                        line.erase(0, pos + 1);

                        qty = stoi(line);

                        billFile << itemName << "|" << itemCode << "|" << price << "|" << qty << endl;
                        totalAmount += price;

                        cust.getCustomerDetails(totalAmount, itemName, itemCode, price);
                        found = true;
                        break;
                    }
                }
                ifile.close();
                if (!found)
                {
                    cout << "Item not found in inventory." << endl;
                }
                break;
            }
            case 2:
                j.input();
                billFile << j.itemname << "|" << j.itemcode << "|" << j.finalprice << "|" << j.qty << endl;
                totalAmount += j.finalprice;
                cust.getCustomerDetails(totalAmount, j.itemname, j.itemcode, j.finalprice);
                break;

            default:
                cout << "Invalid option! Please try again." << endl;
                break;
            }

            cout << "\nDo you want to add another item to the bill? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        cout << "\nTotal Amount: " << totalAmount << endl;
        billFile << "Total Amount: " << totalAmount << endl;
        billFile.close();

        cout << "Bill created and saved successfully!" << endl;
    }

    void viewSalesReport()
    {
        ifstream salesFile("salesrecord.txt");
        if (!salesFile)
        {
            cerr << "Failed to open sales record file!" << endl;
            return;
        }
        string line;
        while (getline(salesFile, line))
        {
            cout << line << endl;
        }
        salesFile.close();
    }
};

int main()
{
    admin *ptra = new admin();
    ptra->login();
    inventory inv;
    sales s;
    customer cust;

    int choice;
    do
    {
        cout << "\n1. Create Bill\n2. Add Item to Inventory\n3. View Inventory\n4. Search Item in Inventory\n5. View Sales Report\n6. Open Customer Details\n7. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.createBill(inv, cust);
            break;
        case 2:
            inv.addItem();
            break;
        case 3:
            inv.readfile();
            break;
        case 4:
            inv.searchitem();
            break;
        case 5:
            s.viewSalesReport();
            break;
        case 6:
            cust.viewCustomerDetails();
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    delete ptra;
    return 0;
}