#include "Staff.h"
#include <string>
#include <sstream>
#include <fstream>
Staff::Staff(string id, string name,string birthday,string address,string wdepartment){
    _id = id;
    _name = name;
    _birthday = birthday;
    _address = address;
    _wDepartment = wdepartment;
}
void Staff::inputStaff(){
    cout <<"" <<endl;
    cin.ignore();
    cout << "Enter id staff : ";
    getline(cin,_id);
    cout << "Enter Name: ";
    getline(cin,_name);
    cout << "Enter birthday: ";
    getline(cin,_birthday);

    cout << "Enter address: ";
    getline(cin,_address);

    while ( _address == ""){
        cout << "Address not empty.Please enter again ! " <<endl;
        cout << "Enter address: ";
        getline(cin,_address);
    }


    cout << "Enter department: ";
    getline(cin,_wDepartment);
    while ( _wDepartment == ""){
        cout << "Department not empty.Please enter again ! "<< endl;
        cout << "Enter address: ";
        getline(cin,_wDepartment);
    }

    fflush(stdin);
}

void Staff::printStaff(){
    cout <<"" <<endl;
    cout << "Id staff: " << _id << endl;
    cout << "Name staff: " << _name << endl;
    cout << "Date of birth: " << _birthday << endl;
    cout << "Address: " << _address << endl;
    cout << "Department: " << _wDepartment << endl;
    cout <<"" <<endl;

}

void Staff::inputStaffFile(){
    ofstream filestaff;
    filestaff.open("C:/Users/DNgoc/Desktop/fileStaff.txt",ios::app);
   // filestaff.<<"ghi du lieu vao file";

}
