#include <iostream>
using namespace std;

class Human {
public:
    Human() {
        cout << "Human constructor" << endl;
    }

    virtual void displayInfo() const = 0; // pure virtual
    virtual ~Human() = default; // thêm destructor ảo
};

class Patient : public Human {
protected:
    string name;
    string id;
    int age;
public:
    // getter - setter
    string getName() const { return name; }
    string getId() const { return id; }
    int getAge() const { return age; }
    void setName(string _name) { name = _name; }
    void setId(string _id) { id = _id; }
    void setAge(int _age) { age = _age; }

    // constructors
    Patient() : name(""), id(""), age(0) {}
    Patient(string _name, string _id, int _age) :
        name(_name), id(_id), age(_age) {}

    void displayInfo() const override {
        cout << "Patient General: Name: " << name 
             << ", Age: " << age 
             << ", ID: " << id << endl;
    }
};

class ChronicPatient : public Patient {
public:
    ChronicPatient(string _name, string _id, int _age) :
        Patient(_name, _id, _age) {}

    void displayInfo() const override {
        cout << "Chronic Patient: Name: " << name 
             << ", Age: " << age 
             << ", ID: " << id << endl;
    }
};

int main() {
    Patient patient("John", "1", 30);
    patient.displayInfo();

    ChronicPatient chronicPatient("Jane", "2", 40);
    chronicPatient.displayInfo();

    return 0;
}
