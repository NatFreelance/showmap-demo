QT       += core gui quick qml quickwidgets positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addobjectform.cpp \
   # coordinate.cpp \
    main.cpp \
    #mapobject.cpp \
    mapwidgettool.cpp \
    markermodel.cpp \
    settingsform.cpp \
    slippymap.cpp

HEADERS += \
    addobjectform.h \
   # coordinate.h \
   # mapobject.h \
    mapwidgettool.h \
    markermodel.h \
    settingsform.h \
    slippymap.h

FORMS += \
    addobjectform.ui \
    mapwidgettool.ui \
    settingsform.ui \

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH ="/usr/include/qt5/QtQml"

# Additional import path used to resolve QML modules just for Qt Quick Designer
#QML_DESIGNER_IMPORT_PATH =


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc\
    helper.js


