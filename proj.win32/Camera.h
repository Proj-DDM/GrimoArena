#ifndef CAMERA_H
#define CAMERA_H

#include "Common.h"

NS_BEGIN(Util)

class Camera : public Node
{
public:
	CREATE_FUNC(Camera);

public:
	Camera();
	~Camera();

	bool init();


private:

};

NS_END
#endif //end_of Camera.h