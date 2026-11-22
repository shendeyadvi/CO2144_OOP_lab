#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
  int accountNumber;
  string accountHolderName;
  double accountBalance;
  string accountType;
  // Static variable to count accounts
  static int totalAccounts;
public:
  // Constructor
  BankAccount(int accNo, string name, double balance, string type)
  {
     this->accountNumber = accNo;
     this->accountHolderName = name;
     this->accountBalance = balance;
     this->accountType = type;
     totalAccounts++;
  }
  BankAccount()
  {
    accountNumber = 0;
    accountHolderName = "Unknown";
    accountBalance = 0.0;
    accountType = "Unknown";
    totalAccounts++;
   }
  // Accept Member Function
  void accept()
  {
   cout<< "\nEnter Account Number: ";
   cin>> accountNumber;
   cin.ignore();
   cout<<"\nEnter Account Holder Name: ";
   getline(cin, accountHolderName);
   cout<<"\nEnter Account Type (Savings or Current): ";
   getline(cin, accountType);
   cout<<"\nEnter Accoutn Balance: ";
   cin>>accountBalance;
  }
  // Function to display account information
  void display()
  {
     cout << "\n----- Account Information -----" << endl;
     cout << "Account Number : " << accountNumber << endl;
     cout << "Account Holder : " << accountHolderName << endl;
     cout << "Account Balance: Rs. " << accountBalance << endl;
     cout << "Account Type : " << accountType << endl;
  }
  // Inline function to calculate and add interest
  inline void addInterest(double rate)
  {
     double interest = accountBalance * rate / 100;
     accountBalance += interest;
     cout << "Interest Added : Rs. " << interest << endl;
     cout << "Updated Balance: Rs. " << accountBalance << endl;
  }
  // Static function to display total accounts
  static void displayTotalAccounts()
  {
     cout << "\nTotal Accounts Created: "
        << totalAccounts << endl;
  }
  // Friend function declaration
  friend void compareBalance(const BankAccount &a1, const BankAccount &a2);
};
// Definition of static variable
int BankAccount::totalAccounts = 0;
// Friend function to compare balances
void compareBalance(const BankAccount &a1, const BankAccount &a2)
{
  cout << "\n----- Balance Comparison -----" << endl;
  if (a1.accountBalance > a2.accountBalance)
  {
     cout << a1.accountHolderName << " has a higher balance." << endl;
  }
  else if (a2.accountBalance > a1.accountBalance)
  {
     cout << a2.accountHolderName << " has a higher balance." << endl;
  }
  else
  {
     cout << "Both accounts have the same balance." << endl;
  }
}
int main()
{
  // Entry of account details
  BankAccount account1;
  BankAccount account2(102, "Priya", 75000, "Current");
  account1.accept();
  // Display account information
  account1.display();
  account2.display();
  // Calculate interest using inline function
  cout << "\nAdding interest to Account 1..." << endl;
  account1.addInterest(5);
  // Compare balances using friend function
  compareBalance(account1, account2);
  // Display total number of accounts
  BankAccount::displayTotalAccounts();
  return 0;
}
