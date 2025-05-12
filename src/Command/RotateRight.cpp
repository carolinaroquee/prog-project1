#include "Command/RotateRight.hpp"

namespace prog::command {

    RotateRight::RotateRight() : Command("rotate_right") {}

    Image* RotateRight::apply(Image* img) {
        int new_width = img->height();
        int new_height = img->width();
        Image* rotated = new Image(new_width, new_height, img->get_fill());

        for (int y = 0; y < img->height(); ++y) {
            for (int x = 0; x < img->width(); ++x) {
                rotated->at(new_width - 1 - y, x) = img->at(x, y);  // rotação 90º à direita
            }
        }

        delete img;
        return rotated;
    }

    std::string RotateRight::toString() const {
        return "rotate_right";
    }

}
