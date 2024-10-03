#include <iostream>
#include <string>
#include <vector>
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
    float basePrice;
    int karat;
    string stoneType;
    int quantity;
    float finalPrice;

public:
    Jewellery(string name, float price, int karatValue, string stone, int qty) 
        : itemName(name), basePrice(price), karat(karatValue), stoneType(stone), quantity(qty) {
        itemCode = "JW" + to_string(nextItemCode++);  // Auto-generate item code
        finalPrice = calculateFinalPrice();
    }

    float calculateFinalPrice() override {
        float karatMultiplier = (karat == 24) ? 1.0 : 0.9; // Adjust price based on karat
        float stonePrice = (stoneType == "diamond") ? 1000 :
                           (stoneType == "ruby") ? 500 :
                           (stoneType == "opal") ? 300 : 0; // Stone price
        return (basePrice * karatMultiplier) + stonePrice;
    }

    void displayDetails() const override {
        cout << "Item Code: " << itemCode << ", Name: " << itemName 
             << ", Final Price: $" << finalPrice << ", Quantity: " << quantity << endl;
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
    vector<pair<string, Item*>> salesRecords;  // Now using polymorphism with Item*

public:
    void recordSale(const string& customerName, Item* item) {
        salesRecords.push_back(make_pair(customerName, item));
        cout << "Sale recorded for customer: " << customerName << "\n";
    }

    void createBill(const string& customerName) const {
        cout << "\n--- Bill for " << customerName << " ---\n";
        for (const auto& sale : salesRecords) {
            if (sale.first == customerName) {
                sale.second->displayDetails();
                cout << "Total: $" << sale.second->calculateFinalPrice() << endl;
            }
        }
    }

    void viewSalesReport() const {
        if (salesRecords.empty()) {
            cout << "No sales recorded.\n";
            return;
        }
        cout << "--- Sales Report ---\n";
        for (const auto& record : salesRecords) {
            cout << "Customer: " << record.first << ", Item: " << record.second->getItemName() << endl;
        }
    }
};

// Function to interactively create a jewellery item
Jewellery createJewelleryItem() {
    string itemName, stoneType;
    float basePrice;
    int karat, quantity;

    cout << "Enter Jewellery Name: ";
    cin.ignore();
    getline(cin, itemName);
    cout << "Enter Base Price: ";
    cin >> basePrice;
    cout << "Enter Gold Karat (24, 22, 18): ";
    cin >> karat;
    cout << "Enter Stone Type (diamond, ruby, opal, none): ";
    cin >> stoneType;
    cout << "Enter Quantity: ";
    cin >> quantity;

    return Jewellery(itemName, basePrice, karat, stoneType, quantity);
}

int main() {
    Inventory inventory;
    Sales sales;

    // Admin login simulation (hardcoded for simplicity)
    string username, password;
    cout << "Admin Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username != "admin" || password != "password") {
        cout << "Login failed!\n";
        return 0;
    }
    cout << "Login successful!\n";

    int choice;
    do {
        cout << "\nMenu:\n1. Add Jewellery\n2. Display Inventory\n3. Record Sale\n4. Create Bill\n5. View Sales Report\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Jewellery newItem = createJewelleryItem();
                inventory.addItem(newItem);
                break;
            }
            case 2:
                inventory.displayInventory();
                break;
            case 3: {
                string customerName, itemCode;
                int fromInventory;
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, customerName);

                cout << "Do you want to select an item from inventory? (1 for Yes, 0 for No): ";
                cin >> fromInventory;

                if (fromInventory == 1) {
                    cout << "Enter Item Code: ";
                    cin >> itemCode;
                    Jewellery* item = inventory.getItemByCode(itemCode);
                    if (item != nullptr) {
                        sales.recordSale(customerName, item);
                    } else {
                        cout << "Item not found!\n";
                    }
                } else {
                    Jewellery newItem = createJewelleryItem();  // Create a custom item (not in inventory)
                    sales.recordSale(customerName, &newItem);   // Use polymorphism to handle it as an Item
                }
                break;
            }
            case 4: {
                string customerName;
                cout << "Enter Customer Name to create bill: ";
                cin.ignore();
                getline(cin, customerName);
                sales.createBill(customerName);
                break;
            }
            case 5:
                sales.viewSalesReport();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
