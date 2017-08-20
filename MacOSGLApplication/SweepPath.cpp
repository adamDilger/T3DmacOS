#include "SweepPath.h"
#include <math.h>

namespace T3D{

	SweepPath::SweepPath(void)
	{
	}


	SweepPath::~SweepPath(void)
	{
	}

	Transform SweepPath::operator[](int index) const{
		return path[index];
	}

	void SweepPath::addTransform(Transform &t){
		path.push_back(t);
	}

	void SweepPath::makeCirclePath(float radius, int density){
		path.clear();
		for (int i=0; i<density; i++){
			Transform t;
			float angle = Math::TWO_PI*i/density;
			t.setLocalPosition(Vector3(radius*cosf(angle),0,radius*sinf(angle)));
			
            //TODO check this change works properly
            //t.setLocalRotation(Quaternion(Vector3(0,-angle,0)));
            t.setLocalRotation(*new Quaternion(Vector3(0,-angle,0)));
			path.push_back(t);
		}
	}
    
    void SweepPath::addPoint(Vector3 pos, Quaternion rot) {
        Transform t;
        t.setLocalPosition(pos);
        
        t.setLocalRotation(rot);
        path.push_back(t);
    }

}
