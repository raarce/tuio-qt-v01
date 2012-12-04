# QT += opengl


QMAKESPEC += macx-xcode

HEADERS += \
    oscpack/ip/NetworkingUtils.h \
    oscpack/osc/OscTypes.h \
    oscpack/osc/OscReceivedElements.h \
    oscpack/osc/OscPrintReceivedElements.h \
    TUIO/TuioTime.h \
    TUIO/TuioClient.h \
    TuioDemo.h \
    oscpack/osc/OscPacketListener.h \
    oscpack/osc/OscHostEndianness.h \
    oscpack/osc/OscException.h \
    oscpack/ip/UdpSocket.h \
    oscpack/ip/TimerListener.h \
    oscpack/ip/PacketListener.h \
    TUIO/TuioPoint.h \
    TUIO/TuioObject.h \
    TUIO/TuioListener.h \
    TUIO/TuioCursor.h \
    TUIO/TuioContainer.h

SOURCES += \
    oscpack/ip/posix/NetworkingUtils.cpp \
    oscpack/osc/OscTypes.cpp \
    oscpack/osc/OscReceivedElements.cpp \
    oscpack/osc/OscPrintReceivedElements.cpp \
    TUIO/TuioTime.cpp \    
    oscpack/ip/posix/UdpSocket.cpp \
    TUIO/TuioClient.cpp \
    TuioDemo.cpp

LIBS +=  -lSDL -lSDLmain

QMAKE_LFLAGS_SONAME  = -Wl,-install_name,@executable_path/../Frameworks/

INCLUDEPATH = oscpack TUIO sdl/include
