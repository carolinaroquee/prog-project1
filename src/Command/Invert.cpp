/**
* @file Invert.cpp
 * @brief Implements the Invert command that inverts the colors of an image.
 */

#include "Command/Invert.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Constructs the Invert command.
         *
         * Initializes the command with the name "invert".
         */
        Invert::Invert() : Command("invert") {}

        /**
         * @brief Applies color inversion to every pixel in the image.
         *
         * Each pixel's red, green, and blue components are replaced by their inverse values
         * (i.e., 255 - original value).
         *
         * @param img Pointer to the image to be modified.
         * @return The modified image with inverted colors.
         */
        Image* Invert::apply(Image* img) {
            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    Color& point = img->at(x, y);
                    point.red()   = 255 - point.red();
                    point.green() = 255 - point.green();
                    point.blue()  = 255 - point.blue();
                }
            }
            return img;
        }

    } // namespace command
} // namespace prog