TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Helpper.cpp \
        InfoAttendance.cpp \
        Staff.cpp \
        main.cpp

HEADERS += \
    Helpper.h \
    InfoAttendance.h \
    Staff.h

DISTFILES += \
    fileStaff.csv
