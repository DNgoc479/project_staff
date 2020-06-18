#include <Staff.h>
#include <InfoAttendance.h>
#include <Helpper.h>
#include <TimekeepingHistory.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
// lay ra thong tin cac trang thai lam viec trong thang cua staff
TimekeepingHistory::TimekeepingHistory(string month,string year,int numberDayDL,int numberDayDLNN,int numberDayN,int numberDayNP):
    _month(month),_year(year),_numberDaysDL(numberDayDL),
    _numberDaysN(numberDayN),_numberDaysNP(numberDayNP),_numberDaysDLNN(numberDayDLNN)
{}
string TimekeepingHistory::url = "C:\\Users\\DNgoc\\Desktop\\ListNv\\";
map<string,TimekeepingHistory> TimekeepingHistory::readFileStaff(string idStaff,map<string,Staff> listStaff,string month){
    map<string,TimekeepingHistory> list;
    ifstream output;
    //    string idStaff;
    //    cout << "Enter id staff: ";
    //    cin >>idStaff;
    //    while(Helpper::checkId(listStaff,idStaff) == 1){
    //        cout << "Enter id staff again: ";
    //        cin >>idStaff;
    //    }
    string urlFile ="C:\\Users\\DNgoc\\Desktop\\ListNv\\"+idStaff+".csv";
    output.open(urlFile,ios::in);

    if(!output.is_open()){
        cout << "ERROR: File Open" << '\n';
    }
    int DL=0;
    int DLNN = 0;
    int N = 0;
    int NP = 0;
    while (output.good()) {
        string date,status;
        getline(output,date,',');
        getline(output,status,':');

        // cout << "date : "<< date <<endl;
//        if(date == ""){
//            return null;
//        }
        vector<string> listDate =  Helpper::split(date,'/');

        if(month == listDate[1]){
            if(status == "DL"){
                DL = DL +1;
            }else if (status == "DLNN") {
                DLNN = DLNN + 1;
            }else if (status == "N") {
                N = N + 1;

            }else if (status == "NP") {
                NP = NP + 1;
            }
        }

    }

    TimekeepingHistory timehistory = TimekeepingHistory(month,"2020",DL,DLNN,N,NP);
    list.insert(pair<string,TimekeepingHistory>(month,timehistory));

    output.close();
    fflush(stdin);
    return  list;

}
int TimekeepingHistory::inputNumber(string month){
    int number = atoi(month.c_str());

    if(number >0 && number <=12){
        return 1;
    }
    return 0;
}
void TimekeepingHistory::inputFileAttendance(string urlFile,string idStaff, map<string, TimekeepingHistory> list){



    fstream inputFile(urlFile+idStaff+".csv", ios::app);

    cout <<"size = " << list.size();
    for(map<string,TimekeepingHistory>::iterator it = list.begin();it != list.end();it++){

        inputFile<<"THANG:"+it->first<<",";
        inputFile<<"DL:";
        inputFile <<it->second.getNumberDaysDL() <<",";
        inputFile<<"N:";
        inputFile <<it->second.getNumberDaysN()<<",";
        inputFile<<"DLNN:";
        inputFile <<it->second.getNumberDaysDLNN()<<",";
        inputFile<<"NP:";
        inputFile <<it->second.getNumberDaysNP()<<"\n";

    }
    //inputFile<<"skskfks";
    inputFile.close();

}
