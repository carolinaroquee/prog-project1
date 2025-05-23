/**
 * @file Resize.cpp
 * @brief Implements the Resize command to crop and resize an image to specified dimensions.
 */

#include "Command/Resize.hpp"
#include "Image.hpp"
#include <algorithm>

namespace prog {
    namespace command {

        /**
         * @brief Constructs a Resize command with position and size parameters.
         *
         * @param x The x-coordinate of the top-left corner of the cropping rectangle.
         * @param y The y-coordinate of the top-left corner of the cropping rectangle.
         * @param w The width of the resized image.
         * @param h The height of the resized image.
         */
        Resize::Resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), width_(w), height_(h) {}

        /**
         * @brief Applies the resize operation on the given image.
         *
         * Crops the image starting from (x_, y_) and copies pixels into a new image
         * with dimensions width_ x height_. Pixels outside the bounds of the original
         * image are ignored. The background fill color of the new image is set to the
         * original image's fill color.
         *
         * @param img Pointer to the image to resize.
         * @return Pointer to the new resized image.
         */
        Image* Resize::apply(Image* img) {
            Color fill = img->get_fill();

            Image* new_img = new Image(width_, height_, fill);

            int min_w = std::min(width_, img->width() - x_);
            int min_h = std::min(height_, img->height() - y_);

            for (int y = 0; y < min_h; ++y) {
                for (int x = 0; x < min_w; ++x) {
                    new_img->at(x, y) = img->at(x_ + x, y_ + y);
                }
            }

            delete img;

            return new_img;
        }

        /**
         * @brief Returns a string representation of the Resize command.
         *
         * @return Command string with parameters.
         */
        std::string Resize::toString() const {
            return "resize " + std::to_string(x_) + " " + std::to_string(y_) + " " + std::to_string(width_) + " " + std::to_string(height_);
        }

    } // namespace command
} // namespace prog
