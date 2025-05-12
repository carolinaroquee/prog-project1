#ifndef PROJECT_RESIZE_HPP
#define PROJECT_RESIZE_HPP

#include "Command.hpp"
#include "Image.hpp"
#include <string>

namespace prog {
    namespace command {
        class Resize : public Command {
        public:
            Resize(int x, int y, int w, int h);

            Image* apply(Image* img) override;

            std::string toString() const override;

        private:
            int x_, y_, width_, height_;
        };
    }
}

#endif //PROJECT_RESIZE_HPP
