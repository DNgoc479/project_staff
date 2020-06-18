#ifndef TIMEKEEPINGHISTORY_H
#define TIMEKEEPINGHISTORY_H
#include <vector>
#include <sstream>
#include  <string>
#include <map>
#include <Staff.h>
#include <InfoAttendance.h>
class TimekeepingHistory{
private:
    string _month;
    string _year;
    int _numberDaysDL; //so ngay di lam   //number of days working;
    int _numberDaysDLNN;// so ngay di lam nua ngay
    int _numberDaysN;// so ngay nghi trong thang
    int _numberDaysNP;// so ngay nghi phep trong thang
public:
    static string url;
    TimekeepingHistory(string month,string year,int numberDayDL,
                       int numberDayDLNN,int numberDayN,int numberDayNP);
    TimekeepingHistory(){};
    ~TimekeepingHistory(){};
    const string &getMonth() const {return  this->_month;}
    const string &getYear() const {return  this->_year;}
    const int &getNumberDaysDL() const{ return this->_numberDaysDL;}
    const int &getNumberDaysDLNN() const{ return  this->_numberDaysDLNN;}
    const int &getNumberDaysN() const {return  this->_numberDaysN;}
    const int &getNumberDaysNP() const { return  this->_numberDaysNP;}
public:
    static map<string,TimekeepingHistory> readFileStaff(string idStaff,map<string,Staff> listStaff,string month); // doc file cham cong nhan vien
    static map<string,TimekeepingHistory> readAllFileFile(string url);
    static int inputNumber(string month);
    static void inputFileAttendance(string url,string idStaff,map<string,TimekeepingHistory>list);

};

#endif // TIMEKEEPINGHISTORY_H
