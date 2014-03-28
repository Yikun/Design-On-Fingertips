#pragma once

#include <irrlicht.h>

namespace irr
{
namespace scene
{

//! Special scene node animator for FPS cameras
class CameraAnimator : public ISceneNodeAnimator
{
public:

	//! Constructor
	CameraAnimator(core::array< ISceneNode* >* wall, IrrlichtDevice* device, ISceneManager* smgr, u32 time)
		:wall_vect_(wall), device_(device), scene_manager_(smgr), start_time_(time), 
		camera_speed_(0), target_speed_(0), target_accel_(0),
        current_node_(NULL), last_node_(NULL), x_target(400),
		z_target(-700), is_drag_(false), is_first_(false)
	{
	};

	//! Destructor
	virtual ~CameraAnimator(){};

	//! Animates the scene node, currently only works on cameras
	virtual void animateNode(ISceneNode* node, u32 timeMs);

	//! Event receiver
	virtual bool OnEvent(const SEvent& event);

	//! This animator will receive events when attached to the active camera
	virtual bool isEventReceiverEnabled() const
	{
		return true;
	}

	//! Creates a clone of this animator.
	/** Please note that you will have to drop
	(IReferenceCounted::drop()) the returned pointer after calling
	this. */
	virtual ISceneNodeAnimator* createClone(ISceneNode* node, ISceneManager* newManager=0);
    int getcurrentnodeid();
private:
	IrrlichtDevice* device_;
	ISceneManager* scene_manager_;
	core::array< ISceneNode* >* wall_vect_;
	u32 start_time_;

    ISceneNode* current_node_;
	ISceneNode* last_node_;
	f32 x_target;
	f32 z_target;
	f32 camera_speed_;
	f32 target_speed_;
	f32 target_accel_;

	bool is_drag_;
	bool is_first_;
	core::position2di drag_start_point_;
};

} // end namespace scene
} // end namespace irr

