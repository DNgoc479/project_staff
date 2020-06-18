#ifndef INFOATTENDANCE_H
#define INFOATTENDANCE_H
#include <stdio.h>
#include <string>
#include <sstream>
#include <map>
#include <Staff.h>
using namespace std;
class InfoAttendance {
private:
    string _idStaff; // id nhan vien
    string _date; // ngay thang diem danh
    string _month;
    string _status; // trang thai di lam cua nv

public:
    InfoAttendance(const string &idStaff,const string &date,const string &month,const string &status);
    InfoAttendance();

public:
    const string &getIdStaff() const;
    const string &getDate() const;
    const string &getMonth() const;
    const string &getStatus() const;
    bool operator <(const InfoAttendance &_InfoAttendance) const;
   static  void read(map<string,Staff>list);

};

#endif // CHECKDATE_H
