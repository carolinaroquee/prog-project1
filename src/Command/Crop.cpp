#include "Command/Crop.hpp"

namespace prog {
    namespace command {

        Crop::Crop(int x, int y, int w, int h)
            : Command("crop"), x(x), y(y), w(w), h(h) {}

        Image *Crop::apply(Image *img) {
            int x_end = std::min(x + w, img->width());
            int y_end = std::min(y + h, img->height());

            int x_start = std::max(0, x);
            int y_start = std::max(0, y);

            int new_width = x_end - x_start;
            int new_height = y_end - y_start;

            if (new_width <= 0 || new_height <= 0) {
                delete img;
                return new Image(1, 1);
            }

            Image *cropped = new Image(new_width, new_height);

            for (int j = 0; j < new_height; ++j) {
                for (int i = 0; i < new_width; ++i) {
                    cropped->at(i, j) = img->at(x_start + i, y_start + j);
                }
            }

            delete img;
            return cropped;
        }

    }
}