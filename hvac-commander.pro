QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    application.cpp \
    blockitem.cpp \
    common/triangle.cpp \
    main.cpp \
    parameterwidget.cpp \
    settingsdialog.cpp \
    textwrapper.cpp \
    uidatamanagerscene.cpp \
    unitsconverter.cpp

HEADERS += \
    application.h \
    appsettings.h \
    blockitem.h \
    common/custombutton.h \
    common/triangle.h \
    enums.h \
    parameter.h \
    parameterwidget.h \
    parameterwidgetcontainer.h \
    settingsdialog.h \
    textwrapper.h \
    uidatamanagerscene.h \
    unitsconverter.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
