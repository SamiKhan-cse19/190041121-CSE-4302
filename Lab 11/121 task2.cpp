#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstring>
using namespace std;

const double AVERAGE_HUMAN_WEIGHT = 80.0; // average weight of humans in kilograms
const double BUS_WEIGHT_FACTOR = 0.10; // percentage of fuel consumption increase due to passenger weight
const double TRUCK_WEIGHT_FACTOR = 0.20; // percentage of fuel consumption increased due to cargo weight
const double AVERAGE_FUEL_CONSUMPTION = 4.25; // in liter per km

const int MAXVEH = 100;

enum VehicleType {tBus, tTruck};

class Vehicle {
protected:
    char model[20];
    double baseWeight; // weight without additional passenger or cargo
    double fuelEconomy; // percentage of fuel saved
    char engineModel[20];

    static int n;
    static Vehicle* varr[MAXVEH];

public:
    Vehicle(){
    }
    Vehicle(char* m, double bW, double fE, char* eM) {
        setModel(m);
        setEngineModel(eM);
        setBaseWeight(bW);
        setFuelEconomy(fE);
    }
    void setModel(char* m) {
        strcpy(model, m);
    }
    char* getModel() {
        return model;
    }
    void setBaseWeight(double bW) {
        if(0 < bW)
            baseWeight = bW;
    }
    double getBaseWeight() const {
        return baseWeight;
    }
    void setFuelEconomy(double fE) {
        if(0 <= fE && fE <= 100)
            fuelEconomy = fE;
    }
    double getFuelEconomy() const {
        return fuelEconomy;
    }
    void setEngineModel(char* eM) {
        strcpy(engineModel, eM);
    }
    char* getEngineModel() {
        return engineModel;
    }
    virtual double getFuelConsumed(double) const = 0;

    virtual void getData() {
        cout<<"Enter Model Name: \t";
        cin>>model;
        cout<<"Enter Base Weight: \t";
        cin>>baseWeight;
        cout<<"Enter Fuel Economy: \t";
        cin>>fuelEconomy;
        cout<<"Enter Engine Model: \t";
        cin>>engineModel;
    }

    virtual void getDetails() const {
        cout<<"Model: \t"<<model<<endl;
        cout<<"Base Weight: \t"<<baseWeight<<endl;
        cout<<"Engine: \t"<<engineModel<<endl;
    }

    virtual VehicleType getType();
    static void add();
    static void display();
    static void read();
    static void write();

};

int Vehicle::n = 0;
Vehicle *Vehicle::varr[MAXVEH];

class Bus : public Vehicle {
private:
    unsigned int passengerNumberLimit;
    unsigned int numberOfPassengers;
public:
    Bus(){
    }
    Bus(char* m, double bW, double fE, char* eM, unsigned int pLim, unsigned int numP)
    : Vehicle(m, bW, fE, eM), passengerNumberLimit(pLim) {
        setNumberOfPassengers(numP);
    }
    void setPassengerNumberLimit(unsigned int pLim) {
        passengerNumberLimit = pLim;
    }
    unsigned int getPassengerNumberLimit() const {
        return passengerNumberLimit;
    }
    void setNumberOfPassengers(unsigned int numP) {
        if(numberOfPassengers <= passengerNumberLimit)
            numberOfPassengers = numP;
        else cout<<"Passenger limit exceeded"<<endl;
    }
    unsigned int getNumberOfPassengers() const {
        return numberOfPassengers;
    }
    double getFuelConsumed(double distance) const {
        double ret = AVERAGE_FUEL_CONSUMPTION * distance / 100 ;
        ret += (baseWeight + numberOfPassengers * AVERAGE_HUMAN_WEIGHT) * BUS_WEIGHT_FACTOR;
        ret -= ret * fuelEconomy;
        return ret;
    }
    void getData() {
        Vehicle::getData();
        cout<<"Enter Passenger Number Limit: \t";
        cin>>passengerNumberLimit;
        cout<<"Enter Number of Passengers on board: \t";
        unsigned int p;
        cin>>p;
        setNumberOfPassengers(p);
    }
    void getDetails() const {
        Vehicle::getDetails();
        cout<<"Carrying Passenger number: \t"<<numberOfPassengers<<endl;
        cout<<"Fuel consumed per 100 km: \t"<<getFuelConsumed(100)<<endl;
    }
};

