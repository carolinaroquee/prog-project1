//
// Created by JBispo on 05/04/2025.
//

#ifndef PROJECT_SAVE_HPP
#define PROJECT_SAVE_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {

        /**
         * @brief Command to save an image to a file.
         */
        class Save : public Command {
        public:
            /**
             * @brief Construct a new Save command.
             *
             * @param filename The file path where the image will be saved.
             */
            Save(std::string filename);

            /**
             * @brief Destroy the Save command.
             */
            ~Save();

            /**
             * @brief Apply the save command, writing the image to the specified file.
             *
             * @param img The image to save.
             * @return Image* The same image pointer passed in (usually unchanged).
             */
            Image *apply(Image *img) override;

            /**
             * @brief Get a string representation of the command.
             *
             * @return std::string Description of the Save command.
             */
            std::string toString() const override;

        private:
            std::string filename; ///< Path where the image will be saved.
        };

    }
}

#endif //PROJECT_SAVE_HPP
