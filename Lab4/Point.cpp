// Brendan O'Connor
// 2/15/16
// Lab #4

#include <cmath>
#include "Point.h"

using namespace std;

// Constructor function to initialize coordinates to 0,0,0
Point::Point() {
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

// Set the point coordinates to the arguments passed 
void Point::setCoordinates(double x, double y, double z) {
	m_x = x;
	m_y = y;
	m_z = z;
}

// Calculate the distance between the point and the origin (0,0,0)
double Point::calcDistance() {
	double dxsq;
	double dysq;
	double dzsq;
	double dist;

	// since this is distance from origin change of each point will be equal to the point
	dxsq = m_x * m_x;
	dysq = m_y * m_y;
	dzsq = m_z * m_z;

	// calculate the distance
	dist = sqrt(dxsq + dysq + dzsq);

	return dist;
}

// Calculate the distance between this point and the point passed as an argument
double Point::calcDistance(Point p) {
	double dxsq;
	double dysq;
	double dzsq;
	double dist;

	dxsq = (m_x - p.m_x) * (m_x - p.m_x);
	dysq = (m_y - p.m_y) * (m_y - p.m_y);
	dzsq = (m_z - p.m_z) * (m_z - p.m_z);

	// calculate the distance
	dist = sqrt(dxsq + dysq + dzsq);

	return dist;
}