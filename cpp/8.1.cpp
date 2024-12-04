#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    string species;

public:
    Animal(string s)
    {
        species = s;
    }

    void displayAnimalData()
    {
        cout << "species: " << species << endl;
    }
};

class Bird : public Animal
{
protected:
    string color;

public:
    Bird(string s, string c) : Animal(s)
    {
        color = c;
    }

    void displayBirdData()
    {
        displayAnimalData();
        cout << "Color of Bird: " << color << endl;
    }
};

class Fish : public Animal
{
protected:
    string color;

public:
    Fish(string s, string c1) : Animal(s)
    {
        color = c1;
    }

    void displayFishData()
    {
        displayAnimalData();
        cout << "Color of Fish: " << color << endl;
    }
};

int main()
{
    Bird b1("sparrow", "brown");
    b1.displayBirdData();
    cout << endl;

    Fish f1("star fish", "orange");
    f1.displayFishData();

    return 0;
}