class Truck : public Vehicle {
private:
    double cargoWeightLimit;
    double cargoWeight;
public:
    Truck(){
    }
    Truck(char* m, double bW, double fE, char* eM, double cWLim, double cW)
    : Vehicle(m, bW, fE, eM), cargoWeightLimit(cWLim) {
        setCargoWeight(cW);
    }
    void setCargoWeightLimit(double cWLim) {
        cargoWeightLimit = cWLim;
    }
    double getCargoWeightLimit() const {
        return cargoWeightLimit;
    }
    void setCargoWeight(double cW) {
        if(cW <= cargoWeightLimit)
            cargoWeight = cW;
        else cout<<"Cargo limit exceeded"<<endl;
    }
    double getCargoWeight() const {
        return cargoWeight;
    }
    double getFuelConsumed(double distance) const {
        double ret = AVERAGE_FUEL_CONSUMPTION * distance / 100 ;
        ret += (baseWeight + cargoWeight) * TRUCK_WEIGHT_FACTOR;
        ret -= ret * fuelEconomy;
        return ret;
    }
    void getData() {
        Vehicle::getData();
        cout<<"Enter Cargo Weight Limit: \t";
        cin>>cargoWeightLimit;
        cout<<"Enter Cargo on Board: \t";
        double cWeight;
        cin>>cWeight;
        setCargoWeight(cWeight);
    }
    void getDetails() const {
        Vehicle::getDetails();
        cout<<"Carrying Cargo Weight: \t"<<cargoWeight<<endl;
        cout<<"Fuel consumed per 100 km: \t"<<getFuelConsumed(100)<<endl;
    }
};

void Vehicle::add() {
    char ch;
    cout << "'b' to add a Bus"
         "\n't' to add a Truck"
     "\nEnter selection: \t";
    cin >> ch;
    switch(ch)
    {
    //create specified employee type
    case 'b':
        varr[n] = new Bus;
        break;
    case 't':
        varr[n] = new Truck;
        break;
    default:
        cout << "\nUnknown Vehicle type\n";
        return;
    }
    varr[n++]->getData();
}

void Vehicle::display() {
    for(int i=0; i<n; i++)
    {
        cout << (i+1); //display number
        switch( varr[i]->getType() ) //display type
        {
        case tBus:
            cout << ". Type: \tBus"<<endl;
            break;
        case tTruck:
            cout << ". Type: \tTruck"<<endl;
            break;
        default:
            cout << ". Unknown type"<<endl;
        }
        varr[i]->getDetails();
        cout << endl;
    }
}

VehicleType Vehicle::getType() {
    if( typeid(*this) == typeid(Bus) )
        return tBus;
    else if( typeid(*this)==typeid(Truck) )
        return tTruck;
    else
    {
        cerr << "\nBad vehicle type";
        exit(1);
    }
    return tBus;
}

void Vehicle::write(){
    int _size;
    cout << "Writing " << n << " vehicles.\n";
    ofstream ouf; //open ofstream in binary
    VehicleType vType; //type of each employee object
    ouf.open("VEHICLE.DAT", ios::trunc | ios::binary);
    if(!ouf){
        cout << "\nCan't open file\n";
        return;
    }
    for(int i=0; i<n; i++) //for every employee object
    {
        //get its type
        vType = varr[i]->getType();
//write type to file
        ouf.write( (char*)&vType, sizeof(vType) );
        switch(vType) //find its size
        {
        case tBus:
            _size=sizeof(Bus);
            break;
        case tTruck:
            _size=sizeof(Truck);
            break;
        }
        //write employee object to file
        ouf.write( (char*)(varr[i]), _size );
        if(!ouf){
            cout << "\nCan't write to file\n";
            return;
        }
    }
}

void Vehicle::read(){
    size_t _size; //size of vehicle object
    VehicleType vType;
    ifstream inf;
    inf.open("VEHICLE.DAT", ios::binary);
    if(!inf){
        cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while(true)
    {
        inf.read( reinterpret_cast<char*>(&vType), sizeof(VehicleType) );
        if( inf.eof() ) //quit loop on eof
            break;
        if(!inf) //error reading type
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch(vType){
        case tBus:
            varr[n] = new Bus();
            _size=sizeof(Bus);
            break;
        case tTruck:
            varr[n] = new Truck();
            _size=sizeof(Truck);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        } //read data from file into it
        inf.read( reinterpret_cast<char*>(varr[n]), _size );
        if(!inf) //error but not eof
        {
            cout << "\nCan't read data from file\n";
            return;
        }
        n++; //count employee
    } //end while
    cout << "Reading " << n << " Vehicles\n";
}

main(){
    char ch;
    while(true)
    {
        cout << "'a' -- add data for a Vehicle"
             "\n'd' -- display data for all Vehicles"
                 "\n'w' -- write all Vehicle data to file"
                 "\n'r' -- read all Vehicle data from file"
                 "\n'x' -- exit"
     "\nEnter selection: \t";
    cin >> ch;
    switch(ch)
        {
        case 'a':
            Vehicle::add();
            break;
        case 'd':
            Vehicle::display();
            break;
        case 'w':
            Vehicle::write();
            break;
        case 'r':
            Vehicle::read();
            break;
        case 'x':
            exit(0);
        default:
            cout << "\nUnknown command";
        } //end switch
    } //end while
    return 0;
}
