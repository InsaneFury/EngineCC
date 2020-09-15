#ifndef FRUSTUM_H
#define FRUSTUM_H
#include <glm/matrix.hpp>

#define EXPORTDLL _declspec(dllexport)

class EXPORTDLL Frustum
{
private:
	enum Planes
	{
		Left = 0,
		Right,
		Bottom,
		Top,
		Near,
		Far,
		Count,
		Combinations = Count * (Count - 1) / 2
	};

	template<Planes i, Planes j>
	struct ij2k
	{
		enum { k = i * (9 - i) / 2 + j - 1 };
	};

	template<Planes a, Planes b, Planes c>
	glm::vec3 intersection(const glm::vec3* crosses) const;

	glm::vec4   m_planes[Count];
	glm::vec3   m_points[8];
public:
	Frustum();
	Frustum(glm::mat4 m);
	bool IsBoxVisible(const glm::vec3& minp, const glm::vec3& maxp) const;


};
#endif