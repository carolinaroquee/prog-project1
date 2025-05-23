#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP

#include "Color.hpp"
#include "Command.hpp"

namespace prog {
    namespace command {
        /**
         * @class Fill
         * @brief Command to fill a rectangular area of an image with a specified color.
         *
         * This command fills a rectangle starting at (x, y) with width w and height h
         * using the given fill color.
         */
        class Fill : public Command {
        public:
            /**
             * @brief Construct a new Fill command.
             *
             * @param x The x-coordinate of the top-left corner of the fill rectangle.
             * @param y The y-coordinate of the top-left corner of the fill rectangle.
             * @param w The width of the rectangle to fill.
             * @param h The height of the rectangle to fill.
             * @param fill The color used to fill the rectangle.
             */
            Fill(int x, int y, int w, int h, Color fill);

            /**
             * @brief Apply the Fill command on the given image.
             *
             * @param img Pointer to the image to be filled.
             * @return Image* Pointer to the modified image.
             */
            Image *apply(Image *img) override;

        private:
            int x_;      ///< X-coordinate of fill start point
            int y_;      ///< Y-coordinate of fill start point
            int w_;      ///< Width of the fill area
            int h_;      ///< Height of the fill area
            Color fill_; ///< Fill color
        };
    }
}
#endif //PROJECT_FILL_HPP
