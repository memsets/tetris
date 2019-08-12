TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
SOURCES += \
        block.cpp \
        figure.cpp \
        stack.cpp \
        main.cpp

HEADERS += \
    block.h \
    stack.h \
    figure.h
