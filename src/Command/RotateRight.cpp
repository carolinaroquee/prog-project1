/**
* @file RotateRight.cpp
 * @brief Implements the RotateRight command to rotate an image 90 degrees clockwise.
 */

#include "Command/RotateRight.hpp"

namespace prog::command {

    /**
     * @brief Constructs a RotateRight command.
     */
    RotateRight::RotateRight() : Command("rotate_right") {}

    /**
     * @brief Applies a 90-degree clockwise rotation to the given image.
     *
     * Creates a new image with swapped width and height, and maps each pixel
     * of the original image to its new rotated position.
     *
     * @param img Pointer to the image to rotate.
     * @return Pointer to the newly rotated image.
     */
    Image* RotateRight::apply(Image* img) {
        int new_width = img->height();
        int new_height = img->width();
        Image* rotated = new Image(new_width, new_height, img->get_fill());

        for (int y = 0; y < img->height(); ++y) {
            for (int x = 0; x < img->width(); ++x) {
                // Rotate 90 degrees CW by swapping coordinates and inverting y
                rotated->at(new_width - 1 - y, x) = img->at(x, y);
            }
        }

        delete img;
        return rotated;
    }

    /**
     * @brief Returns a string representation of the RotateRight command.
     *
     * @return The command name as a string.
     */
    std::string RotateRight::toString() const {
        return "rotate_right";
    }

}
