//
//  Assignment2.cpp
//  MacOSGLApplication
//
//  Created by adam dilger on 9/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#include "Assignment2.hpp"
#include "ADPlane.hpp"
#include "Cube.h"
#include "KeyboardController.h"
#include "LookAtBehaviour.h"
#include "Camera.h"
#include "GLShader.h"
#include "DiagMessageTask.h"
#include "Material.h"
#include "SweepPath.h"
#include "Sweep.h"

namespace T3D {
    
    Assignment2::Assignment2(void)
    {
    }
    
    
    Assignment2::~Assignment2(void)
    {
    }
    
    bool Assignment2::init(){
        // Call init of superclass (sets up sdl and opengl)
        MacOSGLApplication::init();
        
        
        //MATERIALS
        Material *green = renderer->createMaterial(Renderer::PR_OPAQUE);
        green->setDiffuse(0,1,0,1);
        Material *white = renderer->createMaterial(Renderer::PR_OPAQUE);
        white->setDiffuse(1, 1, 1, 1);
        Material *blue = renderer->createMaterial(Renderer::PR_OPAQUE);
        blue->setDiffuse(0.1,0.5,0.9,1);
        
        
        //Add a light
        GameObject *lightObj = new GameObject(this);
        Light *light = new Light(Light::DIRECTIONAL);
        light->setAmbient(1,1,1);
        light->setDiffuse(1,1,1);
        light->setSpecular(1,1,1);
        lightObj->setLight(light);
        lightObj->getTransform()->setLocalRotation(Vector3(-45*Math::DEG2RAD,70*Math::DEG2RAD,0));
        lightObj->getTransform()->setParent(root);
        
        GameObject *camObj = new GameObject(this);
        renderer->camera =
        new Camera(Camera::PERSPECTIVE,0.1,500.0,45.0,1.6);
        camObj->getTransform()->setLocalPosition(Vector3(0, 5, 20));
        camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
        camObj->setCamera(renderer->camera);
        camObj->getTransform()->setParent(root);
        camObj->addComponent(new KeyboardController());
        
        GameObject *plane = new GameObject(this);
        plane->setMesh(new ADPlane(15));
        plane->setMaterial(green);
        plane->getTransform()->setParent(root);
        plane->getTransform()->setLocalPosition(Vector3(0,0,0));
        
        //Create a torus using the Sweep class as a child of rotateOrigin
        SweepPath sp;
        
        for (int i=0; i<32; i++){
            Transform t;
            float angle = Math::TWO_PI*i/8;
            t.setLocalPosition(Vector3(cosf(angle),i 	/ 8.0,sinf(angle)));
            
            //TODO check that this is correct
            t.setLocalRotation(*new Quaternion(Vector3(0,-angle,0)));
            sp.addTransform(t);
        }
        
        GameObject *torus = new GameObject(this);
        vector<Vector3> points;
        points.push_back(Vector3(   0.2f,   0.0f,   0.0f));
        points.push_back(Vector3(   0.14f,  0.14f,  0.0f));
        points.push_back(Vector3(   0.0f,   0.2f,   0.0f));
        points.push_back(Vector3(   -0.14f, 0.14f,  0.0f));
        points.push_back(Vector3(   -0.2f,  0.0f,   0.0f));
        points.push_back(Vector3(   -0.14f, -0.14f, 0.0f));
        points.push_back(Vector3(   0.0f,   -0.2f,  0.0f));
        points.push_back(Vector3(   0.14f,  -0.14f, 0.0f));
        torus->setMesh(new Sweep(points,sp,true));
        torus->setMaterial(blue);
        torus->getTransform()->setLocalPosition(Vector3(0,1,0));
        torus->getTransform()->setParent(root);
        torus->getTransform()->name = "Torus";
        
        
        //camObj->addComponent(new LookAtBehaviour(torus->getTransform()));
        
        return true;
    }
}
