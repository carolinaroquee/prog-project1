
#include "Command/Invert.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        Invert :: Invert() : Command("invert") {}

        Image *Invert::apply(Image *img) {

            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    Color& point = img->at(x, y);
                    point.red()   = 255 - point.red();
                    point.green() = 255 - point.green();
                    point.blue()  = 255 - point.blue();
                }
            }
            return img;
        }
    }
}