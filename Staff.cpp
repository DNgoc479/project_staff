#include "Staff.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include<cstring>
#include <algorithm>
#include <Helpper.h>
#include <iomanip>
#include <stdlib.h>
#include <FileIoUtils.h>
using namespace std;
string urlFile = "C:\\Users\\DNgoc\\Desktop\\ImportData.csv";
Staff::Staff(string id, string name,string birthday,string address,string wdepartment):
    _id(id),
    _name(name),
    _birthday(birthday),
    _address(address),
    _wDepartment(wdepartment)
{
}
void Staff::inputFile(string url,Staff staff){
    cout <<"co sddvsv";
    fstream output(url, ios::app);;
    string id = staff.getId();
    string name = staff.getName();
    string birthday = staff.getBirthday();
    string address = staff.getAddress();
    string wDepartment = staff.getWDepartment();

    output <<id <<",";
    output <<name <<",";
    output <<birthday <<",";
    output <<address <<",";
    output <<wDepartment <<endl;

    output.close();
}


map<string,Staff> Staff::addMapStaff(string urlfile){
    map<string,Staff> mapStaff;
    ifstream output;
    output.open(urlfile,ios::in);

    if(!output.is_open()){
        cout << "ERROR: File Open" << '\n';
    }
    while (output.good()) {
        string lineId,lineName,lineBirthday,linAddress,lineDepartment,line;
        getline(output,lineId,',');
        getline(output,lineName,',');
        getline(output,lineBirthday,',');
        getline(output,linAddress,',');
        getline(output,lineDepartment,'\n');

        Staff staff = Staff(lineId,lineName,lineBirthday,linAddress,lineDepartment);
     // cout << lineId<<endl;
        mapStaff.insert(pair<string,Staff>(lineId,staff));
        //staff.~Staff();
    }
    output.close();
       fflush(stdin);
    return  mapStaff;

}
 map<string,Staff> list =  Staff::addMapStaff(urlFile);
//map<string,Staff> list =  FileIoUtils::readEmployeeFromCsv(urlFile);


int Staff::checkId(string id,map<string,Staff> list){

    for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
        if(it->first == id){
            return 0;
        }
    }

    return 1;
}
//




//
void Staff::inputStaff(){
   // string urlFile = "E:\\QT\\project_staff\\fileStaff.csv";

    cout <<"" <<endl;
    cin.ignore();

    cout << "Enter id staff : ";
    getline(cin,_id);
    while (true) {
        if(checkId(_id,list) == 0){


            cout << "ID contained in the file.Enter id staff : ";
            getline(cin,_id);
        }else{
            break;
        }
    }

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
        cout << "Enter Department: ";
        getline(cin,_wDepartment);
    }

    Staff staff = Staff(_id,_name,_birthday,_address,_wDepartment);



    inputFile(urlFile,staff);



    fflush(stdin);
}

void Staff::printStaff(Staff staff){

    cout <<setw(10)<<staff.getId()<< setw(30) << staff.getName() << setw(20)
                << staff.getBirthday() << setw(30) << staff.getAddress()<<setw(20)<<staff.getWDepartment() << "\n";

}

void Staff::outStaffFile(){
    //string urlFile = "E:\\QT\\project_staff\\fileStaff.csv";
//    map<string,Staff> list =  Staff::addMapStaff(urlFile);
    map<string,Staff>::iterator itr;

    cout << "The number of employees on the list:  "<< list.size() << endl;
    cout <<setw(10)<<"Id"<< setw(30) << "Name" << setw(20)
                << "Birthday" << setw(30) << "Address"<<setw(20)<<"WDepartment" << "\n";
    for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
        printStaff(it->second);
    }


}
int isSubstring(string s1, string s2)
{
    std::transform(s1.begin(), s1.end(),s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(),s2.begin(), ::tolower);
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}
void Staff::SearchStaff(){


   // string urlFile = "E:\\QT\\project_staff\\fileStaff.csv";
    //map<string,Staff> list =  Staff::addMapStaff(urlFile);
    map<string,Staff>::iterator itr;


    int choice;


    do {
        cout << ""<< endl;
        cout <<"------- MENU SEARCH-------" <<endl;
        cout <<"1-Search by ID           -" <<endl ;
        cout <<"2-Search by Name         -" <<endl;
        cout <<"3-Search by Address      -"<<endl ;
        cout <<"4-Search by Department   -"<<endl ;
        cout <<"0-exit employee search   -"<<endl ;
        cout <<"--------------------------" <<endl;
        cout << "Enter the choice you are looking for:  " ;
        cin >> choice;
        switch (choice) {
        case 1:
        {

            string idSearch;
            cout << "=> SEACH BY ID: " <<endl;
            cout << "Enter staff id you are looking for:= " ;
            cin >> idSearch;
            int check = 0;
            for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
                if(it->first == idSearch){
                    printStaff(it->second);
                    check = 1;
                }
            }
            if(check == 0){

                cout << "Not container";

            }
            break;
        }
        case 2:
        {
            cout << "=> SEACH BY NAME" << endl;
            cin.ignore();
            string name;
            cout << "Enter name you are looking for:= ";
            getline(cin,name);
            int check = 0;
            for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
                if(isSubstring(name,it->second.getName()) >= 0){

                    printStaff(it->second);
                    check = 1;
                }
            }
            if(check == 0){

                cout << "Not container !";

            }
            fflush(stdin);
            break;
        }

        case 3:
        {

            cout << "=> SEACH BY Adress" << endl;
            cin.ignore();
            string address;
            cout << "Enter adress you are looking for:= ";
            getline(cin,address);
            int check = 0;
            cout << "----= LIST ADSRESS = "<<address <<"=----" <<endl;
            for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
                if(isSubstring(address,it->second.getAddress()) >= 0){

                    printStaff(it->second);
                    check = 1;
                }
            }
            if(check == 0){

                cout << "Not container !";

            }
            fflush(stdin);
            break;
        }

        case 4:
        {
            cout << "=> SEACH BY Department" <<endl;
            cin.ignore();
            string department;

            cout << "Enter Department you are looking for:= ";
            getline(cin,department);
            cout << department <<"-------------";
            int check = 0;
            for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
                if(isSubstring(department,it->second.getWDepartment()) >= 0){
                    printStaff(it->second);
                    check = 1;
                }
            }
            if(check == 0){

                cout << "Not container";

            }
            fflush(stdin);
            break;
        }
        }

    } while (choice != 0);



    fflush(stdin);
    cout << "\n-----= THE END SEARCH STAFF =-----" <<endl;
}




