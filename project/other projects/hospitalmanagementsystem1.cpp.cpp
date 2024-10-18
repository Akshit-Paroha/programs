#include <iostream>
#include <string>

using namespace std;

class Patient
{
public:
    int id;
    string name;
    int age;
    string ailment;
    string admissionDate;
    string phoneNumber;
    double totalBill;
    bool isDischarged;
};

class Staff
{
public:
    int id;
    string name;
    string position;
};

class Doctor
{
public:
    string name;
    string specialization;
};

class Appointment
{
public:
    int patientId;
    string appointmentDate;
    Doctor doctor;
};

const int MAX_PATIENTS = 100;
const int MAX_STAFF = 50;
const int MAX_APPOINTMENTS = 100;

class HospitalSystem
{
private:
    Patient patients[MAX_PATIENTS];
    Staff staff[MAX_STAFF];
    Appointment appointments[MAX_APPOINTMENTS];
    int patientCount;
    int staffCount;
    int appointmentCount;
    int patientIdCounter;
    int staffIdCounter;

public:
    HospitalSystem() : patientCount(0), staffCount(0), appointmentCount(0), patientIdCounter(1), staffIdCounter(1) {}

    void admitPatient()
    {
        if (patientCount >= MAX_PATIENTS)
        {
            cout << "Hospital is full! Cannot admit more patients.\n";
            return;
        }

        Patient newPatient;
        newPatient.id = patientIdCounter++;
        newPatient.totalBill = 0;
        newPatient.isDischarged = false;

        cout << "Enter patient's name: ";
        cin.ignore();
        getline(cin, newPatient.name);

        cout << "Enter patient's age: ";
        cin >> newPatient.age;

        cout << "Enter patient's illness: ";
        cin.ignore();
        getline(cin, newPatient.ailment);

        cout << "Enter admission date (dd/mm/yyyy): ";
        getline(cin, newPatient.admissionDate);

        cout << "Enter patient's phone number: ";
        getline(cin, newPatient.phoneNumber);

        patients[patientCount] = newPatient;
        patientCount++;

        cout << "Patient admitted successfully!\n";
    }

    void scheduleAppointment()
    {
        if (appointmentCount >= MAX_APPOINTMENTS)
        {
            cout << "No more appointments can be scheduled!\n";
            return;
        }

        int patientId;
        cout << "Enter patient ID to schedule an appointment: ";
        cin >> patientId;

        bool patientExists = false;
        for (int i = 0; i < patientCount; i++)
        {
            if (patients[i].id == patientId)
            {
                patientExists = true;
                break;
            }
        }

        if (!patientExists)
        {
            cout << "Invalid patient ID!\n";
            return;
        }

        Appointment newAppointment;
        newAppointment.patientId = patientId;

        cout << "Enter appointment date (dd/mm/yyyy): ";
        cin.ignore();
        getline(cin, newAppointment.appointmentDate);

        cout << "Enter doctor's name: ";
        getline(cin, newAppointment.doctor.name);

        cout << "Enter doctor's specialization: ";
        getline(cin, newAppointment.doctor.specialization);

        appointments[appointmentCount] = newAppointment;
        appointmentCount++;

        cout << "Appointment scheduled successfully!\n";
    }

    void displayAppointments()
    {
        if (appointmentCount == 0)
        {
            cout << "No appointments scheduled.\n";
            return;
        }

        cout << "List of scheduled appointments:\n";
        for (int i = 0; i < appointmentCount; i++)
        {
            cout << "Patient ID: " << appointments[i].patientId
                 << ", Appointment Date: " << appointments[i].appointmentDate
                 << ", Doctor: " << appointments[i].doctor.name
                 << ", Specialization: " << appointments[i].doctor.specialization << "\n";
        }
    }

    void cancelAppointment()
    {
        if (appointmentCount == 0)
        {
            cout << "No appointments to cancel.\n";
            return;
        }

        int patientId;
        cout << "Enter patient ID to cancel the appointment: ";
        cin >> patientId;

        for (int i = 0; i < appointmentCount; i++)
        {
            if (appointments[i].patientId == patientId)
            {
                for (int j = i; j < appointmentCount - 1; j++)
                {
                    appointments[j] = appointments[j + 1];
                }
                appointmentCount--;
                cout << "Appointment canceled successfully!\n";
                return;
            }
        }

        cout << "Appointment not found for patient ID " << patientId << ".\n";
    }

