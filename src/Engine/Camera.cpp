#include "Camera.h"

#include "glm/gtc/matrix_transform.hpp"

using namespace glm;

Camera::Camera(vec3 _position, vec3 up, vec3 _direction, float _yaw, float _pitch)
	:
	position(_position),
	upVector(up),
	worldUp(up),
	direction(_direction),
	yaw(_yaw),
	pitch(_pitch)
{
	rightVector = glm::normalize(glm::cross(up, direction));
	upVector = glm::cross(direction, rightVector);
	viewMatrix = lookAt(position, position + direction, upVector);
}


Camera::~Camera()
{
}

void Camera::Update() 
{
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction = glm::normalize(front);

	rightVector = glm::normalize(glm::cross(direction, worldUp));
	upVector = glm::normalize(glm::cross(rightVector, direction));

	viewMatrix = lookAt(position, position + direction, upVector);
}

void  Camera::RotatePitch(float angle) 
{
	pitch += angle;
}

void  Camera::RotateYaw(float angle) 
{
	yaw += angle;
}

void  Camera::Translate(glm::vec3 translationVector)
{
	position += translationVector;
}
