#ifndef CAMERA_H
#define CAMERA_H
#define EXPORTDLL _declspec(dllexport)

#include "glm/glm.hpp"

class EXPORTDLL Camera
{
private:
	float yaw;
	float pitch;
	glm::mat4 viewMatrix;
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 upVector;
	glm::vec3 worldUp;
	glm::vec3 rightVector;
public:
	Camera(glm::vec3 _position, glm::vec3 up, glm::vec3 _direction, float _yaw, float _pitch);
	~Camera();
	void Update();
	void RotatePitch(float angle);
	void RotateYaw(float angle);
	void Translate(glm::vec3 translationVector);
	inline glm::vec3 GetPosition() {return position;}
	inline glm::vec3 GetRightVector() {return rightVector;}
	inline glm::vec3 GetDirection() {return direction;}
	inline glm::mat4 GetViewMatrix() {return viewMatrix;}

};
#endif