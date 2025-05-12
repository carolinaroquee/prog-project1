#include "Command/RotateLeft.hpp"

namespace prog::command {

    RotateLeft::RotateLeft() : Command("rotate_left") {}

    Image* RotateLeft::apply(Image* img) {
        int new_width = img->height();
        int new_height = img->width();
        Image* rotated = new Image(new_width, new_height, img->get_fill());
        for (int y = 0; y < img->height(); ++y) {
            for (int x = 0; x < img->width(); ++x) {
                rotated->at(y, new_height - 1 - x) = img->at(x, y); //inverte as coordenadas com a rotação de 90º
            }
        }
        delete img;
        return rotated;
    }

    std::string RotateLeft::toString() const {
        return "rotate_left";
    }

}
