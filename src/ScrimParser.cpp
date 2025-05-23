//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Slide.hpp"
#include "Command/Move.hpp"
#include "Command/Add.hpp"
#include "Command/H_Mirror.hpp"
#include "Command/V_Mirror.hpp"
#include "Command/Fill.hpp"
#include "Command/Crop.hpp"
#include "Command/Scaleup.hpp"
#include "Command/Replace.hpp"
#include "Command/ToGrayScale.hpp"
#include "Command/Invert.hpp"
#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Command/Resize.hpp"
#include "Command/RotateLeft.hpp"
#include "Command/RotateRight.hpp"
#include "Command/Chain.hpp"
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

    /**
     * @brief Default constructor for ScrimParser.
     */
    ScrimParser::ScrimParser() {
    };

    /**
     * @brief Default destructor for ScrimParser.
     */
    ScrimParser::~ScrimParser() {
    };

    /**
     * @brief Parses a scrim from an input stream.
     *
     * Reads commands line by line from the input stream, creates Command objects,
     * and accumulates them into a vector. If parsing fails, cleans up allocated commands.
     *
     * @param input Input stream to read commands from.
     * @return Scrim* Pointer to a Scrim object created with the parsed commands,
     *                or nullptr if parsing failed.
     */
    Scrim* ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands to prevent memory leaks
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }

                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new Scrim object (image pipeline) with the parsed commands
        return new Scrim(commands);
    }

    /**
     * @brief Parses a scrim from a file.
     *
     * Opens the given file and delegates parsing to the stream-based parseScrim.
     *
     * @param filename Path to the file containing scrim commands.
     * @return Scrim* Pointer to a Scrim object created with the parsed commands,
     *                or nullptr if file could not be opened or parsing failed.
     */
    Scrim* ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    /**
     * @brief Parses a single command given its name and the input stream.
     *
     * Reads necessary parameters from the input stream depending on the command name,
     * constructs the corresponding Command object, or returns nullptr if unrecognized.
     *
     * @param command_name Name of the command to parse.
     * @param input Input stream to read command parameters from.
     * @return Command* Pointer to the newly created Command object, or nullptr on failure.
     */
    Command* ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Parse parameters for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Parse parameters for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            // Parse parameters for Open command
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        // Other commands with no or simple parameters

        if (command_name == "invert")
            return new command::Invert();

        if (command_name == "to_gray_scale")
            return new command::ToGrayScale();

        if (command_name == "replace") {
            // Parse parameters for Replace command: two colors
            int r1, g1, b1, r2, g2, b2;
            input >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
            return new command::Replace(Color(r1, g1, b1), Color(r2, g2, b2));
        }

        if (command_name == "crop") {
            // Parse parameters for Crop command: rectangle position and size
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new command::Crop(x, y, w, h);
        }

        if (command_name == "fill") {
            // Parse parameters for Fill command: rectangle and fill color
            int x, y, w, h, r, g, b;
            input >> x >> y >> w >> h >> r >> g >> b;
            return new command::Fill(x, y, w, h, Color(r, g, b));
        }

        if (command_name == "h_mirror")
            return new command::H_Mirror();

        if (command_name == "v_mirror")
            return new command::V_Mirror();

        if (command_name == "scaleup") {
            // Parse scale factors for ScaleUp command
            int fx, fy;
            input >> fx >> fy;
            return new command::ScaleUp(fx, fy);
        }

        if (command_name == "add") {
            // Parse parameters for Add command: filename, color key, and position
            std::string filename;
            int r, g, b, x, y;
            input >> filename >> r >> g >> b >> x >> y;
            return new command::Add(filename, Color(r, g, b), x, y);
        }

        if (command_name == "move") {
            // Parse parameters for Move command: delta x and y
            int x, y;
            input >> x >> y;
            return new command::Move(x, y);
        }

        if (command_name == "slide") {
            // Parse parameters for Slide command: delta x and y
            int x, y;
            input >> x >> y;
            return new command::Slide(x, y);
        }

        if (command_name == "resize") {
            // Parse parameters for Resize command: position and size
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new command::Resize(x, y, w, h);
        }

        if (command_name == "rotate_left")
            return new command::RotateLeft();

        if (command_name == "rotate_right")
            return new command::RotateRight();

        if (command_name == "chain") {
            std::vector<std::string> filenames;
            std::string token;

            while (input >> token && token != "end") {
                filenames.push_back(token);
            }

            return new command::Chain(filenames);
        }
        // Unrecognized command case: log error and return nullptr
        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}