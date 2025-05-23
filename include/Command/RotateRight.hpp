#ifndef PROJECT_ROTATE_RIGHT_HPP
#define PROJECT_ROTATE_RIGHT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to rotate an image 90 degrees clockwise (right).
         */
        class RotateRight : public Command {
        public:
            /**
             * @brief Construct a new RotateRight command.
             */
            RotateRight();

            /**
             * @brief Apply a 90-degree clockwise rotation to the image.
             *
             * @param img The image to rotate.
             * @return Image* The rotated image.
             */
            Image* apply(Image* img) override;

            /**
             * @brief Get a string description of this command.
             *
             * @return std::string Description of the command.
             */
            std::string toString() const override;
        };

    }
}

#endif // PROJECT_ROTATE_RIGHT_HPP
