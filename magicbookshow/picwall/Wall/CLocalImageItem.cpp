

#include "CLocalImageItem.h"
#include "../util.h"

using namespace irr;

namespace era
{
namespace wall
{

video::IImage* CLocalImageItem::getImage()
{
	video::IVideoDriver* driver = era::Util::Instance()->GetDriver();
	video::IImage* image = driver->createImageFromFile(file_.c_str());
	
	if (image)
	{
		ratio_ =  ((f32)image->getDimension().Height) / image->getDimension().Width;
		return image;
	}

	return NULL;
}

video::IImage* CLocalImageItem::getThumb()
{
	video::IImage* image = this->getImage();
	
	if (image == NULL)
	{
		return NULL;
	}

	video::IVideoDriver* driver = era::Util::Instance()->GetDriver();
	
    core::dimension2du size;
	if (image->getDimension().Height/300.0 > image->getDimension().Width/400.0)
	{
		size.Height = 270;
        size.Width = (u32) image->getDimension().Width * 270.0f / image->getDimension().Height;
	}
	else
	{
        size.Height = (u32) image->getDimension().Height * 360.0f / image->getDimension().Width;
		size.Width = 360;
	}

	video::IImage* thumb = driver->createImage(video::ECF_A8R8G8B8, size);
	image->copyToScaling(thumb);
    //加边框可能会影响速度，可以直接把图加上边框
    //video::IImage* thumb_with_border = Util::Instance()->FeatherEdge(thumb, 7, video::SColor(0, 0,0,0));
    //thumb->drop();
	image->drop();

    //return thumb_with_border;
    return thumb;
}

} // namespace wall
} // namespace era
