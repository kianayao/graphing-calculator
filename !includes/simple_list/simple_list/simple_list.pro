TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        my_simple_list_functions.cpp \
        test_simple_list.cpp

HEADERS += \
    ../../my_list/my_list.h \
    ../../node/node.h \
    my_simple_list.h \
    my_simple_list_functions.h \
    test_simple_list.h \
    z_output.h \
    z_work_report.h
