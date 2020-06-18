#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Staff.h>
#include <map>
#include <Helpper.h>
#include <InfoAttendance.h>
#include <TimekeepingHistory.h>
#include <InfoAttendance.h>
using namespace std;

void menu(){
    cout<< ""<< endl;
    cout <<"===========================================" <<endl;
    cout <<"= 1-Nhap nhan vien                        =" << endl;
    cout <<"= 2-Tim Thong tin nhan vien               =" << endl;
    cout <<"= 3-In tat ca cac nhan vien               =" << endl;
    cout <<"= 4-Tao file luu nhan vien                =" << endl;
    cout <<"= 5-nhap thong tin diem danh nhan vien    =" << endl;
    cout <<"= 6-Lich su diem danh nhan vien           =" << endl;
    cout <<"===========================================" <<endl;
    cout << "Chon chuc nang (1-6):" << endl;
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
        case 6:
        {
            cout << "------= lICH SU LAM VIEC CUA NHAN VIEN=------ " <<endl;
            string month;
            cout << "Nhap Thang ban muon diem danh: ";
            cin >> month;
            while (TimekeepingHistory::inputNumber(month) == 0 ) {
                cout << "Nhap Thang ban muon diem danh again: ";
                cin >> month;
            }
            string idStaff;
            cout << "Enter id staff: ";
            cin >>idStaff;
            while(Helpper::checkId(list,idStaff) == 1){
                cout << "Enter id staff again: ";
                cin >>idStaff;
            }

            map<string,TimekeepingHistory> listT = TimekeepingHistory::readFileStaff(idStaff,list,month);
             cout <<"check = " <<listT.empty();
//            int check = listT.empty();
//            if(check == 0){
//                break;
//            }
            for(map<string,TimekeepingHistory>::iterator it = listT.begin();it != listT.end();it++){
                cout <<"so ngay di lam         := " <<it->second.getNumberDaysDL()<< endl;
                cout <<"so ngay ngay nghi      := " <<it->second.getNumberDaysN()<< endl;
                cout <<"so ngay di lam nua ngay:= " <<it->second.getNumberDaysDLNN()<< endl;
                cout <<"so ngay nghi phep      := " <<it->second.getNumberDaysNP()<< endl;

            }
            string urlFileHistory = "C:\\Users\\DNgoc\\Desktop\\HistoryDD\\";
            std::ofstream o( urlFile+idStaff+".csv");

            o.close();
            TimekeepingHistory::inputFileAttendance(urlFileHistory,idStaff,listT);

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
