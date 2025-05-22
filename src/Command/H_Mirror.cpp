
#include "Command/H_Mirror.hpp"

namespace prog {

    namespace command {

        H_Mirror::H_Mirror() : Command("h_mirror") {}

        Image *H_Mirror::apply(Image *img) {

            for (int y = 0; y < img->height(); ++y) {
                for (int x = 0; x < img->width() / 2; ++x) {
                    Color& left = img->at(x, y);
                    Color& right= img->at(img->width() - 1 - x, y);
                    swap(left, right);
                }
            }
            return img;
        }
    }
}