#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Staff.h"
#include "FileIoUtils.h"
#include "InfoAttendance.h"
using namespace std;


 void addCheckPoint(const InfoAttendance & infoAttendance)
{
    string fileName = FileIoUtils::genCheckpointFileName(infoAttendance.getIdStaff());
    ofstream fout;
    fout.open(fileName, ios::app);
    if (fout.is_open()) {
        fout << infoAttendance.getDate() << "," << infoAttendance.getStatus() << endl;
    }
    fout.close();
}
map<string,InfoAttendance> FileIoUtils::loadCheckPoint(const string & idStaff)
{
   map<string,InfoAttendance> checkpoints;

    string fileName = FileIoUtils::genCheckpointFileName(idStaff);
    ifstream fin;
    fin.open(fileName, ios::in);
    if (fin.is_open()) {
        string line, word;

        while (getline(fin, line)) {
            stringstream s(line);
            int i = 0;
            string row[2];
            while (getline(s, word, ',')) {
                row[i++] = word;
            }
          InfoAttendance *in = new InfoAttendance(idStaff, row[0], row[1]);
         checkpoints.insert(pair<string,InfoAttendance>(idStaff,*in));
        }
    }
    fin.close();

    return checkpoints;
}

const string FileIoUtils::genCheckpointFileName(const string & idStaff)
{
    string fileName = "checkpoint-" + idStaff + ".csv";
    return fileName;
}

bool FileIoUtils::checkExist(string &path)
{
    ifstream f(path.c_str());
    return f.good();
}

void FileIoUtils::rewriteCheckPoint(string & idStaff, map<string,InfoAttendance> checkPoints)
{
    string fileName = FileIoUtils::genCheckpointFileName(idStaff);
    ofstream fstream_ob;
    fstream_ob.open(fileName, ios::trunc);

    if (fstream_ob.is_open()) {
       for(map<string,InfoAttendance>::iterator it = checkPoints.begin();it != checkPoints.end();it++){
            fstream_ob << it->second.getDate() << "," << it->second.getStatus() << endl;
        }
    }
    fstream_ob.close();
}
