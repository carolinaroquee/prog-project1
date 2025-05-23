#include "Image.hpp"
#include <iostream>
#include <cassert>

using namespace std;

namespace prog {

    /**
     * @class Image
     * @brief Represents an image as a 2D matrix of Colors.
     */

    /**
     * @brief Constructs an Image of given width and height, initialized with a fill color.
     * @param w Width of the image in pixels.
     * @param h Height of the image in pixels.
     * @param fill The color to initialize all pixels with.
     */
    Image::Image(int w, int h, const Color &fill)
        : width_(w),
          height_(h),
          color_matrix_(h, vector<Color>(w, fill)),  ///< 2D vector: h rows, each with w Colors initialized to fill
          fill_(fill) {}

    /**
     * @brief Destructor for the Image class.
     */
    Image::~Image() {
    }

    /**
     * @brief Returns the width of the image.
     * @return Width (number of pixels horizontally).
     */
    int Image::width() const {
        return width_;
    }

    /**
     * @brief Returns the height of the image.
     * @return Height (number of pixels vertically).
     */
    int Image::height() const {
        return height_;
    }

    /**
     * @brief Returns the fill color of the image.
     * @return The fill Color used to initialize the image.
     */
    Color Image::get_fill() const {
        return fill_;
    }

    /**
     * @brief Provides non-const access to the pixel color at (x, y).
     * @param x X coordinate (column).
     * @param y Y coordinate (row).
     * @return Reference to the Color at the specified pixel.
     * @note Asserts if x or y are out of bounds.
     */
    Color &Image::at(int x, int y) {
        assert(x >= 0 && x < width_);
        assert(y >= 0 && y < height_);
        return color_matrix_[y][x];
    }

    /**
     * @brief Provides const access to the pixel color at (x, y).
     * @param x X coordinate (column).
     * @param y Y coordinate (row).
     * @return Const reference to the Color at the specified pixel.
     * @note Asserts if x or y are out of bounds.
     */
    const Color &Image::at(int x, int y) const {
        assert(x >= 0 && x < width_);
        assert(y >= 0 && y < height_);
        return color_matrix_[y][x];
    }

} // namespace prog