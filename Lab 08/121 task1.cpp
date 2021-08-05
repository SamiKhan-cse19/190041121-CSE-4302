#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNo;
    string accountName;

protected:
    float balance;

public:
    Account(int accountPrefix, int nextAccountNo, string aName, float balance) : accountName(aName), balance(balance) {
        accountNo = to_string(accountPrefix) + " - " + to_string(nextAccountNo);
    }
    string getAccountNo() {
        return accountNo;
    }
    void setAccountNo(string aNo) {
        accountNo = aNo;
    }
    string getAccountName() {
        return accountName;
    }
    void setAccountName(string aName) {
        accountName = aName;
    }
    float getBalance() {
        return balance;
    }
    void setBalance(float bal) {
        balance = bal;
    }

    void description() const {
        cout<<"Account no: "<<accountNo<<"\nAccount Name: "<<accountName<<"\nBalance: "<<balance<<endl;
    }

};

class CurrentAccount : public Account {
private:
    const static int serviceCharge = 100;
    const static int accountPrefix = 100;
    static int nextAccount;
protected:
public:
    CurrentAccount(string name, float balance) : Account(accountPrefix, nextAccount, name, balance) {
        nextAccount++;
    }
    int getServiceCharge() const {
        return serviceCharge;
    }
    int getAccountPrefix() const {
        return accountPrefix;
    }
    int getNextAccount() const {
        return nextAccount;
    }
    void setNextAccount(int newNextAccount) {
        nextAccount = newNextAccount;
    }
    void nextAccountNo() {
        nextAccount ++;
    }

    void description() const {
        Account :: description();
        cout<<"Service Charge: "<<serviceCharge<<endl;
    }
};

int CurrentAccount :: nextAccount = 0;

class SavingsAccount : public Account {
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix = 200;
    static int nextAccount;
protected:
public:
    SavingsAccount(string name, float balance, float interestRate, float monthlyDepositAmount) :
        Account(accountPrefix, nextAccount, name, balance), interestRate(interestRate), monthlyDepositAmount(monthlyDepositAmount) {
        nextAccount++;
    }
    float getInterestRate() const {
        return interestRate;
    }
    void setInterestRate(float newInterestRate) {
        interestRate = newInterestRate;
    }
    float getMonthlyDepositAmount() const {
        return monthlyDepositAmount;
    }
    void setMonthlyDepositAmount(float newMonthlyDepositAmount) {
        monthlyDepositAmount = newMonthlyDepositAmount;
    }
    int getAccountPrefix() const {
        return accountPrefix;
    }
    int getNextAccount() const {
        return nextAccount;
    }
    void setNextAccount(int newNextAccount) {
        nextAccount = newNextAccount;
    }
    void nextAccountNo() {
        nextAccount ++;
    }

    void deposit() {
        balance += monthlyDepositAmount;
    }
    void description() const {
        Account :: description();
        cout<<"Interest rate: "<<interestRate<<"\nMonthly Deposit Amount: "<<monthlyDepositAmount<<endl;
    }

};
int SavingsAccount :: nextAccount = 0;

class MonthlyDepositScheme : public Account {
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix = 300;
    static int nextAccount;
protected:
public:
    MonthlyDepositScheme(string name, float balance, float interestRate, float monthlyDepositAmount) :
        Account(accountPrefix, nextAccount, name, balance), interestRate(interestRate), monthlyDepositAmount(monthlyDepositAmount) {
        nextAccount++;
    }
    float getInterestRate() const {
        return interestRate;
    }
    void setInterestRate(float newInterestRate) {
        interestRate = newInterestRate;
    }
    float getMonthlyDepositAmount() const {
        return monthlyDepositAmount;
    }
    void setMonthlyDepositAmount(float newMonthlyDepositAmount) {
        monthlyDepositAmount = newMonthlyDepositAmount;
    }
    int getAccountPrefix() const {
        return accountPrefix;
    }
    int getNextAccount() const {
        return nextAccount;
    }
    void setNextAccount(int newNextAccount) {
        nextAccount = newNextAccount;
    }
    void nextAccountNo() {
        nextAccount ++;
    }

    void interest() {
        float interest = balance * interestRate * 0.01;
        balance += interest;
    }
    void deposit() {
        balance += monthlyDepositAmount;
    }
    void description() const {
        Account :: description();
        cout<<"Interest rate: "<<interestRate<<"\nMonthly Deposit Amount: "<<monthlyDepositAmount<<endl;
    }

};
int MonthlyDepositScheme :: nextAccount = 0;

class TwoYearMDS : public MonthlyDepositScheme {
private:
    float maximumInterest;
protected:
public:
    TwoYearMDS(string name, float balance, float interestRate, float monthlyDepositAmount, float maximumInterest) :
        MonthlyDepositScheme(name, balance, interestRate, monthlyDepositAmount), maximumInterest(maximumInterest) {
    }
    float getMaximumInterest() const {
        return maximumInterest;
    }
    void setMaximumInterest(float newMaximumInterest) {
        maximumInterest = newMaximumInterest;
    }
    void interest() {
        float interest = balance * getInterestRate() * 0.01;
        balance += min(maximumInterest, interest);
    }

    void description() const {
        MonthlyDepositScheme :: description();
        cout<<"Maximum Interest"<<maximumInterest<<endl;
    }
};

