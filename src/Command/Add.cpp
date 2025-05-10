
#include "Command/Add.hpp"
#include "PNG.hpp"  // para ler imagens PNG

namespace prog {
    namespace command {
        Add::Add(const std::string& filename, Color neutro, int x, int y)
            : Command("add"), filename_(filename), neutro_(neutro), x_(x), y_(y) {}

        Image *Add::apply(Image *img) {
            Image* new_img = loadFromPNG(filename_); //lê a img PNG
            for (int y1 = 0; y1 < new_img->height(); y1++) {
                for (int x1 = 0; x1 < new_img->width(); x1++) {
                    const Color& point = new_img->at(x1, y1);
                    if (point.red() == neutro_.red() &&
                        point.green() == neutro_.green() &&
                        point.blue() == neutro_.blue()) {
                        continue;
                        }

                    int distX = x_ + x1;
                    int distY = y_ + y1;

                    if (distX >= 0 && distX < img->width() &&
                        distY >= 0 && distY < img->height()) {
                        img->at(distX, distY) = point;
                        }
                }
            }

            delete new_img;
            return img;
        }

    }
}