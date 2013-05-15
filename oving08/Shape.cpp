#include "Shape.h"
#include <cmath> // sqrt
#include <cstdlib> // min and max

using namespace std;

Shape::Shape()
	: color(Color(0, 0, 0)) { }

Shape::Shape(const Color &color)
	: color(color) { }


// Part 4
Line::Line(const Coord &pointOne, const Coord &pointTwo, const Color &color)
	: Shape(color) { //That's how you call the super-constructor.
	if (pointOne.x < pointTwo.x) {
		startx = pointOne.x;
		starty = pointOne.y;
		endx = pointTwo.x;
		endy = pointTwo.y;
	} else {
		startx = pointTwo.x;
		starty = pointTwo.y;
		endx = pointOne.x;
		endy = pointOne.y;
	}
}

void Line::Draw(Image &img) const {
	// wait what's a gradient? Oh right a slope.
	// damn my math is getting rusty.
	float gradient = static_cast<float>(endy - starty) / (endx - startx);

	/*
		y = gradient(x-x_1)+y1
		x = (1/gradient)*(y-y_1)+x1
	*/
	// Line's constructor always sets startx to the smallest x
	// however, we can make no assumptions about min(starty, endy)
	//...although we kind of do, I'm just too lazy to fix it.
	unsigned int y1 = min(starty, endy);
	unsigned int y2 = max(starty, endy);
	if (gradient < 1.0f) { //draw along the x-axis
		unsigned int y = y1;
		for (unsigned int x = startx;
			x < endx+1 && x < img.GetWidth() &&
			y < img.GetHeight() && y < y2;
		 	x++) {
			y = gradient*(x-startx)+y1;
			img.SetColor(x, y, GetColor());
		}
	} else { //draw along the y-axis
		gradient = static_cast<float>(endx - startx) / (endy - starty);
		unsigned int x = startx;
		if (starty < endy) {
			for (unsigned int y = starty;
			y < endy+1 && y < img.GetHeight() &&
			x < img.GetWidth() && x < endx;
			y++) {
				x = (gradient)*(y-starty)+startx;
				// there's no risk of dividing by 0 as if gradient == 0 then gradient < 1.0f is true.
				img.SetColor(x, y, GetColor());
			}
		} else {
			for (unsigned int y = endy;
			y < starty+1 && y < img.GetHeight() &&
			x < img.GetWidth() && x < endx;
			y++) {
				x = (gradient)*(y-endy)+startx;
				// there's no risk of dividing by 0 as if gradient == 0 then gradient < 1.0f is true.
				img.SetColor(x, y, GetColor());
			}
		}
	}
}