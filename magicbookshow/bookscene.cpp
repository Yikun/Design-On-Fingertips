#include"bookscene.h"
using namespace irr;
//int closebookscene=0;
class BookEventReceiver : public IEventReceiver
{

    public:
        Bookscene *bookscene;
        virtual bool OnEvent(const SEvent &event)
        {
            if (event.EventType == EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
            {
                switch(event.KeyInput.Key)
                {
                    case KEY_ESCAPE:
                        //device->closeDevice();
                        //device->drop();
                        //closebookscene=1;
                        bookscene->close();
                        return true;
                }
            }
            if (event.EventType == EET_GUI_EVENT)
                   {
                       s32 id = event.GUIEvent.Caller->getID();
                       switch(event.GUIEvent.EventType)
                       {
                       //当响应类型为按钮点击时
                       case EGET_BUTTON_CLICKED:
                                   switch(id)
                                   {
                                    //More
                                    case 1000:
                                       bookscene->close();
                                       printf("press 1000 button\n");
                                       break;
                                    //Setting
                                    case 1001:

                                       printf("press 1001 button\n");
                                       break;
                                   }
                             break;
                       }
                    }
            return false;
        }
};

void Bookscene::close()
{
    device->closeDevice();
}

void Bookscene::show()
{
    readsceneXML();
    bool fullscreen = false;
    BookEventReceiver receiver;
    receiver.bookscene=this;
    device = createDevice( video::EDT_OPENGL, dimension2d<u32>(WIN_WIDTH, WIN_HEIGHT), 16, fullscreen, false, false, &receiver);
    driver = device->getVideoDriver();

    smgr = device->getSceneManager();

    //载入画面，可以避免黑屏时间
    driver->beginScene(true, true, SColor(255,255,255,255));
    device->getGUIEnvironment()->addImage(
                driver->getTexture("irrui/load2.png"),
                                          core::position2d<s32>(0,0));
    device->getGUIEnvironment()->drawAll();
    driver->endScene();

    io::IFileSystem* filesys = device->getFileSystem();
    //gui
    gui::IGUIEnvironment* env = device->getGUIEnvironment();
    gui::SImageGUISkinConfig guicfg = LoadGUISkinFromFile(filesys, driver, "irrui/guiskin.cfg");
       gui::CImageGUISkin* skin = new gui::CImageGUISkin(driver, env->getSkin());
       skin->loadConfig(guicfg);

       gui::IGUIFont* font = env->getFont("irrui/fontlucida.png");

       if (font != 0)
       {
           skin->setFont(font, gui::EGDF_DEFAULT);
           skin->setFont(font, gui::EGDF_WINDOW);
       }

       s32 j = 0;
       video::SColor newCol = video::SColor();
       video::SColor oldCol = newCol;

       for(j = 0; j < gui::EGDC_COUNT; ++j)
       {
           oldCol = skin->getColor((gui::EGUI_DEFAULT_COLOR)j);

           newCol = oldCol;
           newCol.setAlpha(255);

           skin->setColor((gui::EGUI_DEFAULT_COLOR)j, newCol);
       }

       skin->setColor(gui::EGDC_ACTIVE_CAPTION, video::SColor(255,255,255,255));
       skin->setColor(gui::EGDC_BUTTON_TEXT, video::SColor(255,255,255,255));
       skin->setColor(gui::EGDC_HIGH_LIGHT_TEXT, video::SColor(255,255,255,255));
       skin->setColor(gui::EGDC_GRAY_TEXT, video::SColor(150,255,255,255));
       skin->setColor(gui::EGDC_INACTIVE_CAPTION, video::SColor(150,255,255,255));

       skin->setSize(gui::EGDS_WINDOW_BUTTON_WIDTH, 22);
       skin->setSize(gui::EGDS_TITLEBARTEXT_DISTANCE_X, 2);
       skin->setSize(gui::EGDS_TITLEBARTEXT_DISTANCE_Y, 9);

       env->setSkin(skin);

       skin->drop();

       //env->addImage(driver->getTexture("ui/bg.jpg"), core::vector2di(0,0));
       //左上，右上，左下，右下
       gui::IGUIWindow* win = env->addWindow(core::rect<s32>(50,10,200,600), true, L"Magic Book GUI");
       //四个参数分别为左上，右上，左下，右下
       env->addButton( core::rect<s32>(20,110,130,230), win, 1000, L"More Scene" );
       env->addButton( core::rect<s32>(20,310,130,430), win, 1001, L"Settings" );

       //env->addCheckBox(false, core::rect<s32>(40,50,250,70), win , -1, L"Item 1");
       //env->addCheckBox(false, core::rect<s32>(40,80,250,100), win , -1, L"Item 2");
       //env->addCheckBox(false, core::rect<s32>(40,110,250,130), win , -1, L"Item 3");
       //env->addEditBox(L"This is an editbox OH YEA!", core::rect<s32>(40,160,250,190), true, win );

    //window
    //device->setWindowCaption(L"Book Scene");

    //camera stuff
    vector3df camera_pos = vector3df(0,0,0);
    vector3df camera_target = vector3df(0,0,1);
    ICameraSceneNode* camera = smgr->addCameraSceneNode(0, camera_pos, camera_target);

    //AR stuff
    IARManager* armgr = new IARManager(device);
    //init the camera
    armgr->beginCamera("Data/camera_para.dat","Data/WDM_camera_flipV.xml", "-width=640 -height=480 -palette=YUYV -mode=PAL -dev=/dev/video0");//-width=720 -height=288 -palette=YUYV UYVY -mode=PAL -dev=/dev/video0
    //-palette=YUYV
    //something for 3d reference
    ISceneNode* firstnode;

    firstnode = smgr->addMeshSceneNode(smgr->getMesh("./res/model/fw.3DS"));//scenemanager[0].getmodelpath()
    if (firstnode)
    {
        //firstnode->setMaterialTexture( 0, driver->getTexture(scenemanager[i].gettexturepath()) );
        firstnode->setMaterialFlag(EMF_LIGHTING, false);
        firstnode->setPosition(vector3df(0,0,0));//,,前后
        firstnode->setRotation(vector3df(0,180,0));
        firstnode->setScale(vector3df(15,15,15));
    }
    armgr->addARSceneNode("Data/patt.a", firstnode);

    ISceneNode* nextnode;

    nextnode = smgr->addMeshSceneNode(smgr->getMesh("./res/model/House.3DS"));//scenemanager[0].getmodelpath()
    if (nextnode)
    {
        //firstnode->setMaterialTexture( 0, driver->getTexture(scenemanager[i].gettexturepath()) );
        nextnode->setMaterialFlag(EMF_LIGHTING, false);
        nextnode->setPosition(vector3df(0,0,0));//,,前后
        nextnode->setScale(vector3df(0.15,0.15,0.15));
    }
    armgr->addARSceneNode("Data/patt.b", nextnode);

    /*
    firstnode = smgr->addMeshSceneNode(smgr->getMesh(scenemanager[2].getmodelpath()));//scenemanager[0].getmodelpath()
    if (firstnode)
    {
        firstnode->setMaterialTexture( 0, driver->getTexture(scenemanager[2].gettexturepath()) );
        firstnode->setMaterialFlag(EMF_LIGHTING, false);
        firstnode->setPosition(vector3df(0,50,0));
        firstnode->setScale(vector3df(2,2,2));
    }
    armgr->addARSceneNode("Data/patt.two", firstnode);//scenemanager[0].getpatpath()
    //}*/
//    firstnode = smgr->addMeshSceneNode(smgr->getMesh("./res/model/media/dwarf.x"));
//        if (firstnode)
//        {
//            //firstnode->setMaterialTexture( 0, driver->getTexture("./res/model/media/dwarf.x") );
//            firstnode->setMaterialFlag(EMF_LIGHTING, false);
//            firstnode->setPosition(vector3df(0,50,0));
//            firstnode->setScale(vector3df(2,2,2));
//        }
//    armgr->addARSceneNode("Data/patt.a", firstnode);
    //fairy
//    IAnimatedMeshSceneNode* secondnode = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./res/model/media/faerie.md2"));
//    if (secondnode)
//    {
//        secondnode->setMaterialTexture(0, driver->getTexture("./res/model/media/faerie2.bmp"));
//        secondnode->setMaterialFlag(video::EMF_LIGHTING, false);
//        secondnode->setMD2Animation(scene::EMAT_POINT);
//        secondnode->setScale(vector3df(2,2,2));
//        secondnode->setPosition(vector3df(0,45,0));
//        secondnode->setRotation(vector3df(0,180,0));
//    }

    //dwarf
//    IAnimatedMeshSceneNode* thirdnode = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./res/model/media/dwarf.x"));
//    if (secondnode)
//    {
//        thirdnode->setRotation(vector3df(0,180,0));
//        thirdnode->setMaterialFlag(video::EMF_LIGHTING, false);
//        thirdnode->setAnimationSpeed(15);
//    }
//    //water
//    IAnimatedMesh* mesh = smgr->addHillPlaneMesh("myHill", dimension2d<f32>(80,80), dimension2d<u32>(3,2), 0, 0, dimension2d<f32>(0,0), dimension2d<f32>(10,10));
//    ISceneNode* water = smgr->addWaterSurfaceSceneNode(mesh->getMesh(0), 3.0f, 300.0f, 30.0f);
//    water->setMaterialTexture(0, driver->getTexture("./res/media/stones.jpg"));
//    water->setMaterialTexture(1, driver->getTexture("./res/media/water.jpg"));
//    water->setMaterialType(video::EMT_REFLECTION_2_LAYER);
//    water->setMaterialFlag(video::EMF_LIGHTING, false);
//    water->setPosition(vector3df(100,0,-50));
//    water->setParent(thirdnode);




    //node for the lady, attached the the hiro pattern
    //armgr->addARSceneNode("Data/patt.one", firstnode);
    //node for the fairy and water, attached the the sample1 pattern
    //armgr->addARSceneNode("Data/patt.two", secondnode);
    //armgr->addARSceneNode("Data/patt.three",thirdnode);

    //node for the dwarf, attached to a multi-pattern
    //armgr->addARMultiSceneNode("Data/multi/marker.dat", dwarf);
    //now fix our camera to display right
    armgr->fixCamera(camera);


    //while(device->run()&&!closebookscene)
    device->getGUIEnvironment()->clear();
    while(device->run())
    {
        if (device->isWindowActive())
        {

        driver->beginScene(true, true, SColor(255,100,101,140));
       //输出场景面数
       //printf("Prim----:%d\n",driver->getPrimitiveCountDrawn());

        //make movements and bring in new image
        armgr->run();

        //draw the background image centered and scaled
        armgr->drawBackground();
        if(armgr->get_visible_id()!=-1)
        {
            printf("------------%d\n",armgr->get_visible_id());
            this->sceneflag=armgr->get_visible_id();
        }
        smgr->drawAll();

        //env draw should after the armgr.ensure the env above of background
        env->drawAll();

        driver->endScene();
        /*
        //FPS Display
          int fps = driver->getFPS();
          int lastFPS = -1;
          if (lastFPS != fps)
          {
             core::stringw str = L"Irrlicht Engine [";
             str += driver->getName();
             str += "] FPS:";
             str += fps;

             device->setWindowCaption(str.c_str());
             lastFPS = fps;
          }
        */


    }

    }
    //关闭AR的设备
    armgr->~IARManager();
    device->closeDevice();
    //closebookscene=0;
    device->drop();
}

void Bookscene::readsceneXML()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    IrrXMLReader* xml = createIrrXMLReader("./res/model/sceneconf.xml");
    while(xml && xml->read())
    {
       switch(xml->getNodeType())
       {
          case EXN_ELEMENT:
          {
             // Get data from file

             //cout<<xml->getNodeName()<<endl;
             if (!strcmp("scene", xml->getNodeName()))
             {
                //cout<<"------------------"<<endl;
                scenemanager.append(Scenemanager());
                scenemanager[scenemanager.size()-1].setsceneid(xml->getAttributeValueAsInt("id"));
                scenemanager[scenemanager.size()-1].setpatpath((char *)(xml->getAttributeValue("pat")));
                scenemanager[scenemanager.size()-1].setmodelpath((char *)(xml->getAttributeValue("scenemodel")));
                scenemanager[scenemanager.size()-1].settexturepath((char *)(xml->getAttributeValue("scenetexture")));
                scenemanager[scenemanager.size()-1].setscene1path((char *)(xml->getAttributeValue("scene1")));
                scenemanager[scenemanager.size()-1].setscene2path((char *)(xml->getAttributeValue("scene2")));
                scenemanager[scenemanager.size()-1].setscene3path((char *)(xml->getAttributeValue("scene3")));
                //cout<<"id:"<<scenemanager[roomnodes.size()-1].getnodeid();
                cout<<"   "<<"getsceneid:"<<scenemanager[scenemanager.size()-1].getsceneid();
                cout<<"   "<<"getpatpath:"<<scenemanager[scenemanager.size()-1].getpatpath();
                cout<<"   "<<"getmodelpath:"<<scenemanager[scenemanager.size()-1].getmodelpath()<<endl;
                cout<<"   "<<"gettexturepath:"<<scenemanager[scenemanager.size()-1].gettexturepath()<<endl;
             }

          }
          break;
       }
    }
    delete xml;
}
