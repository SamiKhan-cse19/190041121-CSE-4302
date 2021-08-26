#include <iostream>
#include <string>
using namespace std;

void drawLine(char);

class MobilePhone {
private:
    static int serial;
    string model;
    int productId; /// used to uniquely identify a phone
    unsigned int xResolution;
    unsigned int yResolution;
    string cpuModel;
    unsigned int ram; // in MB
    unsigned int internalStorage; // in MB


    /// Preventing users from copying

//    MobilePhone(const MobilePhone& mp) {
//    }
//    MobilePhone operator = (const MobilePhone& mp) {
//    }

public:
    MobilePhone(string model, unsigned int xRes, unsigned int yRes, string cpu, unsigned int ram, unsigned int intStorage)
    : model(model), xResolution(xRes), yResolution(yRes), cpuModel(cpu), ram(ram), internalStorage(intStorage) {
        productId = serial;
        serial++;
    }

    /// Copy constructor and assignment operator overloading

    MobilePhone(const MobilePhone& mp)
    : model(mp.model), productId(mp.productId), xResolution(mp.xResolution), yResolution(mp.yResolution), cpuModel(mp.cpuModel),
        ram(mp.ram), internalStorage(mp.internalStorage) {
        productId = serial;
        serial ++;
    }
    MobilePhone& operator = (const MobilePhone& mp) {
        model = mp.model;
        productId = serial;
        serial++;
        xResolution = mp.xResolution;
        yResolution = mp.yResolution;
        cpuModel = mp.cpuModel;
        ram = mp.ram;
        internalStorage = mp.internalStorage;
        return *this;
    }

    void getDetails() {
        drawLine('*');
        cout<<"Model: "<<model<<endl;
        cout<<"Product ID: "<<productId<<endl;
        cout<<"Display: "<<xResolution<<" x "<<yResolution<<endl;
        cout<<"Processor: "<<cpuModel<<endl;
        cout<<"RAM: "<<ram<<" MB"<<endl;
        cout<<"Internal Storage: "<<internalStorage<<" MB"<<endl;
        drawLine('-');
    }
};

int MobilePhone::serial = 0;

int main() {
    MobilePhone sprintPrototype("Sprint D30", 240, 320, "CX34", 1, 12);
    MobilePhone huaweiPrototype("Huawei NMO-L31", 1080, 1920, "Kirin 650", 2048, 16384);

    /// Creating new phone from prototype
    sprintPrototype.getDetails();
    MobilePhone sprint1(sprintPrototype);
    sprint1.getDetails();

    /// Creating new phone from prototype
    huaweiPrototype.getDetails();
    MobilePhone huawei1(huaweiPrototype);
    huawei1.getDetails();

    cout<<"Printing newPhone"<<endl;
    cout<<"Copying using copy ctor"<<endl;
    MobilePhone newPhone = sprintPrototype;
    newPhone.getDetails();
    cout<<"Copying using assignment operator"<<endl;
    newPhone = huaweiPrototype;
    newPhone.getDetails();
}

void drawLine(char c) {
    for(int i=0; i<80; i++) cout<<c;
    cout<<endl;
}
