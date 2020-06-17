#include "Helpper.h"
#include <vector>
#include <sstream>
#include  <string>
#include <fstream>
//#include <specstrings.h>
using namespace  std;
int Helpper::numberLine(){
    ifstream f1;
    char c;
    int numchars, numlines;

    f1.open("C:\\Users\\DNgoc\Desktop\\ImportData.csv");

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
vector<string> Helpper ::split(const string &s, char delim){
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
int Helpper:: checkDateOfBirth(string dateOfBirth){
    for (int i = 0; i < dateOfBirth.length(); i++) {
        if ((dateOfBirth[i] < 47) || (dateOfBirth[i] > 57)) {
            return 0;
        }
    }
    vector<string> birth;
    while(!dateOfBirth.empty()){
        birth.push_back(dateOfBirth.substr(0, dateOfBirth.find("/")));
        if (dateOfBirth.find("/") > dateOfBirth.size()) {
            break;
        }
        dateOfBirth.erase(0, dateOfBirth.find("/") + 1);
    }
    if (birth.size() != 3) {
        return 0;
    } else {
        if ((stoi(birth[0], 0, 10) > 31) || (stoi(birth[1], 0, 10) > 12)) {
            return 0;
        } else {
            switch (stoi(birth[1], 0, 10))
            {
            case 2:
                if (stoi(birth[0], 0, 10) > 29) {
                    return 0;
                }
                if (stoi(birth[0], 0, 10) == 29){
                    if((stoi(birth[2], 0, 10) % 400 == 0) || ((stoi(birth[2], 0, 10) % 4 == 0) && (stoi(birth[2], 0, 10) % 100 != 0))) {
                        return 1;
                    }
                    return 0;
                }
                return 1;
                break;

            case 4: case 6: case 9: case 11:
                if (stoi(birth[0], 0, 10) > 30) {
                    return 0;
                }
                return 1;
                break;
            }
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


int  checkYear(string date)
{
    vector<string> list = cutStringDate(date,",");
    int year = stoi(list[2]);

    if(year < 1945 || year > 2002){
        return 0;
    }
    return 1;
}
int  checkYearWork(string date)
{
    vector<string> list = cutStringDate(date,",");
    int year = stoi(list[2]);

    if(year < 2017 || year > 2020){
        return 0;
    }
    return 1;
}
int checkMonth(string date)
{
    vector<string> list = cutStringDate(date,",");
    int month = stoi(list[1]);
    if(month < 1 || month > 12){
        return 0;
    }
    return 1;
}
bool checkDate(string date)
{
    vector<string> list = cutStringDate(date,",");
    int day = stoi(list[0]);
    int month = stoi(list[1]);
    if(day > 0){
        if(month == 2){
            if(day > 29){
                return 0;
            }
        }
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            if(day > 31){
                return 0;
            }
        }
        if (month == 4 || month == 6 || month == 11){
            if(day > 30){
                return 0;
            }
        }
    }
    return 1;
}
int Helpper::checkDateStaff(string date){
    vector<string> listDate = cutStringDate(date,"/");
    if(checkDate(listDate[0]) && checkMonth(listDate[1]) && checkYear(listDate[2])){
        return  1;
    }
    return 0;
}








