#ifndef DATESTAFFMANAGEMENT_H
#define DATESTAFFMANAGEMENT_H
#include <map>
#include <Staff.h>
//#include <DateStaffManagement.h>
using namespace  std;

class DateStaffManagement  {
private:
    string _id;
    string _date;
    string _status;
public:
    string getId();
    string getDate();
    string getStatus();
public:
    void setId(string id);
    void setDate(string date);
    void setStatus(string status);
public:
    DateStaffManagement(){};
    ~DateStaffManagement(){};
    DateStaffManagement(string  id,string date,string status);
     DateStaffManagement(string  id,string status);
    void createFileById(string id); // tao full file id staff;
    void insertDateStatus(string status,string urlFile); // them date,status
    void inputFileStaffDate(DateStaffManagement dsm,string url);
    void updateStatus(string id); // sua trang thai
    void deletDate(string id,string date); // xoa ngay
};
#endif // DATESTAFFMANAGEMENT_H
