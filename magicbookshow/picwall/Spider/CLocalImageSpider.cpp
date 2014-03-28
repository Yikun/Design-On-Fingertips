

#include <irrlicht.h>

#include "CLocalImageSpider.h"

#include "../Wall/CLocalImageItem.h"

using namespace irr;

namespace era
{
namespace spider
{

bool isImageFile(core::stringc& filename)
{
	core::stringc ext;
	ext = filename.subString(filename.size() - 3, 3);
	if (ext.equals_ignore_case("bmp") || ext.equals_ignore_case("jpg") || ext.equals_ignore_case("png"))
	{
		return true;
	}

	return false;
}

void CLocalImageSpider::Search()
{
	io::IFileList* file_list = file_system_->createFileList();
	for (int i=0; i<file_list->getFileCount(); i++)
	{
		if (file_list->isDirectory(i) == false)
		{
			core::stringc file_name = file_list->getFileName(i);
			if (isImageFile(file_name) == true)
			{
				image_collection_.push_back(new wall::CLocalImageItem(file_name));
			}
		}
	}

	is_done_ = true;
}

} // spider
} // era
