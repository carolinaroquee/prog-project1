#ifndef PROJECT_ROTATE_RIGHT_HPP
#define PROJECT_ROTATE_RIGHT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class RotateRight : public Command {
        public:
            RotateRight();
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}

#endif // PROJECT_ROTATE_RIGHT_HPP
