//
//  ADPlane.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 9/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#ifndef ADPlane_hpp
#define ADPlane_hpp

#include <stdio.h>
#include "Mesh.h"


namespace T3D
{
    class ADPlane :
    public Mesh
    {
    public:
        ADPlane(float size);
        virtual ~ADPlane(void);
    };
}


#endif /* ADPlane_hpp */
