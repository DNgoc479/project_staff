#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <map>
#include <vector>
using namespace  std;
class Staff{

private:
    string _id;
    string _name;
    string _birthday;
    string _address;
    string _wDepartment; // bo phan cong tac
public:
    const string &getId() const {return  this->_id;};
    const string &getName() const {return  this->_name;};
    const string &getBirthday() const {return this->_birthday;};
    const string &getAddress() const {return this->_address;};
    const string &getWDepartment() const{return  this->_wDepartment;};
public:
    Staff(string id, string name,string birthday,string address,string wdepartment);
    Staff(){};
    ~Staff(){};
    static map<string,Staff>addMapStaff(string urlfile);
    virtual void inputFile(string url,Staff staff);
    virtual void inputStaff();
    static int checkId(string id,map<string,Staff> list);
    virtual void printStaff(Staff staff);
    virtual void outStaffFile();
    virtual void SearchStaff();
    static vector<string> cutStringDate(string s,string delimiter);
};

#endif // STAFF_H
