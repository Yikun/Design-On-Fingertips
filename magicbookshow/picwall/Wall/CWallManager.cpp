#include "CWallManager.h"

#include "IImageItem.h"
#include "../Spider/IImageSpider.h"
#include "../Spider/CLocalImageSpider.h"

#include "../util.h"

namespace era
{
namespace wall
{

CWallManager::CWallManager()
: file_system_(era::Util::Instance()->GetFileSystem())
{
}

CWallManager::~CWallManager()
{
	clearWallItem();
}


/** Create a local folder image spider 
* @return IImageSpider
*/
era::spider::IImageSpider* CWallManager::CreateLocalImageSpider(core::stringc folder)
{
	if (spider_ != NULL)
	{
		clearWallItem();
	}

	spider_  = new era::spider::CLocalImageSpider(folder, file_system_);
	return spider_;
}

void CWallManager::UpdateScene()
{
    scene::ISceneManager* smgr = era::Util::Instance()->GetDevice()->getSceneManager();
	spider_->Search();
	core::array< era::wall::IImageItem* > image_collection = spider_->getImageCollection();

	scene::ISceneNode* wallitem;
	for (int i=0; i<image_collection.size(); i++)
	{
        video::IImage* img = image_collection[i]->getThumb();
		if (img == NULL)
		{
			continue;
		}

        video::ITexture* tex =era::Util::Instance()->GetDriver()->addTexture("picwall",img);// era::Util::Instance()->GetDriver()->getTexture("/home/kero/workspace/magicbookshow/bin/images/mommy.jpg");//////
		core::vector3df size(img->getDimension().Width, img->getDimension().Height, 0.01);
        //core::vector3df(400*(i/3),300*(1-(i%3))   400*1 *2 *3  300*1 300*2
        wallitem = smgr->addCubeSceneNode(1, smgr->getRootSceneNode(), i+1, core::vector3df(400*(i%3),300*(1-i/3)-150, 0), core::vector3df(0,0,0), size);
        wallitem->setMaterialTexture(0, tex);
        wallitem->setMaterialFlag(video::EMF_LIGHTING, false);
        wallitem->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);
        //wallitem->setMaterialType(video::EMT_SOLID);
		this->wall_item_list.push_back(wallitem);
		this->wall_texture_list.push_back(tex);

		img->drop();
	}
}

core::array<scene::ISceneNode*>* CWallManager::GetWallItemList()
{
	return &wall_item_list;
}

void CWallManager::clearWallItem()
{
    for (int i=0; i<wall_item_list.size(); i++)
    {
        scene::ISceneNode* wallitem = wall_item_list[i];
        wallitem->remove();
        video::ITexture* tex = wall_texture_list[i];
        if (tex)
        {
            era::Util::Instance()->GetDriver()->removeTexture(tex);
        }
    }
    wall_item_list.clear();
    wall_texture_list.clear();
}

} // wall
} // era
