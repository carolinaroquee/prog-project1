#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Scrim.hpp"

#include <set>
#include <fstream>

namespace prog::command {

    Chain::Chain(std::vector<std::string> filenames)
        : Command("chain"), filenames(std::move(filenames)) {}

    Image* Chain::apply(Image* img) {
        std::set<std::string> visited;
        for (const std::string& file : filenames) {
            img = execute_script(file, img, visited);
        }
        return img;
    }

    Image* Chain::execute_script(const std::string& filename, Image* img, std::set<std::string>& visited) {
        if (visited.count(filename)) {
            // Recursão detetada; ignorar
            return img;
        }
        visited.insert(filename);

        ScrimParser parser;
        Scrim* scrim = parser.parseScrim(filename);

        if (!scrim) {
            return img;
        }

        for (Command* cmd : scrim->getCommands()) {
            if (!cmd) continue;

            // Ignorar comandos proibidos
            std::string cname = cmd->toString();
            if (cname.find("blank") == 0 || cname.find("open") == 0 || cname.find("save") == 0) {
                continue;
            }

            // Se for um comando chain, aplicar recursivamente
            if (auto* chainCmd = dynamic_cast<Chain*>(cmd)) {
                for (const std::string& f : chainCmd->filenames) {
                    img = execute_script(f, img, visited);
                }
            } else {
                img = cmd->apply(img);
            }
        }

        delete scrim;
        return img;
    }

}
