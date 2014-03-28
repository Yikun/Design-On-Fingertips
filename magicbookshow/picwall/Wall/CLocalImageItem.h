

#ifndef __C_LOCALIMAGEITEM_H_INCLUDED__
#define __C_LOCALIMAGEITEM_H_INCLUDED__

#include <irrlicht.h>

#include "IImageItem.h"

namespace era
{
namespace wall
{

using namespace irr;

/**
* Image item interface
*/
class CLocalImageItem : public IImageItem
{
public:
	CLocalImageItem(core::stringc file) 
		: file_(file)
	{}

	/** @return Thumbnail is ready */
	virtual bool ThumbReady() { return true; }

	/** @return Image is ready */
	virtual bool ImageReady() { return true; }

	/** @return Height/Width */
	virtual irr::f32 HWRatio() 
	{ 
		if (ImageReady())
		{
			return ratio_;
		}
	}

	/** @return The thumbnail */
	virtual video::IImage* getThumb();

	/** @return The image */
	virtual video::IImage* getImage();

private:
	core::stringc file_;
	f32 ratio_;
};

} // namespace wall
} // namespace era
#endif
