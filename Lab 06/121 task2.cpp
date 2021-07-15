#include <iostream>
using namespace std;

class FLOAT {
private:
    float data;
public:
    FLOAT():data(0){
    }
    FLOAT(float f):data(f){
    }
    ~FLOAT(){
    }
    void display(){
        cout<<data<<endl;
    }
    FLOAT operator+(const FLOAT& f) const{
        return FLOAT(data+f.data);
    }
    FLOAT operator-(const FLOAT& f) const{
        return FLOAT(data-f.data);
    }
    FLOAT operator*(const FLOAT& f) const{
        return FLOAT(data*f.data);
    }
    FLOAT operator/(const FLOAT& f) const{
        if(f.data==0) {
            cout<<"Error: invalid math operation. Division by zero."<<endl;
            exit(1);
        }
        return FLOAT(data/f.data);
    }
    operator int() const {
        return static_cast<int>(data);
    }
};

int main(){
    FLOAT f1(5), f2(2), f3, f4;
    f3=f1/f2;
    f4=f1-f2;
    f3.display();
    f4.display();
    int i = f3;
    cout<<i<<endl;
}
