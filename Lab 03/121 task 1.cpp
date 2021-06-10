#include <iostream>
using namespace std;

class Counter {
private:
    int count;
    int incrementStep;
public:
    Counter() : count(0), incrementStep(1) {

    }
    void setIncrementStep(int step_val) {
        incrementStep = step_val;
    }
    int getCount() {
        return count;
    }
    void increment() {
        count += incrementStep;
    }
    void resetCount() {
        count = 0;
    }
};

int main() {
    Counter c;
    cout<<c.getCount()<<endl;
    c.setIncrementStep(2);
    c.increment();
    cout<<c.getCount()<<endl;
    c.increment();
    cout<<c.getCount()<<endl;
    c.resetCount();
    c.increment();
    cout<<c.getCount()<<endl;
}
