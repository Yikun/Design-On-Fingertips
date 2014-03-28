#include "roomscene.h"
#include <irrlicht.h>
#include <QtGui>
//picwall
#include "picwall/Wall/CWallManager.h"
#include "picwall/CameraAnimator.h"
#include "picwall/util.h"
using namespace era;

using namespace irr;
using namespace io;
int test=0;
enum
{
    // I use this ISceneNode ID to indicate a scene node that is
    // not pickable by getSceneNodeAndCollisionPointFromRay()
    ID_IsNotPickable = 0,

    // I use this flag in ISceneNode IDs to indicate that the
    // scene node can be picked by ray selection.
    IDFlag_IsPickable = 1 << 0,

    // I use this flag in ISceneNode IDs to indicate that the
    // scene node can be highlighted.  In this example, the
    // homonids can be highlighted, but the level mesh can't.
    IDFlag_IsChangeable = 1 << 1,

    IDFlag_IsRemoved = 1 << 2


};

class Roomscene::SelcetEventReceiver : public IEventReceiver
{
    bool enterscene;
public:
        virtual bool OnEvent(const SEvent &event)
        {
            if (event.EventType == EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
            {
                switch(event.KeyInput.Key)
                {
                case KEY_ESCAPE:
                    Util::Instance()->GetDevice()->closeDevice();

                    enterscene=false;
                break;
                case KEY_KEY_Y:
                    Util::Instance()->GetDevice()->closeDevice();
                    enterscene=true;
                break;
                }
            }
            return false;
        }
    bool isenterscene()
    {
        return enterscene;
    }
};

class Roomscene::MemSceneEventReceiver : public IEventReceiver
{
public:
    Roomscene *memoryscene;

