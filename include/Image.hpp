#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>

using namespace std;

namespace prog {
    /**
     * @brief Class representing an image composed of a 2D matrix of Colors.
     */
    class Image {
    private:
        int width_;                       ///< Width of the image in pixels
        int height_;                      ///< Height of the image in pixels
        vector<vector<Color>> color_matrix_; ///< 2D matrix storing the color of each pixel
        Color fill_;                      ///< Default fill color used during initialization

    public:
        /**
         * @brief Constructs an Image of given width and height, optionally filled with a color.
         *
         * @param w Width of the image
         * @param h Height of the image
         * @param fill Color to fill the image pixels with (default is white)
         */
        Image(int w, int h, const Color &fill = {255, 255, 255});

        /**
         * @brief Destructor for Image.
         */
        ~Image();

        /**
         * @brief Returns the width of the image.
         * @return int Width in pixels.
         */
        int width() const;

        /**
         * @brief Returns the height of the image.
         * @return int Height in pixels.
         */
        int height() const;

        /**
         * @brief Returns a reference to the Color at pixel (x, y).
         *
         * Allows modification of the pixel color.
         *
         * @param x X-coordinate (column index)
         * @param y Y-coordinate (row index)
         * @return Color& Reference to the pixel color.
         */
        Color &at(int x, int y);

        /**
         * @brief Returns a const reference to the Color at pixel (x, y).
         *
         * Does not allow modification.
         *
         * @param x X-coordinate (column index)
         * @param y Y-coordinate (row index)
         * @return const Color& Const reference to the pixel color.
         */
        const Color &at(int x, int y) const;

        /**
         * @brief Returns the fill color used to initialize the image.
         * @return Color The fill color.
         */
        Color get_fill() const;
    };
}

#endif
