#ifndef CLASS_PLANET
#define CLASS_PLANET

class SpaceObject
{

private:
	double radius; //радиус
	double distance; //расстояние от солнца
	double orbit; //орбита 
	double speedOrbit; //скорость движения по орбите
	double axisTilt; //угол наклона
	double axisAni; //угол поворота (изначально 0)

public:

	double mass; //масса
	SpaceObject(double _radius, double _distance, double _orbit, double _speedOrbit, double _axisTilt, double _axisAni, double _mass);

	void drawSmallOrbit(void);
	void string_sonvertMoons(void* font, char* string);
	void drawMoon(char* str, int activeLabel);

	double getRadius();
	double getDistance();
	double getOrbit();
	double getSpeedOrbit();
	double getAxisTilt();
	double getAxisAni();
	double getMass();

	void setDistance(double d);
	void setOrbit(double o, int index);
	void setAxisAni(double aa, int index);

	void resetForComet();

	void glutWireTorusAll();

	void oneLoop();
	void oneLoopOurAxis();

	//void Info(string s);

};
#endif
