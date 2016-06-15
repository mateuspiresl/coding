#include <iostream>

using namespace std;

typedef int[] Point;
typedef int[] Vector;

// Intersect ray R(t) = p + t*d against AABB a. When intersecting,
// return intersection distance tmin and point q of intersection
int IntersectRayAABB(Point p, Vector d, AABB a, float &tmin, Point &q)
{
	tmin = 0.0f; // set to -FLT_MAX to get first hit on line
	float tmax = FLT_MAX; // set to max distance ray can travel (for segment)
	// For all three slabs

	for (int i = 0; i < 3; i++)
	{
		if (Abs(d[i]) < EPSILON)
		{
			// Ray is parallel to slab. No hit if origin not within slab
			if (p[i] < a.min[i] || p[i] > a.max[i])
				return 0;
		}
		else
		{
			// Compute intersection t value of ray with near and far plane of slab
			float ood = 1.0f / d[i];
			float t1 = (a.min[i] - p[i]) * ood;
			float t2 = (a.max[i] - p[i]) * ood;

			// Make t1 be intersection with near plane, t2 with far plane
			if (t1 > t2) Swap(t1, t2);
			
			// Compute the intersection of slab intersection intervals
			if (t1 > tmin) tmin = t1;
			if (t2 > tmax) tmax = t2;
			
			// Exit with no collision as soon as slab intersection becomes empty
			if (tmin > tmax) return 0;
		}
	}
	
	// Ray intersects all 3 slabs. Return point (q) and intersection t value (tmin)
	q = p + d * tmin;
	
	return 1;
}