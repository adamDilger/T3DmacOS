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
#include "Propeller.hpp"

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
        
//        //Create a torus using the Sweep class as a child of rotateOrigin
//        SweepPath sp;
//        sp.makeCirclePath(0, 30);
//        GameObject *torus = new GameObject(this);
//        
//        vector<Vector3> points;
//        points.push_back(Vector3(   0,      0.0f,   0.0f));
//        points.push_back(Vector3(   0.3f,   0.0f,   0.0f));
//        points.push_back(Vector3(   0.35f,  0.05f,  0.0f));
//        points.push_back(Vector3(   0.6f,   0.2f,   0.0f));
//        points.push_back(Vector3(   0.75f,  0.4f,   0.0f));
//        points.push_back(Vector3(   0.85f,  0.6f,   0.0f));
//        points.push_back(Vector3(   0.9f,   1.0f,   0.0f));
//        points.push_back(Vector3(   0.85f,   1.0f,   0.0f));
//        points.push_back(Vector3(   0.8f,  0.6f,   0.0f)); 
//        points.push_back(Vector3(   0.7f,  0.4f,   0.0f));
//        points.push_back(Vector3(   0.5f,   0.2f,   0.0f));
//        points.push_back(Vector3(   0.15f,  0.1f,   0.0f));
//
//        torus->setMesh(new Sweep(points,sp,true));
//        torus->setMaterial(white);
//        torus->getTransform()->setLocalPosition(Vector3(0,1,0));
//        torus->getTransform()->setParent(root);
//        torus->getTransform()->name = "Torus";
//        
//        SweepPath sp1;
//        sp1.addPoint(Vector3(   0.85f,  0.75f,   0.0f), Quaternion(0,0,   Math::HALF_PI));
//        sp1.addPoint(Vector3(   1.0f,  0.85f,   0.0f),  Quaternion(0,0,  Math::HALF_PI));
//        sp1.addPoint(Vector3(   1.2f,  0.75f,   0.0f),  Quaternion(0,0,  Math::HALF_PI - Math::HALF_PI/2));
//        sp1.addPoint(Vector3(   1.15f,  0.35f,   0.0f), Quaternion(0,0, -Math::HALF_PI/2));
//        sp1.addPoint(Vector3(   0.9f,  0.2f,   0.0f),   Quaternion(0,0, -Math::HALF_PI));
//        sp1.addPoint(Vector3(   0.7f,  0.35f,   0.0f),  Quaternion(0,0, -Math::HALF_PI - Math::HALF_PI/2));
//
//        GameObject *handle = new GameObject(this);
//        
//        vector<Vector3> points1;
//        points1.push_back(Vector3(   0.0f,   0.0f,   0.1f));
//        points1.push_back(Vector3(   -0.03f,   0.0f,   0.07f));
//        points1.push_back(Vector3(   -0.05f,   0.0f,   0.0f));
//        points1.push_back(Vector3(   -0.03f,   0.0f,  -0.07f));
//        points1.push_back(Vector3(   0.0f,   0.0f,  -0.1f));
//        points1.push_back(Vector3(   0.03f,  0.0f,  -0.07f));
//        points1.push_back(Vector3(   0.05f,  0.0f,   0.0f));
//        points1.push_back(Vector3(   0.03f,  0.0f,   0.07f));
//        
//        
//        handle->setMesh(new Sweep(points1,sp1,true));
//        handle->setMaterial(white);
//        handle->getTransform()->setLocalPosition(Vector3(0,0,0));
//        handle->getTransform()->setParent(torus->getTransform());
//        handle->getTransform()->name = "Handle";
        
        GameObject *prop = new GameObject(this);
        prop->setMesh(
                      new Propeller(
                                2.5,		// the outer radius of the propeller
                                0.5f,      // the radius of the propeller hub
                                0.3f,		// the z-thickness of the hub and blades
                                Math::DEG2RAD *  20,      // the twist applied to the top hub vertices
                                7, 		// the number of blades
                                21));
                      
        prop->getTransform()->setParent(root);
        prop->setMaterial(blue);
        prop->getTransform()->setLocalPosition(Vector3(0, 2, 0));
        
        //camObj->addComponent(new LookAtBehaviour(torus->getTransform()));
        
        return true;
    }
}
