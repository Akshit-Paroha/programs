#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string licensePlate;
    string vehicleType;

public:
    Vehicle(string lp, string vt) : licensePlate(lp), vehicleType(vt) {}
    virtual void displayInfo() const
    {
        cout << "Vehicle Type: " << vehicleType << "\nLicense Plate: " << licensePlate << endl;
    }
    string getLicensePlate() const
    {
        return licensePlate;
    }
    virtual double calculateParkingFee(int hours) con
    st = 0; 
};

class Car : public Vehicle
{
public:
    Car(string lp) : Vehicle(lp, "Car") {}
    void displayInfo() const override
    {
        cout << "Car License Plate: " << licensePlate << endl;
    }
    double calculateParkingFee(int hours) const override
    {
        return hours * 5.0; 
    }
};

class Bike : public Vehicle
{
public:
    Bike(string lp) : Vehicle(lp, "Bike") {}
    void displayInfo() const override
    {
        cout << "Bike License Plate: " << licensePlate << endl;
    }
    double calculateParkingFee(int hours) const override
    {
        return hours * 2.0; 
    }
};

class ParkingLot
{
    int totalSlots;
    int availableSlots;
    Vehicle *parkedVehicles[100];
public:
    ParkingLot(int slots) : totalSlots(slots), availableSlots(slots)
    {
        for (int i = 0; i < 100; ++i)
        {
            parkedVehicles[i] = nullptr;
        }
    }

    bool parkVehicle(Vehicle *vehicle, int hours)
    {
        if (availableSlots > 0)
        {
            for (int i = 0; i < totalSlots; ++i)
            {
                if (parkedVehicles[i] == nullptr)
                {
                    parkedVehicles[i] = vehicle;
                    availableSlots--;
                    cout << "Vehicle parked successfully." << endl;

                    // Calculate and display the parking fee based on the number of hours
                    double fee = vehicle->calculateParkingFee(hours);
                    cout << "Parking fee for " << vehicle->getLicensePlate() << " for " << hours << " hours is: $" << fee << endl;

                    return true;
                }
            }
        }
        else
        {
            cout << "No available slots!" << endl;
        }
        return false;
    }

    void removeVehicle(string licensePlate)
    {
        for (int i = 0; i < totalSlots; ++i)
        {
            if (parkedVehicles[i] != nullptr && parkedVehicles[i]->getLicensePlate() == licensePlate)
            {
                parkedVehicles[i] = nullptr;
                availableSlots++;
                cout << "Vehicle removed successfully." << endl;
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }

    void displayAvailableSlots() const
    {
        cout << "Available Slots: " << availableSlots << "/" << totalSlots << endl;
    }

    void displayParkedVehicles() const
    {
        cout << "\nParked Vehicles:\n";
        for (int i = 0; i < totalSlots; ++i)
        {
            if (parkedVehicles[i] != nullptr)
            {
                parkedVehicles[i]->displayInfo();
            }
        }
    }

    void calculateParkingFee(string licensePlate, int hours) const
    {
        for (int i = 0; i < totalSlots; ++i)
        {
            if (parkedVehicles[i] != nullptr && parkedVehicles[i]->getLicensePlate() == licensePlate)
            {
                double fee = parkedVehicles[i]->calculateParkingFee(hours);
                cout << "Parking fee for " << licensePlate << " is: $" << fee << endl;
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }
};

int main()
{
    int totalSlots;
    cout << "Enter total number of parking slots: ";
    cin >> totalSlots;

    ParkingLot lot(totalSlots);

    int choice;
    do
    {
        cout << "\nParking Management System:\n";
        cout << "1. Park a vehicle\n";
        cout << "2. Remove a vehicle\n";
        cout << "3. Display available slots\n";
        cout << "4. Display all parked vehicles\n";
        cout << "5. Calculate parking fee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int vehicleType, hours;
            string licensePlate;
            cout << "Enter vehicle type (1 for Car, 2 for Bike): ";
            cin >> vehicleType;
            cout << "Enter license plate: ";
            cin >> licensePlate;
            cout << "Enter number of hours you plan to park: ";
            cin >> hours;

            if (vehicleType == 1)
            {
                Vehicle *car = new Car(licensePlate);
                lot.parkVehicle(car, hours);
            }
            else if (vehicleType == 2)
            {
                Vehicle *bike = new Bike(licensePlate);
                lot.parkVehicle(bike, hours);
            }
            else
            {
                cout << "Invalid vehicle type!" << endl;
            }
            break;
        }
        case 2:
        {
            string licensePlate;
            cout << "Enter the license plate of the vehicle to remove: ";
            cin >> licensePlate;
            lot.removeVehicle(licensePlate);
            break;
        }
        case 3:
        {
            lot.displayAvailableSlots();
            break;
        }
        case 4:
        {
            lot.displayParkedVehicles();
            break;
        }
        case 5:
        { 
            string licensePlate;
            int hours;
            cout << "Enter the license plate of the vehicle: ";
            cin >> licensePlate;
            cout << "Enter number of hours parked: ";
            cin >> hours;
            lot.calculateParkingFee(licensePlate, hours);
            break;
        }
        case 6:
            cout << "Exiting the system." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}