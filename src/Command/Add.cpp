
/**
 * @file Add.cpp
 * @brief Implements the Add command that overlays a secondary image onto the main image.
 */

#include "Command/Add.hpp"
#include "PNG.hpp"  ///< Used to read PNG images

namespace prog {
    namespace command {

        /**
         * @brief Constructs the Add command.
         *
         * This command overlays another image (loaded from a PNG file) onto the target image.
         * Pixels in the overlay image that match the neutral color are treated as transparent.
         *
         * @param filename The path to the PNG file to overlay.
         * @param neutro The "neutral" color (treated as transparent).
         * @param x The X coordinate offset at which to place the overlay.
         * @param y The Y coordinate offset at which to place the overlay.
         */
        Add::Add(const std::string& filename, Color neutro, int x, int y)
            : Command("add"), filename_(filename), neutro_(neutro), x_(x), y_(y) {}

        /**
         * @brief Applies the Add command to the image.
         *
         * Loads the specified PNG file and overlays it onto the given image at position (x, y).
         * Pixels from the overlay image that match the neutral color are ignored.
         * Pixels that fall outside the bounds of the base image are not written.
         *
         * @param img The base image to apply the overlay to.
         * @return The modified image with the overlay applied.
         */
        Image *Add::apply(Image *img) {
            Image* new_img = loadFromPNG(filename_); ///< Loads the overlay image from file

            for (int y1 = 0; y1 < new_img->height(); y1++) {
                for (int x1 = 0; x1 < new_img->width(); x1++) {
                    const Color& point = new_img->at(x1, y1);

                    // Skip neutral-colored pixels (treated as transparent)
                    if (point.red() == neutro_.red() &&
                        point.green() == neutro_.green() &&
                        point.blue() == neutro_.blue()) {
                        continue;
                    }

                    int distX = x_ + x1;
                    int distY = y_ + y1;

                    // Only draw if within bounds
                    if (distX >= 0 && distX < img->width() &&
                        distY >= 0 && distY < img->height()) {
                        img->at(distX, distY) = point;
                    }
                }
            }

            delete new_img; ///< Clean up dynamically allocated overlay image
            return img;
        }

    } // namespace command
} // namespace prog