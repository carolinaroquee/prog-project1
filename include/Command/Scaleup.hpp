#ifndef PROJECT_SCALEUP_HPP
#define PROJECT_SCALEUP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class ScaleUp : public Command {
        public:
            ScaleUp(int factorX, int factorY);

            Image *apply(Image *img) override;

        private:
            int factorX;
            int factorY;
        };
    }
}

#endif //PROJECT_SCALEUP_HPP
