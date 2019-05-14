QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmailSender
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS \
            _CRT_SECURE_NO_WARNINGS \
            _WINSOCK_DEPRECATED_NO_WARNINGS

CONFIG += c++17

SOURCES += \
        src/App.cpp                     \
        src/Email/CSmtp.cpp             \
        src/Event.cpp                   \
        src/main.cpp                    \
        src/Graphics/MainWindow.cpp     \
        src/Email/base64.cpp            \
        src/Email/CSmtp.cpp             \
        src/Email/Email.cpp             \
        src/Email/md5.cpp               \


HEADERS += \
        src/App.hpp                 \
        src/Event.hpp               \
        src/Graphics/MainWindow.hpp \
        src/Email/base64.h          \
        src/Email/CSmtp.h           \
        src/Email/Email.hpp         \
        src/Email/md5.h

FORMS += \
        src/Graphics/MainWindow.ui


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32: LIBS += -L$$PWD/deps/lib/ -lcapi -ldasync -llibcrypto -llibeay32 -llibssl -lopenssl -lossltest -lpadlock -lssleay32

INCLUDEPATH += $$PWD/deps/include/Sender
DEPENDPATH += $$PWD/deps/include/Sender

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/deps/lib/capi.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/deps/lib/libcapi.a
