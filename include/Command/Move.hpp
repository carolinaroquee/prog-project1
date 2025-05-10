#ifndef PROJECT_MOVE_HPP
#define PROJECT_MOVE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Move : public Command {
        public:
            Move(int x, int y);

            Image *apply(Image *img) override;

        private:
            int x_, y_;
        };
    }
}
#endif //PROJECT_MOVE_HPP
