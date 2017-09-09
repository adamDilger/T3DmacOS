//
//  JimmyController.cpp
//  MacOSGLApplication
//
//  Created by adam dilger on 9/9/17.
//  Copyright © 2017 Adam Dilger. All rights reserved.
//

#include "JimmyController.hpp"
#include "Input.h"
#include "Vector3.h"
#include "GameObject.h"
#include "Transform.h"
#include "Math.h"

namespace T3D
{
    //min and max speeds for key and mouse sensitivity
#define KEY_SENSITIVITY_MIN 3
#define KEY_SENSITIVITY_MAX 4
#define MOUSE_SENSITIVITY_MIN 0.0005f;
#define MOUSE_SENSITIVITY_MAX 0.0010f;
    
    JimmyController::JimmyController(Ike *s)
    {
        keySensitivity = 3.0f;
        mouseSensitivity = 0.0005f;
        ike = s;
    }
    
    
    JimmyController::~JimmyController(void)
    {
        
    }
    
    void JimmyController::update(float dt){
        
        //resolve all of the input actions
        keyDownResolve(dt);
        keyUpResolve(dt);
    }
    
    //Method to resolve the actions of each keyDown event
    void JimmyController::keyDownResolve(float dt)
    {
        Matrix4x4 m = gameObject->getTransform()->getLocalMatrix();
        Vector3 right = Vector3(m[0][0], m[1][0], m[2][0]);
        Vector3 up = Vector3(m[0][1], m[1][1], m[2][1]);
        Vector3 back = Vector3(m[0][2], m[1][2], m[2][2]);
        
        if (Input::keyDown[KEY_LEFT] || Input::keyDown[KEY_J]){
            //            gameObject->getTransform()->move(-right*dt*keySensitivity);
            
            Vector3 rotation = gameObject->getTransform()->getEulerAngles();
            
            rotation += Vector3(0, 0.1, 0);
            float eightydeg = 15 * Math::DEG2RAD;
            if (rotation.x > eightydeg) rotation.x = eightydeg;
            if (rotation.x < -eightydeg) rotation.x = -eightydeg;
            
            gameObject->getTransform()->setLocalRotation(rotation);
        }
        if (Input::keyDown[KEY_RIGHT] || Input::keyDown[KEY_L]){
            //gameObject->getTransform()->move(right*dt*keySensitivity);
            Vector3 rotation = gameObject->getTransform()->getEulerAngles();
            
            rotation -= Vector3(0, 0.1, 0);
            float eightydeg = 15 * Math::DEG2RAD;
            if (rotation.x > eightydeg) rotation.x = eightydeg;
            if (rotation.x < -eightydeg) rotation.x = -eightydeg;
            
            gameObject->getTransform()->setLocalRotation(rotation);
        }
        if (Input::keyDown[KEY_UP] || Input::keyDown[KEY_K]){
            ike->walking(true);
            gameObject->getTransform()->move(-back*dt*keySensitivity);
        }
        if (Input::keyDown[KEY_DOWN] || Input::keyDown[KEY_I]){
            ike->walking(true);
            gameObject->getTransform()->move(back*dt*keySensitivity);
        }
    }
    
    //Method to resolve the actions of each keyUp event, following keyDown
    void JimmyController::keyUpResolve(float dt){
        
        
        
        if (!Input::keyDown[KEY_I]) {
            ike->walking(false);
        } else if (!Input::keyDown[KEY_I]){
            ike->walking(false);
        }
        
        if (!Input::keyDown[KEY_LEFT_SHIFT]){
            keySensitivity = KEY_SENSITIVITY_MIN;
        }
        
    }
}
