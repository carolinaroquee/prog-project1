//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Move.hpp"
#include "Command/Add.hpp"
#include "Command/H_Mirror.hpp"
#include "Command/Fill.hpp"
#include "Command/Replace.hpp"
#include "Command/ToGrayScale.hpp"
#include "Command/Invert.hpp"
#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Logger.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        // TODO: implement cases for the new commands
        if (command_name == "invert") return new command::Invert();

        if (command_name == "to_gray_scale") return new command::ToGrayScale();

        if (command_name == "replace") {
            int r1, g1, b1, r2, g2, b2;
            input >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
            return new command::Replace(Color(r1, g1, b1), Color(r2, g2, b2));
        }

        if (command_name == "fill") {
            int x, y, w, h, r, g, b;
            input >> x >> y >> w >> h >> r >> g >> b;
            return new command:: Fill(x, y, w, h, Color(r, g, b));
        }

        if (command_name == "h_mirror") return new command::H_Mirror();

        if (command_name == "add") {
            std::string filename;
            int r, g, b, x, y;
            input >> filename >> r >> g >> b >> x >> y;
            return new command :: Add(filename, Color(r, g, b), x, y);
        }

        if (command_name == "move") {
            int x, y;
            input >> x >> y;
            return new command :: Move(x, y);
        }

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
