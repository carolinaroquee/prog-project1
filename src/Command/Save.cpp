//
// Created by JBispo on 05/04/2025.
//

#include "Command/Save.hpp"
#include "PNG.hpp"
#include "Utils.h"
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

namespace prog {

    namespace command {

        /**
         * @brief Constructs a Save command with the specified filename.
         *
         * @param filename The path where the image will be saved.
         */
        Save::Save(std::string filename) : Command("Save"), filename(filename) {}

        /**
         * @brief Destructor for Save command.
         */
        Save::~Save() {}

        /**
         * @brief Saves the current image to the specified PNG file.
         *
         * Ensures that the directory path exists before saving.
         *
         * @param img Pointer to the image to save.
         * @return The same image pointer (no modification).
         */
        Image *Save::apply(Image *img) {
            // Ensure folder exists before writing file
            fs::path filepath(filename);
            mkdir(filepath.parent_path().string());

            saveToPNG(filename, img);

            return img;
        }

        /**
         * @brief Returns a string representation of the Save command.
         *
         * @return The command name and filename as a string.
         */
        std::string Save::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename;
            return ss.str();
        }

    }
}
