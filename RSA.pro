#-------------------------------------------------
#
# Project created by QtCreator 2013-05-24T08:22:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RSA
TEMPLATE = app


SOURCES += main.cpp\
        maindialog.cpp \
    KeyPair.cpp \
    Key.cpp \
    BigInt.cpp \
    RSA.cpp \
    PrimeGenerator.cpp

HEADERS  += maindialog.h \
    KeyPair.h \
    Key.h \
    BigInt.h \
    RSA.h \
    PrimeGenerator.h

FORMS    += maindialog.ui

TRANSLATIONS = tr_ru.ts
