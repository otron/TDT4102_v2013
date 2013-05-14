#include "handout\Image.h"

// Part 3: an abstract class representing shapes
class Shape {
private:
	Color color; //the color of the beast

public:
	Color GetColor() const { return this->color; } //grab that color and run.
	Shape(const Color &color);
	Shape(); //default constructor should probably just set the color to 0x000000

	// Part 3-c: pure virtuality
	// A pure virtual function is required to be implemented
	// by all classes derived from the class containing it.
	// An abstract class is defined as a class containing one or more pure
	// virtual functions (in C++). We cannot initialize an instance of an abstract class.
	virtual void Draw(Image &img) const = 0;
	// pure virtuality is indicated by the = 0 postfixing the function declaration

};

struct Coord {
	// simple struct to hold two unsigned integers representing a single point
	// on a grid
	Coord(unsigned int x, unsigned int y) : x(x), y(y) {}
	Coord() : x(0), y(0) {}
	unsigned int x, y;
};

// Part 4: Line segments.
class Line : public Shape {
private:
	unsigned int startx, starty, endx, endy;

public:
	Line(const Coord &pointOne, const Coord &pointTwo, const Color &color);
	virtual void Draw(Image &img) const;
};