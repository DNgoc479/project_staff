#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <Staff.h>
#include <Helpper.h>
#include "InfoAttendance.h"
using namespace  std;

void InfoAttendance::read(map<string, Staff> list){
    cin.ignore();
    string url = "C:\\Users\\admin\\Desktop\\GitHub\\project_staff\\ListDSNV\\";
    string idStaff;
    cout <<"Enter the employee id you want to time: ";
    getline(cin,idStaff);
    while(Staff::checkId(idStaff,list) == 1){
        cout << "Enter the employee id you want to time! again: "<< endl;
        getline(cin,idStaff);
    }
    ifstream ifs(url+idStaff+".csv", ios::in);


    cout<< "Enter the date you want to timekeeping: ";
    string date;
    getline(cin,date);
//    while (Helpper::checkDateStaff(date) == 1) {
//        cout<< "Enter the date you want to timekeeping(dd/mm/yyyy): ";
//        getline(cin,date);
//    }

    cout<< "Enter status of employee to work (DL-DLNN-N-NP): ";
    string status;
//    cin >> status;
    getline(cin,status);
    while(Helpper::checkStatus(status) ==0){
        cout<<"Dinh dang sai , xin nhap lai ";
        //cin >> status;
         getline(cin,status);
    }

    fflush(stdin);

//vector<string> listdate = Helpper::split(date,'/');
    // ghi vào
    fstream output(url+idStaff+".csv", ios::app);
    output <<":" <<date <<","<<status;

    // đóng đọc file
    output.close();
    ifs.close();


}

