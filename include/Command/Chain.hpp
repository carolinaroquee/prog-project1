#ifndef PROJECT_CHAIN_HPP
#define PROJECT_CHAIN_HPP

#include "Command.hpp"
#include <vector>
#include <string>
#include <set>

namespace prog::command {

    class Chain : public Command {
    public:
        Chain(std::vector<std::string> filenames);

        Image* apply(Image* img) override;

    private:
        std::vector<std::string> filenames;

        static Image* execute_script(const std::string& filename, Image* img, std::set<std::string>& visited);
    };

}

#endif // PROJECT_CHAIN_HPP
