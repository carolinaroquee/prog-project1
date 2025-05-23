#ifndef PROJECT_ROTATE_LEFT_HPP
#define PROJECT_ROTATE_LEFT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to rotate an image 90 degrees counterclockwise (left).
         */
        class RotateLeft : public Command {
        public:
            /**
             * @brief Construct a new RotateLeft command.
             */
            RotateLeft();

            /**
             * @brief Apply a 90-degree counterclockwise rotation to the image.
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

#endif // PROJECT_ROTATE_LEFT_HPP
