
#include "Command/ToGrayScale.hpp"
#include "Color.hpp"

namespace prog {

    namespace command {

        ToGrayScale :: ToGrayScale() : Command("to_gray_scale") {}

        Image *ToGrayScale::apply(Image *img) {

            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    Color& point = img->at(x, y);

                    rgb_value v = (point.red() + point.green() + point.blue()) / 3;
                    point.red() = v;
                    point.green() = v;
                    point.blue() = v;
                }
            }
            return img;
        }
    }
}