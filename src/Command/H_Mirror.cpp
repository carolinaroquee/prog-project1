/**
* @file H_Mirror.cpp
 * @brief Implements the H_Mirror command that mirrors the image horizontally.
 */

#include "Command/H_Mirror.hpp"

namespace prog {

    namespace command {

        /**
         * @brief Constructs the H_Mirror command.
         *
         * The command name is set to "h_mirror".
         */
        H_Mirror::H_Mirror() : Command("h_mirror") {}

        /**
         * @brief Applies the horizontal mirror transformation to the image.
         *
         * This operation swaps pixels horizontally so that the image appears mirrored along the vertical axis.
         *
         * @param img Pointer to the image to be modified.
         * @return The modified image after applying horizontal mirror.
         */
        Image *H_Mirror::apply(Image *img) {
            for (int y = 0; y < img->height(); ++y) {
                for (int x = 0; x < img->width() / 2; ++x) {
                    Color& left = img->at(x, y);
                    Color& right = img->at(img->width() - 1 - x, y);
                    swap(left, right);
                }
            }
            return img;
        }

    } // namespace command

} // namespace prog
