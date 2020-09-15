#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#define EXPORTDLL _declspec(dllexport)

#include <glm/glm.hpp>

#include <vector>
#include "Entity3D.h"

#define	BOXVERTICES 8

class EXPORTDLL BoundingBox
{
private:
	glm::vec3 vertex[BOXVERTICES];
	static class Shader* shader;
	unsigned int VAO, VBO, EBO;
	std::vector<unsigned int> indices;
	bool isVisible = false;
	Bounds actualBounds;

public:
	BoundingBox();
	void CalculateBoundingBox(Bounds bounds);
	void CreateBuffers();
	void Setup();
	void Draw(glm::mat4 viewMat, glm::mat4 projMat);
	void SetVisibility(bool visibility) { isVisible = visibility; }
	inline const bool GetVisibility() { return isVisible; }
	inline glm::vec3 GetVertex(unsigned int index) {return vertex[index];}
	inline glm::vec3 GetMinP() {return glm::vec3{ actualBounds.minX, actualBounds.minY, actualBounds.minZ };}
	inline glm::vec3 GetMaxP() {return glm::vec3{ actualBounds.maxX, actualBounds.maxY, actualBounds.maxZ };}
	static VertexArray GetBoxVertices(Bounds bounds);
};

#endif