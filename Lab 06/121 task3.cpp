#include<iostream>
#include<string>
using namespace std;

class ZooAnimal {
private:
    string nameOfAnimal;
    int birthYear;
    int cageNumber;
    float weightData;
    int height;
public:
    ZooAnimal(): birthYear(2021), cageNumber(-1), weightData(0), height(0) {
        nameOfAnimal = "null";
    }
    string getNameOfAnimal(){
        return nameOfAnimal;
    }
    void setNameOfAnimal(string name) {
        nameOfAnimal = name;
    }
    int getBirthYear() {
        return birthYear;
    }
    void setBirthYear(int by = 2021) {
        if(by > 2021) {
            cout<<"Error: invalid birth year"<<endl;
        }
        birthYear = by;
    }
    int getCageNumber() {
        return cageNumber;
    }
    void setCageNumber(int cn) {
        cageNumber = cn;
    }
    float getWeightData() {
        return weightData;
    }
    void setWeightData(float w) {
        weightData = w;
    }
    int getHeight() {
        return height;
    }
    void setHeight(int h) {
        height = h;
    }
    int getAge() {
        return 2021 - birthYear;
    }
    void getInformation() {
        cout<<"Name of Animal: "<<nameOfAnimal<<endl;
        cout<<"Birth year: "<<birthYear<<endl;
        cout<<"Cage Number: "<<cageNumber<<endl;
        cout<<"Weight: "<<weightData<<" kg"<<endl;
        cout<<"Height: "<<height<<" cm"<<endl;
        cout<<"Age: "<<getAge()<<" years"<<endl;
    }
    bool operator == (int data) const {
//        return weightData-data>=-1e-6 && weightData-data<=1e-6;
        return weightData == data;
    }
    void operator -= (int dec) {
        height -= dec;
    }

};

int main() {
    ZooAnimal a1;
    a1.setNameOfAnimal("Panda");
    a1.setBirthYear(2019);
    a1.setCageNumber(154);
    a1.setWeightData(100);
    a1.setHeight(154);
    a1.getInformation();
    if(a1 == 100) cout<<"Weight is equal to 100"<<endl;
    a1 -= 4;
    a1.getInformation();
}