        virtual bool OnEvent(const SEvent &event)
        {
            if (event.EventType == EET_KEY_INPUT_EVENT )//&& !event.KeyInput.PressedDown
            {
                if(!event.KeyInput.PressedDown)
                {
                switch(event.KeyInput.Key)
                {
                if(!event.KeyInput.PressedDown)
                {
                case KEY_ESCAPE:
                    memoryscene->close();
                    //printf("Press the Esc Key!\n");
                    //closememscene=1;
                break;
                case KEY_KEY_N:
                    memoryscene->creatnode(memoryscene->roomnodes[0].getnodepath(),memoryscene->roomnodes[0].gettexturepath());
                    memoryscene->selectnodeid=1;
                break;
                //change the mov Direction
                case KEY_KEY_Y:
                    memoryscene->setnode();
                    break;
                case KEY_KEY_D:
                    memoryscene->movenode(MOVE_Y_ADD);
                    break;
                case KEY_KEY_A:
                    memoryscene->movenode(MOVE_Y_DEC);
                    break;
                case KEY_KEY_W:
                    memoryscene->movenode(MOVE_X_ADD);
                    break;
                case KEY_KEY_S:
                    memoryscene->movenode(MOVE_X_DEC);
                    break;
                case KEY_KEY_Q:
                    memoryscene->movenode(MOVE_Z_ADD);
                    break;
                case KEY_KEY_Z:
                    memoryscene->movenode(MOVE_Z_DEC);
                    break;
                //change the size
                case KEY_PLUS:
                    memoryscene->sizenode(SIZE_LARGE);
                    break;
                case KEY_MINUS:
                    memoryscene->sizenode(SIZE_SMALL);
                    break;
                //change the Rotation
                case KEY_KEY_X:
                    memoryscene->rotatenode(CLOCKWISE);
                    break;
                case KEY_KEY_C:
                    memoryscene->rotatenode(ANTICLOCKWISE);
                    break;
                case KEY_KEY_E:
                    memoryscene->switchnode(FORMER);
                    break;
                case KEY_KEY_R:
                    memoryscene->switchnode(NEXT);
                    break;
                case KEY_KEY_I:
                        if(memoryscene->cameraposition==2) memoryscene->cameraposition=0;
                        else memoryscene->cameraposition=1;
                        break;
                case KEY_KEY_K:
                        if(memoryscene->cameraposition==1) memoryscene->cameraposition=0;
                        else memoryscene->cameraposition=2;
                        break;

                case KEY_KEY_J:
                    if(memoryscene->camerarotate==2) memoryscene->camerarotate=0;
                    else memoryscene->camerarotate=1;
                    //memoryscene->rotatecamera(ANTICLOCKWISE);
                    break;
                case KEY_KEY_L:
                    if(memoryscene->camerarotate==1) memoryscene->camerarotate=0;
                    else memoryscene->camerarotate=2;
                    break;
                case KEY_KEY_M:
                    if(memoryscene->camerazrotate==4) memoryscene->camerazrotate=0;
                    else memoryscene->camerazrotate=3;
                    //memoryscene->rotatecamera(ANTICLOCKWISE);
                    break;
                case KEY_KEY_U:
                    if(memoryscene->camerazrotate==3) memoryscene->camerazrotate=0;
                    else memoryscene->camerazrotate=4;
                    //memoryscene->rotatecamera(CLOCKWISE);
                    break;
                case KEY_KEY_O:
                    memoryscene->cameraposition=0;
                    memoryscene->camerazrotate=0;
                    memoryscene->camerarotate=0;
                    memoryscene->camera->setPosition(core::vector3df(0.f, -20.f, 100.f));
                    memoryscene->camera->setRotation(core::vector3df(0.f, 180.f, 0.f));
                    //memoryscene->rotatecamera(CLOCKWISE);
                    break;
                }


                    return true;
                }
                }
            }

            return false;
        }
};
//void Roomscene::rotatecamera(ROTATION rotation)
//{

//        switch(rotation)
//        {
//        case ANTICLOCKWISE:
//            camera->setRotation(camera->getRotation()+core::vector3df(0,-1,0));
//            break;
//        case CLOCKWISE:
//            camera->setRotation(camera->getRotation()+core::vector3df(0,1,0));
//            break;
//        }

//}
//void Roomscene::movecamera(DIRECTION direct)
//{

//        switch(direct)
//        {
//        case MOVE_X_ADD:
//            camera->setPosition(camera->getPosition()+core::vector3df(0,0,5);
//            break;
//        case MOVE_X_DEC:
//            camera->setRotation(camera->getRotation()+core::vector3df(0,0,-5));
//            break;
//        }

//}
void Roomscene::deletefocusenode()
{
    if(focusnode)
    {

        deletefocusnode=focusnode;
        deletefocusnode->setID(IDFlag_IsRemoved);
        update_cam_anim();
        refallnodecollision();
        deletefocusnode->remove();
        focusnode=0;
        deletefocusnode=0;

    }
}

void Roomscene::switchnode(SWITCH switchit)
{
    if(focusnode)
    {
        //QTextStream cout(stdout, QIODevice::WriteOnly);
        switch(switchit)
        {
        case NEXT:
            deletefocusenode();
            selectnodeid++;
            if(selectnodeid>roomnodes.size())
                    selectnodeid=1;
            creatnode(roomnodes[selectnodeid-1].getnodepath(),roomnodes[selectnodeid-1].gettexturepath());

        break;
        case FORMER:
            deletefocusenode();
            selectnodeid--;
            if(selectnodeid<1)
                    selectnodeid=roomnodes.size();
            creatnode(roomnodes[selectnodeid-1].getnodepath(),roomnodes[selectnodeid-1].gettexturepath());


            //deletefocusenode();
        break;
        }
    }
}
void Roomscene::rotatenode(ROTATION rotation)
{
    //if fousnode is not null, set the node;otherwise, do nothing
    if(focusnode)
    {
        //focusnode->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
        switch(rotation)
        {
        case CLOCKWISE:

        focusnode->setRotation(focusnode->getRotation()+core::vector3df(0,30,0));
        //refnodecollision();
        break;
        case ANTICLOCKWISE:
        focusnode->setRotation(focusnode->getRotation()+core::vector3df(0,-30,0));
        //refnodecollision();
        break;
        }
    }
}
void Roomscene::sizenode(SIZE size)
{

    //if fousnode is not null, set the node;otherwise, do nothing
    if(focusnode)
    {
        switch(size)
        {
            case SIZE_LARGE:
            //focusnode->getRotation()
            focusnode->setScale(focusnode->getScale()+core::vector3df(1,1,1));
            //refnodecollision();
            //printf("+%f focusnode->getBoundingBox().MaxEdge  =",focusnode->getBoundingBox().MaxEdge);
            break;
            case SIZE_SMALL:
            focusnode->setScale(focusnode->getScale()+core::vector3df(-1,-1,-1));
            //refnodecollision();
            break;
        }
    }

}

void Roomscene::translateNodeLoc(scene::ISceneNode *node, core::vector3df amt)
{

    irr::core::matrix4 m;

    m.setRotationDegrees(camera->getRotation());

    m.transformVect(amt);

    node->setPosition(node->getPosition() + amt);

    //node->updateAbsolutePosition();

}

void Roomscene::translateCameraLoc(scene::ISceneNode *node, core::vector3df amt)
{

    irr::core::matrix4 m;

    m.setRotationDegrees(camera->getRotation());

    m.transformVect(amt);

    node->setPosition(node->getPosition()+core::vector3df(amt.X,0,amt.Z));
    printf("test postion:X:%f Y:%f Z:%f!\n",amt.X,amt.Y,amt.Z);
    //node->updateAbsolutePosition();

}

void Roomscene::translateCreatLoc(scene::ISceneNode *node, core::vector3df amt)
{

    irr::core::matrix4 m;

    m.setRotationDegrees(camera->getRotation());

    m.transformVect(amt);

    node->setPosition(camera->getPosition() + amt);

    //node->updateAbsolutePosition();

}

void Roomscene::movenode(DIRECTION direct)
{
    //if fousnode is not null, move the node;otherwise, do nothing
    if(focusnode)
    {
        //focusnode->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
        switch(direct)
        {
            case MOVE_Z_DEC:
            //focusnode->setPosition(focusnode->getPosition()+core::vector3df(0,-5,0));
            translateNodeLoc(focusnode,core::vector3df(0,-5,0));
            break;
            case MOVE_Z_ADD:
           // focusnode->setPosition(focusnode->getPosition()+core::vector3df(0,5,0));
            translateNodeLoc(focusnode,core::vector3df(0,5,0));
            break;
            case MOVE_Y_ADD:
            //focusnode->setPosition(focusnode->getPosition()+core::vector3df(5,0,0));
            translateNodeLoc(focusnode,core::vector3df(5,0,0));
            //printf("%f %f %f\n",focusnode->getPosition().X,focusnode->getPosition().Y,focusnode->getPosition().Z);
            break;
            case MOVE_Y_DEC:
            //focusnode->setPosition(focusnode->getPosition()+core::vector3df(-5,0,0));
            translateNodeLoc(focusnode,core::vector3df(-5,0,0));
            break;
            case MOVE_X_ADD:
            //focusnode->setPosition(focusnode->getPosition()+core::vector3df(0,0,5));
            translateNodeLoc(focusnode,core::vector3df(0,0,5));
            break;
            case MOVE_X_DEC:
            //focusnode->setPosition(focusnode->getPosition()+core::vector3df(0,0,-5));
            translateNodeLoc(focusnode,core::vector3df(0,0,-5));
            break;
        }
        //refnodecollision();
    }
}
void Roomscene::creatnode(const char *nodepath,const char *texturepath)
{
//if focusnode is null, creat a new node;otherwise, do noting
    if(!focusnode)
    {
        focusnode = 0;
        // Add an MD2 node, which uses vertex-based animation.
//        focusnode = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./box.irrmesh"),
//                            0, 1 | 2);
        if(nodepath)
        {
            //set a custom mesh
            focusnode = smgr->addMeshSceneNode(smgr->getMesh(nodepath),
                                0, IDFlag_IsPickable | IDFlag_IsChangeable);
        }
        else{
            //set a default mesh
            //focusnode = smgr->addMeshSceneNode(smgr->getMesh("./ds_02.tga"),
                           // 0, IDFlag_IsPickable | IDFlag_IsChangeable);
        }
//        focusnode = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/faerie.md2"),
//                           0, IDFlag_IsPickable | IDFlag_IsChangeable);
        //focusnode->setPosition(camera->getPosition()+core::vector3df(20,0,20));
        translateCreatLoc(focusnode,core::vector3df(0,-10,80));
        focusnode->setScale(core::vector3df(20, 20, 20)); // Make it appear realistically scaled
        focusnode->setRotation(focusnode->getRotation()+core::vector3df(0,180,0));
        focusnode->setID(IDFlag_IsPickable|IDFlag_IsChangeable);
        //focusnode->setMD2Animation(scene::EMAT_POINT);
        //focusnode->setAnimationSpeed(20.f);
//        if(texturepath)
//        {
        //material.setTexture(0, driver->getTexture("/home/kero/workspace/magicbookshow/bin/res/model/tietu/wall0.png"));
//        }
//        else{
//        //material.setTexture(0, driver->getTexture("./arch49_leather_bump.jpg"));
//        }
        material.Lighting = true;
        material.NormalizeNormals = true;
//        material.Wireframe=true;
        //focusnode->getMaterial(0) = material;

        focusnode->setMaterialFlag(video::EMF_LIGHTING,false);
        focusnode->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);//_ADD_COLOR
        //focusnode->setDebugDataVisible(true);
        refnodecollision();

    }



}

