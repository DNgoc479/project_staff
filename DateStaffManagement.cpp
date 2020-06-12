#include <DateStaffManagement.h>
#include <fstream>
#include <string>
#include <Staff.h>
#include <Staff.h>
#include <iostream>
#include <ctime>
using namespace  std;
map<string,Staff> listStaff = Staff::addMapStaff("E:\\QT\\project_staff\\fileStaff.csv");
DateStaffManagement::DateStaffManagement(string id,string date,string status){
    id = _id;
    date = _date;
    status = _status;
}
DateStaffManagement enterTheTimekeeping(){
    DateStaffManagement dsm;
    string id,status;
      cin.ignore();
      cout << "Enter the employee id to be timed : ";
      getline(cin,id);
      for(map<string,Staff>::iterator it = listStaff.begin();it != listStaff.end();it++){
          if(dsm.getId() != it->first){
              cout << "Enter the employee id to be timed again: ";
              getline(cin,id);
          }

    }
      cout << "Enter employee's working status: ";
      getline(cin,id);
}
string DateStaffManagement::getId(){
    return  _id;
}
string DateStaffManagement::getDate(){

    const int MAXLEN = 80;
    char date[MAXLEN];
    time_t t = time(0);
    strftime(date, MAXLEN, "%m/%d/%Y", localtime(&t));
    return  date;
}
string DateStaffManagement::getStatus(){
    return _status;
}
void DateStaffManagement::createFileById(string id){
    string s = "E:/QT/project_staff/"+id+".txt";
    ofstream MyFile(s);
    MyFile.close();
}

void DateStaffManagement::insertDateStatus(string status,string url){
  cin.ignore();
    fstream output(url, ios::app);;

    // lay thoi gian thuc


    getline(cin,status);

    output <<getDate() <<",";
    output <<status <<endl;
    fflush(stdin);
    output.close();
}

void DateStaffManagement::inputFileStaffDate(DateStaffManagement dsm,string url){
      int check = 0;

    for(map<string,Staff>::iterator it = listStaff.begin();it != listStaff.end();it++){
        if(dsm.getId() == it->first){
            check = 1;
            DateStaffManagement::insertDateStatus(dsm.getStatus(),url);
        }
    }
    if( check == 0 ){
        cout<< "ID nhan vien khong ton tai trong danh sach" << endl;
    }
}


