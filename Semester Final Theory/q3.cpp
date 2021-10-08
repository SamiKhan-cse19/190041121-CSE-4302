#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_INDOOR = 100;

class Physician;
class Patient {
    static int idCount;
    int id;
    string name;
    Physician* assigned;
public:
    Patient(string n): name(n) {
        id = idCount++;
        assigned = nullptr;
    }
    int getId() const {
        return id;
    }
    string getName() const {
        return name;
    }
    void setName(string n) {
        name = n;
    }
    void setAssigned(Physician* p) {
        assigned = p;
    }
    Physician* getAssigned() const {
        return assigned;
    }
    ~Patient() {
        delete assigned;
    }
};

class Physician {
    static int idCount;
    int id;
    string name;
    string speciality;
public:
    Physician(string n, string sp) : name(n), speciality(sp) {
        id = idCount++;
    }
    int getId() const {
        return id;
    }
    string getName() const {
        return name;
    }
    string getSpeciality() const {
        return speciality;
    }
    void setName(string n) {
        name = n;
    }
    void setSpeciality(string sp) {
        speciality = sp;
    }
    virtual ~Physician() {
    }
    virtual bool admitPatient(Patient&) = 0;
    virtual bool dischargePatient(Patient&) = 0;
};
class Emergency : public Physician {
};
class Outdoor : public Physician {
};

class Indoor : public Physician {
    Patient** patients;
    int max_no_of_sup;
    int cur_no_of_sup;
public:
    Indoor(string n, string sp, int mx) : Physician(n, sp), max_no_of_sup(mx), cur_no_of_sup(0) {
        patients = new Patient *[max_no_of_sup];
    }
    ~Indoor() {
        delete[] patients;
    }
    bool admitPatient(Patient& p) {
        if(cur_no_of_sup >= max_no_of_sup) return false;
        patients[cur_no_of_sup] = &p;
        cur_no_of_sup ++;
        p.setAssigned(this);
        return true;
    }
    bool dischargePatient(Patient& p) {
        int i;
        for(i=0; i<cur_no_of_sup; i++) {
            if(p.getId() == patients[i]->getId()) break;
        }
        if(i == cur_no_of_sup) return false;
        swap(patients[i], patients[cur_no_of_sup]);
        patients[cur_no_of_sup]->setAssigned(nullptr);
        delete patients[cur_no_of_sup];
        cur_no_of_sup --;
        return true;
    }
    void showPatients() {
        for(int i=0; i<cur_no_of_sup; i++) cout<<patients[i]->getName()<<endl;
    }
};

class Hospital {
    int totalAdmittedPatients;
    int totalIndoorPhysicians;
    Indoor** indoors;
    string name;
public:
    Hospital(string n): name(n), totalAdmittedPatients(0), totalIndoorPhysicians(0) {
        indoors = new Indoor* [MAX_INDOOR];
    }
    ~Hospital() {
        delete[] indoors;
    }
    void addIndoor(Indoor& i) {
        indoors[totalIndoorPhysicians] = &i;
        totalIndoorPhysicians ++;
    }
    bool admit(Patient& p, Indoor& i) {
        bool ret = i.admitPatient(p);
        if(ret) totalAdmittedPatients++;
        return ret;
    }
    bool discharge(Patient& p) {
        bool ret = p.getAssigned()->dischargePatient(p);
        if(ret) totalAdmittedPatients--;
        return ret;
    }
    void showData() {
        cout<<name<<endl;
        cout<<"Total Admitted Patient: "<<totalAdmittedPatients<<endl;
        cout<<"Total Indoor Physicians: "<<totalIndoorPhysicians<<endl;
        for(int i=0; i<totalIndoorPhysicians; i++) {
            cout<<"---------------------"<<endl;
            cout<<indoors[i]->getName()<<" has the following patients:"<<endl;
            indoors[i]->showPatients();
        }
    }
    void diskIn() {

    }
    void diskOut() {
        ofstream ouf("hospital.dat", ios::binary | ios::app);
        out.write(reinterpret_cast<char*>(this), sizeof())
        for(int i=0; i<totalIndoorPhysicians; i++) {

        }
    }

};

int Patient::idCount = 0;
int Physician::idCount = 0;

int main() {
    Hospital iutMed("IUT Medical Center");

    Indoor drX("Dr. X", "Medicine", 4);
    Indoor drY("Dr. Y", "ENT", 3);

    iutMed.addIndoor(drX);
    iutMed.addIndoor(drY);

//    iutMed.showData();

    Patient a("Mr. A");
    Patient b("Mr. B");
    Patient c("Mrs. C");
    Patient d("Mr. D");

    iutMed.admit(a, drX);
    iutMed.admit(b, drX);
    iutMed.admit(c, drX);
    iutMed.admit(d, drY);

    iutMed.showData();

    ofstream of("hospital.dat", ios::binary);
    of.write(reinterpret_cast<char*>(&iutMed), sizeof(iutMed));
//    of.close();
//    ifstream inf("hospital.dat", ios::binary);
//    inf.read(reinterpret_cast<char*>(&iutMed), sizeof(iutMed));
//    iutMed.showData();

}

