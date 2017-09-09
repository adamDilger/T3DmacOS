//
//  JimmyController.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 9/9/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#ifndef JimmyController_hpp
#define JimmyController_hpp

#include <stdio.h>
#include "Component.h"
#include "Ike.hpp"

namespace T3D
{
    class JimmyController :
    public Component
    {
    public:
        JimmyController(Ike *s);
        virtual ~JimmyController(void);
        
        virtual void update(float dt);
        void keyDownResolve(float dt);
        void keyUpResolve(float dt);
        void mouseMoveResolve();
        
        Ike *ike;
        
    private:
        float keySensitivity;
        float mouseSensitivity;
    };
    
}

#endif /* JimmyController_hpp */
