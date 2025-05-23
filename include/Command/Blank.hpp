//
// Created by JBispo on 05/04/2025.
//

#ifndef PROJECT_BLANK_HPP
#define PROJECT_BLANK_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        /**
         * @class Blank
         * @brief Command to create a blank image filled with a specified color.
         *
         * This command generates a new image with given width and height,
         * filling every pixel with the specified fill color.
         */
        class Blank : public Command {
        public:
            /**
             * @brief Construct a new Blank command.
             *
             * @param w Width of the blank image.
             * @param h Height of the blank image.
             * @param fill Color to fill the image with.
             */
            Blank(int w, int h, Color &fill);

            /**
             * @brief Destructor for Blank command.
             */
            ~Blank();

            /**
             * @brief Apply the Blank command by creating a blank image.
             *
             * @param img Pointer to an existing image (ignored).
             * @return Image* Pointer to the newly created blank image.
             */
            Image *apply(Image *img) override;

            /**
             * @brief Get a string representation of the command.
             *
             * @return std::string Description of the Blank command.
             */
            std::string toString() const override;

        private:
            int w;       ///< Width of the blank image
            int h;       ///< Height of the blank image
            Color fill;  ///< Fill color for the blank image
        };
    }
}

#endif //PROJECT_BLANK_HPP
