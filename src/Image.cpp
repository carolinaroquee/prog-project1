#include "Image.hpp"
#include <iostream>
#include <cassert>
using namespace std;
namespace prog {
    Image::Image(int w, int h, const Color &fill) : width_(w),
    height_(h), color_matrix_(h, vector<Color>(w, fill)), fill_(fill){}
    //vector<Color>(w, fill) - vetor com w elementos, todos com a cor fill, vetor com h elementos, cada elemento com size w
    Image::~Image() {
    }

    int Image::width() const {
        return width_;
    }

    int Image::height() const {
        return height_;
    }

    Color Image::get_fill() const {
        return fill_;
    }


    Color &Image::at(int x, int y) {
        assert(x >= 0 && x < width_);
        assert(y >= 0 && y < height_);
        return color_matrix_[y][x];
    }

    const Color &Image::at(int x, int y) const {
        assert(x >= 0 && x < width_);
        assert(y >= 0 && y < height_);
        return color_matrix_[y][x];
    }


}
