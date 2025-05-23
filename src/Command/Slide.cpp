#include "Command/Slide.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        /**
         * @class Slide
         * @brief Command to slide (shift) an image horizontally and vertically with wrapping.
         */
        Slide::Slide(int x, int y)
           : Command("slide"), x_(x), y_(y) {}

        /**
         * @brief Applies the slide transformation to the given image.
         * 
         * Creates a new image with the same dimensions as the original,
         * shifting every pixel by x_ horizontally and y_ vertically.
         * Pixels shifted out on one edge wrap around to the other side.
         * 
         * @param img Pointer to the original image to transform.
         * @return Pointer to the new slid image. The original image is deleted.
         */
        Image *Slide::apply(Image *img) {
            Color fill = img->get_fill(); ///< Fill color for new image background.

            // Create a new image filled with the original image's background color
            Image* new_img = new Image(img->width(), img->height(), fill);

            // For every pixel in the original image, calculate its new position
            for (int x = 0; x < img->width(); x++) {
                for (int y = 0; y < img->height(); y++) {
                    // Calculate new position with wrapping using modulo operator
                    int new_x =  (x + x_) % img->width();
                    int new_y = (y + y_) % img->height();

                    // Copy pixel color to the new position
                    new_img->at(new_x, new_y) = img->at(x, y);
                }
            }

            delete img;  // Free the original image memory
            return new_img;
        }

    }
}