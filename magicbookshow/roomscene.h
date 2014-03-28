#ifndef MEMORYSCENE_H
#define MEMORYSCENE_H
#include <irrlicht.h>
#include <QtGui>
using namespace irr;
enum DIRECTION{
    MOVE_X_ADD=1,
    MOVE_X_DEC,
    MOVE_Y_ADD,
    MOVE_Y_DEC,
    MOVE_Z_ADD,
    MOVE_Z_DEC
};
enum SIZE{
    SIZE_LARGE=1,
    SIZE_SMALL
};
enum ROTATION{
    CLOCKWISE=1,
    ANTICLOCKWISE
};
enum SWITCH{
    NEXT=1,
    FORMER
};
class Roomscene
{
    class MemSceneEventReceiver;
    class SelcetEventReceiver;
    class Roomnode
    {
    private:

        int nodeid;
        int nodecnt;
        int nodeprice;
        char *nodepath;
        char *texturepath;
    public:
        Roomnode()
        {
            nodepath=new char[255];
            texturepath=new char[255];
            nodeid=0;
            nodecnt=0;
            nodeprice=0;
        }
        void setnodeid(int id)
        {
            nodeid=id;
        }
        void setnodecnt(int cnt)
        {
            nodecnt=cnt;
        }
        void setnodeprice(int price)
        {
            nodeprice=price;
        }
        void setnodepath(char *path)
        {
            strcpy(nodepath,path);

        }
        void settexturepath(char *path)
        {

            strcpy(texturepath,path);
        }
        int getnodeid()
        {
            return nodeid;
        }
        int getnodecnt()
        {
            return nodecnt;
        }
        int getnodeprice()
        {
            return nodeprice;
        }
        char * getnodepath()
        {
            return nodepath;
        }
        char *gettexturepath()
        {
            return texturepath;
        }

    };
public:
    Roomscene()
    {
        focusnode=0;
        sceneid=0;
        nodeid=0;
        nodecnt=0;
        deletefocusnode=0;
        selectnodeid=0;
        camerarotate=0;
        cameraposition=0;
        camerazrotate=0;

    }
    irr::video::IVideoDriver* driver;
    irr::IrrlichtDevice* memdevice;
    irr::scene::ISceneManager* smgr;
    //irr::scene::IAnimatedMeshSceneNode* focusnode;
    irr::scene::ISceneNode* focusnode;
    irr::scene::ISceneNode* deletefocusnode;
    irr::scene::ISceneNodeAnimator* anim;
    irr::scene::ICameraSceneNode * camera;
    //scene::ICameraSceneNode * camera;
    irr::video::SMaterial material;
    irr::scene::ISceneNode* changedSceneNode;

    //show the scene
    void show(const char *scenepath);
    //close the device
    //jump out the while(device->run()),to Stop the circle
    void close();
    //creat the node
    void creatnode(const char *nodepath=NULL, const char *texturepath=NULL);
    //change the focus node,我diao bao了啊！都开始写英文注释了。。。= =
    void setnode();
    void movenode(DIRECTION direct);
    //to enlarge or ensmall the node
    void sizenode(SIZE size);
    //switch NEXT/FORMER node
    void switchnode(SWITCH switchit);
    //updata_cam_anim to refresh the collision of scene
    void rotatenode(ROTATION rotation);
    void translateNodeLoc(irr::scene::ISceneNode *node, irr::core::vector3df amt);
    void translateCreatLoc(scene::ISceneNode *node, core::vector3df amt);

    void translateCameraLoc(scene::ISceneNode *node, core::vector3df amt);
    //delete the focusenode
    void deletefocusenode();

    void rotatecamera(ROTATION rotation);


    void update_cam_anim();
    void refallnodecollision();
    void refnodecollision();
    void showselect();
    irr::scene::IMetaTriangleSelector *initcamerameta();
    irr::scene::IMetaTriangleSelector *refreshcamerameta();
    irr::scene::IMetaTriangleSelector *refreshnodemeta();
    void initRoomNodes();
    int sceneid;
    int nodeid;
    int nodecnt;
    QVector<Roomnode> roomnodes;
    //换家具的当前nodeid
    int selectnodeid;
    int camerarotate;
    int camerazrotate;
    int cameraposition;

};

#endif // MEMORYSCENE_H
