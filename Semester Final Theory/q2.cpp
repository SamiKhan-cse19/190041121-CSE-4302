#include<iostream>
#include<vector>
using namespace std;

class RB {
    float curTransPower;
    float minTransPower;
    float maxTransPower;
    bool isUplink;
    float channelFreq;
    static int idCount;
    int id;
public:
    RB(float cTP, float minTP, float maxTP, bool isUp, float cF)
    : curTransPower(cTP), minTransPower(minTP), maxTransPower(maxTP), isUplink(isUp), channelFreq(cF) {
        id = idCount++;
    }
    int getId() const {
        return id;
    }
    float getChannelFreq() const {
        return channelFreq;
    }
    bool isUplinkRB() const {
        return isUplink;
    }

};

class BTS;

class C {
    float xC;
    float yC;
    float curTransPower;
    float minTransPower;
    float maxTransPower;
    static int idCount;
    int id;
    bool underCom;
    BTS* bts;
    RB* up;
    RB* down;
public:
    C(float x, float y, float cTP, float minTP, float maxTP)
    : xC(x), yC(y), curTransPower(cTP), minTransPower(minTP), maxTransPower(maxTP) {
        id = idCount++;
        up = nullptr;
        down = nullptr;
    }
    int getId() const {
        return id;
    }
    bool isUnderCommunication() const {
        return underCom;
    }
    void setRBCell(RB* rb) {
        if(rb->isUplinkRB()) up = rb;
        else down = rb;
    }
    class NoFreeRB {
    };

    void startCommunication() {
        int upi=-1, downi=-1;
        for(int i=0; i<bts->getFreeRBs().size(); i++) {
            if(upi!=-1 && bts->getFreeRBs()[i]->isUplink()) upi = i;
            if(downi!=-1 && !bts->getFreeRBs()[i]->isUplink()) downi = i;
        }
        if(upi==-1 || downi==-1) throw NoFreeRB();
        bts->allocateRBCell(bts->getFreeRBs()[up], this);
        bts->allocateRBCell(bts->getFreeRBs()[down], this);
        underCom = true;
    }
    void endCommunication() {
        underCom = false;
        bts->deallocateRBCell(up, this);
        bts->deallocateRBCell(down, this);
        up = nullptr;
        down = nullptr;
    }
    void status() const {
        cout<<"ID: "<<id<<endl;
        if(underCom) {
            cout<<"Currently Under Communication"<<endl;
            cout<<"Uplink: "<<up->getId()<<endl;
            cout<<"Downlink: "<<down->getId()<<endl;
        }
    }
};

class BTS {
    float xC;
    float yC;
    static int idCount;
    int id;
    vector<RB*> freeRBs;
    vector<RB*> allocatedRBs;
    vector<C*> Cs;
public:
    BTS(float x, float y) : xC(x), yC(y) {
        id = idCount++;
    }
    class AllocatedRB {
    };
    class UsingRB {
    };
    void allocateRBCell(RB* rb, C* c) {
        if(find(freeRBs.begin(), freeRBs.end(), rb) == freeRBs.end()) throw AllocatedRB();
        if(c->isUnderCommunication()) throw UsingRB();
        vector<RB*> :: iterator it = find(freeRBs.begin(), freeRBs.end(), rb);
        c->setRBCell(rb);
        freeRBs.erase(it);
        allocatedRBs.push_back(rb);
    }
    void deallocateRBCell(RB* rb, C* c) {
        vector<RB*> :: iterator it = find(freeRBs.begin(), freeRBs.end(), rb);
        allocatedRBs.erase(it);
        freeRBs.push_back(rb);
    }
    vector<RB*>& getFreeRBs() {
        return freeRBs;
    }
};

int main() {

}
