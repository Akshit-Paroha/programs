#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

// Base class Login
class Login
{
protected:
    string username;
    string password;

public:
    bool loginInfo()
    {
        cout << "\n-------Welcome To Computer department's Student section ---------" << endl;
        cout << endl;
        cout << "\n                           LOGIN                           " << endl;
        // Taking username and password from the user
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        password = "";
        char ch;
        while (true)
        {
            ch = _getwch(); // Use _getch() to get a single character without echoing
            if (ch == '\r')
            { // Enter key (carriage return)
                break;
            }
            else if (ch == '\b')
            { // Backspace key
                if (!password.empty())
                {
                    cout << "\b \b"; // Erase the last asterisk
                    password.pop_back();
                }
            }
            else
            {
                cout << '*';    // Print an asterisk
                password += ch; // Append the actual character to the password
            }
        }
        cout << endl;

        // Checking if the username and password are correct
        if (username == "student" && password == "student123")
        {
            cout << "Login successful!" << endl;
            return true;
        }
        else
        {
            cout << "Invalid username or password!" << endl;
            return false;
        }
    }
};

// Derived class with multiple member functions
class StudentSection : public Login
{
public:
    void writestudentInfo()
    {
        string name, email, dep, year, aadhar, dob, phone;
        int enno;

        cout << "Enter Enrollment Number : ";
        cin >> enno;
        cout << "Enter Student Name : ";
        cin >> name;
        cout << "Enter Email Id : ";
        cin >> email;
        cout << "Enter Department : ";
        cin >> dep;
        cout << "Enter Year : ";
        cin >> year;
        cout << "Enter Aadhar No : ";
        cin >> aadhar;
        cout << "Enter DOB : ";
        cin >> dob;
        cout << "Enter Mobile No : ";
        cin >> phone;

        // Saving to file
        ofstream outFile("student_info.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << "Enrollment Number: " << enno << endl;
            outFile << "Student Name: " << name << endl;
            outFile << "Email Id: " << email << endl;
            outFile << "Department: " << dep << endl;
            outFile << "Year: " << year << endl;
            outFile << "Aadhar No: " << aadhar << endl;
            outFile << "DOB: " << dob << endl;
            outFile << "Mobile No: " << phone << endl;
            outFile << "---------------------" << endl;
            outFile.close();
            cout << "Student information saved in student_info.txt!" << endl;
        }
    }

