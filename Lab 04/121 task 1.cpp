#include <iostream>
#include <cstring>
using namespace std;

class Calculator {
private:
    int field;
public:
    Calculator(): field(0) {
    }
    Calculator(int val): field(val){
    }
    int getValue(){
        return field;
    }
    void setValue(int val) {
        field = val;
    }
    void add( int Value ) {
        field += Value;
    }
    void subtract( int Value ){
        field -= Value;
    }
    void multiply( int Value ){
        field *= Value;
    }
    void divideBy( int Value ){
        if(Value == 0) {
            cout<<"Error : divide by 0 is undefined."<<endl;
            return;
        }
        field /= Value;
    }
    void clear() {
        field = 0;
    }
    void display() {
        cout<<"Calculator display: "<<field<<endl;
    }
    ~Calculator() {
        cout<<"Calculator object is destroyed."<<endl;
    }
};

int main() {
    char* command = new char[10];
    int var;
    Calculator calc;
    while(true) {
        for(int i=0; i<50; i++) cout<<'-';
        cout<<endl;
        cin>>command;
        if(!strcmp(command, "add")){
            cin>>var;
            calc.add(var);
            calc.display();
        }
        else if(!strcmp(command, "subtract")){
            cin>>var;
            calc.subtract(var);
            calc.display();
        }
        else if(!strcmp(command, "multiply")){
            cin>>var;
            calc.multiply(var);
            calc.display();
        }
        else if(!strcmp(command, "divide")){
            cin>>command;
            if(strcmp(command, "by")) continue;
            cin>>var;
            calc.divideBy(var);
            calc.display();
        }
        else if(!strcmp(command, "clear")){
            calc.clear();
            calc.display();
            break;
        }
    }
    return 0;
}


