//
//  Stan.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 8/9/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#pragma once
#include "GameObject.h"


#include "Cylinder.hpp"
#include "DrawTask.h"
#include "Animation.h"

namespace T3D {
    
    class Stan : public GameObject
    {
    public:
        Stan(T3DApplication *app);
        ~Stan(void);
        
        Material *red;
        
        GameObject *head;
        GameObject *body;
        GameObject *armL;
        GameObject *shoulderL;
        GameObject *handL;
        GameObject *armR;
        GameObject *shoulderR;
        GameObject *handR;
        GameObject *shoulderLJoint;
        GameObject *shoulderRJoint;
        GameObject *legL;
        GameObject *legR;
        GameObject *legLJoint;
        GameObject *legRJoint;
        GameObject *footL;
        GameObject *footR;
        
        GameObject *bobble;
        GameObject *headBand;
        GameObject *beanie;
        
        Animation *walkingAnimation;
        
        bool isWalking = false;
        void walking(bool isWalking);
    };
    
}
