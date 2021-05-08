#-------------------------------------------------
#
# Project created by QtCreator 2021-05-08T13:40:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crypt_qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lcrypto -lssl

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    aes_wind.cpp \
    aes_c.cpp \
    sha_c.cpp \
    sha1_wind.cpp \
    sha2_wind.cpp \
    sub_test.cpp \
    RSA_c.cpp \
    dynamic_mem_c.cpp \
    rsa_wind.cpp

HEADERS += \
        mainwindow.h \
    aes_wind.h \
    aes_c.hpp \
    aes_c.hpp \
    sha_c.hpp \
    sha1_wind.h \
    sha2_wind.h \
    sub_test.h \
    RSA_c.hpp \
    dynamic_mem_c.hpp \
    rsa_wind.h

FORMS += \
        mainwindow.ui \
    aes_wind.ui \
    sha1_wind.ui \
    sha2_wind.ui \
    sub_test.ui \
    rsa_wind.ui