void Roomscene::refallnodecollision()
{
    core::array<scene::ISceneNode *> nodes;
    smgr->getSceneNodesFromType(scene::ESNT_ANY, nodes); // Find all nodes

    for (u32 i=0; i < nodes.size(); ++i)
    {

        scene::ISceneNode * nodetmp = nodes[i];
        if(nodetmp->getID()==(IDFlag_IsPickable | IDFlag_IsChangeable))
        {
            //printf("name :%s id: %d \n",nodetmp->getName(),nodetmp->getID());
            focusnode=nodetmp;
            refnodecollision();
        }

    }
    //update_cam_anim();
}
void Roomscene::refnodecollision()
{

        const core::aabbox3d<f32>& box = focusnode->getTransformedBoundingBox();//getBoundingBox();//
        //core::vector3df radius = box.MaxEdge - box.getCenter();
        irr::scene::ISceneNodeAnimator* focusanim;
        irr::scene::IMetaTriangleSelector *meta = refreshnodemeta();
        focusanim = smgr->createCollisionResponseAnimator(
                    meta,
                    focusnode,
                    box.MaxEdge - box.getCenter(),
                    core::vector3df(0,0.0f,0)
                    );
        //meta->drop(); // I'm done with the meta selector now
        if(deletefocusnode)
            meta->removeTriangleSelector(deletefocusnode->getTriangleSelector());
        focusnode->removeAnimators();
        focusnode->addAnimator(focusanim);


}
irr::scene::IMetaTriangleSelector *Roomscene::refreshnodemeta()
{
    irr::scene::IMetaTriangleSelector * meta=smgr->createMetaTriangleSelector();
    core::array<scene::ISceneNode *> nodes;
    smgr->getSceneNodesFromType(scene::ESNT_ANY, nodes); // Find all nodes
    for (u32 i=0; i < nodes.size(); ++i)
    {
        scene::ISceneNode * currentnode = nodes[i];
        scene::ITriangleSelector * selector = 0;
        //currentnode->setID(currentnode->getID()|(IDFlag_IsPickable));
        if(currentnode->getName()!=focusnode->getName())//&&currentnode->getName()!=bill->getName()
        {

            switch(currentnode->getType())
            {
            case scene::ESNT_CUBE:
            case scene::ESNT_ANIMATED_MESH:
                selector = smgr->createTriangleSelectorFromBoundingBox(currentnode);

            break;

            case scene::ESNT_MESH:
            case scene::ESNT_SPHERE: // Derived from IMeshSceneNode
                selector = smgr->createTriangleSelector(((scene::IMeshSceneNode*)currentnode)->getMesh(), currentnode);
                break;

            case scene::ESNT_TERRAIN:
                selector = smgr->createTerrainTriangleSelector((scene::ITerrainSceneNode*)currentnode);
                break;

            case scene::ESNT_OCTREE:
                selector = smgr->createOctreeTriangleSelector(((scene::IMeshSceneNode*)currentnode)->getMesh(), currentnode);
                break;

            default:
                // Don't create a selector for this node type
                break;
            }

            if(selector)
            {
                currentnode->setTriangleSelector(selector);
                // Add it to the meta selector, which will take a reference to it
                meta->addTriangleSelector(selector);
                // And drop my reference to it, so that the meta selector owns it.
                selector->drop();
            }

        }else
        {
            //printf("camera node!");
        }
    }
    return meta;
}

