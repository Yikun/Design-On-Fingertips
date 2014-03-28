/** 
* @file CLocalImageSpider.h
* @brief Search image in local folder
* @author Yuan Lichuan
* @version 1.0
* @date 2009-2010
*/

#ifndef __C_LOCALIMAGESPIDER_H_INCLUDED__
#define __C_LOCALIMAGESPIDER_H_INCLUDED__

#include <irrlicht.h>

#include "../Wall/IImageItem.h"
#include "IImageSpider.h"

namespace era
{
namespace spider
{

using namespace irr;

/**
* Search image in local folder
*/
class CLocalImageSpider : public IImageSpider
{

public:

	CLocalImageSpider(core::stringc folder, io::IFileSystem* file_system) 
		: folder_(folder), file_system_(file_system), is_done_(false)
	{
		bool res = file_system_->changeWorkingDirectoryTo(folder_.c_str());
	}

	virtual ~CLocalImageSpider()
	{
		for(int i=0; i<image_collection_.size(); i++)
		{
			image_collection_[i]->drop();
		}
	}

	/** Search image 
	* This function is thread safe.
	*/
	virtual void Search();

	/** Is search finished
	* @return if the search is finished.
	*/
	virtual bool IsDone(){ return is_done_; }

	/** Image item 
	* @return Vector of IImageItem
	*/
	virtual core::array< wall::IImageItem* > getImageCollection()
	{
		return image_collection_;
	}

private:

	core::array< wall::IImageItem* > image_collection_; /**< this should be deleted in destructor */
	core::stringc folder_;

	io::IFileSystem* file_system_;
	bool is_done_;
};

} // spider
} // era

#endif