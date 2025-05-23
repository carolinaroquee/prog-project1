/**
* @file Fill.cpp
 * @brief Implements the Fill command, which fills a rectangular region in the image with a color.
 */

#include "Command/Fill.hpp"

namespace prog {

    namespace command {

        /**
         * @brief Constructs a Fill command.
         *
         * This command fills a rectangular area starting from (x, y) with width `w` and height `h`
         * using the specified fill color.
         *
         * @param x X-coordinate of the top-left corner of the fill area.
         * @param y Y-coordinate of the top-left corner of the fill area.
         * @param w Width of the rectangle to fill.
         * @param h Height of the rectangle to fill.
         * @param fill The color to fill the rectangle with.
         */
        Fill::Fill(int x, int y, int w, int h, Color fill)
           : Command("fill"), x_(x), y_(y), w_(w), h_(h), fill_(fill) {}

        /**
         * @brief Applies the Fill command to the image.
         *
         * Modifies the original image by filling the specified rectangular area with a given color.
         * If the area extends outside the image bounds, only the overlapping region is filled.
         *
         * @param img Pointer to the image to be modified.
         * @return The modified image.
         */
        Image *Fill::apply(Image *img) {
            for (int y = y_; y < y_ + h_; y++) {
                for (int x = x_; x < x_ + w_; x++) {
                    // Check if the pixel is within the bounds of the image
                    if (x >= 0 && x < img->width() && y >= 0 && y < img->height()) {
                        img->at(x, y) = fill_;
                    }
                }
            }
            return img;
        }

    } // namespace command

} // namespace prog