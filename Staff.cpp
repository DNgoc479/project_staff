#include "Staff.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

Staff::Staff(string id, string name,string birthday,string address,string wdepartment){
    _id = id;
    _name = name;
    _birthday = birthday;
    _address = address;
    _wDepartment = wdepartment;
}
void Staff::inputFile(string url,Staff staff){
    fstream output(url, ios::app);;
    string id = staff.getId();
    string name = staff.getName();
    string birthday = staff.getBirthday();
    string address = staff.getAddress();
    string wDepartment = staff.getWDepartment();

    output <<id <<endl;
    output <<name <<endl;
    output <<birthday <<endl;
    output <<address <<endl;
    output <<wDepartment <<endl;

    output.close();
}

map<string,Staff> Staff::addMapStaff(string urlfile){
    map<string,Staff> mapStaff;
    fstream output;
    output.open(urlfile,ios::in);
    string lineId,lineName,lineBirthday,linAddress,lineDepartment;
    while (!output.eof()) {
        getline(output,lineId);
        getline(output,lineName);
        getline(output,lineBirthday);
        getline(output,linAddress);
        getline(output,lineDepartment);

        Staff staff = Staff(lineId,lineName,lineBirthday,linAddress,lineDepartment);
        mapStaff.insert(pair<string,Staff>(lineId,staff));

    }
    output.close();
    return  mapStaff;
}
int Staff::checkId(string id,map<string,Staff> list){

    for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
          if(it->first == id){
              return 0;
          }
      }

    return 1;
}
void Staff::inputStaff(){
    string urlFile = "E:\\QT\\project_staff\\fileStaff.txt";
    map<string,Staff> mapStaff = addMapStaff(urlFile);
    cout <<"" <<endl;
    cin.ignore();

    cout << "Enter id staff : ";
    getline(cin,_id);
    while (true) {
        if(checkId(_id,mapStaff) == 0){


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
        cout << "Enter address: ";
        getline(cin,_wDepartment);
    }

    Staff staff = Staff(_id,_name,_birthday,_address,_wDepartment);



        inputFile(urlFile,staff);



    fflush(stdin);
}

void Staff::printStaff(Staff staff){
    cout <<"" <<endl;
    cout << "Id staff: " << staff.getId() << endl;
    cout << "Name staff: " << staff.getName() << endl;
    cout << "Date of birth: " << staff.getBirthday() << endl;
    cout << "Address: " << staff.getAddress() << endl;
    cout << "Department: " << staff.getWDepartment() << endl;
    cout <<"" <<endl;

}

void Staff::outStaffFile(){
    string urlFile = "E:\\QT\\project_staff\\fileStaff.txt";
    map<string,Staff> list =  Staff::addMapStaff(urlFile);
    map<string,Staff>::iterator itr;

    cout << "The number of employees on the list:  "<< list.size();
    for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
          printStaff(it->second);
      }


}
void Staff::SearchStaff(){


    string urlFile = "E:\\QT\\project_staff\\fileStaff.txt";
    map<string,Staff> list =  Staff::addMapStaff(urlFile);
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
                          if(it->second.getName() == name){
                              printStaff(it->second);
                              check = 1;
                          }
                      }
                    if(check == 0){

                        cout << "Not container !";

                    }
                    break;
                }
                case 3:
                {
                    cout << "=> SEACH BY Department" <<endl;
                    string department;
                    cin.ignore();
                    cout << "Enter Department you are looking for:= ";
                    getline(cin,department);
                    int check = 0;
                    for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
                          if(it->first == department){
                              printStaff(it->second);
                              check = 1;
                          }
                      }
                    if(check == 0){

                        cout << "Not container";

                    }
                    break;
                }
                }

        } while (choice != 0);



   fflush(stdin);
    cout << "\n-----= THE END SEARCH STAFF =-----" <<endl;
}




