#include <iostream>
#include <string>
using namespace std;

const double AVERAGE_HUMAN_WEIGHT = 80.0; // average weight of humans in kilograms
const double BUS_WEIGHT_FACTOR = 0.10; // percentage of fuel consumption increase due to passenger weight
const double TRUCK_WEIGHT_FACTOR = 0.20; // percentage of fuel consumption increased due to cargo weight
const double AVERAGE_FUEL_CONSUMPTION = 4.25; // in liter per km

class Vehicle {
protected:
    string model;
    double baseWeight; // weight without additional passenger or cargo
    double fuelEconomy; // percentage of fuel saved
    string engineModel;
public:
    Vehicle(string m, double bW, double fE, string eM) : model(m), engineModel(eM) {
        setBaseWeight(bW);
        setFuelEconomy(fE);
    }
    void setModel(string m) {
        model = m;
    }
    string getModel() const {
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
    void setEngineModel(string eM) {
        engineModel = eM;
    }
    string getEngineModel() const {
        return engineModel;
    }
    virtual double getFuelConsumed(double) const = 0;

    virtual void getDetails() const {
        cout<<"Model: "<<getModel()<<endl;
        cout<<"Base Weight: "<<getBaseWeight()<<endl;
        cout<<"Engine: "<<getEngineModel()<<endl;
    }

};

class Bus : public Vehicle {
private:
    unsigned int passengerNumberLimit;
    unsigned int numberOfPassengers;
public:
    Bus(string m, double bW, double fE, string eM, unsigned int pLim, unsigned int numP)
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
    void getDetails() const {
        Vehicle::getDetails();
        cout<<"Carrying Passenger number: "<<numberOfPassengers<<endl;
        cout<<"Fuel consumed per 100 km: "<<getFuelConsumed(100)<<endl;
    }
};

class Truck : public Vehicle {
private:
    double cargoWeightLimit;
    double cargoWeight;
public:
    Truck(string m, double bW, double fE, string eM, double cWLim, double cW)
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
    void getDetails() const {
        Vehicle::getDetails();
        cout<<"Carrying Cargo Weight: "<<cargoWeight<<endl;
        cout<<"Fuel consumed per 100 km: "<<getFuelConsumed(100)<<endl;
    }
};

int main() {
    Vehicle *bus, *truck;
    bus = new Bus("Setra S 416 LE business", 12647.0, 0.15, "Mercedes-Benz OM 936", 34, 20);
    truck = new Truck(" Kenworth W900", 22679.619, 0.25, "Caterpillar C15 435", 34019.428, 11300.7);

    bus->getDetails();
    cout<<endl;
    truck->getDetails();

    delete bus;
    delete truck;
}