void Roomscene::setnode()
{

    if(focusnode){

        const core::aabbox3d<f32>& box = focusnode->getTransformedBoundingBox();
        irr::scene::ISceneNodeAnimator* focusanim;
        irr::scene::IMetaTriangleSelector *meta = refreshnodemeta();
        focusanim = smgr->createCollisionResponseAnimator(
                    meta,
                    focusnode,
                    box.MaxEdge - box.getCenter(),
                    core::vector3df(0,-10.0f,0)
                    );

        focusnode->removeAnimators();
        focusnode->addAnimator(focusanim);
        focusnode->setMaterialType(video::EMT_LIGHTMAP_LIGHTING);

        update_cam_anim();

        focusnode=0;
        selectnodeid=0;

   }
}

//update the camera, to add the new node's collision
void Roomscene::update_cam_anim()
{
    camera->removeAnimator(anim);
    anim=0;
    irr::scene::IMetaTriangleSelector * meta=refreshcamerameta();
    if(deletefocusnode)
        meta->removeTriangleSelector(deletefocusnode->getTriangleSelector());
    anim = smgr->createCollisionResponseAnimator(
        meta, camera, core::vector3df(5,5,5),
        core::vector3df(0,0,0));
    camera->addAnimator(anim);
}
void Roomscene::close()
{
    memdevice->closeDevice();
}
void Roomscene::showselect()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QTime timer;

    timer.start();
    cout<<"------1-------"<<endl;
    cout<<timer.elapsed()<<endl;
    cout<<"------1-------">>endl;
    SelcetEventReceiver selectrecevier;
    IrrlichtDevice* walldevice =Util::Instance()->GetDevice();

    if ( 0 == walldevice )
    {
        exit(1);
    }
    walldevice->setEventReceiver(&selectrecevier);
    ///home/kero/workspace/magicbookshow/bin/res
    //walldevice->getFileSystem()->changeWorkingDirectoryTo("./res");
    video::IVideoDriver* walldriver = walldevice->getVideoDriver();
    scene::ISceneManager* scene_mgr = walldevice->getSceneManager();

    //载入画面，可以避免黑屏时间
    walldriver->beginScene(true, true, video::SColor(255,0,0,0));
    walldevice->getGUIEnvironment()->addImage(
                walldriver->getTexture("./irrui/load3.png"),
                                          core::position2d<s32>(0,0));
    walldevice->getGUIEnvironment()->drawAll();
    walldriver->endScene();

    wall::CWallManager* wall_mgr = new wall::CWallManager();
    wall_mgr->CreateLocalImageSpider("./res");
    wall_mgr->UpdateScene();

    scene::ICameraSceneNode* wallcamera = scene_mgr->addCameraSceneNode(0, core::vector3df(0,0,-700), core::vector3df(0,0,0), 0);
    scene::CameraAnimator* wallanimator = new scene::CameraAnimator(wall_mgr->GetWallItemList(), walldevice, scene_mgr, walldevice->getTimer()->getTime());
    wallcamera->addAnimator(wallanimator);


    while (walldevice->run())
    {
        //if (walldevice->isWindowActive())
        //{
            walldriver->beginScene(true, true, video::SColor(0, 255, 255, 255));
            scene_mgr->drawAll();
            walldriver->endScene();
        //}
    }
    //walldevice->closeDevice();
    if(selectrecevier.isenterscene())
    {
        sceneid=wallanimator->getcurrentnodeid();
    }
    else
        sceneid=0;
    //wall_mgr->~CWallManager();
    cout<<"------2-------"<<endl;
    cout<<timer.elapsed()<<endl;
    cout<<"------2-------">>endl;
    walldevice->getFileSystem()->changeWorkingDirectoryTo("../");
    //walldevice->drop();
    Util::Instance()->drop();


}
irr::scene::IMetaTriangleSelector *Roomscene::refreshcamerameta()
{
    irr::scene::IMetaTriangleSelector * meta=smgr->createMetaTriangleSelector();
    core::array<scene::ISceneNode *> nodes;
    smgr->getSceneNodesFromType(scene::ESNT_ANY, nodes); // Find all nodes
    for (u32 i=0; i < nodes.size(); ++i)
    {
        scene::ISceneNode * currentnode = nodes[i];
        scene::ITriangleSelector * selector = 0;
        //currentnode->setID(IDFlag_IsPickable);
        if(currentnode->getName()!=camera->getName())//&&currentnode->getName()!=bill->getName()
        {

            switch(currentnode->getType())
            {
            case scene::ESNT_CUBE:
            case scene::ESNT_ANIMATED_MESH:
                selector = smgr->createTriangleSelectorFromBoundingBox(currentnode);

            break;

            case scene::ESNT_MESH:
            case scene::ESNT_SPHERE: // Derived from IMeshSceneNode
                selector = smgr->createTriangleSelector(((scene::IMeshSceneNode*)currentnode)->getMesh(), currentnode);
                break;

            case scene::ESNT_TERRAIN:
                selector = smgr->createTerrainTriangleSelector((scene::ITerrainSceneNode*)currentnode);
                break;

            case scene::ESNT_OCTREE:
                selector = smgr->createOctreeTriangleSelector(((scene::IMeshSceneNode*)currentnode)->getMesh(), currentnode);
                break;

            default:
                // Don't create a selector for this node type
                break;
            }

            if(selector)
            {
                currentnode->setTriangleSelector(selector);
                // Add it to the meta selector, which will take a reference to it
                meta->addTriangleSelector(selector);
                // And drop my reference to it, so that the meta selector owns it.
                selector->drop();
            }

        }else
        {
            printf("camera node!");
        }
    }
    return meta;
}
irr::scene::IMetaTriangleSelector *Roomscene::initcamerameta()
{
    irr::scene::IMetaTriangleSelector * meta=smgr->createMetaTriangleSelector();
    core::array<scene::ISceneNode *> nodes;
    smgr->getSceneNodesFromType(scene::ESNT_ANY, nodes); // Find all nodes
    for (u32 i=0; i < nodes.size(); ++i)
    {
        scene::ISceneNode * currentnode = nodes[i];
        scene::ITriangleSelector * selector = 0;
        currentnode->setID(IDFlag_IsPickable);
        if(currentnode->getName()!=camera->getName())//&&currentnode->getName()!=bill->getName()
        {

            switch(currentnode->getType())
            {
            case scene::ESNT_CUBE:
            case scene::ESNT_ANIMATED_MESH:
                selector = smgr->createTriangleSelectorFromBoundingBox(currentnode);

            break;

            case scene::ESNT_MESH:
            case scene::ESNT_SPHERE: // Derived from IMeshSceneNode
                selector = smgr->createTriangleSelector(((scene::IMeshSceneNode*)currentnode)->getMesh(), currentnode);
                break;

            case scene::ESNT_TERRAIN:
                selector = smgr->createTerrainTriangleSelector((scene::ITerrainSceneNode*)currentnode);
                break;

            case scene::ESNT_OCTREE:
                selector = smgr->createOctreeTriangleSelector(((scene::IMeshSceneNode*)currentnode)->getMesh(), currentnode);
                break;

            default:
                // Don't create a selector for this node type
                break;
            }

            if(selector)
            {
                currentnode->setTriangleSelector(selector);
                // Add it to the meta selector, which will take a reference to it
                meta->addTriangleSelector(selector);
                // And drop my reference to it, so that the meta selector owns it.
                selector->drop();
            }

        }else
        {
            printf("camera node!");
        }
    }
    return meta;
}
void Roomscene::initRoomNodes()
{
    //save the roomnodes info
    //QVector<Roomnode> roomnodes;
    QTextStream cout(stdout, QIODevice::WriteOnly);
    IrrXMLReader* xml = createIrrXMLReader("conf.xml");
    while(xml && xml->read())
    {
       switch(xml->getNodeType())
       {
          case EXN_ELEMENT:
          {
             // Get data from file

             //cout<<xml->getNodeName()<<endl;
             if (!strcmp("model", xml->getNodeName()))
             {
                //cout<<"------------------"<<endl;
                roomnodes.append(Roomnode());
                roomnodes[roomnodes.size()-1].setnodeid(xml->getAttributeValueAsInt("id"));
                roomnodes[roomnodes.size()-1].setnodeprice(xml->getAttributeValueAsInt("price"));
                roomnodes[roomnodes.size()-1].setnodepath((char *)(xml->getAttributeValue("mesh")));
                roomnodes[roomnodes.size()-1].settexturepath((char *)(xml->getAttributeValue("texture")));
                //cout<<"id:"<<roomnodes[roomnodes.size()-1].getnodeid();
                //cout<<"   "<<"cnt:"<<roomnodes[roomnodes.size()-1].getnodecnt();
                //cout<<"   "<<"price:"<<roomnodes[roomnodes.size()-1].getnodeprice();
                //cout<<"   "<<"nodepath:"<<roomnodes[roomnodes.size()-1].getnodepath()<<endl;
                //cout<<"   "<<"texturepath:"<<roomnodes[roomnodes.size()-1].gettexturepath()<<endl;
             }

          }
          break;
       }
    }
    delete xml;
    cout<<roomnodes[0].getnodepath()<<endl;
    cout<<roomnodes[1].getnodepath()<<endl;

    cout<<roomnodes[0].gettexturepath()<<endl;
    cout<<roomnodes[1].gettexturepath()<<endl;

    cout<<roomnodes[0].getnodeid()<<endl;
    cout<<roomnodes[1].getnodeid()<<endl;

}
void Roomscene::show(const char * scenepath)
{

    MemSceneEventReceiver recevier;
    memdevice =createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1024, 768),16,false,false,false,&recevier);
    if (memdevice == 0)
        exit (1); // could not create selected driver.

    recevier.memoryscene=this;
    //memdevice->setWindowCaption("Load .irr file example");
    //..res/model /home/kero/workspace/magicbookshow/bin/res/model
    memdevice->getFileSystem()->changeWorkingDirectoryTo("./res/model");
    //
    initRoomNodes();
    driver = memdevice->getVideoDriver();
    smgr = memdevice->getSceneManager();

    //载入画面，可以避免黑屏时间
    driver->beginScene(true, true, video::SColor(255,0,0,0));
    memdevice->getGUIEnvironment()->addImage(
                driver->getTexture("../../irrui/load1.png"),
                                          core::position2d<s32>(0,0));
    memdevice->getGUIEnvironment()->drawAll();
    driver->endScene();

    // load the scene
    if (scenepath)
        smgr->loadScene(scenepath);
    else
        smgr->loadScene("");

    camera = smgr->addCameraSceneNodeFPS(0, 50.f, 0.1f,ID_IsNotPickable, 0, 0, true, 3.f);//, 0, 0, true, 3.f);
    camera->setName("camera");
    irr::scene::IMetaTriangleSelector * meta = initcamerameta();

    anim = smgr->createCollisionResponseAnimator(
        meta, camera, core::vector3df(3,3,3),
        core::vector3df(0,0,0));
    //meta->drop(); // I'm done with the meta selector now

    camera->addAnimator(anim);
    //anim->drop(); // I'm done with the animator now


    // Point the camera at the cube node, by finding the first node of type ESNT_CUBE
    scene::ISceneNode * cube = smgr->getSceneNodeFromType(scene::ESNT_CUBE);
    if(cube)
        camera->setTarget(cube->getAbsolutePosition());
    // And set the camera position so that it doesn't start off stuck in the geometry
    camera->setPosition(core::vector3df(0.f, -20.f, 100.f));
    camera->setRotation(core::vector3df(0.f, 180.f, 0.f));
    //bill-----------------------------
    memdevice->getCursorControl()->setVisible(false);

    // Add the billboard.
    scene::IBillboardSceneNode * bill = smgr->addBillboardSceneNode();
    bill->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
    bill->setMaterialTexture(0, driver->getTexture("media/particle.bmp"));
    bill->setMaterialFlag(video::EMF_LIGHTING, false);
    bill->setMaterialFlag(video::EMF_ZBUFFER, false);
    bill->setSize(core::dimension2d<f32>(5.0f, 5.0f));
    bill->setID(ID_IsNotPickable); // This ensures that we don't accidentally ray-pick it
    //bill-----------------------------

    /*
    That's it. Draw everything and finish as usual.
    */


    //灯光
