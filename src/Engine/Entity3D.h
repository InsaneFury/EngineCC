#ifndef ENTITY3D_H
#define ENTITY3D_H
#define EXPORTDLL _declspec(dllexport)
#include <iostream>
#include "glm/glm.hpp"
#include <vector>

struct Bounds
{
	float maxX = INT32_MIN;
	float maxY = INT32_MIN;
	float maxZ = INT32_MIN;
	float minX = INT32_MAX;
	float minY = INT32_MAX;
	float minZ = INT32_MAX;
};

struct VertexArray
{
	glm::vec3 actualVertexArray[8];
};

class EXPORTDLL Entity3D
{

private:
	static Entity3D* sceneRoot;

	friend class Model;
public:
	Entity3D();
	Entity3D(glm::vec3 position, Entity3D* parent, class Shader* shader);
	~Entity3D();

	//transformations
	void Rotate(float angle, glm::vec3 axis);
	void Translate(float value, glm::vec3 axis);
	void Scale(glm::vec3 scaleValues);
	void UpdateModelMatrix();
	virtual Bounds UpdateModelMatAndBoundingBox();
	void CalculateBounds(std::vector<glm::vec3> vertices);
	Bounds CombineBounds(Bounds bounds1, Bounds bounds2);
	Bounds GenerateBoundsByVertex(VertexArray vertexArray);
	Bounds GenerateBoundsByTransformedVertex(VertexArray vArray, glm::mat4 modelMatrix);
	virtual bool isBSPPlane() const;
	bool isVisible = true;

	//Set
	void SetPosition(glm::vec3 newPosition);
	void SetParent(Entity3D* parent);
	static void SetSceneRoot(Entity3D* root);
	void SetVisibility(bool visible);
	void SetColliderVisibility(bool visibility);
	
	//Get
	inline glm::mat4 GetModel() {return worldModel;}
	inline Entity3D* GetParent() {return parent;}
	inline std::vector<Entity3D*>& GetChilds() {return childs;}
	inline virtual Shader* GetShader() {return shader;}
	inline virtual std::string GetName() { return name; }
	inline virtual std::string GetTag() { return tag; }
	virtual Entity3D* GetNode(std::string node);
	class BoundingBox* GetBoundingBox();
	virtual void GetVertexPositions(std::vector<glm::vec3>& vertexVector) { return; }
	bool GetColliderVisibility() const;


protected:
	glm::vec3 position;
	glm::vec3 scale;
	glm::mat4 localModel;
	glm::mat4 worldModel;
	std::string name;
	std::string tag = "obj";
	Entity3D* parent;
	std::vector<Entity3D*> childs;
	Shader* shader;
	BoundingBox* regenerativeAABB;
	BoundingBox* staticBoundingBox;
	Bounds bounds;

};

#endif