//
//  StanController.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 8/9/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#ifndef StanController_hpp
#define StanController_hpp

#include <stdio.h>
#include "Component.h"
#include "Stan.hpp"

namespace T3D
{
    class StanController :
    public Component
    {
    public:
        StanController(Stan *s);
        virtual ~StanController(void);
        
        virtual void update(float dt);
        void keyDownResolve(float dt);
        void keyUpResolve(float dt);
        void mouseMoveResolve();
        
        Stan *stan;
        
    private:
        float keySensitivity;
        float mouseSensitivity;
    };
    
}

#endif /* StanController_hpp */
