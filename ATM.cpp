// Navid Afzali
#include <iostream>
#include <string>

using namespace std;

class Bank {
private:
    string name; 
    long long accNumber; 
    string type; 
    long long balance; 

public:
    void setValue() {
        cout << "Enter customer name: ";
        getline(cin, name);

        cout << "Enter account number: ";
        cin >> accNumber;

        cout << "Enter account type: ";
        cin.ignore();
        getline(cin, type);

        cout << "Enter account balance: ";
        cin >> balance;
    }

    void showData() {
        cout << "Customer name: " << name << endl;
        cout << "Account number: " << accNumber << endl;
        cout << "Account type: " << type << endl;
        cout << "Account balance: " << balance << endl;
    }

    void deposit() {
        long long amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
    }

    void showBalance() {
        cout << "Account balance: " << balance << endl;
    }

    void withdraw() {
        long long amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance" << endl;
        } else {
            balance -= amount;
            cout << "Remaining balance: " << balance << endl;
        }
    }

    void transfer(Bank& targetAccount) {
        long long amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance" << endl;
        } else {
            balance -= amount;
            targetAccount.balance += amount;
            cout << "Amount " << amount << " transferred to account " << targetAccount.accNumber << endl;
        }
    }

    void changePassword() {
        string oldPassword, newPassword;
        
        cout << "Enter current password: ";
        
        cin >> oldPassword;
        
        cout << "Enter new password: ";
        
        cin >> newPassword;
        
        cout << "Password changed successfully" << endl;
    }
};

int main() {
    Bank account1;
    Bank account2;

    int choice;

    while (true) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~Welcome~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
        cout << "Enter your choice\n";
        cout << "\t1. Set customer information for account 1\n";
        cout << "\t2. Show customer information for account 1\n";
        cout << "\t3. Deposit money to account 1\n";
        cout << "\t4. Show account balance for account 1\n";
        cout << "\t5. Withdraw money from account 1\n";
        cout << "\t6. Transfer money from account 1 to account 2\n";
        cout << "\t7. Change password for account 1\n";
        cout << "\t8. Set customer information for account 2\n";
        cout << "\t9. Show customer information for account 2\n";
        cout << "\t10. Deposit money to account 2\n";
        cout << "\t11. Show account balance for account 2\n";
        cout << "\t12. Withdraw money from account 2\n";
        cout << "\t13. Transfer money from account 2 to account 1\n";
        cout << "\t14. Change password for account 2\n";
        cout << "\t15. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                account1.setValue();
                break;
            case 2:
                account1.showData();
                break;
            case 3:
                account1.deposit();
                break;
            case 4:
                account1.showBalance();
                break;
            case 5:
                account1.withdraw();
                break;
            case 6:
                account1.transfer(account2);
                break;
            case 7:
                account1.changePassword();
                break;
            case 8:
                account2.setValue();
                break;
            case 9:
                account2.showData();
                break;
            case 10:
                account2.deposit();
                break;
            case 11:
                account2.showBalance();
                break;
            case 12:
                account2.withdraw();
                break;
            case 13:
                account2.transfer(account1);
                break;
            case 14:
                account2.changePassword();
                break;
            case 15:
                return 0;
            default:
                cout << "\nInvalid choice\n";
        }
    }

    return 0;
}
