#include "Command/Scaleup.hpp"

namespace prog {
    namespace command {

        ScaleUp::ScaleUp(int factorX, int factorY)
            : Command("scaleup"), factorX(factorX), factorY(factorY) {}

        Image *ScaleUp::apply(Image *img) {

            int newWidth = img->width() * factorX;
            int newHeight = img->height() * factorY;
            Image *newImg = new Image(newWidth, newHeight);

            for (int y = 0; y < img->height(); ++y) {
                for (int x = 0; x < img->width(); ++x) {
                    const Color& pixel = img->at(x, y);

                    for (int dy = 0; dy < factorY; ++dy) {
                        for (int dx = 0; dx < factorX; ++dx) {
                            newImg->at(x * factorX + dx, y * factorY + dy) = pixel;
                        }
                    }
                }
            }

            delete img;
            return newImg;
        }

    }
}
