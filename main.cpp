#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Staff.h>
#include <map>
using namespace std;
void menu(){
    cout <<"===========================================" <<endl;
    cout <<"= 1-Nhap nhan vien                        =" << endl;
    cout <<"= 2-In tat ca cac nha vien                =" << endl;
    cout <<"= 3-Tim Thong tin nhan vien               =" << endl;
    cout <<"===========================================" <<endl;
    cout << "Chon chuc nang (1-2):" << endl;
    cout << "Moi ban nhap lai lua chon:  ";

}
int main()
{
    vector<Staff*> listStaff;
    Staff *staff;

    int choice;
    string urlFile = "E:\\QT\\project_staff\\fileStaff.txt";
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
            cout << "------= LIST STAFF =------ " <<endl;
            staff->outStaffFile();

            break;
        }
        case 3:
        {

            cout << "\n------= SEARCH STAFF =------" <<endl;

            staff->SearchStaff();
            break;
        }
        }

    }while (choice != 0);


    cout << "THE END !" << endl;
    return 0;
}
