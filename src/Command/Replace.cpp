
#include "Command/Replace.hpp"

namespace prog {

    namespace command {

        Replace::Replace(Color c1, Color c2) : Command("replace"), c1_(c1), c2_(c2) {}

        Image *Replace::apply(Image *img) {

            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    Color& point = img->at(x, y);
                    if (point.red() == c1_.red() &&
                    point.green() == c1_.green() &&
                    point.blue() == c1_.blue()){
                      point = c2_;
                    }
                }
            }
            return img;
        }
    }
}