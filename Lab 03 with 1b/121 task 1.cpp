#include <iostream>
using namespace std;

class RationalNumber {
private:
    int numerator, denominator;
public:
    RationalNumber() : numerator(0), denominator(1) {
    }
    void assign(int numerator, int denominator) {
        if(denominator == 0) {
            cout<<"Error: The given number is undefined"<<endl;
            return;
        }
        this->numerator = numerator;
        this->denominator = denominator;
    }
    double convert() {
        return static_cast<double> (numerator) / denominator;
    }
    void invert() {
        if(numerator == 0) {
            cout<<"Error: The inverse number is undefined"<<endl;
            return;
        }
        int temp = numerator;
        numerator = denominator;
        denominator = temp;
    }
    void print() {
        cout<<"The Rational Number is "<<numerator<<"/"<<denominator<<endl;
    }
};

int main() {
    RationalNumber n;
    n.assign(1, 3);
    n.print();
    cout<<n.convert()<<endl;
    n.invert();
    n.print();
    cout<<n.convert()<<endl;
}

