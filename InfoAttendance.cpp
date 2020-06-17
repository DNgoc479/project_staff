#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <Staff.h>
#include <helpper.h>
#include "InfoAttendance.h"
using namespace  std;

void InfoAttendance::read(map<string, Staff> list){
    string url = "C:\\Users\\DNgoc\\Desktop\\ListNv";
    string idStaff;
    cout <<"Enter the employee id you want to time: ";
    cin >> idStaff;
    while(Staff::checkId(idStaff,list) == 1){
        cout << "Enter the employee id you want to time! again: "<< endl;
        cin >>idStaff;
    }
    ifstream ifs(url+idStaff+".csv", ios::in);
    cout<< "Enter the date you want to timekeeping: ";
    string date;
    cin >> date;


    cout<< "Enter status of employee to work (DL-DLNN-N-NP)" <<endl;
    string status;
    cin >> status;
    while(Helpper::checkStatus(status) ==0){
        cout<<"dinh dang sai , xin nhap lai "<<endl;
        cin >> status;
    }



    // ghi vào
    fstream output(url+idStaff+".csv", ios::app);
    output << date<<","<<status<<endl;

    // đóng đọc file
    output.close();
    ifs.close();


}

