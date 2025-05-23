/**
* @file Open.cpp
 * @brief Implements the Open command that loads an image from a PNG file.
 */

#include "Command/Open.hpp"
#include "PNG.hpp"
#include "Logger.hpp"
#include <cstdlib>
#include <sstream>

namespace prog {
    namespace command {

        /**
         * @brief Constructs the Open command with the specified filename.
         *
         * @param filename Path to the PNG file to open.
         */
        Open::Open(std::string filename) : Command("Open"), filename(filename) {}

        /**
         * @brief Destructor for Open command.
         */
        Open::~Open() {}

        /**
         * @brief Loads an image from the given filename, replacing the input image.
         *
         * Deletes the input image and attempts to load a new image from the PNG file.
         * If loading fails, logs an error and terminates the program.
         *
         * @param img Pointer to the current image to be replaced.
         * @return Pointer to the newly loaded image.
         */
        Image* Open::apply(Image* img) {
            // Dispose of previous image
            delete img;

            // TODO: fix rootpath if needed
            // img = loadFromPNG("../" + filename);
            img = loadFromPNG(filename);

            if (!img) {
                *Logger::err() << "Could not open file " << filename << "\n";
                std::exit(1);
            }

            return img;
        }

        /**
         * @brief Returns a string representation of the Open command.
         *
         * @return String describing the command and filename.
         */
        std::string Open::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename;
            return ss.str();
        }

    } // namespace command
} // namespace prog