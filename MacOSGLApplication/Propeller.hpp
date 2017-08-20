//
//  Propeller.hpp
//  MacOSGLApplication
//
//  Created by adam dilger on 15/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#ifndef Propeller_hpp
#define Propeller_hpp

#include "Mesh.h"

namespace T3D
{
    class Propeller :
    public Mesh
    {
    public:
        
        Propeller(
                  float radius,		// the outer radius of the propeller
                  float hubRadius,	// the radius of the propeller hub
                  float height,		// the z-thickness of the hub and blades
                  float attackAngle, 	// the twist applied to the top hub vertices
                  int blades, 		// the number of blades
                  int density
                  );
        
        virtual ~Propeller(void);
    };
}


#endif /* Propeller_hpp */
