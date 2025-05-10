
#include "Command/Fill.hpp"

namespace prog {

    namespace command {

        Fill::Fill(int x, int y, int w, int h, Color fill)
           : Command("fill"), x_(x), y_(y), w_(w), h_(h), fill_(fill) {}

        Image *Fill::apply(Image *img) {

            for (int y = y_; y < y_ + h_; y++) {
                for (int x = x_; x < x_ +w_; x++) {
                  if (x >= 0 && x < img->width() && y >= 0 && y < img->height()){
                    img -> at(x, y) = fill_;
                  }
                }
            }
        return img;
        }
    }
}