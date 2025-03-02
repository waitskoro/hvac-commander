QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    application.cpp \
    blockitem.cpp \
    blockssceneviewer.cpp \
    common/textwrapper.cpp \
    common/triangle.cpp \
    common/unitsconverter.cpp \
    main.cpp \
    parameterwidget.cpp \
    settingsdialog.cpp

HEADERS += \
    application.h \
    blockitem.h \
    blockssceneviewer.h \
    common/enums.h \
    common/parameter.h \
    common/textwrapper.h \
    common/triangle.h \
    common/unitsconverter.h \
    headerwidget.h \
    parameter.h \
    parameterwidget.h \
    settingsdialog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
