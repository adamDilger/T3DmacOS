//
//  Assignment2.cpp
//  MacOSGLApplication
//
//  Created by adam dilger on 9/8/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#include "Assignment2.hpp"
#include "Animation.h"
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
#include "Lamp.hpp"
#include "Stan.hpp"
#include "StanController.hpp"

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
        green->setDiffuse(0.5,1,0.5,1);
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
        lightObj->getTransform()->setLocalRotation(Vector3(0,45 *Math::DEG2RAD,0));
        lightObj->getTransform()->setParent(root);
        
        GameObject *camObj = new GameObject(this);
        renderer->camera =
        new Camera(Camera::PERSPECTIVE,0.1,500.0,45.0,1.6);
        camObj->getTransform()->setLocalPosition(Vector3(0, 5, 20));
        camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
        camObj->setCamera(renderer->camera);
        camObj->getTransform()->setParent(root);
        camObj->addComponent(new KeyboardController());
        
//        GameObject *plane = new GameObject(this);
//        plane->setMesh(new ADPlane(30));
//        plane->setMaterial(green);
//        plane->getTransform()->setParent(root);
//        plane->getTransform()->setLocalPosition(Vector3(0,0,0));
//
////        //Create a torus using the Sweep class as a child of rotateOrigin
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
        
//        GameObject *prop = new GameObject(this);
//        prop->setMesh(
//                      new Propeller(
//                                5,		// the outer radius of the propeller
//                                1,      // the radius of the propeller hub
//                                1,		// the z-thickness of the hub and blades
//                                Math::DEG2RAD *  40,      // the twist applied to the top hub vertices
//                                7, 		// the number of blades
//                                21));
//                      
//        prop->getTransform()->setParent(root);
//        prop->setMaterial(blue);
//        prop->getTransform()->setLocalPosition(Vector3(0, 2, 0));
        
        //camObj->addComponent(new LookAtBehaviour(torus->getTransform()));
        
        Material *stanBrown = renderer->createMaterial(Renderer::PR_OPAQUE);
        stanBrown->setDiffuse(201/255.0,119/255.0,107/255.0,  1);
        
        Material *stanSkin = renderer->createMaterial(Renderer::PR_OPAQUE);
        stanSkin->setDiffuse(255/255.0,238/255.0,198/255.0,   1);

        Material *stanRed = renderer->createMaterial(Renderer::PR_OPAQUE);
        stanRed->setDiffuse(238/255.0, 48/255.0,76/255.0,   1);
        
        Material *stanBlue = renderer->createMaterial(Renderer::PR_OPAQUE);
        stanBlue->setDiffuse(72/255.0, 116/255.0,183/255.0,   1);
        
        Material *stanBlack = renderer->createMaterial(Renderer::PR_OPAQUE);
        stanBlack->setDiffuse(45/255.0, 45/255.0, 45/255.0,   1);
        
//        Lamp *lamp = new Lamp(this);
//        lamp->setMaterial(grey);
//        lamp->getTransform()->setLocalScale(Vector3(10, 10, 10));
//        lamp->getTransform()->setLocalPosition(Vector3(0,0,0));
//        lamp->getTransform()->setParent(root);
//        
//        lamp->base->setMaterial(grey);
//        lamp->arm1->setMaterial(grey);
//        lamp->arm2->setMaterial(grey);
        
        //Create some textured materials (using texture files)
        Texture *smileytex = new Texture(getResourcePath("Stan.png"), true, true);
        renderer->loadTexture(smileytex);
        Material *smiley = renderer->createMaterial(Renderer::PR_OPAQUE);
        smiley->setTexture(smileytex);
        
        Stan *stan = new Stan(this);
        
        stan->getTransform()->setLocalPosition(Vector3(0,0,0));
        stan->getTransform()->setParent(root);
        
        stan->head->setMaterial(smiley);
        stan->body->setMaterial(stanBrown);
        stan->armL->setMaterial(stanBrown);
        stan->shoulderL->setMaterial(stanBrown);
        stan->handL->setMaterial(stanRed);
        stan->armR->setMaterial(stanBrown);
        stan->shoulderR->setMaterial(stanBrown);
        stan->handR->setMaterial(stanRed);
        stan->legL->setMaterial(stanBlue);
        stan->legR->setMaterial(stanBlue);
        stan->footL->setMaterial(stanBlack);
        stan->footR->setMaterial(stanBlack);
        stan->headBand->setMaterial(stanRed);
        stan->beanie->setMaterial(stanBlue);
        stan->bobble->setMaterial(stanRed);
        
        stan->addComponent(new StanController(stan));
        
        return true;
    }
}
