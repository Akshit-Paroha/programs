#include <iostream>
#include <string>
using namespace std;

class Athlete
{
protected:
    string name;
    int age;

public:
    Athlete(string athleteName, int athleteAge)
    {
        name = athleteName;
        age = athleteAge;
    }

    void display()
    {
        cout << "Athlete Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Runner : virtual public Athlete
{
protected:
    double runningSpeed;

public:
    Runner(string athleteName, int athleteAge, double speed) : Athlete(athleteName, athleteAge)
    {
        runningSpeed = speed;
    }

    void display()
    {
        cout << "Runner Details:" << endl;
        Athlete::display();
        cout << "Running Speed: " << runningSpeed << " km/h" << endl;
    }
};

class Swimmer : virtual public Athlete
{
protected:
    double swimmingSpeed;

public:
    Swimmer(string athleteName, int athleteAge, double speed) : Athlete(athleteName, athleteAge)
    {
        swimmingSpeed = speed;
    }

    void display()
    {
        cout << "Swimmer Details:" << endl;
        Athlete::display();
        cout << "Swimming Speed: " << swimmingSpeed << " m/s" << endl;
    }
};

class Triathlete : public Runner, public Swimmer
{
private:
    double cyclingSpeed;

public:
    Triathlete(string athleteName, int athleteAge, double runSpeed, double swimSpeed, double cycleSpeed)
        : Athlete(athleteName, athleteAge), Runner(athleteName, athleteAge, runSpeed), Swimmer(athleteName, athleteAge, swimSpeed)
    {
        cyclingSpeed = cycleSpeed;
    }

    void display()
    {
        cout << "Triathlete Details:" << endl;
        Athlete::display();
        cout << "Running Speed: " << runningSpeed << " km/h" << endl;
        cout << "Swimming Speed: " << swimmingSpeed << " m/s" << endl;
        cout << "Cycling Speed: " << cyclingSpeed << " km/h" << endl;
    }
};

int main()
{
    Athlete athlete("John Doe", 30);
    Runner runner("Alice Smith", 25, 20.5);
    Swimmer swimmer("Bob Johnson", 28, 2.3);
    Triathlete triathlete("Charlie Brown", 35, 18.2, 2.0, 25.0);

    athlete.display();
    cout << endl;
    runner.display();
    cout << endl;
    swimmer.display();
    cout << endl;
    triathlete.display();

    return 0;
}
