#ifndef PROJECT_H_MIRROR_HPP
#define PROJECT_H_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class H_Mirror : public Command {
        public:
            H_Mirror();

            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_H_MIRROR_HPP
