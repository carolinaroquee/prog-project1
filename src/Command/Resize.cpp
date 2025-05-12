#include "Command/Resize.hpp"
#include "Image.hpp"
#include <algorithm>

namespace prog {
    namespace command {
        Resize::Resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), width_(w), height_(h) {}

        Image* Resize::apply(Image* img) {
            Color fill = img->get_fill(); // fundo igual

            // Cria uma nova imagem com as dimensões especificadas
            Image* new_img = new Image(width_, height_, fill);

            int min_w = std::min(width_, img->width() - x_);
            int min_h = std::min(height_, img->height() - y_);

            // manter o nº de pixeis nas duas imagens
            for (int y = 0; y < min_h; ++y) {
                for (int x = 0; x < min_w; ++x) {
                    new_img->at(x, y) = img->at(x_ + x, y_ + y);
                }
            }

            delete img; // libertar memória

            return new_img;
        }

        std::string Resize::toString() const {
            return "resize " + std::to_string(x_) + " " + std::to_string(y_) + " " + std::to_string(width_) + " " + std::to_string(height_);
        }
    }
}
