#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Staff.h>
#include <map>

#include <InfoAttendance.h>
using namespace std;
void menu(){
    cout <<"===========================================" <<endl;
    cout <<"= 1-Nhap nhan vien                        =" << endl;
    cout <<"= 2-Tim Thong tin nhan vien               =" << endl;
    cout <<"= 3-In tat ca cac nhan vien               =" << endl;
    cout <<"= 4-Tao file luu nhan vien                =" << endl;
    cout <<"= 5-nhap thong tin diem danh nhan vien    =" << endl;
    cout <<"===========================================" <<endl;
    cout << "Chon chuc nang (1-2):" << endl;
    cout << "Moi ban nhap lai lua chon:  ";

}
void run(){

    Staff *staff;

    int choice;
    string urlFile = "E:\\QT\\project_staff\\fileStaff.csv";
    staff = new Staff();
    map<string,Staff> list = staff->addMapStaff(urlFile);
    do {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
        {


            staff->inputStaff();


            break;
        }
        case 2:
        {

            cout << "\n------= SEARCH STAFF =------" <<endl;

            staff->SearchStaff();
            break;
        }
        case 3:
        {
            cout << "------= LIST STAFF =------ " <<endl;
            staff->outStaffFile();

            break;
        }case 4:
        {

            for(map<string,Staff>::iterator it = list.begin();it != list.end();it++){
                // tao file nhan vien diem danh
                std::ofstream o( "C:\\Users\\DNgoc\\Desktop\\ListNv\\"+it->first+".csv");
            }
            cout << "File creation successful !!! " <<endl;
            break;
        }
        case 5:
        {
            cout << "------= Nhap thong tin diem danh=------ " <<endl;
            InfoAttendance::read(list);

            break;
        }

        }

    }while (choice != 0);


    cout << "THE END !" << endl;
}
int main()
{
    run(); //<mo run>


    return 0;
}
