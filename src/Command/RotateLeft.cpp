/**
* @file RotateLeft.cpp
 * @brief Implements the RotateLeft command to rotate an image 90 degrees counterclockwise.
 */

#include "Command/RotateLeft.hpp"

namespace prog::command {

    /**
     * @brief Constructs a RotateLeft command.
     */
    RotateLeft::RotateLeft() : Command("rotate_left") {}

    /**
     * @brief Applies a 90-degree counterclockwise rotation to the given image.
     *
     * Creates a new image with swapped width and height, and maps each pixel
     * of the original image to its new rotated position.
     *
     * @param img Pointer to the image to rotate.
     * @return Pointer to the newly rotated image.
     */
    Image* RotateLeft::apply(Image* img) {
        int new_width = img->height();
        int new_height = img->width();
        Image* rotated = new Image(new_width, new_height, img->get_fill());

        for (int y = 0; y < img->height(); ++y) {
            for (int x = 0; x < img->width(); ++x) {
                // Rotate 90 degrees CCW by swapping coordinates and inverting x
                rotated->at(y, new_height - 1 - x) = img->at(x, y);
            }
        }

        delete img;
        return rotated;
    }

    /**
     * @brief Returns a string representation of the RotateLeft command.
     *
     * @return The command name as a string.
     */
    std::string RotateLeft::toString() const {
        return "rotate_left";
    }

}