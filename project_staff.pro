TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        DateStaffManagement.cpp \
        Staff.cpp \
        main.cpp

HEADERS += \
    DateStaffManagement.h \
    Staff.h \
    helpper.h

DISTFILES += \
    fileStaff.csv
