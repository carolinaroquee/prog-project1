#ifndef PROJECT_CROP_HPP
#define PROJECT_CROP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Crop : public Command {
        public:
            Crop(int x, int y, int w, int h);

            Image *apply(Image *img) override;

        private:
            int x, y, w, h;
        };
    }
}

#endif // PROJECT_CROP_HPP
