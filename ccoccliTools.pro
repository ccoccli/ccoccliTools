QT += core gui sql widgets xml

CONFIG += c++17

INCLUDEPATH += $$PWD/src

SOURCES += $$files($$INCLUDEPATH/*.cpp, true)
HEADERS += $$files($$INCLUDEPATH/*.hpp, true)

FORMS += res/mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/ccoccliTools.qrc
