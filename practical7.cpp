#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <cctype>
using namespace std;
// User-defined exception class
class InvalidUserException : public exception 
{
private:
    string message;
public:
    InvalidUserException(const string &msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
// Helper: convert string to lowercase for case-insensitive comparison
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
}
// a. Age must be between 18 and 55
void checkAge(int age) {
    if (age < 18 || age > 55)
        throw InvalidUserException("Age must be between 18 and 55.");
}
// b. Income must be between Rs. 50,000 and Rs. 1,00,000 per month
void checkIncome(double income) {
    if (income < 50000 || income > 100000)
        throw InvalidUserException("Income must be between Rs. 50,000 and Rs. 1,00,000 per month.");
}
// c. City must be Pune / Mumbai / Bangalore / Chennai
void checkCity(const string &city) {
    string c = toLower(city);
    if (c != "pune" && c != "mumbai" && c != "bangalore" && c != "chennai")
        throw InvalidUserException("City must be Pune, Mumbai, Bangalore or Chennai.");
}
// d. User must have a 4-wheeler
void checkVehicle(const string &vehicle) {
    string v = toLower(vehicle);
    if (v != "yes" && v != "y")
        throw InvalidUserException("User must own a 4-wheeler.");
}
int main() {
    int age;
    double income;
    string city, vehicle;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter monthly income (Rs.): ";
    cin >> income;
    cout << "Enter city: ";
    cin >> city;
    cout << "Do you have a 4-wheeler? (yes/no): ";
    cin >> vehicle;
    try {
        checkAge(age);
        checkIncome(income);
        checkCity(city);
        checkVehicle(vehicle);
        cout << "\nAll conditions met. User is eligible." << endl;
    }
    catch (const InvalidUserException &e) {
        cout << "\nException caught: " << e.what() << endl;
    }
    return 0;
}
