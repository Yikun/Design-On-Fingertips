
#ifndef __C_WALLMANAGER_H_INCLUDED__
#define __C_WALLMANAGER_H_INCLUDED__

#include <irrlicht.h>

namespace era
{

namespace spider
{
	class IImageSpider;
}

namespace wall
{

using namespace irr;
/**
* Spider manager to search the web.
* This manager will maintain a spider list as history.
*/
class CWallManager
{

public:
	CWallManager();

	virtual ~CWallManager();

	/** Create a local folder image spider 
	* @return IImageSpider
	*/
	era::spider::IImageSpider* CreateLocalImageSpider(core::stringc folder);

	void UpdateScene();

	core::array<scene::ISceneNode*>* GetWallItemList();

private:
	void clearWallItem();

private:
	era::spider::IImageSpider* spider_; /**< this should be deleted in destructor */
	core::array< scene::ISceneNode* > wall_item_list; /**< this should be deleted in destructor */
	core::array< video::ITexture* > wall_texture_list; /**< this should be deleted in destructor */

	io::IFileSystem* file_system_;
};

} // spider
} // era

#endif
