#include<iostream>
#include<cstring>
using namespace std;

class Medicine {
private:
    char name[30];
    char genericName[30];
    double discountPercent;
    double unitPrice;
public:
    Medicine() : unitPrice(0), discountPercent(5){

    }
    void assignName(char name[], char genericName[]) {
        strcpy(this->name, name);
        strcpy(this->genericName, genericName);
    }
    void assignPrice(double price) {
        if(price < 0) {
            cout<<"Error: invalid price input"<<endl;
            return;
        }
        unitPrice = price;
    }
    void setDiscountPercent(double percent) {
        if(percent < 0 || percent > 45) {
            cout<<"Error: invalid discount percent input"<<endl;
            return;
        }
        discountPercent = percent;
    }
    double getSellingPrice(int nos) {
        double price_wo_disc = unitPrice * nos;
        double tot_disc = price_wo_disc * discountPercent * 0.01;
        return price_wo_disc - tot_disc;
    }
    void display() {
        cout<<name<<" ("<<genericName<<") has a unit price BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%."<<endl;
    }
};

int main() {
    Medicine napa;
    napa.assignName("Napa", "Paracetamol");
    napa.assignPrice(0.80);
    napa.setDiscountPercent(10);
    napa.display();
    cout<<"Cost of buying 10 napa packs is "<<napa.getSellingPrice(10);
}
