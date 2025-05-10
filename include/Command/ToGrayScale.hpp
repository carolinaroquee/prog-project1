#ifndef PROJECT_TOGRAYSCALE_HPP
#define PROJECT_TOGRAYSCALE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class ToGrayScale : public Command {
        public:
            ToGrayScale();

            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_TOGRAYSCALE_HPP
