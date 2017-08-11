//
//  Assignment2.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 9/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#ifndef Assignment2_hpp
#define Assignment2_hpp

#include <stdio.h>
#include "MacOSGLApplication.h"

namespace T3D {
    
    class Assignment2 :
    public MacOSGLApplication
    {
    public:
        Assignment2(void);
        ~Assignment2(void);
        
        bool init();
    };
    
}

#endif /* Assignment2_hpp */
