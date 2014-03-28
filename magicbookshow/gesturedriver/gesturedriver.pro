HEADERS += \
    qextserialport/qextserialbase.h \
    qextserialport/posix_qextserialport.h \
    gestureview.h

SOURCES += \
    qextserialport/qextserialbase.cpp \
    qextserialport/posix_qextserialport.cpp \
    gesturedriver.cpp \
    gestureview.cpp

FORMS += \
    gestureview.ui
LIBS += -lXtst
QMAKE_LIBS=-lXi -lXmu -lX11 -lXxf86vm -lXext -lX11 -lXi -lXmu

