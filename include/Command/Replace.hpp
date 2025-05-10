#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Replace : public Command {
        public:
            Replace(Color c1, Color c2);

            Image *apply(Image *img) override;

        private:
          Color c1_, c2_;
        };
    }
}
#endif //PROJECT_REPLACE_HPP