    void dischargePatient()
    {
        int patientId;
        cout << "Enter patient ID to discharge: ";
        cin >> patientId;

        for (int i = 0; i < patientCount; i++)
        {
            if (patients[i].id == patientId)
            {
                if (patients[i].isDischarged)
                {
                    cout << "Patient has already been discharged.\n";
                    return;
                }

                patients[i].isDischarged = true;
                cout << "Patient " << patients[i].name << " has been discharged.\n";
                return;
            }
        }

        cout << "Invalid patient ID!\n";
    }

    void processPayment()
    {
        int patientId;
        double amountPaid;
        cout << "Enter patient ID for billing: ";
        cin >> patientId;

        for (int i = 0; i < patientCount; i++)
        {
            if (patients[i].id == patientId)
            {
                if (patients[i].isDischarged)
                {
                    cout << "Enter total bill amount for the patient: $";
                    cin >> patients[i].totalBill;

                    cout << "Enter amount paid by the patient: $";
                    cin >> amountPaid;

                    double balance = patients[i].totalBill - amountPaid;

                    if (balance == 0)
                    {
                        cout << "Full payment received. Thank you!\n";
                    }
                    else if (balance > 0)
                    {
                        cout << "Remaining balance: $" << balance << "\n";
                    }
                    else
                    {
                        cout << "Overpayment detected. Please refund $" << -balance << "\n";
                    }
                    return;
                }
                else
                {
                    cout << "Patient has not been discharged yet.\n";
                    return;
                }
            }
        }

        cout << "Invalid patient ID!\n";
    }

    void addStaff()
    {
        if (staffCount >= MAX_STAFF)
        {
            cout << "Maximum staff capacity reached.\n";
            return;
        }

        Staff newStaff;
        newStaff.id = staffIdCounter++;

        cout << "Enter staff member's name: ";
        cin.ignore();
        getline(cin, newStaff.name);

        cout << "Enter staff member's position: ";
        getline(cin, newStaff.position);

        staff[staffCount] = newStaff;
        staffCount++;

        cout << "Staff member added successfully!\n";
    }
 
    void deleteStaff()
    {
        int staffId;
        cout << "Enter staff ID to delete: ";
        cin >> staffId;

        for (int i = 0; i < staffCount; i++)
        {
            if (staff[i].id == staffId)
            {
                for (int j = i; j < staffCount - 1; j++)
                {
                    staff[j] = staff[j + 1];
                }
                staffCount--;
                cout << "Staff member deleted successfully!\n";
                return;
            }
        }

        cout << "Invalid staff ID!\n";
    }

    void displayPatients()
    {
        if (patientCount == 0)
        {
            cout << "No patients admitted.\n";
            return;
        }

        cout << "List of admitted patients:\n";
        for (int i = 0; i < patientCount; i++)
        {
            cout << "ID: " << patients[i].id << ", Name: " << patients[i].name
                 << ", Age: " << patients[i].age << ", Ailment: " << patients[i].ailment
                 << ", Admission Date: " << patients[i].admissionDate
                 << ", Phone Number: " << patients[i].phoneNumber
                 << ", Total Bill: $" << patients[i].totalBill
                 << ", Discharged: " << (patients[i].isDischarged ? "Yes" : "No") << "\n";
        }
    }

    void displayStaff()
    {
        if (staffCount == 0)
        {
            cout << "No staff members available.\n";
            return;
        }

        cout << "List of staff members:\n";
        for (int i = 0; i < staffCount; i++)
        {
            cout << "ID: " << staff[i].id << ", Name: " << staff[i].name
                 << ", Position: " << staff[i].position << "\n";
        }
    }
};

int main()
{
    HospitalSystem hospital;

    int choice;
    do
    {
        cout << "\nHospital Management System Menu:\n";
        cout << "1. Admit Patient\n";
        cout << "2. Schedule Appointment\n";
        cout << "3. Display Appointments\n";
        cout << "4. Cancel Appointment\n";
        cout << "5. Discharge Patient\n";
        cout << "6. Process Payment\n";
        cout << "7. Add Staff Member\n";
        cout << "8. Delete Staff Member\n";
        cout << "9. Display All Patients\n";
        cout << "10. Display All Staff Members\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            hospital.admitPatient();
            break;
        case 2:
            hospital.scheduleAppointment();
            break;
        case 3:
            hospital.displayAppointments();
            break;
        case 4:
            hospital.cancelAppointment();
            break;
        case 5:
            hospital.dischargePatient();
            break;
        case 6:
            hospital.processPayment();
            break;
        case 7:
            hospital.addStaff();
            break;
        case 8:
            hospital.deleteStaff();
            break;
        case 9:
            hospital.displayPatients();
            break;
        case 10:
            hospital.displayStaff();
            break;
        case 11:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 11);

    return 0;
}
