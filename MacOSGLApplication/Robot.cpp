//
//  Robot.cpp
//  MacOSGLApplication
//
//  Created by adam dilger on 12/9/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#include "Robot.hpp"
#include "SweepPath.h"
#include "Cube.h"
#include "Sphere.h"

namespace T3D
{
    Robot::Robot(T3DApplication *app):GameObject(app) {
        getTransform()->name = "Robot";
        
        float LEG_RADIUS = 0.2;
        float LEG_HEIGHT = 0.4;
        
        bodyJoint = new GameObject(app);
        bodyJoint->getTransform()->setParent(getTransform());
        bodyJoint->getTransform()->setLocalPosition(Vector3(0, 3, 0));
        
        body = new GameObject(app);
        body->setMesh(new Cube(1));
        body->getTransform()->setParent(bodyJoint->getTransform());
        body->getTransform()->setLocalPosition(Vector3(0, 0, 0));
        body->getTransform()->setLocalScale(Vector3(0.8, 1, 0.3));
        body->getTransform()->name = "Body";
        
        head = new GameObject(app);
        head->getTransform()->setParent(bodyJoint->getTransform());
        head->getTransform()->setLocalPosition(Vector3(0, 1.5, 0));
        head->getTransform()->setLocalScale(Vector3(0.8, 1, 1));
        head->setMesh(new Sphere(0.5, 16));
        
        legLJoint = new GameObject(app);
        legLJoint->getTransform()->setParent(bodyJoint->getTransform());
        legLJoint->getTransform()->setLocalPosition(Vector3(.4,-1,0));
        
        legRJoint = new GameObject(app);
        legRJoint->getTransform()->setParent(bodyJoint->getTransform());
        legRJoint->getTransform()->setLocalRotation(Vector3(-15*Math::DEG2RAD,0,0));
        legRJoint->getTransform()->setLocalPosition(Vector3(-.4,-1,0));
        
        legL = new GameObject(app);
        legL->getTransform()->setParent(legLJoint->getTransform());
        legL->getTransform()->setLocalPosition(Vector3(0, -LEG_HEIGHT,0));
        legL->setMesh(new Cylinder(LEG_RADIUS, LEG_HEIGHT, 16));
        
        legR = new GameObject(app);
        legR->getTransform()->setParent(legRJoint->getTransform());
        legR->getTransform()->setLocalPosition(Vector3(0, -LEG_HEIGHT,0));
        legR->setMesh(new Cylinder(LEG_RADIUS, LEG_HEIGHT, 16));
        
        kneeLJoint = new GameObject(app);
        kneeLJoint->getTransform()->setParent(legLJoint->getTransform());
        kneeLJoint->getTransform()->setLocalPosition(Vector3(0,-LEG_HEIGHT*2,0));
        
        kneeRJoint = new GameObject(app);
        kneeRJoint->getTransform()->setParent(legRJoint->getTransform());
        kneeRJoint->getTransform()->setLocalRotation(Vector3(40*Math::DEG2RAD,0,0));
        kneeRJoint->getTransform()->setLocalPosition(Vector3(0,-LEG_HEIGHT*2,0));
        
        kneeL = new GameObject(app);
        kneeL->getTransform()->setParent(kneeLJoint->getTransform());
        kneeL->getTransform()->setLocalPosition(Vector3(0,0,0));
        kneeL->setMesh(new Sphere(LEG_RADIUS*1.1, 8));
        
        kneeR = new GameObject(app);
        kneeR->getTransform()->setParent(kneeRJoint->getTransform());
        kneeR->getTransform()->setLocalPosition(Vector3(0,0,0));
        kneeR->setMesh(new Sphere(LEG_RADIUS*1.1, 8));
        
        shinL = new GameObject(app);
        shinL->getTransform()->setParent(kneeLJoint->getTransform());
        shinL->getTransform()->setLocalPosition(Vector3(0,LEG_HEIGHT*-1.1,0));
        shinL->setMesh(new Cylinder(LEG_RADIUS*0.95, LEG_HEIGHT*1.1, 16));
        
        shinR = new GameObject(app);
        shinR->getTransform()->setParent(kneeRJoint->getTransform());
        shinR->getTransform()->setLocalPosition(Vector3(0,LEG_HEIGHT*-1.1,0));
        shinR->setMesh(new Cylinder(LEG_RADIUS*0.95, LEG_HEIGHT*1.1, 16));
        
        shoulderLJoint = new GameObject(app);
        shoulderLJoint->getTransform()->setParent(bodyJoint->getTransform());
        shoulderLJoint->getTransform()->setLocalRotation(Vector3(0, 30*Math::DEG2RAD, 30*Math::DEG2RAD));
        shoulderLJoint->getTransform()->setLocalPosition(Vector3(0.8, 0.8, 0));
        
        shoulderRJoint = new GameObject(app);
        shoulderRJoint->getTransform()->setParent(bodyJoint->getTransform());
        shoulderRJoint->getTransform()->setLocalPosition(Vector3(-0.8, 0.8, 0));
        
        shoulderL = new GameObject(app);
        shoulderL->getTransform()->setParent(shoulderLJoint->getTransform());
        shoulderL->getTransform()->setLocalPosition(Vector3(0, 0, 0));
        shoulderL->setMesh(new Sphere(0.2, 6));
        
        shoulderR = new GameObject(app);
        shoulderR->getTransform()->setParent(shoulderRJoint->getTransform());
        shoulderR->getTransform()->setLocalPosition(Vector3(0, 0, 0));
        shoulderR->setMesh(new Sphere(0.2, 6));
        
        armL = new GameObject(app);
        armL->getTransform()->setParent(shoulderLJoint->getTransform());
        armL->getTransform()->setLocalPosition(Vector3(0,-0.6,0));
        armL->setMesh(new Cylinder(LEG_RADIUS, 0.6, 16));
        
        armR = new GameObject(app);
        armR->getTransform()->setParent(shoulderRJoint->getTransform());
        armR->getTransform()->setLocalPosition(Vector3(0,-0.6,0));
        armR->setMesh(new Cylinder(LEG_RADIUS, 0.6, 16));
    }
}
