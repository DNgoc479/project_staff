#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <map>
using namespace  std;
class Staff{

private:
    string _id;
    string _name;
    string _birthday;
    string _address;
    string _wDepartment; // bo phan cong tac
public:
//    void setId(string id){};
//    void setName(string name){};
//    void setBirthday(string birthday){};
//    void setAddress(string address){};
//    void setWDepartment(string wDepartment){};

    string getId(){return  this->_id;};
    string getName(){return  this->_name;};
    string getBirthday(){return this->_birthday;};
    string getAddress(){return this->_address;};
    string getWDepartment(){return  this->_wDepartment;};
public:
    Staff(string id, string name,string birthday,string address,string wdepartment);
    Staff(){};
    ~Staff(){};
    static map<string,Staff>addMapStaff(string urlfile);
    virtual void inputFile(string url,Staff staff);
    virtual void inputStaff();
    virtual int checkId(string id,map<string,Staff> list);
    virtual void printStaff(Staff staff);
    virtual void outStaffFile();
    virtual void SearchStaff();

};

#endif // STAFF_H