    void readstudentInfo()
    {
        int searchEnno;
        string line;
        bool found = false;
        cout << "Enter Enrollment Number to search: ";
        cin >> searchEnno;

        ifstream inFile("student_info.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                if (line.find("Enrollment Number: " + to_string(searchEnno)) != string::npos)
                {
                    found = true;
                    // Print the student's information
                    cout << line << endl; // Enrollment Number
                    for (int i = 0; i < 8; ++i)
                    { // There are 7 more lines to read for the student's details
                        getline(inFile, line);
                        cout << line << endl;
                    }
                    cout << "---------------------" << endl;
                    break;
                }
            }
            inFile.close();

            if (!found)
            {
                cout << "Student with Enrollment Number " << searchEnno << " not found." << endl;
            }
        }
        else
        {
            cout << "Unable to open student_info.txt" << endl;
        }
    }

    void writefeesStatus()
    {
        int enno;
        string fees;
        cout << "Enter Enrollment Number: ";
        cin >> enno;
        cout << "Enter Fees status: ";
        cin >> fees;

        // Saving to file
        ofstream outFile("fees_status.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << "Enrollment Number: " << enno << endl;
            outFile << "Fees Status: " << fees << endl;
            outFile << "---------------------" << endl;
            outFile.close();
            cout << "Fees status saved in fees_status.txt!" << endl
                 << endl;
        }
    }

    void readFeesStatus()
    {
        int searchEnno;
        string line;
        bool found = false;
        cout << "Enter Enrollment Number to search: ";
        cin >> searchEnno;

        ifstream inFile("fees_status.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                if (line.find("Enrollment Number: " + to_string(searchEnno)) != string::npos)
                {
                    found = true;
                    // Print the student's fee status
                    cout << line << endl;  // Enrollment Number
                    getline(inFile, line); // Read Fees Status line
                    cout << line << endl;
                    cout << "---------------------" << endl;
                    break;
                }
            }
            inFile.close();

            if (!found)
            {
                cout << "Fees status for Enrollment Number " << searchEnno << " not found." << endl;
            }
        }
        else
        {
            cout << "Unable to open fees_status.txt" << endl;
        }
    }

    void writedepartmentInfo()
    {
        string departmentName, hodName, facultyname, courses, depEvents;

        ofstream DepartmentFile("department_info.txt", ios::app);
        if (DepartmentFile.is_open())
        {
            DepartmentFile << "Department Name : CM " << endl;
            DepartmentFile << "HOD Name : Dr. M.V Sarode " << endl;

            DepartmentFile << "Faculties : \n For first year\n 1.Akshat Uike\n 2.Shilpa Patil \n 3.Minakshi Dave\n"
                           << endl;
            DepartmentFile << "Faculties : \n For second year\n 1.Akshat Uike\n 2.Dhanashree Nalinde \n 3.Isha Bawankule\n 4.Nita Badiya\n"
                           << endl;
            DepartmentFile << "Faculties : \n For third year\n 1.Sumit Khatri\n 2.Ujjwala Aher \n 3.Kamalakant Bawankule\n"
                           << endl;

            DepartmentFile << "Courses :\nFor first year \n 1.Applied Physics\n Faculty : Shilpa Patil \n\n 2.Applied Mathematics\n Faculty : Minakshi Dave" << endl;
            DepartmentFile << " 3.C language \n Faculty : Akshat Uike \n\n 4.Basics of communication \n Faculty : Shilpa Patil\n"
                           << endl;
            DepartmentFile << "Courses :\nFor second year \n 1.Data structures\n Faculty : Dhanashree Nalinde\n 2.Computer communication and networks\n Faculty : Isha Bawankule \n 3.Object Oriented Programming\n Faculty : Akshat Uike \n 4.Digital Techniques\n Faculty : Nita Badiya\n"
                           << endl;
            DepartmentFile << "Courses :\nFor third year \n 1.Operating System\n Faculty : Sumit khatri\n 2. DBMS\n Faculty : Ujjwala Aher\n 3. Advanced Java\n Faculty : Kamalakant Bawankule\n"
                           << endl;
            DepartmentFile << "Department Event : TechTonix" << endl;
            DepartmentFile << "\n---------------------" << endl;
            DepartmentFile.close();
            cout << "Department information saved in department_info.txt!" << endl;
        }
    }

    void readDepartmentInfo()
    {
        string line;
        ifstream inFile("department_info.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open department_info.txt" << endl;
        }
    }

    void writeLibrarySection()
    {
        // Saving to file
        ofstream outFile("library_section.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << "\nYear : 1" << endl;
            outFile << "\nBook Name: Basics of Electronics\n Book ID: 1\n Quantity: 20" << endl;
            outFile << "\nBook Name: IPDC\n Book ID: 2\n Quantity: 20" << endl;
            outFile << "\nBook Name: Applied Physics\n Book ID: 3\n Quantity: 20" << endl;
            outFile << "\nBook Name: Applied Mathematics\n Book ID: 4\n Quantity: 20" << endl;
            outFile << "---------------------" << endl;

            outFile << "\nYear : 2" << endl;
            outFile << "\nBook Name: Data Structures\n Book ID: 5\n Quantity: 20" << endl;
            outFile << "\nBook Name: OOPs\n Book ID: 6\n Quantity: 20" << endl;
            outFile << "\nBook Name: Digital Techniques\n Book ID: 7\n Quantity: 20" << endl;
            outFile << "\nBook Name: CCN Theory\n Book ID: 8\n Quantity: 20" << endl;
            outFile << "---------------------" << endl;

            outFile << "\nYear : 3" << endl;
            outFile << "\nBook Name: Operating Systems\n Book ID: 9\n Quantity: 20" << endl;
            outFile << "\nBook Name: Applied Java\n Book ID: 10\n Quantity: 20" << endl;
            outFile << "\nBook Name: ACN\n Book ID: 11\n Quantity: 20" << endl;
            outFile << "\nBook Name: DBMS\n Book ID: 12\n Quantity: 20" << endl;
            outFile << "---------------------" << endl;

            outFile.close();
            cout << "Library section information saved in library_section.txt!" << endl;
        }
    }

    void readLibrarySection()
    {
        int searchBook;
        string line;
        int BookID;
        int searchBookID;
        bool found = false;
        cout << "Enter year: ";
        cin >> searchBook;

        ifstream inFile("library_section.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                if (line.find("Year : " + to_string(searchBook)) != string::npos)
                {
                    found = true;

                    cout << line << endl;
                    for (int i = 0; i < 17; ++i)
                    {
                        getline(inFile, line);
                        cout << line << endl;
                    }
                    cout << "---------------------" << endl;
                    break;
                }
            }
            inFile.close();

            if (!found)
            {
                cout << "Book for this year " << searchBook << " not found." << endl;
            }
        }
        else
        {
            cout << "Unable to open library_section.txt" << endl;
        }
        cout << "Enter the Book ID you want to Issue : ";
        cin >> BookID;

        if (BookID <= 12)
        {
            ifstream LibraryFile("library_section.txt");
            if (LibraryFile.is_open())
            {
                while (getline(LibraryFile, line))
                {
                    if (line.find("Book ID : " + to_string(searchBookID)) != string::npos)
                    {
                        found = true;

                        cout << line << endl;
                        for (int i = 0; i < 3; ++i)
                        {
                            getline(LibraryFile, line);
                            cout << line << endl;
                        }
                        cout << "---------------------" << endl;
                        break;
                    }
                }
                LibraryFile.close();

                if (!found)
                {
                    cout << "Book ID " << searchBookID << " not found." << endl;
                }
            }
            else
            {
                cout << "Unable to open library_section.txt" << endl;
            }
        }

        void applicationSection()
        {
            int enroll;
            string applicationType;
            string subject;
            string matter;

            cout << "\nTaking Application Details from User!!" << endl
                 << endl;
            cout << "\nEnter Enrollment No : ";
            cin >> enroll;
            int choice;
            cout << "\nTypes of Applications!!\n  1.Complaint \n  2.Scholarship Application \n  3.ID Card issue \n  4.Uniform Repurchasing\n  5.Application regarding bonafide\n";
            cout << "\nSelect Application Type : ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Complaint\n";
                cout << "\nEnter Subject : ";
                cin >> subject;
                cout << "\nWrite Your Application!!\n";
                cin >> matter;
                cout << "\nYour application is submitted!!\n"
                     << endl;
            }
            else if (choice == 2)
            {
                cout << "scholarship application\n",
                    cout << "\nEnter Subject : ";
                cin >> subject;
                cout << "\nWrite Your Application!!\n";
                cin >> matter;
                cout << "\nYour application is submitted!!\n"
                     << endl;
            }
            else if (choice == 3)
            {
                cout << "icard issue\n",
                    cout << "\nEnter Subject : ";
                cin >> subject;
                cout << "\nWrite Your Application!!\n";
                cin >> matter;
                cout << "\nYour application is submitted!!\n"
                     << endl;
            }
            else if (choice == 4)
            {
                cout << "Uniform repurchasing\n";
                cout << "\nEnter Subject : ";
                cin >> subject;
                cout << "\nWrite Your Application!!\n";
                cin >> matter;
                cout << "\nYour application is submitted!!\n"
                     << endl;
            }
            else if (choice == 5)
            {
                cout << "Application regarding bonafide\n",
                    cout << "\nEnter Subject : ";
                cin >> subject;
                cout << "\nWrite Your Application!!\n";
                cin >> matter;
                cout << "\nYour application is submitted!!\n"
                     << endl;
            }
            else
            {
                cout << "Invalid Choice!!\n";
            }
            // Saving to file
            ofstream outFile("application_section.txt", ios::app);
            if (outFile.is_open())
            {
                outFile << "Types of Applications!!\n  1.Complaint \n  2.scholarship application \n  3.icard issue \n  4.uniform repurchasing\n  5.Application regarding bonafide\n";
                outFile << "Application Type: " << choice << endl;
                outFile << "Subject : " << subject << endl;
                outFile << "Application Matter : " << matter << endl;
                outFile << "---------------------" << endl;
                outFile.close();
                cout << "Application information saved in application_section.txt!" << endl;
            }
        }

        // Function to read Application Info
        void readApplicationSection()
        {
            ifstream inFile("application_section.txt");
            string line;

            if (inFile.is_open())
            {
                cout << "\n--- Application Information ---\n";
                while (getline(inFile, line))
                {
                    cout << line << endl;
                }
                inFile.close();
            }
            else
            {
                cout << "Unable to open application_section.txt!" << endl;
            }
        }

        void writescholarshipSection()
        {
            string schname;
            int enno;

            ofstream ScholarshipFile("scholarship_section.txt", ios::app);
            if (ScholarshipFile.is_open())
            {
                ScholarshipFile << "\nScholarship For 1st year \n";
                ScholarshipFile << "\n1.MahaDBT\n -Criteria : Merit based Scholarship\n  -Only for OBC , SC , ST , VJ , NT \n";
                ScholarshipFile << "\n2.NSP\n -Criteria : Merit based Scholarship\n  -Only for OBC and General\n";
                ScholarshipFile << "\n3.JYOTIBAI PHULE SCHOLARSHIP\n -Criteria : Merit based Scholarship\n  -Only for SC , ST\n";
                ScholarshipFile << "----------------------------------------------------------------" << endl;
                ScholarshipFile << "\nScholarship For 2nd year\n";
                ScholarshipFile << "\n1.MahaDBT\n -Criteria : Merit based Scholarship\n  -Only for OBC , SC , ST , VJ , NT \n";
                ScholarshipFile << "\n2.NSP\n -Criteria : Merit based Scholarship\n  -Only for OBC and General \n";
                ScholarshipFile << "\n3.JYOTIBAI PHULE SCHOLARSHIP\n -Criteria : Merit based Scholarship\n  -Only for SC , ST \n";
                ScholarshipFile << "----------------------------------------------------------------" << endl;
                ScholarshipFile << "\nScholarship For 3rd year\n";
                ScholarshipFile << "\n1.MahaDBT\n -Criteria : Merit based Scholarship\n  -Only for OBC , SC ,ST , VJ , NT \n";
                ScholarshipFile << "\n2.NSP\n -Criteria : Merit based Scholarship\n  -Only for OBC and General \n";
                ScholarshipFile << "\n3.JYOTIBAI PHULE SCHOLARSHIP\n -Criteria : Merit based Scholarship\n  -Only for SC , ST \n";
                ScholarshipFile << "----------------------------------------------------------------" << endl;
                ScholarshipFile.close();
                cout << "Scholarship information saved in scholarship_section.txt!" << endl;
            }
        }

        void readscholarshipSection()
        {
            ifstream inFile("scholarship_section.txt");
            string line;
            int yearChoice;

            cout << "\nEnter the year for which you want to view scholarship information (1 for 1st year, 2 for 2nd year, 3 for 3rd year): ";
            cin >> yearChoice;

            if (inFile.is_open())
            {
                cout << "\n--- Scholarship Information ---\n";
                bool displaySection = false;
                string targetSection;

                // Determine the target section based on user input
                switch (yearChoice)
                {
                case 1:
                    targetSection = "Scholarship For 1st year";
                    break;
                case 2:
                    targetSection = "Scholarship For 2nd year";
                    break;
                case 3:
                    targetSection = "Scholarship For 3rd year";
                    break;
                default:
                    cout << "Invalid year choice!" << endl;
                    inFile.close();
                    return;
                }

                // Read through the file and display only the relevant section
                while (getline(inFile, line))
                {
                    if (line.find(targetSection) != string::npos)
                    {
                        displaySection = true;
                    }
                    else if (line.find("----------------------------------------------------------------") != string::npos)
                    {
                        displaySection = false;
                    }

                    if (displaySection)
                    {
                        cout << line << endl;
                    }
                }
                inFile.close();
            }
            else
            {
                cout << "Unable to open scholarship_section.txt!" << endl;
            }
        }
        void writeeventInformation()
        {
            string eventName;
            string eventDate;

            // Saving to file
            ofstream EventFile("event_info.txt", ios::app);
            if (EventFile.is_open())
            {
                EventFile << "Current Events!!" << endl;
                EventFile << "Genesis (By Electronic And Telecommunication)\n Date 18th - 19th october\n " << endl;
                EventFile << "Techtonix (Computer Department)\n Date 20th - 21st November\n " << endl;
                EventFile << "MESA (BY Mechanical Department)\n Date 2nd - 3rd December\n " << endl;
                EventFile << "EASA (By Electrical Department)\n Date 14th - 15th December\n " << endl;
                EventFile << "\n---------------------" << endl;

                EventFile.close();
                cout << "Event information saved in event_info.txt!" << endl;
            }
        }
        // Function to read Event Information
        void readEventInformation()
        {
            ifstream inFile("event_info.txt");
            string line;

            if (inFile.is_open())
            {
                cout << "\n--- Event Information ---\n";
                while (getline(inFile, line))
                {
                    cout << line << endl;
                }
                inFile.close();
            }
            else
            {
                cout << "Unable to open event_info.txt!" << endl;
            }
        }

        void showMenu()
        {
            int choice;

            do
            {
                cout << "\nSections!!\n";
                cout << "1. Student Profile\n";
                cout << "2. Fees Section\n";
                cout << "3. Department Info\n";
                cout << "4. Library Section\n";
                cout << "5. Application Section\n";
                cout << "6. Scholarship Section\n";
                cout << "7. Event Info\n";
                cout << "8. Exit\n\n";
                cout << "\nSelect Section : ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    readstudentInfo();
                    break;
                case 2:
                    readFeesStatus();
                    break;
                case 3:
                    readDepartmentInfo();
                    break;
                case 4:
                    readLibrarySection();
                    break;
                case 5:
                    applicationSection();
                    break;
                case 6:
                    readscholarshipSection();
                    break;
                case 7:
                    readEventInformation();
                    break;
                case 8:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
                }
            } while (choice != 8);
               } }
};

    int main()
    {
        int choice;
        StudentSection studentSection;
        do
        {
            cout << "\nPick a choice!!\n  1. Login\n  2. Write data to files\n  3. Exit\n";
            cout << "\nEnter your Choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                if (studentSection.loginInfo())
                {
                    studentSection.showMenu();
                }
                break;
            case 2:
            {
                StudentSection s[1];
                int i;
                cout << "\nWriting information to files !!" << endl
                     << endl;
                for (i = 0; i < 1; i++)
                {
                    cout << "\nWriting student information!!" << endl
                         << endl;
                    s[i].writestudentInfo();
                    cout << "\nWriting fees details!!" << endl
                         << endl;
                    s[i].writefeesStatus();
                }
                StudentSection d, l, sch, e;
                d.writedepartmentInfo();
                l.writeLibrarySection();
                sch.writescholarshipSection();
                e.writeeventInformation();
            }
            break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice! Try again.\n";
            }
        } while (choice != 3);

        return 0;
    }