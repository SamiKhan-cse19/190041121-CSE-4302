#include <iostream>
#include <string>
using namespace std;

class Lab {
private:
    string labName;
    int capacity;
public:
    Lab() {
    }
    Lab(string labName, int capacity) : labName(labName), capacity(capacity) {
    }
    string getLabName() const{
        return labName;
    }
    int getCapacity() const {
        return capacity;
    }
    void setLabName(string name) {
        labName = name;
    }
    void setCapacity(int cap) {
        capacity = cap;
    }
    void showDetails() const {
        cout<<getLabName()<<" "<<getCapacity()<<" Capacity"<<endl;
    }
};

class LecturerRoom {
private:
    string roomName;
    int roomNo;
    int capacity;
public:
    LecturerRoom() {
    }
    LecturerRoom(string name, int roomNo, int capacity) : roomName(name), roomNo(roomNo), capacity(capacity) {
    }
    string getRoomName() const{
        return roomName;
    }
    int getRoomNo() const {
        return roomNo;
    }
    int getCapacity() const {
        return capacity;
    }
    void setRoomName(string name) {
        roomName = name;
    }
    void setCapacity(int cap) {
        capacity = cap;
    }
    void setRoomNo(int rNo) {
        roomNo = rNo;
    }
    void showDetails() const {
        cout<<getRoomName()<<" "<<getRoomNo()<<" "<<getCapacity()<<" Capacity"<<endl;
    }

};

class N28_Building {
private:
    Lab lab[4];
    LecturerRoom lecturerRoom[4];
public:
    N28_Building() {
        lab[0].setLabName("Lab MPK1");
        lab[0].setCapacity(60);
        lab[1].setLabName("Lab MPK2");
        lab[1].setCapacity(60);
        lab[2].setLabName("Lab MPK3");
        lab[2].setCapacity(50);
        lab[3].setLabName("Lab MPK4");
        lab[3].setCapacity(50);

        lecturerRoom[0].setRoomName("Hafiz");
        lecturerRoom[0].setRoomNo(102);
        lecturerRoom[0].setCapacity(3);
        lecturerRoom[1].setRoomName("Shafie");
        lecturerRoom[1].setRoomNo(105);
        lecturerRoom[1].setCapacity(3);
        lecturerRoom[2].setRoomName("Aisyah");
        lecturerRoom[2].setRoomNo(202);
        lecturerRoom[2].setCapacity(3);
        lecturerRoom[3].setRoomName("Rahim");
        lecturerRoom[3].setRoomNo(208);
        lecturerRoom[3].setCapacity(3);

    }
    void showAllLabs() const {
        cout<<"Show all labs:\n";
        for(int i=0; i<4; i++) {
            lab[i].showDetails();
        }
    }
    void showAllLecturerRoom() const {
        cout<<"Show all lecturers room:\n";
        for(int i=0; i<4; i++) {
            lecturerRoom[i].showDetails();
        }
    }
};

int main() {
    N28_Building building;
    building.showAllLabs();
    building.showAllLecturerRoom();
    return 0;
}
