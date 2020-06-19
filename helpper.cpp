#include "Helpper.h"
#include <vector>
#include <sstream>
#include  <string>
#include <fstream>
#include <regex>
#include <ctime>
//#include <specstrings.h>
using namespace  std;
int Helpper::numberLine(){
    ifstream f1;
    char c;
    int numchars, numlines;

    f1.open("C:\\Users\\admin\\Desktop\\GitHub\\project_staff\\fileStaff.csv");

    numchars = 0;
    numlines = 0;
    f1.get(c);
    while (f1) {
        while (f1 && c != '\n') {
            numchars = numchars + 1;
            f1.get(c);
        }
        numlines = numlines + 1;
        f1.get(c);
    }

    return(numlines);
}
vector<string> Helpper::split(const string &s, char delim){
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


int Helpper:: checkId(map<string,Staff> list, string id) // trùng id trả về 0 ,không trùng trả về 1
{;
    for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
        if (it->second.getId() == id){
            return 0;
        }
    }
    return 1;
}


int Helpper ::checkStatus(string status){ // hop le return 1 , khong hop le return 0
    if(status =="DL"||status =="DLNN"||status =="N"||status =="NP"){
        return 1;
    }
    return 0;
}


vector<string> cutStringDate(string s,string delimiter){
    vector<string> list;

    //string delimiter = "/";

    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        //cout << token << endl;
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);

    return  list;
}


int checkDateStaff(string date) {
    if(!regex_match (date, regex("^([0-2][0-9]|(3)[0-1])(\\/)(((0)[0-9])|((1)[0-2]))(\\/)\\d{4}$"))) {
        return 1;
    }
    vector<string> list = Helpper::split(date,'/') ;
    stringstream s(date);

    string tmp;
    //int i = 0;

    for (int j=0 ;j<=list.size();j++) {
        cout << list[j] <<endl;
    }
    int day, month, year;

    day = stoi(list[0]);
    month =stoi(list[1]);
    year = stoi(list[2]);

    if (day < 1 || day > 31 || month < 1 || month > 12) {
        return 0;
    }
    if ((month==4 || month==6 || month==9|| month==11) && day == 31) {
        return 0;
    }
    if (month == 2 && (day > 29 || (day == 29 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))))) {
        return 0;
    }

    time_t t = time(0);
    struct tm * timeStruct = localtime(&t);
    int currentY = timeStruct->tm_year + 1900;
    int currentM = timeStruct->tm_mon + 1;
    int currentD = timeStruct->tm_mday;
    if (year < 1900 || year > currentY) {
        return 0;
    }
    if (year == currentY) {
        if (month > currentM || (month == currentM && day > currentD)) {
            return 0;
        }
    }

    return 1;
}









