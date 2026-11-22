#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
    string employeeId;
    string employeeName;
public:
    void acceptEmployee()
    {
        cout << "Enter Employee ID: ";
        getline(cin, employeeId);
        cout << "Enter Employee Name: ";
        getline(cin, employeeName);
    }
    void displayEmployee() const
    {
        cout << "\nEmployee ID       : " << employeeId << endl;
        cout << "Employee Name     : " << employeeName << endl;
    }
};
class PersonalRecord : virtual public Employee
{
protected:
    string dateOfBirth;
    string address;
    string contactNumber;
public:
    void acceptPersonal()
    {
        cout << "\n--- Personal Details ---" << endl;
        cout << "Enter Date of Birth: ";
        getline(cin, dateOfBirth);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Contact Number: ";
        getline(cin, contactNumber);
    }
    void displayPersonal() const
    {
        cout << "\n--- Personal Details ---" << endl;
        cout << "Date of Birth     : " << dateOfBirth << endl;
        cout << "Address           : " << address << endl;
        cout << "Contact Number    : " << contactNumber << endl;
    }
};
class ProfessionalRecord : virtual public Employee
{
protected:
    string designation;
    string department;
    string organization;
    string yearsOfExperience;
public:
    void acceptProfessional()
    {
        cout << "\n--- Professional Details ---" << endl;
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Organization: ";
        getline(cin, organization);
        cout << "Enter Years of Experience: ";
        getline(cin, yearsOfExperience);
    }
    void displayProfessional() const
    {
        cout << "\n--- Professional Details ---" << endl;
        cout << "Designation       : " << designation << endl;
        cout << "Department        : " << department << endl;
        cout << "Organization      : " << organization << endl;
        cout << "Years of Experience: " << yearsOfExperience << endl;
    }
};
class AcademicRecord : virtual public Employee
{
protected:
    string highestQualification;
    string specialization;
    string university;
    string passingYear;
public:
    void acceptAcademic()
    {
        cout << "\n--- Academic Details ---" << endl;
        cout << "Enter Highest Qualification: ";
        getline(cin, highestQualification);
        cout << "Enter Specialization: ";
        getline(cin, specialization);
        cout << "Enter University: ";
        getline(cin, university);
        cout << "Enter Passing Year: ";
        getline(cin, passingYear);
    }
    void displayAcademic() const
    {
        cout << "\n--- Academic Details ---" << endl;
        cout << "Highest Qualification: " << highestQualification << endl;
        cout << "Specialization     : " << specialization << endl;
        cout << "University         : " << university << endl;
        cout << "Passing Year       : " << passingYear << endl;
    }
};
class EmployeeBioData : public PersonalRecord,
                        public ProfessionalRecord,
                        public AcademicRecord
{
public:
    void accept()
    {
        acceptEmployee();
        acceptPersonal();
        acceptProfessional();
        acceptAcademic();
    }
    void display() const
    {
        cout << "\n========== EMPLOYEE BIO-DATA ==========" << endl;
        displayEmployee();
        displayPersonal();
        displayProfessional();
        displayAcademic();
        cout << "\n========================================" << endl;
    }
};
int main()
{
    EmployeeBioData employee;
    cout << "===== EMPLOYEE BIO-DATA SYSTEM =====" << endl;
    employee.accept();
    employee.display();
    return 0;
}
