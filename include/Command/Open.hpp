//
// Created by JBispo on 05/04/2025.
//

#ifndef PROJECT_OPEN_HPP
#define PROJECT_OPEN_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {

        /**
         * @brief Command to open an image file.
         *
         * This command loads an image from a specified file.
         */
        class Open : public Command {
        public:
            /**
             * @brief Construct a new Open command with a filename.
             *
             * @param filename The path to the image file to open.
             */
            Open(std::string filename);

            /**
             * @brief Destroy the Open command.
             */
            ~Open();

            /**
             * @brief Apply the open operation, loading the image from the file.
             *
             * @param img The current image (can be ignored or deleted).
             * @return Image* Pointer to the newly loaded image.
             */
            Image *apply(Image *img) override;

            /**
             * @brief Get a string representation of the command.
             *
             * @return std::string Description of the command including the filename.
             */
            std::string toString() const override;

        private:
            std::string filename; ///< The filename to open.
        };
    }
}

#endif //PROJECT_OPEN_HPP
