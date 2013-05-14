
// TIL: #pragma once can be used instead of include guards.

#include "Image.h"

// Part 2: The Image Class
// Part 2-a: implement the constructor for the Image class.

Image::Image(unsigned int width, unsigned int height)
	: width(width)
	, height(height) {
		data = new unsigned char[width*height*3]();
		//According to stackoverflow, the paranthesis will initialize all values in the array
	}

// Part 2-b: implement the destructor
Image::~Image() {
	if (data != 0)
		delete data;
}

// Part 2-c: Implement GetWidth() and GetHeight()
// The 'const' at the end of the function declaration means they
// don't alter any member variables.
unsigned int Image::GetHeight() const {
	return this->height;
}
// const should be used here because non-const member functions
// can't be called from within a const member function.
// But it's also because it makes the code self-documenting.
unsigned int Image::GetWidth() const {
	return this->width;
}

// Part 2-d: get.dat.data();
// wait, do we have to do anything specific within the function body in order
// to return a pointer?
// Answer: we do not.
const unsigned char *Image::GetData() const {
	return this->data;
}
unsigned char *Image::GetData() {
	return this->data;
}

// Part 2-e: implement SetColor()
//first we must find zhe position
unsigned int Image::getPos(unsigned int x, unsigned int y) const {
	// (y*width + x)*3
	return (y*width + x)*3;
}
void Image::SetColor(unsigned int x, unsigned int y, const Color &color) {
	unsigned int pos = this->getPos(x, y);
	this->data[pos] = color.red;
	this->data[pos+1] = color.green;
	this->data[pos+2] =	color.blue;
}

// Part 2-f: implement getColor()
Color Image::GetColor(unsigned int x, unsigned int y) const {
	unsigned int pos = this->getPos(x, y);
	//Color res = Color(this->data[pos], this->data[++pos], this->data[++pos]);
	//this results in red and green == blue (red and green get the same value as blue)
	//Color res = Color(this->data[pos++], this->data[pos++], this->data[pos]);
	//this mixes up green and blue
	Color res = Color(this->data[pos], this->data[pos+1], this->data[pos+2]);
	//this works
	/*Color res;
	res.red = this->data[pos++];
	res.green = this->data[pos++];
	res.blue = this->data[pos];*/
	//this also works. >:)
	return res;
}

// Part 2-g: implement Fill()
void Image::Fill(const Color &color) {
	for (unsigned int x = 0; x < this->GetWidth(); x++) {
		for (unsigned int y = 0; y < this->GetHeight(); y++) {
			this->SetColor(x, y, color);
		}
	}
}
