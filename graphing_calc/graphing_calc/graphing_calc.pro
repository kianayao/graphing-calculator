TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#WINDOWS
# put SFML file in the same location as project
LIBS += -L"C:\Users\yaoki\OneDrive\Desktop\SFML-2.5.1\lib" #change this
LIBS += -L"C:\Users\yaoki\OneDrive\Desktop\SFML-2.5.1\bin" #change this


CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "C:\Users\yaoki\OneDrive\Desktop\SFML-2.5.1\include" #change this
DEPENDPATH += "C:\Users\yaoki\OneDrive\Desktop\SFML-2.5.1\include" #change this

SOURCES += \
        ../../shunting_yard/shunting_yard/lparen.cpp \
        ../../shunting_yard/shunting_yard/numbers.cpp \
        ../../shunting_yard/shunting_yard/operators.cpp \
        ../../shunting_yard/shunting_yard/rparen.cpp \
        ../../shunting_yard/shunting_yard/shunt_yard.cpp \
        ../../shunting_yard/shunting_yard/token.cpp \
        ../../shunting_yard/shunting_yard/function.cpp \
        animate.cpp \
        coordinate_translator.cpp \
        graph.cpp \
        graph_info.cpp \
        main.cpp \
        plot.cpp \
        rpn.cpp \
        sidebar.cpp \
        system.cpp \
        tokenizer.cpp

HEADERS += \
    ../../!includes/my_vector/my_vector.h \
    ../../shunting_yard/shunting_yard/lparen.h \
    ../../shunting_yard/shunting_yard/numbers.h \
    ../../shunting_yard/shunting_yard/operators.h \
    ../../shunting_yard/shunting_yard/rparen.h \
    ../../shunting_yard/shunting_yard/shunt_yard.h \
    ../../shunting_yard/shunting_yard/token.h \
    ../../shunting_yard/shunting_yard/function.h \
    ../../shunting_yard/shunting_yard/z_output.h \
    ../../shunting_yard/shunting_yard/z_work_report.h \
    animate.h \
    constants.h \
    coordinate_translator.h \
    graph.h \
    graph_info.h \
    plot.h \
    rpn.h \
    sidebar.h \
    system.h \
    tokenizer.h \
    z_work_report.h

SUBDIRS += \
    ../../shunting_yard/shunting_yard/shunting_yard.pro \
    ../../shunting_yard/shunting_yard/shunting_yard.pro

DISTFILES +=
