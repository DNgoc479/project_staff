#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Staff.h>
using namespace std;
void menu(){
    cout <<"===========================================" <<endl;
    cout <<"= 1-Nhap nhan vien                        =" << endl;
    cout <<"= 2-Xuat nhan vien                        =" << endl;
    cout <<"===========================================" <<endl;
    cout << "Chon chuc nang (1-2):" << endl;
    cout << "Moi ban nhap lai lua chon = ";
}
int main()
{
    vector<Staff*> listStaff;
    Staff *staff;
//    string id;
//    string name;
//    string birthday;
//    string address;
//    string wDepartment;
    int choice;
    do {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:// nhap 1 nguoi
        {
            staff = new Staff();
            staff->inputStaff();
            listStaff.push_back(staff);
            break;
        }
        case 2:// in ra ds nhan vien
        {
            if(listStaff.size() == 0 ){
                cout << "Danh sach khong co staff nao";
            }else{
                for (int i = 0; i < listStaff.size(); i++ ){
                    listStaff[i]->printStaff();

                }
            }
        }
        }

    }while (choice != 0);


    cout << "Hello World!" << endl;
    return 0;
}
