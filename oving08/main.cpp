#include "handout\Image.h"
#include "Shape.h"
#include <iostream>

void testImageFunctionality();

int main() {

	// Part 2-h: use the SaveImage function.
	Color fuchsia = Color(193, 84, 193);
	Image test = Image(100,100);
	test.Fill(fuchsia);
	test.SetColor(0, 0, Color(255, 255, 255));

	Color black = Color(0, 0, 0);
	// testing line
	Line line = Line(Coord(0, 0), Coord(50, 100), black);
	//line.Draw(test);
	Line li = Line(Coord(20, 33), Coord(60, 90), black);
	//li.Draw(test);
	Line lid = Line(Coord(80, 60), Coord(0, 50), black);
	//lid.Draw(test);
	Line lie = Line(Coord(60, 88), Coord(100, 5), black);
	lie.Draw(test);

	SaveImage(test, "imageyo.bmp");
	std::cin.get();
}

void testImageFunctionality() {
	Image yo = Image(10, 10);
	unsigned int r = 120, g = 233, b = 86;
	Color test = Color(r, g, b);
	yo.SetColor(9, 9, test);
	printf("Setting 9,9 to %i, %i, %i", r, g, b);
	printf("test\tyo5,5\n");
	Color unfh = Color(yo.GetColor(9,9));
	printf("%i\t%i\n", test.red, unfh.red);
	printf("%i\t%i\n", test.green, unfh.green);
	printf("%i\t%i\n", test.blue, unfh.blue);

	r = 77, g = 100, b = 121;
	printf("\nFilling the 10x10 Image with %i, %i, %i\n", r, g, b);
	yo.Fill(Color(r,g,b));
	for (unsigned int x = 0; x < yo.GetWidth(); x++) {
		for (unsigned int y = 0; y < yo.GetHeight(); y++) {
			Color col = yo.GetColor(x, y);
			if (col.red != r || col.green != g || col.blue != b) {
				printf("Color mismatch at (%i, %i):\n", x, y);
				printf("%i\t%i\n", col.red, r);
				printf("%i\t%i\n", col.green, g);
				printf("%i\t%i\n", col.blue, b);
			}
		}
	}	
}