class FiveYearMDS : public MonthlyDepositScheme {
private:
    float maximumInterest;
protected:
public:
    FiveYearMDS(string name, float balance, float interestRate, float monthlyDepositAmount, float maximumInterest) :
        MonthlyDepositScheme(name, balance, interestRate, monthlyDepositAmount), maximumInterest(maximumInterest) {
    }
    float getMaximumInterest() const {
        return maximumInterest;
    }
    void setMaximumInterest(float newMaximumInterest) {
        maximumInterest = newMaximumInterest;
    }

    void interest() {
        float interest = balance * getInterestRate() * 0.01;
        balance += min(maximumInterest, interest);
    }
    void description() const {
        MonthlyDepositScheme :: description();
        cout<<"Maximum Interest"<<maximumInterest<<endl;
    }
};

class InitialDepositMDS : public MonthlyDepositScheme {
private:
    float maximumInterest;
    float initialDepositAmount;
protected:
public:
    InitialDepositMDS(string name, float balance, float interestRate, float monthlyDepositAmount, float maximumInterest, float initialDepositAmount) :
        MonthlyDepositScheme(name, balance, interestRate, monthlyDepositAmount), maximumInterest(maximumInterest), initialDepositAmount(initialDepositAmount) {
    }
    float getMaximumInterest() const {
        return maximumInterest;
    }
    void setMaximumInterest(float newMaximumInterest) {
        maximumInterest = newMaximumInterest;
    }
    float getInitialDepositAmount() const {
        return initialDepositAmount;
    }
    void setInitialDepositAmount(float newInitialDepositAmount) {
        initialDepositAmount = newInitialDepositAmount;
    }

    void interest() {
        float interest = balance * getInterestRate() * 0.01;
        balance += min(maximumInterest, interest);
    }
    void description() const {
        MonthlyDepositScheme :: description();
        cout<<"Maximum Interest"<<maximumInterest<<"\nInitial Deposit Amount: "<<initialDepositAmount<<endl;
    }
};

class LoanAccount : public Account {
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix = 900;
    static int nextAccount;
protected:
public:
    LoanAccount(string name, float balance, float interestRate, float monthlyDepositAmount) :
        Account(accountPrefix, nextAccount, name, balance), interestRate(interestRate), monthlyDepositAmount(monthlyDepositAmount) {
        nextAccount++;
    }
    float getInterestRate() const {
        return interestRate;
    }
    void setInterestRate(float newInterestRate) {
        interestRate = newInterestRate;
    }
    float getMonthlyDepositAmount() const {
        return monthlyDepositAmount;
    }
    void setMonthlyDepositAmount(float newMonthlyDepositAmount) {
        monthlyDepositAmount = newMonthlyDepositAmount;
    }
    int getAccountPrefix() const {
        return accountPrefix;
    }
    int getNextAccount() const {
        return nextAccount;
    }
    void setNextAccount(int newNextAccount) {
        nextAccount = newNextAccount;
    }
    void nextAccountNo() {
        nextAccount ++;
    }

    void interest() {
        float interest = balance * interestRate * 0.01;
        balance += interest;
    }
    void deposit() {
        balance += monthlyDepositAmount;
    }
    void description() const {
        Account :: description();
        cout<<"Interest rate: "<<interestRate<<"\nMonthly Deposit Amount: "<<monthlyDepositAmount<<endl;
    }
};
int LoanAccount :: nextAccount = 0;

int main() {

    CurrentAccount current("Tolkiens", 1200.0f);
    SavingsAccount savings("Robert", 3400.0f, 7.5f, 1000.0f);
    TwoYearMDS twoYearMDS("Sylvia", 5600.0f, 9.5f, 500.f, 1200.f);
    FiveYearMDS fiveYearMDS("Price", 6000.f, 8.5f, 500.f, 1500.f);
    InitialDepositMDS initialDeposit("Salt", 4500.f, 8.f, 600.f, 2000.f, 4500.f);
    LoanAccount loan("Tyler", 4500.f, 9.5f, 1000.f);

    current.description();

    savings.description();
    savings.deposit();
    cout<<"After 1 month, balance = "<<savings.getBalance()<<endl;
    savings.deposit();
    cout<<"After 2 month, balance = "<<savings.getBalance()<<endl;

    twoYearMDS.description();
    twoYearMDS.deposit();
    cout<<"After 1 month, balance = "<<twoYearMDS.getBalance()<<endl;
    twoYearMDS.deposit();
    cout<<"After 2 month, balance = "<<twoYearMDS.getBalance()<<endl;

    fiveYearMDS.description();
    fiveYearMDS.deposit();
    cout<<"After 1 month, balance = "<<fiveYearMDS.getBalance()<<endl;
    fiveYearMDS.deposit();
    cout<<"After 2 month, balance = "<<fiveYearMDS.getBalance()<<endl;

    initialDeposit.description();
    initialDeposit.deposit();
    cout<<"After 1 month, balance = "<<initialDeposit.getBalance()<<endl;
    initialDeposit.deposit();
    cout<<"After 2 month, balance = "<<initialDeposit.getBalance()<<endl;

    loan.description();
    loan.deposit();
    cout<<"After 1 month, balance = "<<loan.getBalance()<<endl;
    loan.deposit();
    cout<<"After 2 month, balance = "<<loan.getBalance()<<endl;

    return 0;
}
