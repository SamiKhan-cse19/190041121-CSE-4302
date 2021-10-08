#include<iostream>
using namespace std;

class Base {
    int bDataA;
    int bDataB;
public:
    Base() {
        bDataA = 0;
        bDataB = 100;
    }
    class AGreaterThanB {
    };

    int getBDataA() {
        return bDataA;
    }
    void setBDataA(int a) {
        if(a > bDataB) throw AGreaterThanB();
        bDataA = a;
    }
    void setB(int b) {
        bDataB = b;
    }

};

class Derr : public Base {
public:
    void setBDataB(int b) {
        if(b < getBDataA()) throw AGreaterThanB();
        setB(b);
    }
};

int main() {
    Base b;
    Derr d;
    try {
        d.setBDataB(-5);
    } catch (Base::AGreaterThanB) {
        cout<<"A Greater than B Exception"<<endl;
    }

    for (int i = 8; i > 0; i--) {
			for (int j = 8; j > 0; j--) {
				cout<<((8*(j-1) + i))<< " ";
			}
			cout<<endl;
		}

}
