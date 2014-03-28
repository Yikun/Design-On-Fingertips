/** 
* @file util.cpp
* @brief Util function
* @author Yuan Lichuan
* @version 1.0
* @date 2009-2010
*/

#include "util.h"

#include <valarray>

using namespace irr;

namespace era
{

Util* Util::instance_ = NULL;
video::IImage* Util::skin_image_ = NULL;
IrrlichtDevice* Util::device_ = NULL;


video::IImage* Util::FeatherEdge(video::IImage* image, u32 size, video::SColor base_color)
{
	video::IVideoDriver* driver = Util::GetDriver();

	video::IImage* feather_edged_image = driver->createImage(video::ECF_A8R8G8B8, image->getDimension() + core::dimension2du(size*2, size*2));
	
	video::SColor alpha_color = base_color;
	//U D 
	for (int i=size; i<size+image->getDimension().Width; i++)
	{
		for (int j=0; j<size; j++)
		{
			alpha_color.setAlpha(j*200/size);
			feather_edged_image->setPixel(i, j, alpha_color);
			feather_edged_image->setPixel(i, image->getDimension().Height+2*size-j-1, alpha_color);
		}
	}
	//L R
	for (int i=size; i<size+image->getDimension().Height; i++)
	{
		for (int j=0; j<size; j++)
		{
			alpha_color.setAlpha(j*200/size);
			feather_edged_image->setPixel(j, i, alpha_color);
			feather_edged_image->setPixel(image->getDimension().Width+2*size-j-1, i, alpha_color);
		}
	}

	//sijiao
	f32 R = 1.1*size;
	for (int i=0; i< (int)R; i++)
	{
		for (int j=0; j< (int)R; j++)
		{
			int r = (int) sqrt((R-i)*(R-i)+(R-j)*(R-j));

			if ( r > R)
			{
				alpha_color.setAlpha(0);
			}
			else
			{
				alpha_color.setAlpha( (R-r)/R*200);
			}
			// L U
			feather_edged_image->setPixel(i, j, alpha_color);
			// R U
			feather_edged_image->setPixel(image->getDimension().Width+2*size - i -1, j, alpha_color);
			// L D
			feather_edged_image->setPixel(i, image->getDimension().Height+2*size-j-1, alpha_color);
			// R D
			feather_edged_image->setPixel(image->getDimension().Width+2*size - i -1, image->getDimension().Height+2*size-j-1, alpha_color);
		}
	}

	//pic
	image->copyTo(feather_edged_image, core::position2d<s32>(size,size), 
		core::rect<s32>(0, 0, image->getDimension().Width, image->getDimension().Height));

	return feather_edged_image;
}


}
