
#ifndef __I_IMAGEITEM_H_INCLUDED__
#define __I_IMAGEITEM_H_INCLUDED__

#include <irrlicht.h>

namespace era
{
namespace wall
{

/**
* Image item interface
*/
class IImageItem : public irr::IReferenceCounted
{
public:

	/** Destructor */
	virtual ~IImageItem() {}

	/** @return Thumbnail is ready */
	virtual bool ThumbReady() = 0;

	/** @return Image is ready */
	virtual bool ImageReady() = 0;

	/** @return Height/Width */
	virtual irr::f32 HWRatio() = 0;

	/** @return The thumbnail */
	virtual irr::video::IImage* getThumb() = 0;

	/** @return The image */
	virtual irr::video::IImage* getImage() = 0;
};

} // namespace wall
} // namespace era
#endif
