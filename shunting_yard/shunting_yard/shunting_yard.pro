TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        function.cpp \
        lparen.cpp \
        main.cpp \
        numbers.cpp \
        operators.cpp \
        rparen.cpp \
        shunt_yard.cpp \
        token.cpp

HEADERS += \
    function.h \
    lparen.h \
    numbers.h \
    operators.h \
    rparen.h \
    shunt_yard.h \
    token.h \
    z_output.h \
    z_work_report.h
