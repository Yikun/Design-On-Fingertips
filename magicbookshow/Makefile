#############################################################################
# Makefile for building: bin/magicbookshow
# Generated by qmake (2.01a) (Qt 4.7.4) on: Tue Jul 16 18:28:43 2013
# Project:  magicbookshow.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile magicbookshow.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4 -I/usr/include/qt4/QtTest -I../ARToolKit/include -I../irrlicht-1.7.3/include -I/usr/include/GL -Ibuild -Ibuild
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/home/kero/workspace/ARToolKit/lib -L/home/kero/workspace/irrlicht-1.7.3/lib/Linux -L/usr/lib/i386-linux-gnu -lARgsub -lARvideo -lAR -lARMulti -lglut -lGLU -lm -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXi -lXmu -lXtst -ljpeg /usr/lib/libglut.so -lQtTest -lQtXml -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = magicbookshow.cpp \
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
		viewmanagedialog.cpp build/moc_settingdialog.cpp \
		build/moc_plotter.cpp \
		build/moc_NaviBar.cpp \
		build/moc_homeview.cpp \
		build/moc_QImageButton.cpp \
		build/moc_modelmanagedialog.cpp \
		build/moc_viewmanagedialog.cpp \
		qrc_magicbookshow.cpp
OBJECTS       = build/magicbookshow.o \
		build/settingdialog.o \
		build/plotter.o \
		build/SkinLoader.o \
		build/irrAR.o \
		build/CImageGUISkin.o \
		build/CGUIProgressBar.o \
		build/CConfigReader.o \
		build/CConfigMap.o \
		build/bookscene.o \
		build/roomscene.o \
		build/util.o \
		build/CameraAnimator.o \
		build/CLocalImageSpider.o \
		build/CWallManager.o \
		build/CLocalImageItem.o \
		build/NaviBar.o \
		build/homeview.o \
		build/QImageButton.o \
		build/modelmanagedialog.o \
		build/viewmanagedialog.o \
		build/moc_settingdialog.o \
		build/moc_plotter.o \
		build/moc_NaviBar.o \
		build/moc_homeview.o \
		build/moc_QImageButton.o \
		build/moc_modelmanagedialog.o \
		build/moc_viewmanagedialog.o \
		build/qrc_magicbookshow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qtestlib.prf \
		/usr/share/qt4/mkspecs/features/staticlib.prf \
		/usr/share/qt4/mkspecs/features/static.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		magicbookshow.pro
QMAKE_TARGET  = magicbookshow
DESTDIR       = bin/
TARGET        = bin/magicbookshow

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): build/ui_maindialog.h build/ui_settingdialog.h build/ui_modelmanagedialog.h build/ui_viewmanagedialog.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: magicbookshow.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/qtestlib.prf \
		/usr/share/qt4/mkspecs/features/staticlib.prf \
		/usr/share/qt4/mkspecs/features/static.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/i386-linux-gnu/libQtTest.prl \
		/usr/lib/i386-linux-gnu/libQtXml.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile magicbookshow.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/qtestlib.prf:
/usr/share/qt4/mkspecs/features/staticlib.prf:
/usr/share/qt4/mkspecs/features/static.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/i386-linux-gnu/libQtTest.prl:
/usr/lib/i386-linux-gnu/libQtXml.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile magicbookshow.pro

