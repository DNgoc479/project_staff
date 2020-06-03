#ifndef STAFF_H
#define STAFF_H
#include <iostream>
using namespace  std;
class Staff{

private:
    string _id;
    string _name;
    string _birthday;
    string _address;
    string _wDepartment; // bo phan cong tac
public:
    void setId(string id){};
    void setName(string name){};
    void setBirthday(string birthday){};
    void setAddress(string address){};
    void setWDepartment(string wDepartment){};

    string getId(){return  _id;};
    string getName(){return  _name;};
    string getBirthday(){return _birthday;};
    string getAddress(){return _address;};
    string getWDepartment(){return  _wDepartment;};
public:
    Staff(string id, string name,string birthday,string address,string wdepartment);
    Staff(){};
    ~Staff(){};
    virtual void inputStaff();
    virtual void printStaff();
    virtual void inputStaffFile();
    //virtual void readFileStaff();

};

#endif // STAFF_H
