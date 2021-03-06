QT      += core gui widgets testlib
TEMPLATE = app
TARGET   = UnitTest
CONFIG  += testcase

include(../../_install/rsatoolbox.pri)
HEADERS += VnaIntermodTest.h \
           VnaPauseSweepsTest.h \
           VnaArbitraryFrequencyTest.h \
           VnaSweepTest.h \
           UnitsTest.h \
           VnaCalibrateTest.h \
           VnaChannelTest.h \
           VnaTraceTest.h \
    MockBusTest.h \
    vnaundotest.h \
    vnapulsegeneratortest.h \
    vnatriggertest.h \
    vnasyncgeneratortest.h \
    visabustest.h \
    genericinstrumenttest.h
SOURCES += main.cpp \
           VnaIntermodTest.cpp \
           VnaPauseSweepsTest.cpp \
           VnaArbitraryFrequencyTest.cpp \
           VnaSweepTest.cpp \
           UnitsTest.cpp \
           VnaCalibrateTest.cpp \
           VnaChannelTest.cpp \
           VnaTraceTest.cpp \
    MockBusTest.cpp \
    vnaundotest.cpp \
    vnapulsegeneratortest.cpp \
    vnatriggertest.cpp \
    vnasyncgeneratortest.cpp \
    visabustest.cpp \
    genericinstrumenttest.cpp

DEFINES += SOURCE_DIR=\\\"$$PWD/\\\"
