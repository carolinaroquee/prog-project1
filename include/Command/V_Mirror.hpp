#ifndef PROJECT_V_MIRROR_HPP
#define PROJECT_V_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class V_Mirror : public Command {
        public:
            V_Mirror();

            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_V_MIRROR_HPP
