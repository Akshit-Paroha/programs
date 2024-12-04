#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    string brand;

public:
    Device(string brandName)
    {
        brand = brandName;
    }

    void display()
    {
        cout << "Device Brand: " << brand << endl;
    }
};

class Computer : virtual public Device
{
protected:
    int ram;

public:
    Computer(string brandName, int ramSize) : Device(brandName)
    {
        ram = ramSize;
    }

    void display()
    {
        cout << "Computer Details:" << endl;
        Device::display();
        cout << "RAM: " << ram << " GB" << endl;
    }
};

class Phone : virtual public Device
{
protected:
    int batteryCapacity;

public:
    Phone(string brandName, int battery) : Device(brandName)
    {
        batteryCapacity = battery;
    }

    void display()
    {
        cout << "Phone Details:" << endl;
        Device::display();
        cout << "Battery Capacity: " << batteryCapacity << " mAh" << endl;
    }
};

class Laptop : public Computer, public Phone
{
private:
    double weight;

public:
    Laptop(string brandName, int ramSize, int battery, double laptopWeight)
        : Device(brandName), Computer(brandName, ramSize), Phone(brandName, battery)
    {
        weight = laptopWeight;
    }

    void display()
    {
        cout << "Laptop Details:" << endl;
        Device::display();
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Battery Capacity: " << batteryCapacity << " mAh" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main()
{
    Device device("Generic Brand");
    Computer computer("HP", 16);
    Phone phone("Samsung", 4500);
    Laptop laptop("Dell", 16, 5000, 2.2);

    device.display();
    cout << endl;
    computer.display();
    cout << endl;
    phone.display();
    cout << endl;
    laptop.display();

    return 0;
}
