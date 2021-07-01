#include<iostream>
#include<cstring>
using namespace std;

class ZooAnimal {
private:
    char* nameOfAnimal;
    int birthYear;
    int cageNumber;
    float weight;
    int height;
public:
    ZooAnimal(): birthYear(2021), cageNumber(-1), weight(0), height(0) {
        char* nameOfAnimal = new char[30];
        strcpy(nameOfAnimal, "null");
    }
    char* getNameOfAnimal(){
        return nameOfAnimal;
    }
    void setNameOfAnimal(char* name) {
        strcpy(nameOfAnimal, name);
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
    float getWeight() {
        return weight;
    }
    void setWeight(float w) {
        weight = w;
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
        cout<<"Weight: "<<weight<<" kg"<<endl;
        cout<<"Height: "<<height<<" cm"<<endl;
        cout<<"Age: "<<getAge()<<" years"<<endl;
    }

};

int main() {
    ZooAnimal a1;
    a1.setNameOfAnimal("Panda");
    a1.setBirthYear(2019);
    a1.setCageNumber(154);
    a1.setWeight(100);
    a1.setHeight(154);
    a1.getInformation();
}
