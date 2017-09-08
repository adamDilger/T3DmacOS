//
//  Cylinder.cpp
//  MacOSGLApplication
//
//  Created by adam dilger on 8/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#include "Cylinder.hpp"
#include <math.h>
#include "Math.h"

namespace T3D
{
    Cylinder::Cylinder(float radius, float height, int density)
    {
        // Init vertex and index arrays
        initArrays(density * 4 + 2,	// num vertices
                   density * 2,		// num tris
                   density);		// num quads
        
        // Set vertices
        for (int i = 0; i < density; i++) {
            float theta = i * (Math::TWO_PI / density);
            
            float x = radius * cos(theta);
            float z = radius * sin(theta);
            float y = height;
            
            setVertex(i, x, y, z);
            setVertex(density + i, x, y, z);
            setVertex(density * 2 + i, x, -y, z);
            setVertex(density * 3 + i, x, -y, z);
        }
        
        setVertex(density * 4,      0,   height,    0);
        setVertex(density * 4 + 1,  0,   -height,   0);
        
        
        // Build for Top
        for (int i = 0; i < density; i++) {
            setFace(i,
                    i + density,
                    ((i + 1) % density) + density,
                    (((i + 1) % density) + density*2),
                    density*2 + i);
        }

        //build tri top
        for (int i = 0; i < density; i++) {
            setFace(i,
                    i + 1,
                    i,
                    density * 4);
        }
        
        for (int i = 0; i < density; i++) {
            setFace(i + density,
                    i + (density * 3),
                    ((i + 1) % density) + (density * 3),
                    density * 4 + 1);
        }
        
        // Check vertex and index arrays
        checkArrays();
        
        // Calculate normals
        calcNormals();
    }
    
    
    Cylinder::~Cylinder(void)
    {
        // Mesh delete arrays if they have been created, not need to do anything here
    }
}
