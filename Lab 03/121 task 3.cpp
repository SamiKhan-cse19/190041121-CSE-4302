#include <iostream>
#include <cstring>
using namespace std;

class Product {
private:
    char name[30];
    double discountPercent;
    double unitPrice;
public:
    Product() : discountPercent(0.5), unitPrice(10){
    }
    void assignName(char name[]) {
        strcpy(this->name, name);
    }
    void setPrice(double price) {
        if(price < 0) {
            cout<<"Error: invalid price"<<endl;
            return;
        }
        unitPrice = price;
    }
    void setDiscPercent(double percent) {
        if(percent < 0 || percent > 10) {
            cout<<"Error: Invalid discount percent"<<endl;
            return;
        }
        discountPercent = percent;
    }
    double getSellingPrice(int nos) {
        double total = unitPrice * nos;
        double discount = total * discountPercent * 0.01;
        return total - discount;
    }
    void display() {
        cout<<name<<" has a unit price BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%"<<endl;
    }
};

int main() {
    Product noodles, dew;
    noodles.assignName("Cocola noodle");
    noodles.setPrice(10);
    noodles.setDiscPercent(10);
    noodles.display();
    dew.assignName("Mountain Dew");
    dew.setPrice(25);
    dew.setDiscPercent(1);
    dew.display();
}
