#include "CameraAnimator.h"

#include <iostream>
#include <cmath>
namespace irr
{
namespace scene
{

void CameraAnimator::animateNode(ISceneNode* node, u32 timeMs)
{
	if ( 0 == node || node->getType() != ESNT_CAMERA)
	{
		return;
	}

	ICameraSceneNode* camera = static_cast<ICameraSceneNode*>(node);

	core::vector3df camera_position = camera->getPosition();
	core::vector3df target_position = camera->getTarget();
	f32 dt = (timeMs - start_time_) / 1000.0;

	f32 sign;
	f32 x_current = target_position.X;
	f32 x_speed = 0;

	if (is_drag_ && current_node_ == NULL) // drag
	{
		core::position2di mouse_position = device_->getCursorControl()->getPosition();
		s32 xdiff = drag_start_point_.X - mouse_position.X;
		drag_start_point_ = mouse_position;

		x_target += 0.01*xdiff / core::max_(dt, 0.0000001f);
	}

	if (current_node_!=NULL) // click
	{
		is_first_ = false;
		x_target = current_node_->getPosition().X;
	}
	sign = (x_target < x_current) ? -1 : 1;
	x_speed = sign*sqrt(abs(x_target - x_current)) * 50;
	target_position.X += x_speed * dt;

	// 1.2 camera
	sign = (target_position.X < camera_position.X) ? -1 : 1;
	camera_speed_ = sign*sqrt(abs(target_position.X - camera_position.X)) * 80;
	camera_position.X += camera_speed_ * dt;

	if (x_target < 0)
	{
		x_target = 0;
	}
	if (x_target > ::ceil((double)wall_vect_->size() / 3 - 1) * 400)
	{
		x_target = ::ceil((double)wall_vect_->size() / 3 - 1) * 400;
	}

	// 2. Y motion
	f32 y_target = 0;
	f32 y_current = camera_position.Y;
	f32 y_speed = 0;
	if (current_node_ != NULL)
	{
		y_target = current_node_->getPosition().Y;
	}

	sign = (y_target < y_current) ? -1 : 1;
	y_speed = sign*sqrt(abs(y_target - y_current)) * 80;
	y_current += y_speed * dt;

	camera_position.Y = y_current;
	target_position.Y = y_current;

	// 3. Z motion
	if (is_drag_)
	{
		z_target = -700;
	}
	f32 z_current = camera_position.Z;
	f32 z_speed = 0;
	if (current_node_ != NULL)
	{
		z_target = -400;
	}

	sign = (z_target < z_current) ? -1 : 1;
	z_speed = sign*sqrt(abs(z_target - z_current)) * 50;
	z_current += z_speed * dt;

	camera_position.Z = z_current;

	// 5. set position
	camera->setPosition(camera_position);
	camera->setTarget(target_position);
	//std::cout << "camera: " << camera_position.X << "\t\t" << "target: " << target_position.X << std::endl;

	// 4. Node motion
	if (last_node_ != NULL)
	{
		f32 z_current = last_node_->getAbsolutePosition().Z;
		f32 z_target = 0;
		f32 z_speed = 0;

		f32 sign = (z_target < z_current) ? -1 : 1;
		z_speed = sign*sqrt(abs(z_target - z_current)) * 80;
		z_current += z_speed * dt;

		core::vector3df pos = last_node_->getAbsolutePosition();
		pos.Z = z_current;
		last_node_->setPosition(pos);
	}

	if (current_node_ != NULL)
	{
		f32 z_current = current_node_->getAbsolutePosition().Z;
		f32 z_target = -180;
		f32 z_speed = 0;

		f32 sign = (z_target < z_current) ? -1 : 1;
		z_speed = sign*sqrt(abs(z_target - z_current)) * 80;
		z_current += z_speed * dt;

		core::vector3df pos = current_node_->getAbsolutePosition();
		pos.Z = z_current;
		current_node_->setPosition(pos);
	}

	start_time_ = timeMs;
}

bool CameraAnimator::OnEvent(const SEvent& event)
{
	switch(event.EventType)
	{
	case EET_MOUSE_INPUT_EVENT:
		if (event.MouseInput.Event == EMIE_LMOUSE_PRESSED_DOWN)
		{
			core::position2d<s32> mouse_position(event.MouseInput.X, event.MouseInput.Y);
			ISceneNode* node = scene_manager_->getSceneCollisionManager()->getSceneNodeFromScreenCoordinatesBB(mouse_position, -1);

            last_node_ = current_node_;
            //scene_manager_->getSceneNodeFromId()
			if (node && node->getType() == ESNT_CUBE )
			{
				current_node_ = node;

                printf("Name %s id %d \n",node->getName(),node->getID());
			}
			else
			{
				current_node_ = NULL;
			}

			is_drag_ = true;
			drag_start_point_ = mouse_position;
		}
		else if (event.MouseInput.Event == EMIE_LMOUSE_LEFT_UP)
		{
			is_drag_ = false;
		}
		else if (event.MouseInput.Event == EMIE_MOUSE_WHEEL)
		{
			if (current_node_ == NULL)
			{
				z_target += 100*event.MouseInput.Wheel;
				if (z_target > -200)
				{
					z_target = -200;
				}
				if (z_target < -3000)
				{
					z_target = -3000;
				}
			}
		}
		break;
    case EET_KEY_INPUT_EVENT:
        if(!event.KeyInput.PressedDown)
        {


                switch(event.KeyInput.Key)
                {

                case KEY_KEY_U:
                    if(current_node_==NULL)
                    {
                        current_node_=scene_manager_->getSceneNodeFromId(1);
                    }else{
                        last_node_= current_node_;
                        if(current_node_->getID()-3>0)
                        {
                            current_node_ = scene_manager_->getSceneNodeFromId(current_node_->getID()-3);
                        }else{
                            if(current_node_->getID()==1) current_node_ = scene_manager_->getSceneNodeFromId(6);
                            else current_node_ = scene_manager_->getSceneNodeFromId(current_node_->getID()+2);
                        }
                    }
                break;
                case KEY_KEY_M:
                    if(current_node_==NULL)
                    {
                        current_node_=scene_manager_->getSceneNodeFromId(1);
                    }else{
                    last_node_= current_node_;
                    if(current_node_->getID()+3<7)
                        current_node_ = scene_manager_->getSceneNodeFromId(current_node_->getID()+3);
                    else{
                        //if last node, back begin
                        if(current_node_->getID()==6) current_node_ = scene_manager_->getSceneNodeFromId(1);
                        //else next
                        else current_node_ = scene_manager_->getSceneNodeFromId(current_node_->getID()-2);
                    }

                    }
                break;
                case KEY_KEY_J:
                    if(current_node_==NULL)
                    {
                        current_node_=scene_manager_->getSceneNodeFromId(1);
                    }else
                    {
                    last_node_= current_node_;
                    if(current_node_->getID()-1>0)
                        current_node_ = scene_manager_->getSceneNodeFromId(current_node_->getID()-1);
                    }

                break;
                case KEY_KEY_L:
                    if(current_node_==NULL)
                    {
                        current_node_=scene_manager_->getSceneNodeFromId(1);
                    }else
                    {
                    last_node_= current_node_;
                    if(current_node_->getID()+1<7)
                        current_node_ = scene_manager_->getSceneNodeFromId(current_node_->getID()+1);

                    }
                break;
                }
        }

		return true;
	}

	return false; 
}
int CameraAnimator::getcurrentnodeid()
{
    if(current_node_)
        return current_node_->getID();
    else
        return 0;
}
ISceneNodeAnimator* CameraAnimator::createClone(ISceneNode* node, ISceneManager* newManager/* =0 */)
{
	return NULL;
}

}
}
