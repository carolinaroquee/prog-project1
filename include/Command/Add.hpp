#ifndef PROJECT_ADD_HPP
#define PROJECT_ADD_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        /**
         * @class Add
         * @brief Command to add an image overlay at a specific position with a neutral color key.
         *
         * This command loads an image from a file and overlays it onto
         * the target image at coordinates (x, y). Pixels matching the neutral color are ignored.
         */
        class Add : public Command {
        public:
            /**
             * @brief Construct a new Add command
             *
             * @param filename Path to the image file to add.
             * @param neutro Color to treat as transparent/neutral in the overlay image.
             * @param x Horizontal position to place the overlay.
             * @param y Vertical position to place the overlay.
             */
            Add(const std::string& filename, Color neutro, int x, int y);

            /**
             * @brief Apply the Add command by overlaying the loaded image.
             *
             * @param img Pointer to the target image to modify.
             * @return Image* Pointer to the modified image.
             */
            Image *apply(Image *img) override;

        private:
            std::string filename_;  ///< Image filename to load
            Color neutro_;          ///< Neutral color to ignore during overlay
            int x_, y_;             ///< Coordinates for placing the overlay
        };
    }
}

#endif //PROJECT_ADD_HPP
