#include <iostream>
#include <cmath>
using namespace std;

class Coordinate {
private:
    float xCoor, yCoor;
public:
    Coordinate():xCoor(0),yCoor(0){
    }
    Coordinate(float x, float y):xCoor(x),yCoor(y){
    }
    ~Coordinate(){
    }
    void display() const{
        cout<<"Abscissa: "<<xCoor<<"\nOrdinate: "<<yCoor<<endl;
    }
    float getDistance(const Coordinate& c) const{
        return sqrt((xCoor-c.xCoor)*(xCoor-c.xCoor)+(yCoor-c.yCoor)*(yCoor-c.yCoor));
    }
    float getDistance() const{
        return getDistance(Coordinate());
    }
    void move_x(float val){
        xCoor+=val;
    }
    void move_y(float val){
        yCoor+=val;
    }
    void move(float val){
        move_x(val);
        move_y(val);
    }
    bool operator > (const Coordinate&) const;
    bool operator >= (const Coordinate&) const;
    bool operator < (const Coordinate&) const;
    bool operator <= (const Coordinate&) const;
    bool operator == (const Coordinate&) const;
    bool operator != (const Coordinate&) const;
    Coordinate operator ++ ();
    Coordinate operator ++ (int);
    Coordinate operator -- ();
    Coordinate operator -- (int);
};

bool Coordinate::operator > (const Coordinate& c) const{
    return getDistance()>c.getDistance();
}
bool Coordinate::operator >= (const Coordinate& c) const{
    return getDistance()>=c.getDistance();
}
bool Coordinate::operator < (const Coordinate& c) const{
    return getDistance()<c.getDistance();
}
bool Coordinate::operator <= (const Coordinate& c) const{
    return getDistance()<=c.getDistance();
}
bool Coordinate::operator == (const Coordinate& c) const{
    return getDistance()==c.getDistance();
}
bool Coordinate::operator != (const Coordinate& c) const{
    return getDistance()!=c.getDistance();
}
Coordinate Coordinate::operator ++ (){
    move(1);
    return Coordinate(xCoor, yCoor);
}
Coordinate Coordinate::operator ++ (int){
    move(1);
    return Coordinate(xCoor-1, yCoor-1);
}
Coordinate Coordinate::operator -- (){
    move(-1);
    return Coordinate(xCoor, yCoor);
}
Coordinate Coordinate::operator -- (int){
    move(-1);
    return Coordinate(xCoor+1, yCoor+1);
}

int main() {
    Coordinate a(2, 4), b(-2, -4);
    cout<<a.getDistance()<<endl;
    a.display();
    cout<<"Displaying a==b: ";
    if(a==b) cout<<1<<endl;
    Coordinate c=++a;
    Coordinate d=--b;
    a.display();
    b.display();
    cout<<"Displaying a==b: ";
    if(a==b) cout<<1<<endl;
    cout<<"Displaying c: \n";
    c.display();
    cout<<"Displaying d: \n";
    d.display();
}
