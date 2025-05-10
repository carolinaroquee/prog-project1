#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP

#include "Color.hpp"
#include "Command.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:
            Fill(int x, int y, int w, int h, Color fill);

            Image *apply(Image *img) override;

        private:
            int x_, y_, w_, h_;
            Color fill_;
        };
    }
}
#endif //PROJECT_FILL_HPP
