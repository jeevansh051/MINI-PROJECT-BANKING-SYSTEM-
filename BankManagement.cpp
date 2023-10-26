#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account {
    int account_number;
    string name;
    float balance;
};

void create_account(vector<Account> &accounts);
void deposit(vector<Account> &accounts);
void withdraw(vector<Account> &accounts);
void view_account(const vector<Account> &accounts);

int main() {
    int choice;
    vector<Account> accounts;

    while (true) {
        cout << "\n\n***BANK MANAGEMENT SYSTEM***\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. View Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create_account(accounts);
                break;
            case 2:
                deposit(accounts);
                break;
            case 3:
                withdraw(accounts);
                break;
            case 4:
                view_account(accounts);
                break;
            case 5:
                cout << "\nThank you for using the banking system!\n";
                exit(0);
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }
    return 0;
}

void create_account(vector<Account> &accounts) {
    Account newAccount;
    cout << "\nEnter Account Number: ";
    cin >> newAccount.account_number;

    for (const Account &acc : accounts) {
        if (acc.account_number == newAccount.account_number) {
            cout << "An account with this number already exists. Please try again with a different account number.\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> newAccount.name;
    cout << "Enter Initial Balance: ";
    cin >> newAccount.balance;
    accounts.push_back(newAccount);
    cout << "\nAccount created successfully.\n";
}

void deposit(vector<Account> &accounts) {
    int account_number;
    float deposit_amount;
    int found = 0;
    cout << "\nEnter Account Number: ";
    cin >> account_number;

    for (Account &acc : accounts) {
        if (acc.account_number == account_number) {
            found = 1;
            cout << "\nEnter Amount to be Deposited: ";
            cin >> deposit_amount;
            acc.balance += deposit_amount;
            cout << "\nAmount Deposited Successfully.\n";
            break;
        }
    }

    if (found == 0)
        cout << "\nAccount not found.\n";
}

void withdraw(vector<Account> &accounts) {
    int account_number;
    float withdraw_amount;
    int found = 0;
    cout << "\nEnter Account Number: ";
    cin >> account_number;

    for (Account &acc : accounts) {
        if (acc.account_number == account_number) {
            found = 1;
            cout << "\nEnter Amount to be Withdrawn: ";
            cin >> withdraw_amount;

            if (withdraw_amount <= acc.balance) {
                acc.balance -= withdraw_amount;
                cout << "\nAmount Withdrawn Successfully.\n";
            } else {
                cout << "\nInsufficient Balance.\n";
            }
            break;
        }
    }

    if (found == 0)
        cout << "\nAccount not found.\n";
}

void view_account(const vector<Account> &accounts) {
    int account_number;
    int found = 0;
    cout << "\nEnter Account Number: ";
    cin >> account_number;

    for (const Account &acc : accounts) {
        if (acc.account_number == account_number) {
            found = 1;
            cout << "\nAccount Number: " << acc.account_number << endl;
            cout << "Name: " << acc.name << endl;
            cout << "Balance: " << acc.balance << endl;
            break;
        }
    }

    if (found == 0)
        cout << "\nAccount not found.\n";
}
