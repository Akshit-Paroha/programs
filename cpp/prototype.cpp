#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Admin Class
class Admin {
private:
    string username;
    string password;

public:
    Admin(string uname, string pass) : username(uname), password(pass) {}

    bool login(string input_username, string input_password) {
        return (username == input_username && password == input_password);
    }
};

// Jewellery Class
class Jewellery {
private:
    string itemCode;
    string itemName;
    float basePrice;
    int karat;
    string stoneType;
    int quantity;
    float finalPrice;

public:
    Jewellery(string code, string name, float price, int karatValue, string stone, int qty) 
        : itemCode(code), itemName(name), basePrice(price), karat(karatValue), stoneType(stone), quantity(qty) {
        finalPrice = calculateFinalPrice();
    }

    float calculateFinalPrice() {
        float karatMultiplier = (karat == 24) ? 1.0 : 0.9; // Example multiplier
        float stonePrice = 0.0;
        
        if (stoneType == "diamond") {
            stonePrice = 1000;
        } else if (stoneType == "ruby") {
            stonePrice = 500;
        } else if (stoneType == "opal") {
            stonePrice = 300;
        }

        return (basePrice * karatMultiplier) + stonePrice;
    }

    void displayDetails() {
        cout << "Item: " << itemName << ", Final Price: $" << finalPrice << ", Quantity: " << quantity << endl;
    }

    string getItemCode() {
        return itemCode;
    }

    int getQuantity() {
        return quantity;
    }

    void setQuantity(int qty) {
        quantity = qty;
    }
};

// Inventory Class
class Inventory {
private:
    vector<Jewellery> items;

public:
    void addItem(Jewellery jewellery) {
        items.push_back(jewellery);
    }

    void updateStock(string itemCode, int newQuantity) {
        for (auto& item : items) {
            if (item.getItemCode() == itemCode) {
                item.setQuantity(newQuantity);
                cout << "Stock updated for item: " << itemCode << endl;
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    Jewellery* getItemByCode(string itemCode) {
        for (auto& item : items) {
            if (item.getItemCode() == itemCode) {
                return &item;
            }
        }
        return nullptr;
    }

    void displayInventory() {
        for (auto& item : items) {
            item.displayDetails();
        }
    }
};

// Customer Class
class Customer {
private:
    string name;
    string contactNumber;

public:
    Customer(string cname, string cnumber) : name(cname), contactNumber(cnumber) {}

    string getName() {
        return name;
    }

    string getContactNumber() {
        return contactNumber;
    }
};

// Sales Class
class Sales {
private:
    vector<pair<Customer, Jewellery>> salesRecords;

public:
    void recordSale(Customer customer, Jewellery jewellery) {
        salesRecords.push_back(make_pair(customer, jewellery));
    }

    void viewSalesReport() {
        cout << "Sales Report:" << endl;
        for (auto& sale : salesRecords) {
            cout << "Customer: " << sale.first.getName() << ", Item: " << sale.second.getItemCode() << endl;
        }
    }
};

// Function to get jewellery details interactively
Jewellery createJewelleryItem() {
    string itemCode, itemName, stoneType;
    float basePrice;
    int karat, quantity;

    cout << "\nEnter Jewellery Item Code: ";
    cin >> itemCode;
    cout << "Enter Jewellery Item Name: ";
    cin.ignore();
    getline(cin, itemName);
    cout << "Enter Base Price of the Jewellery: ";
    cin >> basePrice;
    cout << "Enter Gold Karat (e.g., 24, 22, 18): ";
    cin >> karat;
    cout << "Enter Stone Type (diamond, ruby, opal, none): ";
    cin >> stoneType;
    cout << "Enter Quantity Available: ";
    cin >> quantity;

    Jewellery newJewellery(itemCode, itemName, basePrice, karat, stoneType, quantity);
    return newJewellery;
}

// Main Function
int main() {
    // Create Admin
    Admin admin("admin", "password");

    // Admin login process
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (!admin.login(username, password)) {
        cout << "Login failed!" << endl;
        return 0;
    }

    cout << "Login successful!" << endl;

    // Create inventory
    Inventory inventory;

    // Option to add items interactively
    int numItems;
    cout << "\nHow many items do you want to add to the inventory? ";
    cin >> numItems;

    for (int i = 0; i < numItems; ++i) {
        Jewellery newItem = createJewelleryItem();
        inventory.addItem(newItem);
    }

    // Display inventory
    cout << "\n--- Inventory ---" << endl;
    inventory.displayInventory();

    // Option to update stock
    string updateCode;
    int newQuantity;
    cout << "\nEnter the Item Code to update stock: ";
    cin >> updateCode;
    cout << "Enter the new quantity: ";
    cin >> newQuantity;

    inventory.updateStock(updateCode, newQuantity);

    // Display inventory after stock update
    cout << "\n--- Updated Inventory ---" << endl;
    inventory.displayInventory();

    // Create sales system
    Sales sales;

    // Create customer
    string customerName, contactNumber;
    cout << "\nEnter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter Customer Contact Number: ";
    cin >> contactNumber;
    Customer customer1(customerName, contactNumber);

    // Option to record sale
    string saleCode;
    cout << "\nEnter Item Code for the sale: ";
    cin >> saleCode;

    // Find the item in the inventory for sale
    Jewellery* saleItem = inventory.getItemByCode(saleCode);
    if (saleItem != nullptr) {
        sales.recordSale(customer1, *saleItem);
    } else {
        cout << "Item not found in inventory!" << endl;
    }

    // Display sales report
    cout << "\n--- Sales Report ---" << endl;
    sales.viewSalesReport();

    return 0;
}