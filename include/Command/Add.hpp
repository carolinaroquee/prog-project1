#ifndef PROJECT_ADD_HPP
#define PROJECT_ADD_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Add : public Command {
        public:
            Add(const std::string& filename, Color neutro, int x, int y);

            Image *apply(Image *img) override;

        private:
          string filename_;
          Color neutro_;
          int x_, y_;
        };
    }
}
#endif //PROJECT_ADD_HPP