dist: 
	@$(CHK_DIR_EXISTS) build/magicbookshow1.0.0 || $(MKDIR) build/magicbookshow1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/magicbookshow1.0.0/ && $(COPY_FILE) --parents settingdialog.h plotter.h irrAR/SkinLoader.h irrAR/irrAR.h irrAR/clipRects.h irrAR/CImageGUISkin.h irrAR/CGUIProgressBar.h irrAR/CConfigReader.h irrAR/CConfigMap.h bookscene.h roomscene.h picwall/CameraAnimator.h picwall/util.h picwall/CameraAnimator.h picwall/Spider/IImageSpider.h picwall/Spider/CLocalImageSpider.h picwall/Wall/IImageItem.h picwall/Wall/CWallManager.h picwall/Wall/CLocalImageItem.h homeview/NaviBar.h homeview.h homeview/QImageButton.h modelmanagedialog.h viewmanagedialog.h build/magicbookshow1.0.0/ && $(COPY_FILE) --parents magicbookshow.qrc build/magicbookshow1.0.0/ && $(COPY_FILE) --parents magicbookshow.cpp settingdialog.cpp plotter.cpp irrAR/SkinLoader.cpp irrAR/irrAR.cpp irrAR/CImageGUISkin.cpp irrAR/CGUIProgressBar.cpp irrAR/CConfigReader.cpp irrAR/CConfigMap.cpp bookscene.cpp roomscene.cpp picwall/util.cpp picwall/CameraAnimator.cpp picwall/Spider/CLocalImageSpider.cpp picwall/Wall/CWallManager.cpp picwall/Wall/CLocalImageItem.cpp homeview/NaviBar.cpp homeview.cpp homeview/QImageButton.cpp modelmanagedialog.cpp viewmanagedialog.cpp build/magicbookshow1.0.0/ && $(COPY_FILE) --parents ui/maindialog.ui ui/settingdialog.ui ui/modelmanagedialog.ui ui/viewmanagedialog.ui build/magicbookshow1.0.0/ && (cd `dirname build/magicbookshow1.0.0` && $(TAR) magicbookshow1.0.0.tar magicbookshow1.0.0 && $(COMPRESS) magicbookshow1.0.0.tar) && $(MOVE) `dirname build/magicbookshow1.0.0`/magicbookshow1.0.0.tar.gz . && $(DEL_FILE) -r build/magicbookshow1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_settingdialog.cpp build/moc_plotter.cpp build/moc_NaviBar.cpp build/moc_homeview.cpp build/moc_QImageButton.cpp build/moc_modelmanagedialog.cpp build/moc_viewmanagedialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_settingdialog.cpp build/moc_plotter.cpp build/moc_NaviBar.cpp build/moc_homeview.cpp build/moc_QImageButton.cpp build/moc_modelmanagedialog.cpp build/moc_viewmanagedialog.cpp
build/moc_settingdialog.cpp: build/ui_settingdialog.h \
		settingdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) settingdialog.h -o build/moc_settingdialog.cpp

build/moc_plotter.cpp: plotter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) plotter.h -o build/moc_plotter.cpp

build/moc_NaviBar.cpp: homeview/NaviBar.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) homeview/NaviBar.h -o build/moc_NaviBar.cpp

build/moc_homeview.cpp: homeview/NaviBar.h \
		homeview/QImageButton.h \
		bookscene.h \
		irrAR/irrAR.h \
		irrAR/CGUIProgressBar.h \
		irrAR/CImageGUISkin.h \
		irrAR/SkinLoader.h \
		roomscene.h \
		settingdialog.h \
		build/ui_settingdialog.h \
		modelmanagedialog.h \
		build/ui_modelmanagedialog.h \
		viewmanagedialog.h \
		build/ui_viewmanagedialog.h \
		plotter.h \
		homeview.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) homeview.h -o build/moc_homeview.cpp

build/moc_QImageButton.cpp: homeview/QImageButton.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) homeview/QImageButton.h -o build/moc_QImageButton.cpp

build/moc_modelmanagedialog.cpp: build/ui_modelmanagedialog.h \
		modelmanagedialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modelmanagedialog.h -o build/moc_modelmanagedialog.cpp

build/moc_viewmanagedialog.cpp: build/ui_viewmanagedialog.h \
		viewmanagedialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) viewmanagedialog.h -o build/moc_viewmanagedialog.cpp

