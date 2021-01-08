/*
Create a simple class SavingsAccount for savings account used in banks as follows: Each SavingsAccount object
should have three data members to store the account holder's name, unique account number and balance of the
account. Assume account numbers are integers and generated sequentially. Note that once an account number is
allocated to an account, it does not change during the entire operational period of the account. The bank also
specifies a rate of interest for all savings accounts created. Write relevant methods (such as withdraw, deposit
etc.) in the class. The bank restricts that each account must have a minimum balance of Rs. 1000. Now create
100 SavingsAccount objects specifying balance at random ranging from Rs. 1,000 to 1,00,000. Now, calculate
the interest for one year to be paid to each account and deposit the interest to the corresponding balance. Also
find out total amount of interest to be paid to all accounts in one year.
*/

#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    string name;
    int acc_no;
    double bal;

public:
    SavingsAccount();
    SavingsAccount(string name, int acc_no, double bal);
    void withdraw(double);
    void deposit(double);
    double annualInterest(double);
};

SavingsAccount::SavingsAccount()
{
    name = "";
    acc_no = 0;
    bal = 0.0;
}

SavingsAccount::SavingsAccount(string name, int acc_no, double bal)
{
    this->name = name;
    this->acc_no = acc_no;
    this->bal = bal;
}

void SavingsAccount::withdraw(double amt)
{
    if (this->bal - amt < 1000)
    {
        cout << "Withdrawal not possible due to insufficient minimum balance\n";
        return;
    }
    this->bal -= amt;
    cout << "Withdrawal in A/C " << this->acc_no << " successful: Rs " << amt << "\n";
}

void SavingsAccount::deposit(double amt)
{
    this->bal += amt;
    cout << "Deposit in A/C " << this->acc_no << " successful: Rs " << amt << "\n";
}

double SavingsAccount::annualInterest(double rate)
{
    double interest = this->bal * rate / 100.0;
    return interest;
}

int main()
{
    const int no_of_accs = 100;

    SavingsAccount savac[no_of_accs];
    for (int i = 0; i < no_of_accs; i++)
    {
        // random data
        string name = "account holder " + to_string(i + 1);
        double bal = 1000.0 * (i + 1);
        savac[i] = SavingsAccount(name, i + 1, bal);
    }

    double rate;
    cout << "Enter rate of interest\n";
    cin >> rate;

    double tot_int = 0.0;

    // depositing interest to each account
    for (int i = 0; i < no_of_accs; i++)
    {
        double interest = savac[i].annualInterest(rate);
        savac[i].deposit(interest);
        tot_int += interest;
    }
    cout << "Total interest payable by bank: Rs " << tot_int << "\n";
}