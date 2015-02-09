// Copyright 2014 Isis Innovation Limited and the authors of InfiniTAM

#pragma once

#include "../Utils/ITMLibDefines.h"

#include "ITMPose.h"
#include "ITMPointCloud.h"
#include "ITMScene.h"

namespace ITMLib
{
	namespace Objects
	{
		/** \brief
		    Stores some internal variables about the current tracking
		    state, most importantly the camera pose
		*/
		class ITMTrackingState
		{
		public:
			/** @brief
			    Excerpt of the scene used by the tracker to align
			    a new frame.

			    This is usually the main result generated by the
			    raycasting operation in a ITMLib::Engine::ITMSceneReconstructionEngine.
			*/
			ITMPointCloud *pointCloud;

			/// The pose used to generate the point cloud.
			ITMPose *pose_pointCloud;

			/// Current pose of the depth camera.
			ITMPose *pose_d;

			ITMTrackingState(Vector2i imgSize, MemoryDeviceType memoryType)
			{
				this->pointCloud = new ITMPointCloud(imgSize, memoryType);

				this->pose_d = new ITMPose();
				this->pose_d->SetFrom(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

				this->pose_pointCloud = new ITMPose();
				this->pose_pointCloud->SetFrom(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
			}

			~ITMTrackingState(void)
			{
				delete pointCloud;
				delete pose_d;
				delete pose_pointCloud;
			}

			// Suppress the default copy constructor and assignment operator
			ITMTrackingState(const ITMTrackingState&);
			ITMTrackingState& operator=(const ITMTrackingState&);
		};
	}
}