compiler_rcc_make_all: qrc_magicbookshow.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_magicbookshow.cpp
qrc_magicbookshow.cpp: magicbookshow.qrc \
		images/stop.png \
		images/fish.jpg \
		images/cookies.jpg \
		images/pasta.jpg \
		images/zoomin.png \
		images/puding.jpg \
		images/mussels.jpg \
		images/brownies.jpg \
		images/sushi.jpg \
		images/trouts.jpg \
		images/pizza.jpg \
		images/zoomout.png \
		images/open.png \
		images/chocolate.jpg \
		icons/manage.png \
		icons/contacts-page.svg \
		icons/btn_pressed.png \
		icons/map-page.svg \
		icons/setting.png \
		icons/btn_normal.png \
		icons/display.png \
		icons/btn_checked.png \
		icons/go-back.png \
		icons/weather-page.svg \
		icons/image-page.svg \
		icons/web-page.svg \
		icons/options-menu.png \
		icons/go-forward.png \
		icons/home-page.svg \
		icons/info.png \
		icons/btn_hovered.png \
		icons/homeui/bt_40.png \
		icons/homeui/item_3_1.png \
		icons/homeui/bt_30.png \
		icons/homeui/item_1_10.png \
		icons/homeui/bt_2.png \
		icons/homeui/bt_20.png \
		icons/homeui/ui_3.png \
		icons/homeui/item_1_20.png \
		icons/homeui/bt_10.png \
		icons/homeui/item_1_2.png \
		icons/homeui/bt_3.png \
		icons/homeui/ui_4.png \
		icons/homeui/ui_bg.png \
		icons/homeui/item_2_10.png \
		icons/homeui/item_1_1.png \
		icons/homeui/item_2_2.png \
		icons/homeui/item_2_20.png \
		icons/homeui/bt_4.png \
		icons/homeui/ui_1.png \
		icons/homeui/item_3_10.png \
		icons/homeui/item_2_1.png \
		icons/homeui/bt_1.png \
		icons/homeui/ui_2.png
	/usr/bin/rcc -name magicbookshow magicbookshow.qrc -o qrc_magicbookshow.cpp

compiler_image_collection_make_all: build/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) build/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_maindialog.h build/ui_settingdialog.h build/ui_modelmanagedialog.h build/ui_viewmanagedialog.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_maindialog.h build/ui_settingdialog.h build/ui_modelmanagedialog.h build/ui_viewmanagedialog.h
build/ui_maindialog.h: ui/maindialog.ui
	/usr/bin/uic-qt4 ui/maindialog.ui -o build/ui_maindialog.h

build/ui_settingdialog.h: ui/settingdialog.ui
	/usr/bin/uic-qt4 ui/settingdialog.ui -o build/ui_settingdialog.h

build/ui_modelmanagedialog.h: ui/modelmanagedialog.ui
	/usr/bin/uic-qt4 ui/modelmanagedialog.ui -o build/ui_modelmanagedialog.h

build/ui_viewmanagedialog.h: ui/viewmanagedialog.ui
	/usr/bin/uic-qt4 ui/viewmanagedialog.ui -o build/ui_viewmanagedialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

build/magicbookshow.o: magicbookshow.cpp build/ui_maindialog.h \
		homeview.h \
		homeview/NaviBar.h \
		homeview/QImageButton.h \
		bookscene.h \
		irrAR/irrAR.h \
		irrAR/CGUIProgressBar.h \
		irrAR/CImageGUISkin.h \
		irrAR/SkinLoader.h \
		roomscene.h \
		settingdialog.h \
		build/ui_settingdialog.h \
		modelmanagedialog.h \
		build/ui_modelmanagedialog.h \
		viewmanagedialog.h \
		build/ui_viewmanagedialog.h \
		plotter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/magicbookshow.o magicbookshow.cpp

build/settingdialog.o: settingdialog.cpp settingdialog.h \
		build/ui_settingdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/settingdialog.o settingdialog.cpp

build/plotter.o: plotter.cpp plotter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/plotter.o plotter.cpp

build/SkinLoader.o: irrAR/SkinLoader.cpp irrAR/SkinLoader.h \
		irrAR/CImageGUISkin.h \
		irrAR/CConfigMap.h \
		irrAR/CConfigReader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/SkinLoader.o irrAR/SkinLoader.cpp

build/irrAR.o: irrAR/irrAR.cpp irrAR/irrAR.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/irrAR.o irrAR/irrAR.cpp

build/CImageGUISkin.o: irrAR/CImageGUISkin.cpp irrAR/CImageGUISkin.h \
		irrAR/clipRects.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CImageGUISkin.o irrAR/CImageGUISkin.cpp

build/CGUIProgressBar.o: irrAR/CGUIProgressBar.cpp irrAR/CGUIProgressBar.h \
		irrAR/CImageGUISkin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CGUIProgressBar.o irrAR/CGUIProgressBar.cpp

