//
//  Lamp.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 22/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#pragma once
#include "GameObject.h"


#include "Cylinder.hpp"
#include "DrawTask.h"

namespace T3D {
    
    class Lamp : public GameObject
    {
    public:
        Lamp(T3DApplication *app);
        ~Lamp(void);
        
        GameObject *base;
        GameObject *arm1;
        GameObject *arm2;
        GameObject *baseJoint;
        GameObject *elbowJoint;
        GameObject *shadeJoint;
    };
    
}
