

#ifndef __UTIL_H_INCLUDED__
#define __UTIL_H_INCLUDED__


#include <irrlicht.h>

namespace era
{
class Util
{

public:
    static Util* Instance()
	{
		if (instance_ == NULL)
		{
			instance_ = new Util();
        }

		return instance_;
	}

    static irr::u32 Now()
	{
        return Util::Instance()->GetDevice()->getTimer()->getTime();
	}

    irr::core::dimension2d<irr::u32> GetScreenSize()
	{
        return irr::core::dimension2d<irr::u32>(1024,768);//::GetSystemMetrics(SM_CXSCREEN), ::GetSystemMetrics(SM_CYSCREEN));
	}
    static void drop()
    {

        delete instance_;

        device_=NULL;

        instance_=NULL;
        //delete instance_;
        //delete this;
    }
    irr::IrrlichtDevice* GetDevice()
	{
		if (device_ == NULL)
		{
            irr::video::E_DRIVER_TYPE driver_type = irr::video::EDT_OPENGL;

            device_=irr::createDevice(driver_type, era::Util::GetScreenSize(), 16, false);

            //device_=device;
            if ( 0 == device_ )
            {
                exit(1);
            }
		}
		return device_;
	}

	irr::video::IVideoDriver* GetDriver()
	{
		if (device_ == NULL)
		{
            Util::Instance()->GetDevice();
		}

		return device_->getVideoDriver();
	}

	irr::gui::IGUIEnvironment* GetGuiEnvironment()
	{
		if (device_ == NULL)
		{
            Util::Instance()->GetDevice();
		}

		return device_->getGUIEnvironment();
	}

	irr::io::IFileSystem* GetFileSystem()
	{
		if (device_ == NULL)
		{
            Util::Instance()->GetDevice();
		}

		return device_->getFileSystem();
	}

	irr::video::IImage* FeatherEdge(irr::video::IImage* image, irr::u32 size, irr::video::SColor base_color = irr::video::SColor(0, 0, 0, 0));

	irr::core::stringc GetRuningPath()
	{

		return running_path_;
	}


	Util()
    {
        GetDevice();
        running_path_ = GetDevice()->getFileSystem()->getWorkingDirectory();
	}

private:
    static Util* instance_;
    static irr::IrrlichtDevice* device_;
    static irr::video::IImage* skin_image_;
	irr::core::stringc running_path_;
};

}


#endif