build/CConfigReader.o: irrAR/CConfigReader.cpp irrAR/CConfigReader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CConfigReader.o irrAR/CConfigReader.cpp

build/CConfigMap.o: irrAR/CConfigMap.cpp irrAR/CConfigMap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CConfigMap.o irrAR/CConfigMap.cpp

build/bookscene.o: bookscene.cpp bookscene.h \
		irrAR/irrAR.h \
		irrAR/CGUIProgressBar.h \
		irrAR/CImageGUISkin.h \
		irrAR/SkinLoader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/bookscene.o bookscene.cpp

build/roomscene.o: roomscene.cpp roomscene.h \
		picwall/Wall/CWallManager.h \
		picwall/CameraAnimator.h \
		picwall/util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/roomscene.o roomscene.cpp

build/util.o: picwall/util.cpp picwall/util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/util.o picwall/util.cpp

build/CameraAnimator.o: picwall/CameraAnimator.cpp picwall/CameraAnimator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CameraAnimator.o picwall/CameraAnimator.cpp

build/CLocalImageSpider.o: picwall/Spider/CLocalImageSpider.cpp picwall/Spider/CLocalImageSpider.h \
		picwall/Wall/IImageItem.h \
		picwall/Spider/IImageSpider.h \
		picwall/Wall/CLocalImageItem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CLocalImageSpider.o picwall/Spider/CLocalImageSpider.cpp

build/CWallManager.o: picwall/Wall/CWallManager.cpp picwall/Wall/CWallManager.h \
		picwall/Wall/IImageItem.h \
		picwall/Spider/IImageSpider.h \
		picwall/Spider/CLocalImageSpider.h \
		picwall/util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CWallManager.o picwall/Wall/CWallManager.cpp

build/CLocalImageItem.o: picwall/Wall/CLocalImageItem.cpp picwall/Wall/CLocalImageItem.h \
		picwall/Wall/IImageItem.h \
		picwall/util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CLocalImageItem.o picwall/Wall/CLocalImageItem.cpp

build/NaviBar.o: homeview/NaviBar.cpp homeview/NaviBar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/NaviBar.o homeview/NaviBar.cpp

build/homeview.o: homeview.cpp homeview.h \
		homeview/NaviBar.h \
		homeview/QImageButton.h \
		bookscene.h \
		irrAR/irrAR.h \
		irrAR/CGUIProgressBar.h \
		irrAR/CImageGUISkin.h \
		irrAR/SkinLoader.h \
		roomscene.h \
		settingdialog.h \
		build/ui_settingdialog.h \
		modelmanagedialog.h \
		build/ui_modelmanagedialog.h \
		viewmanagedialog.h \
		build/ui_viewmanagedialog.h \
		plotter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/homeview.o homeview.cpp

build/QImageButton.o: homeview/QImageButton.cpp homeview/QImageButton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/QImageButton.o homeview/QImageButton.cpp

build/modelmanagedialog.o: modelmanagedialog.cpp modelmanagedialog.h \
		build/ui_modelmanagedialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/modelmanagedialog.o modelmanagedialog.cpp

build/viewmanagedialog.o: viewmanagedialog.cpp viewmanagedialog.h \
		build/ui_viewmanagedialog.h \
		roomscene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/viewmanagedialog.o viewmanagedialog.cpp

build/moc_settingdialog.o: build/moc_settingdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_settingdialog.o build/moc_settingdialog.cpp

build/moc_plotter.o: build/moc_plotter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_plotter.o build/moc_plotter.cpp

build/moc_NaviBar.o: build/moc_NaviBar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_NaviBar.o build/moc_NaviBar.cpp

build/moc_homeview.o: build/moc_homeview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_homeview.o build/moc_homeview.cpp

build/moc_QImageButton.o: build/moc_QImageButton.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_QImageButton.o build/moc_QImageButton.cpp

build/moc_modelmanagedialog.o: build/moc_modelmanagedialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_modelmanagedialog.o build/moc_modelmanagedialog.cpp

build/moc_viewmanagedialog.o: build/moc_viewmanagedialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_viewmanagedialog.o build/moc_viewmanagedialog.cpp

build/qrc_magicbookshow.o: qrc_magicbookshow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_magicbookshow.o qrc_magicbookshow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

