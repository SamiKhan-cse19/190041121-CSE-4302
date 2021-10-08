#include <iostream>
using namespace std;

const int MAXSIZE = 100;

template<class T> class my_stack {

    T arr[MAXSIZE];
    int top;
public:
    my_stack() : top(0) {
    }
    void push(T x) {
        if(top + 1 >= MAXSIZE) return ;

        arr[top++] = x;
    }
    T pop(){
        if(top == 0) return -1;

        return arr[--top];
    }
    T peek() {
        if(top == 0) return -1;

        return arr[0];
    }
};

int main() {
    int choice;
    my_stack<int> stki;
    while(true) {
        cout<<"integer stack operations:\n"
        "1. Push item\n2. Pop item\n3. Peek first item\n0. Done with integers\n"
        "Enter choice:\t";
        cin>>choice;
        switch(choice) {
        case 1:
            int x;
            cout<<"Enter item:\t";
            cin>>x;
            stki.push(x);
            cout<<endl;
            break;
        case 2:
            cout<<"Popped item: "<<stki.pop()<<endl;
            break;
        case 3:
            cout<<"First inserted item: "<<stki.peek()<<endl;
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input of choice"<<endl;
        }
        if(!choice) break;
    }

    my_stack<float> stkf;
    while(true) {
        cout<<"float stack operations:\n"
        "1. Push item\n2. Pop item\n3. Peek first item\n0. Done with floats\n"
        "Enter choice:\t";
        cin>>choice;
        switch(choice) {
        case 1:
            float x;
            cout<<"Enter item:\t";
            cin>>x;
            stkf.push(x);
            cout<<endl;
            break;
        case 2:
            cout<<"Popped item: "<<stkf.pop()<<endl;
            break;
        case 3:
            cout<<"First inserted item: "<<stkf.peek()<<endl;
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input of choice"<<endl;
        }
        if(!choice) break;
    }

}
