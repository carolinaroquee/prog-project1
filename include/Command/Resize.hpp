#ifndef PROJECT_RESIZE_HPP
#define PROJECT_RESIZE_HPP

#include "Command.hpp"
#include "Image.hpp"
#include <string>

namespace prog {
    namespace command {

        /**
         * @brief Command to resize a region of an image.
         *
         * This command resizes a rectangular portion of the image defined by (x, y, width, height).
         */
        class Resize : public Command {
        public:
            /**
             * @brief Construct a new Resize command.
             *
             * @param x The x-coordinate of the top-left corner of the resize region.
             * @param y The y-coordinate of the top-left corner of the resize region.
             * @param w The width of the resize region.
             * @param h The height of the resize region.
             */
            Resize(int x, int y, int w, int h);

            /**
             * @brief Apply the resize operation on the given image.
             *
             * @param img The image to modify.
             * @return Image* The resized image.
             */
            Image* apply(Image* img) override;

            /**
             * @brief Get a string representation of the command.
             *
             * @return std::string Description of the command and parameters.
             */
            std::string toString() const override;

        private:
            int x_;       ///< X-coordinate of the resize region.
            int y_;       ///< Y-coordinate of the resize region.
            int width_;   ///< Width of the resize region.
            int height_;  ///< Height of the resize region.
        };
    }
}

#endif //PROJECT_RESIZE_HPP
