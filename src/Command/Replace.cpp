/**
* @file Replace.cpp
 * @brief Implements the Replace command to substitute one color with another in an image.
 */

#include "Command/Replace.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Constructs the Replace command with the source and target colors.
         *
         * @param c1 The color to be replaced.
         * @param c2 The color to replace with.
         */
        Replace::Replace(Color c1, Color c2) : Command("replace"), c1_(c1), c2_(c2) {}

        /**
         * @brief Applies the replace operation on the given image.
         *
         * Iterates through all pixels in the image and replaces any pixel matching
         * color c1_ with color c2_.
         *
         * @param img Pointer to the image to be modified.
         * @return Pointer to the modified image.
         */
        Image* Replace::apply(Image* img) {
            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    Color& point = img->at(x, y);
                    if (point.red() == c1_.red() &&
                        point.green() == c1_.green() &&
                        point.blue() == c1_.blue()) {
                        point = c2_;
                        }
                }
            }
            return img;
        }

    } // namespace command
} // namespace prog