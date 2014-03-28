/** 
* @file IImageSpider.h
* @brief Image spider Common Interface
* @author Yuan Lichuan
* @version 1.0
* @date 2009-2010
*/

#ifndef __I_IMAGESPIDER_H_INCLUDED__
#define __I_IMAGESPIDER_H_INCLUDED__

#include <irrlicht.h>

#include "../Wall/IImageItem.h"

namespace era
{
namespace spider
{

/**
*  Image Spider Interface
*/
class IImageSpider : public irr::IReferenceCounted
{
public:

	/** Destructor */
	virtual ~IImageSpider(){}

	/** Search image 
	* This function is thread safe.
	*/
	virtual void Search() = 0;

	/** Is search finished
	* @return if the search is finished.
	*/
	virtual bool IsDone() = 0;

	/** Image item 
	* @return Vector of IImageItem
	*/
	virtual irr::core::array< wall::IImageItem* > getImageCollection() = 0;
};

} // spider
} // era

#endif