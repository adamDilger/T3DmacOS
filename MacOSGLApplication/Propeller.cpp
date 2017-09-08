//
//  Propeller.cpp
//  MacOSGLApplication
//
//  Created by adam dilger on 15/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#include "Propeller.hpp"
#include "Math.h"

namespace T3D
{
    Propeller::Propeller(float radius,		// the outer radius of the propeller
                         float hubRadius,	// the radius of the propeller hub
                         float height,		// the z-thickness of the hub and blades
                         float attackAngle, // the twist applied to the top hub vertices
                         int blades, 		// the number of blades
                         int density
                         )
    {
        // Init vertex and index arrays
        initArrays(density * 4 + 2 + (blades * 20),	// num vertices
                   density * 4 + (blades * 10),		// num tris
                   0);//density);		// num quads
        
        printf("making Propellor radius: [%f], hubRadius: [%f], height: [%f], attackAngle: [%f], blades: [%d], density:[%d]\n", 
            radius, hubRadius, height, attackAngle, blades, density);
        
        
        // -----------  CYLINDER    -------------------------------------------------------------------------------
        
        // Set vertices for cylinder
        for (int i = 0; i < density; i++) {
            float theta = i * (Math::TWO_PI / density) + attackAngle;
            
            float x = hubRadius * cos(theta);
            float z = hubRadius * sin(theta);
            float y = height/2;
            
            setVertex(i, x, y, z);
            setVertex((density*2) + i, x, y, z);
            
            
            //rotate for bottom verticies
            theta = i * (Math::TWO_PI / density);
            
            x = hubRadius * cos(theta);
            z = hubRadius * sin(theta);
            y = height/2;
            
            setVertex(density + i, x, -y, z);
            setVertex(i + density*3, x, -y, z);
        }
        
        setVertex(density * 4, 0, height/2, 0);
        setVertex(density * 4 + 1, 0, -(height/2), 0);
        
        int tri = 0;
        
        //build tri edges
        for (int i = 0; i < density; i++) {
            if (i == density - 1) {
                setFace(tri++,
                        i,
                        i + 1,
                        i + density);
            } else {
                setFace(tri++,
                        i,
                        (i + density) + 1,
                        i + density);
            }
            
            
            setFace(tri++,
                    i,
                    (i+1) % density,
                    ((i + 1) % density) + density);
        }
        
        //build tri top/bottom
        for (int i = 0; i < density; i++) {
            
            setFace(tri++,
                    i + density * 2,
                    density*4, //center
                    (i + 1) % density + density * 2);
            setFace(tri++,
                    i + density * 3,
                    (i + 1) % density + density * 3,
                    density*4 + 1); //center
        }
        
        
        
        // -----------  END CYLINDER    -------------------------------------------------------------------------------
        
        
        
        
        const int totalCylinderVCount = density * 4 + 1 + 1;
        int verticies = totalCylinderVCount;
        
        // -----------  PROPELLERS    -------------------------------------------------------------------------------
        
        //set vertex for propellor
        for (int prop = 0; prop < blades; prop++) {
            float theta = (prop * (density/blades)) * (Math::TWO_PI / density);
            float theta_2 = ((prop * (density/blades)) + 1) * (Math::TWO_PI / density);
            float midTheta = theta + ((theta_2 - theta) / 2);
            
            float outer_radius = radius - hubRadius;
            float propX = outer_radius * cos(midTheta);
            float propZ = outer_radius * sin(midTheta);
            
//            printf("PROPELLOR: [%d], theta: [%f], theta_2: [%f], midTheta: [%f]\n",
//                   prop, theta, theta_2, midTheta);
            
            int tmpV = verticies;
            
            float x = hubRadius * cos(theta + attackAngle);
            float z = hubRadius * sin(theta + attackAngle);
            float y = height/2;
            
            setVertex(verticies++, x, y, z);
            setVertex(verticies++, x, y, z);
            
            x = hubRadius * cos(theta);
            z = hubRadius * sin(theta);
            
            setVertex(verticies++, x, -y, z);
            setVertex(verticies++, x, -y, z);
            
            //extend radius
            
            x = hubRadius * cos(theta + attackAngle) + propX;
            z = hubRadius * sin(theta + attackAngle) + propZ;
            
            setVertex(verticies++, x, y, z);
            setVertex(verticies++, x, y, z);
            setVertex(verticies++, x, y, z);
            
            x = hubRadius * cos(theta) + propX;
            z = hubRadius * sin(theta) + propZ;
            
            setVertex(verticies++, x, -y, z);
            setVertex(verticies++, x, -y, z);
            setVertex(verticies++, x, -y, z);
            
            //change theta to be set at the other side of the prop
            
            x = hubRadius * cos(theta_2 + attackAngle);
            z = hubRadius * sin(theta_2 + attackAngle);
            
            setVertex(verticies++, x, y, z);
            setVertex(verticies++, x, y, z);
            
            x = hubRadius * cos(theta_2);
            z = hubRadius * sin(theta_2);
            
            setVertex(verticies++, x, -y, z);
            setVertex(verticies++, x, -y, z);
            
            //extend radius with changed theta
            
            float extraRadius = hubRadius * sin(theta_2-theta);
            float newPropX = (outer_radius + extraRadius) * cos(midTheta);
            float newPropZ = (outer_radius + extraRadius) * sin(midTheta);
            
            x = hubRadius * cos(theta_2 + attackAngle) + newPropX;
            z = hubRadius * sin(theta_2 + attackAngle) + newPropZ;
            
            setVertex(verticies++, x, y, z);
            setVertex(verticies++, x, y, z);
            setVertex(verticies++, x, y, z);
            
            x = hubRadius * cos(theta_2) + propX;
            z = hubRadius * sin(theta_2) + propZ;
            
            setVertex(verticies++, x, -y, z);
            setVertex(verticies++, x, -y, z);
            setVertex(verticies++, x, -y, z);
            
            setFace(tri++, tmpV, tmpV + 4, tmpV + 7);
            setFace(tri++, tmpV, tmpV + 7, tmpV + 2);
            
            setFace(tri++, tmpV + 1, tmpV + 10, tmpV + 14);
            setFace(tri++, tmpV + 1, tmpV + 14, tmpV + 5);
            
            setFace(tri++, tmpV + 11, tmpV + 12, tmpV + 17);
            setFace(tri++, tmpV + 11, tmpV + 17, tmpV + 15);
            
            setFace(tri++, tmpV + 3, tmpV + 18, tmpV + 13);
            setFace(tri++, tmpV + 3, tmpV + 8, tmpV + 18);
            
            setFace(tri++, tmpV + 16, tmpV + 19, tmpV + 9);
            setFace(tri++, tmpV + 16, tmpV + 9, tmpV + 6);
        }
        
        // -----------  END PROPELLERS    -------------------------------------------------------------------------------
        
        calcNormals();
    }
    
    
    Propeller::~Propeller(void)
    {
        // Mesh delete arrays if they have been created, not need to do anything here
    }
}
