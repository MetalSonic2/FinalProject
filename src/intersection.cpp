#include <intersection.h>
#include <glm/glm.hpp>

bool Plane_Plane(Face P1, Face P2)
{
	Ray r[4];

	r[0].pos = P1.A;
	r[0].dir = glm::normalize(P1.B - P1.A);

	r[1].pos = P1.B;
	r[1].dir = glm::normalize(P1.D - P1.B);

	r[2].pos = P1.D;
	r[2].dir = glm::normalize(P1.C - P1.D);

	r[3].pos = P1.C;
	r[3].dir = glm::normalize(P1.A - P1.C);

	for (Ray _r : r)
	{
		if(Ray_Face_intersect(_r, P2)) return true;
	}

	r[0].pos = P2.A;
	r[0].dir = glm::normalize(P2.B - P2.A);

	r[1].pos = P2.B;
	r[1].dir = glm::normalize(P2.D - P2.B);

	r[2].pos = P2.D;
	r[2].dir = glm::normalize(P2.C - P2.D);

	r[3].pos = P2.C;
	r[3].dir = glm::normalize(P2.A - P2.C);

	for (Ray _r : r)
	{
		if (Ray_Face_intersect(_r, P1)) return true;
	}

	return false;
}

bool Box_Plane(Hitbox box, Face plane)
{
	for (Face face : box.faces)
	{
		if (Plane_Plane(face, plane)) return true;
	}

	return false;
}