#include "Command/V_Mirror.hpp"

namespace prog {
    namespace command {

        V_Mirror::V_Mirror() : Command("v_mirror") {}

        Image *V_Mirror::apply(Image *img) {

            for (int y = 0; y < img->height() / 2; ++y) {
                for (int x = 0; x < img->width(); ++x) {
                    Color& top = img->at(x, y);
                    Color& bottom = img->at(x, img->height() - 1 - y);
                    swap(top, bottom);
                }
            }
            return img;
        }
    }
}