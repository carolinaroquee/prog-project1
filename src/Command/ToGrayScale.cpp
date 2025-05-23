#include "Command/ToGrayScale.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        /**
         * @class ToGrayScale
         * @brief Command to convert an image to grayscale.
         */
        ToGrayScale :: ToGrayScale() : Command("to_gray_scale") {}

        /**
         * @brief Applies grayscale conversion to the image.
         * 
         * For each pixel, computes the average of the red, green, and blue
         * color channels, then sets all three channels to that average value.
         * This effectively converts the image to shades of gray.
         * 
         * @param img Pointer to the image to convert.
         * @return Pointer to the modified grayscale image (same image object).
         */
        Image *ToGrayScale::apply(Image *img) {

            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    Color& point = img->at(x, y);

                    // Calculate the average of RGB components
                    rgb_value v = (point.red() + point.green() + point.blue()) / 3;

                    // Set all channels to the average value for grayscale
                    point.red() = v;
                    point.green() = v;
                    point.blue() = v;
                }
            }
            return img;
        }
    }
}
