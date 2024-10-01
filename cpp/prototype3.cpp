#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Base Class for Items
class Item {
public:
    virtual void displayDetails() const = 0;
    virtual float calculateFinalPrice() = 0;
    virtual string getItemCode() const = 0;
    virtual string getItemName() const = 0;
};

// Jewellery Class (Inherits from Item)
class Jewellery : public Item {
private:
    static int nextItemCode; // Static counter for item code
    string itemCode;
    string itemName;
    float goldPricePerGram;  // Current gold price per gram
    float weightInGrams;     // Weight of jewellery
    int karat;
    string stoneType;
    int quantity;
    float finalPrice;

public:
    Jewellery(string name, float goldPrice, float weight, int karatValue, string stone, int qty) 
        : itemName(name), goldPricePerGram(goldPrice), weightInGrams(weight), karat(karatValue), stoneType(stone), quantity(qty) {
        itemCode = "JW" + to_string(nextItemCode++);  // Auto-generate item code
        finalPrice = calculateFinalPrice();
    }

    float calculateFinalPrice() override {
        float basePrice = goldPricePerGram * weightInGrams;  // Base price based on gold price and weight
        float karatMultiplier = (karat == 24) ? 1.0 : 0.9; // Adjust price based on karat
        float stonePrice = (stoneType == "diamond") ? 100000 :
                           (stoneType == "ruby") ? 50000 :
                           (stoneType == "opal") ? 30000 : 0; // Stone price in rupees
        return (basePrice * karatMultiplier) + stonePrice;
    }

    void displayDetails() const override {
        cout << "Item Code: " << itemCode << ", Name: " << itemName 
             << ", Final Price: ₹" << finalPrice << ", Quantity: " << quantity << endl;
    }

    string getItemCode() const override { return itemCode; }
    string getItemName() const override { return itemName; }
    int getQuantity() const { return quantity; }
    void setQuantity(int qty) { quantity = qty; }
};

// Initialize the static member
int Jewellery::nextItemCode = 1;

// Inventory Class
class Inventory {
private:
    vector<Jewellery> items;

public:
    void addItem(const Jewellery& jewellery) {
        items.push_back(jewellery);
        cout << "Item added to inventory.\n";
    }

    void displayInventory() const {
        if (items.empty()) {
            cout << "No items in inventory.\n";
            return;
        }
        cout << "--- Inventory ---\n";
        for (const auto& item : items) {
            item.displayDetails();
        }
    }

    Jewellery* getItemByCode(const string& itemCode) {
        for (auto& item : items) {
            if (item.getItemCode() == itemCode) {
                return &item;
            }
        }
        return nullptr;
    }
};

// Sales Class
class Sales {
private:
    map<string, vector<pair<string, Item*>>> salesRecordsByAdmin;  // Sales records organized by admin

public:
    void recordSale(const string& adminName, const string& customerName, Item* item) {
        salesRecordsByAdmin[adminName].push_back(make_pair(customerName, item));
        cout << "Sale recorded for customer: " << customerName << " by " << adminName << "\n";
    }

    void createBill(const string& adminName, const string& customerName) const {
        cout << "\n--- Bill for " << customerName << " (Handled by " << adminName << ") ---\n";
        for (const auto& sale : salesRecordsByAdmin.at(adminName)) {
            if (sale.first == customerName) {
                sale.second->displayDetails();
                cout << "Total: ₹" << sale.second->calculateFinalPrice() << endl;
            }
        }
    }

    void viewSalesReport(const string& adminName) const {
        if (salesRecordsByAdmin.find(adminName) == salesRecordsByAdmin.end() || salesRecordsByAdmin.at(adminName).empty()) {
            cout << "No sales recorded for " << adminName << ".\n";
            return;
        }
        cout << "--- Sales Report for " << adminName << " ---\n";
        for (const auto& record : salesRecordsByAdmin.at(adminName)) {
            cout << "Customer: " << record.first << ", Item: " << record.second->getItemName() << endl;
        }
    }

    void viewOverallSalesReport() const {
        if (salesRecordsByAdmin.empty()) {
            cout << "No sales recorded.\n";
            return;
        }
        cout << "--- Overall Sales Report ---\n";
        for (const auto& adminSales : salesRecordsByAdmin) {
            cout << "Sales by " << adminSales.first << ":\n";
            for (const auto& record : adminSales.second) {
                cout << "Customer: " << record.first << ", Item: " << record.second->getItemName() << endl;
            }
        }
    }
};

// Function to interactively create a jewellery item
Jewellery createJewelleryItem() {
    string itemName, stoneType;
    float goldPrice, weight;
    int karat, quantity;

    cout << "Enter Jewellery Name: ";
    cin.ignore();
    getline(cin, itemName);
    cout << "Enter Current Gold Price (per gram in ₹): ";
    cin >> goldPrice;
    cout << "Enter Weight of Jewellery (in grams): ";
    cin >> weight;
    cout << "Enter Gold Karat (24, 22, 18): ";
    cin >> karat;
    cout << "Enter Stone Type (diamond, ruby, opal, none): ";
    cin >> stoneType;
    cout << "Enter Quantity: ";
    cin >> quantity;

    return Jewellery(itemName, goldPrice, weight, karat, stoneType, quantity);
}

int main() {
    Inventory inventory;
    Sales sales;
    string currentAdmin;
    map<string, string> adminAccounts = {{"Akshit", "pass1"}, {"Rutuja", "pass2"}, {"Akshat", "pass3"}};  // Admin profiles

    // Admin
}