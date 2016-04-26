// Brendan O'Connor
// 2/15/16
// Lab #4

#ifndef POINT_H
#define POINT_H


// Define your class here
class Point {
public:
	Point();
	void setCoordinates(double x,double y,double z);
	double calcDistance();
	double calcDistance(Point p);

	
private:
	double m_x;
	double m_y;
	double m_z;
};

#endif