/**
* @file Move.cpp
 * @brief Implements the Move command that shifts the image pixels by a given offset.
 */

#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Constructs the Move command with the specified x and y offsets.
         *
         * @param x Horizontal shift amount.
         * @param y Vertical shift amount.
         */
        Move::Move(int x, int y)
            : Command("move"), x_(x), y_(y) {}

        /**
         * @brief Applies the move transformation to the image.
         *
         * This shifts each pixel by the specified (x_, y_) offset. Pixels shifted outside
         * the image bounds are discarded. The resulting image is filled with the original
         * image's fill color where no pixel is copied.
         *
         * @param img Pointer to the original image. It will be deleted.
         * @return A new image with the pixels moved accordingly.
         */
        Image* Move::apply(Image* img) {
            Color fill = img->get_fill();

            // Create a new image with the same dimensions and fill color
            Image* new_img = new Image(img->width(), img->height(), fill);

            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    int new_x = x + x_;
                    int new_y = y + y_;

                    // Copy pixel if within bounds
                    if (new_x >= 0 && new_x < img->width() && new_y >= 0 && new_y < img->height()) {
                        new_img->at(new_x, new_y) = img->at(x, y);
                    }
                }
            }

            delete img;  // Delete original image
            return new_img;
        }

    } // namespace command
} // namespace prog