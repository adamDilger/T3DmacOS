//
//  Stan.cpp
//  MacOSGLApplication
//
//  Created by adam dilger on 8/9/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#include "Stan.hpp"
#include "SweepPath.h"
#include "Sweep.h"
#include "HemiSphere.hpp"
#include "Sphere.h"
#include "Animation.h"

namespace T3D {
    
    Stan::Stan(T3DApplication *app):GameObject(app) {
        getTransform()->name = "Stan";
        
        head = new GameObject(app);
        head->setMesh(new HemiSphere(0.5f, 16));
        head->getTransform()->setParent(getTransform());
        head->getTransform()->setLocalPosition(Vector3(0, 1, 0));
        head->getTransform()->setLocalRotation(Vector3(Math::PI + 20*Math::DEG2RAD, Math::PI, 0));
        head->getTransform()->name = "Head";
        
        headBand = new GameObject(app);
        headBand->setMesh(new Cylinder(0.51f, 0.1, 16));
        headBand->setMaterial(red);
        headBand->getTransform()->setParent(head->getTransform());
        headBand->getTransform()->setLocalPosition(Vector3(0, 0, 0));
        //headBand->getTransform()->setLocalRotation(Vector3(0, 0, 0));
        headBand->getTransform()->name = "HeadBand";
        
        beanie = new GameObject(app);
        beanie->setMesh(new HemiSphere(0.5f, 16));
        beanie->getTransform()->setParent(head->getTransform());
        beanie->getTransform()->setLocalPosition(Vector3(0, 0, 0));
        beanie->getTransform()->setLocalRotation(Vector3(-Math::PI, 1, 0));
        beanie->getTransform()->name = "Beanie";

        bobble = new GameObject(app);
        bobble->setMesh(new Sphere(0.1f, 8));
        bobble->getTransform()->setParent(head->getTransform());
        bobble->getTransform()->setLocalPosition(Vector3(0, -0.54, 0));
        bobble->getTransform()->name = "Bobble";
        
        
        std::vector<Vector3> armProfile;
        armProfile.push_back(Vector3(0.35f,  0.0f, 0.0f));
        armProfile.push_back(Vector3(0.25f,  0.0f, -0.2f));
        armProfile.push_back(Vector3(0.0f,  0.0f, -0.3));
        armProfile.push_back(Vector3(-.25f,  0.0f, -0.2f));
        armProfile.push_back(Vector3(-.35f,  0.0f, 0.0f));
        armProfile.push_back(Vector3(-.25f,  0.0f, .2f));
        armProfile.push_back(Vector3(0.0f,  0.0f, .3f));
        armProfile.push_back(Vector3(0.25f,  0.0f, .2f));

        SweepPath armsp;
        Transform t;

        t.setLocalPosition(Vector3(0,0.1f,0));
        armsp.addTransform(t);
        
        t.setLocalPosition(Vector3(0,0.5,0));
        t.setLocalScale(Vector3(0.8f, 1, 0.9f));
        armsp.addTransform(t);
        
        t.setLocalPosition(Vector3(0,0.6,0));
        t.setLocalScale(Vector3(0.4f,  1,  0.4));
        armsp.addTransform(t);
        
        shoulderLJoint = new GameObject(app);
        shoulderLJoint->getTransform()->setLocalPosition(Vector3(0.3,0.5,0));
        shoulderLJoint->getTransform()->setParent(getTransform());
        shoulderLJoint->getTransform()->setLocalRotation(*new Quaternion(Vector3(0,0,Math::PI + 15*Math::DEG2RAD))); // this rotation is just to make a good starting pose
        shoulderLJoint->getTransform()->name = "ShoulderLJoint";
        
        shoulderRJoint = new GameObject(app);
        shoulderRJoint->getTransform()->setLocalPosition(Vector3(-0.3,0.5,0));
        shoulderRJoint->getTransform()->setParent(getTransform());
        shoulderRJoint->getTransform()->setLocalRotation(*new Quaternion(Vector3(0,0,Math::PI - 15*Math::DEG2RAD))); // this rotation is just to make a good starting pose
        shoulderRJoint->getTransform()->name = "ShoulderRJoint";
       
        body = new GameObject(app);
        body->setMesh(new Sweep(armProfile,armsp,false));
        body->getTransform()->setLocalPosition(Vector3(0,0,0));
        body->getTransform()->setParent(getTransform());
        body->getTransform()->name = "Body";
        
        armL = new GameObject(app);
        armL->setMesh(new Cylinder(0.06f, 0.15f, 10));
        armL->getTransform()->setLocalPosition(Vector3(0,0.15f,0));
        armL->getTransform()->setParent(shoulderLJoint->getTransform());
        armL->getTransform()->name = "Arm2";
        
        shoulderL = new GameObject(app);
        shoulderL->setMesh(new Sphere(0.06f, 10));
        shoulderL->getTransform()->setLocalPosition(Vector3(0,0,0));
        shoulderL->getTransform()->setParent(shoulderLJoint->getTransform());
        shoulderL->getTransform()->name = "ArmTop";
        
        handL = new GameObject(app);
        handL->setMesh(new Sphere(0.065f, 10));
        handL->getTransform()->setLocalPosition(Vector3(0, 0.3f, 0));
        handL->getTransform()->setParent(shoulderLJoint->getTransform());
        handL->getTransform()->name = "HandL";
        
        armR = new GameObject(app);
        armR->setMesh(new Cylinder(0.06f, 0.15f, 10));
        armR->getTransform()->setLocalPosition(Vector3(0,0.15f,0));
        armR->getTransform()->setParent(shoulderRJoint->getTransform());
        armR->getTransform()->name = "Arm2";
        
        shoulderR = new GameObject(app);
        shoulderR->setMesh(new Sphere(0.06f, 10));
        shoulderR->getTransform()->setLocalPosition(Vector3(0,0,0));
        shoulderR->getTransform()->setParent(shoulderRJoint->getTransform());
        shoulderR->getTransform()->name = "ArmTop";
        
        handR = new GameObject(app);
        handR->setMesh(new Sphere(0.065f, 10));
        handR->getTransform()->setLocalPosition(Vector3(0, 0.3f, 0));
        handR->getTransform()->setParent(shoulderRJoint->getTransform());
        handR->getTransform()->name = "HandL";
        
        SweepPath legSP;
        Transform t1;
        
        t1.setLocalPosition(Vector3(0,0.0f,0));
        t1.setLocalScale(Vector3(0.5, 0.5, 0.5));
        legSP.addTransform(t1);
        
        t1.setLocalPosition(Vector3(0,0.15f,0));
        //t1.setLocalScale(Vector3(0.8f, 1, 0.9f));
        legSP.addTransform(t1);
        
        legLJoint = new GameObject(app);
        legLJoint->getTransform()->setLocalPosition(Vector3(0.15,0.15,0));
        legLJoint->getTransform()->setLocalRotation(*new Quaternion(Vector3(0,0,0)));
        legLJoint->getTransform()->setParent(getTransform());
        legLJoint->getTransform()->name = "LegLJoint";

        legL = new GameObject(app);
        legL->setMesh(new Sweep(armProfile,legSP,false));
        legL->getTransform()->setLocalPosition(Vector3(0,-0.15,0));
        legL->getTransform()->setParent(legLJoint->getTransform());
        legL->getTransform()->name = "LegL";
        
        legRJoint = new GameObject(app);
        legRJoint->getTransform()->setLocalPosition(Vector3(-0.15,0.15,0));
        legRJoint->getTransform()->setLocalRotation(*new Quaternion(Vector3(0,0,0))); // this rotation is just to make a good starting pose
        legRJoint->getTransform()->setParent(getTransform());
        legRJoint->getTransform()->name = "LegRJoint";
        
        legR = new GameObject(app);
        legR->setMesh(new Sweep(armProfile,legSP,false));
        legR->getTransform()->setLocalPosition(Vector3(0,-0.15,0));
        legR->getTransform()->setParent(legRJoint->getTransform());
        legR->getTransform()->name = "LegR";
        
        SweepPath footSP;
        Transform t2;
        
        t2.setLocalPosition(Vector3(0,0.0f,0));
        t2.setLocalScale(Vector3(0, 0, 0));
        footSP.addTransform(t2);
        
        t2.setLocalPosition(Vector3(0,0.0f,0));
        t2.setLocalScale(Vector3(0.55, 0.55, 0.55));
        footSP.addTransform(t2);
        
        t2.setLocalPosition(Vector3(0,0.03f,0));
        footSP.addTransform(t2);
        
        t2.setLocalPosition(Vector3(0,0.05f,0));
        t2.setLocalScale(Vector3(0.2f, 0.2, 0.2f));
        footSP.addTransform(t2);
        
        footL = new GameObject(app);
        footL->setMesh(new Sweep(armProfile,footSP,false));
        footL->getTransform()->setLocalPosition(Vector3(0,-0.15,0));
        footL->getTransform()->setParent(legLJoint->getTransform());
        footL->getTransform()->name = "FootL";
        
        footR = new GameObject(app);
        footR->setMesh(new Sweep(armProfile,footSP,false));
        footR->getTransform()->setLocalPosition(Vector3(0,-0.15,0));
        footR->getTransform()->setParent(legRJoint->getTransform());
        footR->getTransform()->name = "FootR";
        
        //Create some animation for the sphere and torus
        walkingAnimation = new Animation(0.5);
        addComponent(walkingAnimation);
        walkingAnimation->addKey("LegLJoint",0, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, 0)),      legLJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("LegLJoint",0.2, Quaternion(     Vector3(15*Math::DEG2RAD, 0, 0)),     legLJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("LegLJoint",0.25, Quaternion(     Vector3(15*Math::DEG2RAD, 0, 0)),    legLJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("LegLJoint",0.45, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, 0)),    legLJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("LegLJoint",0.5, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, 0)),    legLJoint->getTransform()->getLocalPosition());

        walkingAnimation->addKey("LegRJoint",0, Quaternion(     Vector3(15*Math::DEG2RAD, 0, 0)),           legRJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("LegRJoint",0.2, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, 0)),        legRJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("LegRJoint",0.25, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, 0)),       legRJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("LegRJoint",0.45, Quaternion(     Vector3(15*Math::DEG2RAD, 0, 0)),         legRJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("LegRJoint",0.5, Quaternion(     Vector3(15*Math::DEG2RAD, 0, 0)),         legRJoint->getTransform()->getLocalPosition());

        walkingAnimation->addKey("ShoulderLJoint",0, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, Math::PI + 15*Math::DEG2RAD)),      shoulderLJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("ShoulderLJoint",0.2, Quaternion(     Vector3(15*Math::DEG2RAD, 0, Math::PI + 15*Math::DEG2RAD)),     shoulderLJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("ShoulderLJoint",0.25, Quaternion(     Vector3(15*Math::DEG2RAD, 0, Math::PI + 15*Math::DEG2RAD)),    shoulderLJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("ShoulderLJoint",0.45, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, Math::PI + 15*Math::DEG2RAD)),    shoulderLJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("ShoulderLJoint",0.5, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, Math::PI + 15*Math::DEG2RAD)),    shoulderLJoint->getTransform()->getLocalPosition());

        walkingAnimation->addKey("ShoulderRJoint",0, Quaternion(     Vector3(15*Math::DEG2RAD, 0, Math::PI - 15*Math::DEG2RAD)),      shoulderRJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("ShoulderRJoint",0.2, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, Math::PI - 15*Math::DEG2RAD)),     shoulderRJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("ShoulderRJoint",0.25, Quaternion(     Vector3(-15*Math::DEG2RAD, 0, Math::PI - 15*Math::DEG2RAD)),    shoulderRJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("ShoulderRJoint",0.45, Quaternion(     Vector3(15*Math::DEG2RAD, 0, Math::PI - 15*Math::DEG2RAD)),    shoulderRJoint->getTransform()->getLocalPosition());
        walkingAnimation->addKey("ShoulderRJoint",0.5, Quaternion(     Vector3(15*Math::DEG2RAD, 0, Math::PI - 15*Math::DEG2RAD)),    shoulderRJoint->getTransform()->getLocalPosition());
        walkingAnimation->loop(true);
//        walkingAnimation->play();
        
//        Animation *animMove = new Animation(30);
//        addComponent(animMove);
//        animMove->addKey("Stan",0,     Quaternion(Vector3(0, 0, 0)),    Vector3(0, 0, 0));
//        animMove->addKey("Stan",30,   Quaternion(Vector3(0, 0, 0)),     Vector3(0, 0, 30));
//        animMove->loop(true);
//        animMove->play();
    }
    
    void Stan::walking(bool w) {
        
        if (w) {
            
            
            if (!isWalking) {
                walkingAnimation->play();
                isWalking = true;
            }
        } else {
            isWalking = false;
            walkingAnimation->pause();
        }
    }
}



