#ifndef FileIoUtils_hpp
#define FileIoUtils_hpp

#include <stdio.h>
#include <map>
#include <string>
using namespace std;

class Staff;
class InfoAttendance;

class FileIoUtils {

public:
    static string _resourceFile;

public:
    static void addEmployee(Staff *staff);
    static void addListEmployees(map<string,Staff> & employees);
    static void loadAllEmployee(map<string,Staff> & employees);
    static map<string,Staff> & readEmployeeFromCsv(string & path);
    static bool checkExist(string & path);
    static void addCheckPoint(const InfoAttendance & infoAttendance); // Write to a file, indentify by employee_id
    static map<string,InfoAttendance> loadCheckPoint(const string & idStaff); // Get checkpoit of a employee by employee_id
    static void rewriteCheckPoint(string & idStaff, map<string,InfoAttendance> checkPoints);
    static const string genCheckpointFileName(const string & idStaff); // Specify checkpoint file by employeeId
};
#endif /* FileIoUtils_hpp */
