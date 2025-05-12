#ifndef PROJECT_ROTATE_LEFT_HPP
#define PROJECT_ROTATE_LEFT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class RotateLeft : public Command {
        public:
            RotateLeft();
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}

#endif // PROJECT_ROTATE_LEFT_HPP
