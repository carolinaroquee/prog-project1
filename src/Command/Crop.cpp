/**
 * @file Crop.cpp
 * @brief Implements the Crop command, which crops a rectangular region from an image.
 */

#include "Command/Crop.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Constructs a Crop command.
         *
         * This command crops the image to a rectangular region defined by top-left corner (x, y)
         * and size (w, h). Any part of the crop rectangle outside the image bounds is ignored.
         *
         * @param x X-coordinate of the top-left corner of the crop region.
         * @param y Y-coordinate of the top-left corner of the crop region.
         * @param w Width of the crop region.
         * @param h Height of the crop region.
         */
        Crop::Crop(int x, int y, int w, int h)
            : Command("crop"), x(x), y(y), w(w), h(h) {}

        /**
         * @brief Applies the Crop command to the image.
         *
         * Creates a new image containing only the pixels in the specified crop region.
         * If the crop region is fully outside the bounds, returns a 1x1 image.
         *
         * @param img The original image to crop.
         * @return A new image containing only the cropped region.
         */
        Image *Crop::apply(Image *img) {
            // Clamp crop region to image bounds
            int x_end = std::min(x + w, img->width());
            int y_end = std::min(y + h, img->height());

            int x_start = std::max(0, x);
            int y_start = std::max(0, y);

            int new_width = x_end - x_start;
            int new_height = y_end - y_start;

            // If crop region is invalid or outside bounds, return a 1x1 blank image
            if (new_width <= 0 || new_height <= 0) {
                delete img;
                return new Image(1, 1);
            }

            Image *cropped = new Image(new_width, new_height);

            // Copy cropped region into the new image
            for (int j = 0; j < new_height; ++j) {
                for (int i = 0; i < new_width; ++i) {
                    cropped->at(i, j) = img->at(x_start + i, y_start + j);
                }
            }

            delete img;  ///< Dispose of the original image
            return cropped;
        }

    } // namespace command
} // namespace prog