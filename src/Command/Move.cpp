
#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        Move::Move(int x, int y)
           : Command("move"), x_(x), y_(y) {}

        Image *Move::apply(Image *img) {
            Color fill = img->get_fill();

            // nova imagem preenchida com a cor base
            Image* new_img = new Image(img->width(), img->height(), fill);

            for (int y = 0; y < img->height(); y++) {
                for (int x = 0; x < img->width(); x++) {
                    int new_x = x + x_;
                    int new_y = y + y_;

                    // só copia se o novo pixel estiver dentro dos limites
                    if (new_x >= 0 && new_x < img->width() && new_y >= 0 && new_y < img->height()) {
                        new_img->at(new_x, new_y) = img->at(x, y);
                    }
                }
            }

            delete img;  // libertar imagem original
            return new_img;
        }

    }
}