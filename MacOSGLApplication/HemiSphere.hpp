//
//  HemiSphere.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 8/9/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#ifndef HemiSphere_hpp
#define HemiSphere_hpp

#include <stdio.h>
#include "mesh.h"

namespace T3D{
    
    class HemiSphere :
    public Mesh
    {
    public:
        HemiSphere(float radius, int density = 8);
        virtual ~HemiSphere(void);
    };
    
}


#endif /* HemiSphere_hpp */
