
#include "Command/Slide.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        Slide::Slide(int x, int y)
           : Command("slide"), x_(x), y_(y) {}

        Image *Slide::apply(Image *img) {
            Color fill = img->get_fill();

            // nova imagem preenchida com a cor base
            Image* new_img = new Image(img->width(), img->height(), fill);

            for (int x = 0; x < img->width(); x++) {
                for (int y = 0; y < img->height(); y++) {
                    int new_x =  (x + x_) % img->width();
                    int new_y = (y + y_) % img->height();
                    new_img->at(new_x, new_y) = img->at(x, y);
                }
            }

            delete img;  // libertar imagem original
            return new_img;
        }

    }
}