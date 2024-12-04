#include <iostream>
#include <string>
using namespace std;

class Appliance
{
protected:
    string brand;

public:
    Appliance(string brandName)
    {
        brand = brandName;
    }

    void displayBrand()
    {
        cout << "Brand: " << brand << endl;
    }
};

class WashingMachine : public Appliance
{
private:
    int loadCapacity;

public:
    WashingMachine(string brandName, int capacity) : Appliance(brandName)
    {
        loadCapacity = capacity;
    }

    void displayDetails()
    {
        displayBrand();
        cout << "Load Capacity: " << loadCapacity << " kg" << endl;
    }
};

class Refrigerator : public Appliance
{
private:
    int storageVolume;

public:
    Refrigerator(string brandName, int volume) : Appliance(brandName)
    {
        storageVolume = volume;
    }

    void displayDetails()
    {
        displayBrand();
        cout << "Storage Volume: " << storageVolume << " liters" << endl;
    }
};

int main()
{
    WashingMachine wm("Samsung", 7);
    wm.displayDetails();

    Refrigerator fridge("LG", 300);
    fridge.displayDetails();

    return 0;
}
