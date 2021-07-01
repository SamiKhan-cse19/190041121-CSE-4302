#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    int accountNum;
    char* holderName;
    int accountType; // Current = 0, Savings = 1
    float balance;
    float minBalance;
public:
    BankAccount(int acNum, char* hName, char* acType, float bal, float minBal): accountNum(acNum), balance(bal), minBalance(minBal) {
        holderName = new char[30];
        strcpy(holderName, hName);
        if(!strcmp(acType, "Current")) accountType = 0;
        else if(!strcmp(acType, "Savings")) accountType = 1;
    }
    BankAccount() {
    }
    void setAcNum(int acNum) {
        accountNum = acNum;
    }
    void setHolName(char* name) {
        strcpy(holderName, name);
    }
    void setAcType(char* type) {
        if(!strcmp(type, "Current")) accountType = 1;
        else if(!strcmp(type, "Savings")) accountType = 1;
        else {
            cout<<"Error: incorrect account type"<<endl;
        }
    }
    void setBalance(float bal) {
        if(bal < minBalance) {
            cout<<"Error: Balance cannot be less than BDT "<<minBalance<<endl;
            return;
        }
        balance = bal;
    }
    void setMinBalance(float minBal) {
        minBalance = minBal;
    }
    void displayAccountInfo() {
        cout<<"Account no.: "<<accountNum<<endl;
        cout<<"Account holder name: "<<holderName<<endl;
        cout<<"Account type: "<<(accountType?"Current":"Savings")<<endl;
        cout<<"Current Balance: BDT "<<balance<<endl;
        cout<<"Minimum Balance: BDT "<<minBalance<<endl;
    }
    void showBalance() {
        cout<<"Current Balance is: "<<balance<<endl;
    }
    void deposit(float amount) {
        balance += amount;
    }
    void withdraw(float amount) {
        if(balance - amount < minBalance) {
            cout<<"Error: Remaining balance cannot be less than BDT "<<minBalance<<endl;
        }
        balance -= amount;
    }
    void giveInterest(float perc = 0.025) {
        int interest = balance * perc;
        int tax = interest * 0.1;
        balance += interest - tax;
    }
    ~BankAccount() {
        delete[] holderName;
        cout<<"Account of Mr. "<<holderName<<" with account no "<<accountNum<<" is destroyed with a balance BDT "<<balance<<endl;
    }
};

int main() {
    BankAccount ac1(1001, "Mohammed Sami Khan", "Savings", 10000, 5000);
    ac1.displayAccountInfo();
    ac1.deposit(1000);
    ac1.showBalance();
    ac1.withdraw(5000);
    ac1.showBalance();
    ac1.giveInterest(0.035);
    ac1.showBalance();
}
