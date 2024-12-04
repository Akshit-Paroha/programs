#include <iostream>
using namespace std;

class Organization
{
public:
    string orgName;

    void setOrganization(string name)
    {
        orgName = name;
    }

    void showOrganization()
    {
        cout << "Organization: " << orgName << endl;
    }
};

class Department : public Organization
{
public:
    string deptName;

    void setDepartment(string name)
    {
        deptName = name;
    }

    void showDepartment()
    {
        showOrganization();
        cout << "Department: " << deptName << endl;
    }
};

class Team : public Department
{
private:
    string teamName;

public:
    void setTeam(string name)
    {
        teamName = name;
    }

    void showTeam()
    {
        showDepartment();
        cout << "Team: " << teamName << endl;
    }
};

int main()
{
    Team t;
    t.setOrganization("GPN");
    t.setDepartment("CS Department");
    t.setTeam("Students");
    t.showTeam();

    return 0;
}