//    scene::ILightSceneNode * light = smgr->addLightSceneNode(0, core::vector3df(-60,100,400),
//            video::SColorf(1.0f,1.0f,1.0f,1.0f), 600.0f);
//    light->setID(0);

  // Remember which scene node is changed
    scene::ISceneNode* changedSceneNode = 0;
    scene::ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();
    int lastFPS = -1;
    memdevice->getGUIEnvironment()->clear();
    while(memdevice->run())
    if (memdevice->isWindowActive())
    {
        driver->beginScene(true, true, 0);//video::SColor(0,200,200,200)
        smgr->drawAll();
        // Unlight any currently highlighted scene node

//        if ((changedSceneNode)&&deletefocusnode)//&&focusnode&&focusnode&&(focusnode->getID()!=IDFlag_IsRemoved)
//        {
//            //highlightedSceneNode->setMaterialFlag(video::EMF_LIGHTING, true);

//            changedSceneNode->setMaterialType(video::EMT_SOLID);
//            changedSceneNode = 0;
//        }


        core::line3d<f32> ray;
        ray.start = camera->getPosition();
        ray.end = ray.start + (camera->getTarget() - ray.start).normalize() * 1000.0f;

        // Tracks the current intersection point with the level or a mesh
        core::vector3df intersection;
        // Used to show with triangle has been hit
        core::triangle3df hitTriangle;


        scene::ISceneNode * selectedSceneNode =
            collMan->getSceneNodeAndCollisionPointFromRay(
                    ray,
                    intersection, // This will be the position of the collision
                    hitTriangle, // This will be the triangle hit in the collision
                    IDFlag_IsPickable, // This ensures that only nodes that we have
                            // set up to be pickable are considered
                    0); // Check the entire scene (this is actually the implicit default)


        if(selectedSceneNode)
        {
            bill->setPosition(intersection);

            // We need to reset the transform before doing our own rendering.
            //driver->setTransform(video::ETS_WORLD, core::matrix4());
            //driver->setMaterial(material);
            //driver->draw3DTriangle(hitTriangle, video::SColor(255,255,0,0));

            // We can check the flags for the scene node that was hit to see if it should be
            // highlighted. The animated nodes can be highlighted, but not the Quake level mesh
            if((selectedSceneNode->getID() & (IDFlag_IsChangeable)) == (IDFlag_IsChangeable))
            {
                changedSceneNode = selectedSceneNode;

                // Highlighting in this case means turning lighting OFF for this node,
                // which means that it will be drawn with full brightness.
                // changedSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);
                changedSceneNode->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
                if((changedSceneNode->getID())==(IDFlag_IsChangeable|IDFlag_IsPickable)&&(focusnode!=changedSceneNode))//
                {
                    if(focusnode)
                    {
                        focusnode->setMaterialType(video::EMT_LIGHTMAP_LIGHTING);
                    }
                    focusnode=changedSceneNode;
                    changedSceneNode=0;

                }
            }
        }

        driver->endScene();

        int fps = driver->getFPS();

        if (lastFPS != fps)
        {

            core::stringw str = L"Load Irrlicht File example - Irrlicht Engine [";
            str += driver->getName();
            str += "] FPS:";
            str += fps;
            printf("%d %d\n",fps,driver->getPrimitiveCountDrawn());
            //memdevice->setWindowCaption(str.c_str());
            lastFPS = fps;
        }

            if(camerarotate==1)
                camera->setRotation(camera->getRotation()+core::vector3df(0,900*-0.01/lastFPS,0));
            else if(camerarotate==2)
                camera->setRotation(camera->getRotation()+core::vector3df(0,900*0.01/lastFPS,0));

            if(camerazrotate==3)
                camera->setRotation(camera->getRotation()+core::vector3df(900*0.01/lastFPS,0,0));
            else if(camerazrotate==4)
                camera->setRotation(camera->getRotation()+core::vector3df(900*-0.01/lastFPS,0,0));

            if(cameraposition==1)
                translateCameraLoc(camera,core::vector3df(0,0,900*0.015/lastFPS));
            else if(cameraposition==2)
                translateCameraLoc(camera,core::vector3df(0,0,900*-0.015/lastFPS));


    }
    smgr->saveScene("test.irr");
    //memdevice->closeDevice();
    //closememscene=0;
    //driver->drop();
    memdevice->getFileSystem()->changeWorkingDirectoryTo("../../");
    memdevice->drop();

    //Util::dropInstance();


}
