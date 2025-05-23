#include "Command/Scaleup.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Construct a new ScaleUp command with specified scaling factors.
         *
         * @param factorX Horizontal scaling factor.
         * @param factorY Vertical scaling factor.
         */
        ScaleUp::ScaleUp(int factorX, int factorY)
            : Command("scaleup"), factorX(factorX), factorY(factorY) {}

        /**
         * @brief Apply the scale-up transformation to the given image.
         *
         * This method enlarges the image by duplicating pixels according to the
         * scaling factors along the X and Y axes.
         *
         * @param img Pointer to the input image to be scaled up.
         * @return Image* Pointer to the newly created scaled-up image.
         */
        Image *ScaleUp::apply(Image *img) {

            int newWidth = img->width() * factorX;
            int newHeight = img->height() * factorY;
            Image *newImg = new Image(newWidth, newHeight);

            for (int y = 0; y < img->height(); ++y) {
                for (int x = 0; x < img->width(); ++x) {
                    const Color& pixel = img->at(x, y);

                    // Duplicate pixel by factorX horizontally and factorY vertically
                    for (int dy = 0; dy < factorY; ++dy) {
                        for (int dx = 0; dx < factorX; ++dx) {
                            newImg->at(x * factorX + dx, y * factorY + dy) = pixel;
                        }
                    }
                }
            }

            // Delete the old image and return the new scaled-up image
            delete img;
            return newImg;
        }

    }
}
