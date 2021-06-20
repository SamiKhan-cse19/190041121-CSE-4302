#include<iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:

    Distance(int f, float i) : feet(f), inches(i){

    }
    void show() {
        cout<<"Feet: "<<feet<<endl;
        cout<<"Inches: "<<inches<<endl;
    }
    void add_dist(Distance);
};

void Distance::add_dist(Distance d2) {
    feet += d2.feet;
    inches += d2.inches;
    if( inches > 12 ) {
        feet++;
        inches-=12;
    }
}

int main() {
    Distance d1(3, 7.5), d2(0, 5);
    d1.add_dist(d2);
    d1.show();
    return 0;
}
