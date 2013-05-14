#include "Image.h"
#include <iostream>

void testImageFunctionality();

int main() {

	// Part 2-h: use the SaveImage function.
	Color fuchsia = Color(193, 84, 193);
	Image test = Image(10,10);
	test.Fill(fuchsia);
	test.SetColor(5,5, Color(255, 255, 255));
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