//
//  Skateboard.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 12/9/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#ifndef Skateboard_hpp
#define Skateboard_hpp

#include <stdio.h>
#include "GameObject.h"
#include "Cylinder.hpp"

namespace T3D {
    
    class Robot : public GameObject
    {
    public:
        Robot(T3DApplication *app);
        ~Robot(void);
        
        GameObject *body;
        GameObject *legL;
        GameObject *legR;
        GameObject *kneeL;
        GameObject *kneeR;
        GameObject *shinL;
        GameObject *shinR;
        
        GameObject *shoulderL;
        GameObject *shoulderR;
        GameObject *armL;
        GameObject *armR;
        
        GameObject *head;
        
        GameObject *bodyJoint;
        GameObject *legLJoint;
        GameObject *legRJoint;
        GameObject *kneeLJoint;
        GameObject *kneeRJoint;
        GameObject *shoulderLJoint;
        GameObject *shoulderRJoint;
        
    };
}

#endif
