QT = gui core xml
CONFIG += qt \
 warn_on \
 console \
 staticlib \
 build_all \
 qtestlib \
 lib_bundle \
 app_bundle \
 debug \
 -nomake
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
SOURCES = \
    magicbookshow.cpp \
    settingdialog.cpp \
    plotter.cpp \
    irrAR/SkinLoader.cpp \
    irrAR/irrAR.cpp \
    irrAR/CImageGUISkin.cpp \
    irrAR/CGUIProgressBar.cpp \
    irrAR/CConfigReader.cpp \
    irrAR/CConfigMap.cpp \
    bookscene.cpp \
    roomscene.cpp \
    picwall/util.cpp \
    picwall/CameraAnimator.cpp \
    picwall/Spider/CLocalImageSpider.cpp \
    picwall/Wall/CWallManager.cpp \
    picwall/Wall/CLocalImageItem.cpp \
    homeview/NaviBar.cpp \
    homeview.cpp \
    homeview/QImageButton.cpp \
    modelmanagedialog.cpp \
    viewmanagedialog.cpp

FORMS += \
    ui/maindialog.ui \
    ui/settingdialog.ui \
    ui/modelmanagedialog.ui \
    ui/viewmanagedialog.ui
HEADERS += \
    settingdialog.h \
    plotter.h \
    irrAR/SkinLoader.h \
    irrAR/irrAR.h \
    irrAR/clipRects.h \
    irrAR/CImageGUISkin.h \
    irrAR/CGUIProgressBar.h \
    irrAR/CConfigReader.h \
    irrAR/CConfigMap.h \
    bookscene.h \
    roomscene.h \
    picwall/CameraAnimator.h \
    picwall/util.h \
    picwall/CameraAnimator.h \
    picwall/Spider/IImageSpider.h \
    picwall/Spider/CLocalImageSpider.h \
    picwall/Wall/IImageItem.h \
    picwall/Wall/CWallManager.h \
    picwall/Wall/CLocalImageItem.h \
    homeview/NaviBar.h \
    homeview.h \
    homeview/QImageButton.h \
    modelmanagedialog.h \
    viewmanagedialog.h
TEMPLATE = app
LIBS += -lXtst -ljpeg
RESOURCES += \
    magicbookshow.qrc


INCLUDEPATH +=~/workspace/ARToolKit/include \
~/workspace/irrlicht-1.7.3/include \
/usr/include/GL

QMAKE_LIBS= -lARgsub -lARvideo -lAR -lARMulti -lglut -lGLU -lGL -lXi -lXmu -lX11 -lm -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXi -lXmu
LIBPATH +=~/workspace/ARToolKit/lib \
~/workspace/irrlicht-1.7.3/lib/Linux

LIBS +=/usr/lib/libglut.so
