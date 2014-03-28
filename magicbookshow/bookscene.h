#ifndef BOOKSCENE_H
#define BOOKSCENE_H
#include <irrlicht.h>
#include "irrAR/irrAR.h"
#include "irrAR/CGUIProgressBar.h"
#include "irrAR/CImageGUISkin.h"
#include "irrAR/SkinLoader.h"
//XML
#include <QDomDocument>
#include <QDomElement>
#include <QDomAttr>
#include <QFile>
#include <QVector>
#include <QtCore>
#define WIN_WIDTH 640
#define WIN_HEIGHT 480

class Bookscene
{

    class Scenemanager
    {
    public:

        int sceneid;
        char *modelpath;
        char *texturepath;
        char *patpath;
        char *scene1path;
        char *scene2path;
        char *scene3path;
    public:
        Scenemanager()
        {
            modelpath=new char[255];
            texturepath=new char[255];
            patpath = new char[255];
            scene1path=new char[255];
            scene2path=new char[255];
            scene3path=new char[255];
            sceneid=0;

        }
        void setsceneid(int id)
        {
            sceneid=id;
        }

        void setmodelpath(const char *path)
        {
            strcpy(modelpath,path);

        }
        void settexturepath(const char *path)
        {

            strcpy(texturepath,path);
        }
        void setpatpath(const char *path)
        {

            strcpy(patpath,path);
        }
        void setscene1path(const char *path)
        {
            strcpy(scene1path,path);
        }
        void setscene2path(const char *path)
        {
            strcpy(scene2path,path);
        }
        void setscene3path(const char *path)
        {
            strcpy(scene3path,path);
        }
        int getsceneid()
        {
            return sceneid;
        }

        char *getmodelpath()
        {
            return modelpath;
        }
        char *gettexturepath()
        {
            return texturepath;
        }
        char *getpatpath()
        {
            return patpath;
        }
        char *getscene1path()
        {
            return scene1path;
        }
        char *getscene2path()
        {
            return scene2path;
        }
        char *getscene3path()
        {
            return scene3path;
        }

    };
public:
    QVector<Scenemanager> scenemanager;
public:
    Bookscene()
    {
         sceneflag=-1;
    }
IrrlichtDevice *device;
IVideoDriver* driver;
ISceneManager* smgr;
IARManager* armgr;
void show();
int sceneflag;
void close();
void readsceneXML();

};

#endif // BOOKSCENE_H
