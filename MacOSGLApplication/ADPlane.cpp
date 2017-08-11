//
//  ADPlane.cpp
//  MacOSGLApplication
//
//  Created by adam dilger on 9/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#include "ADPlane.hpp"

namespace T3D
{
    ADPlane::ADPlane(float size)
    {
        // Init vertex and index arrays
        initArrays(4,	// num vertices
                   0,		// num tris
                   1);		// num quads
        
        // Set vertices
        
        float s = size/2;
        
        int pos=0;
        //front
        setVertex(pos++, s, 0, s);
        setVertex(pos++, s, 0, -s);
        setVertex(pos++, -s, 0, -s);
        setVertex(pos++, -s, 0, s);
        
        // Build quads
        
        setFace(0, 0, 1, 2, 3);
        
        // Calculate normals
        calcNormals();
        
//        // Setup other arrays
//        pos = 0;
//        //front
//        for (int i=0; i<4; i++){
//            colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
//        }
//        
//        //uvs
//        pos = 0;
//        for (int f = 0; f<6; f++){
//            uvs[pos++] = 0; uvs[pos++] = 0; 
//            uvs[pos++] = 0; uvs[pos++] = 1; 
//            uvs[pos++] = 1; uvs[pos++] = 1; 
//            uvs[pos++] = 1; uvs[pos++] = 0; 
//        }
    }
    
    
    ADPlane::~ADPlane(void)
    {
        // Mesh delete arrays if they have been created, not need to do anything here
    }
}
