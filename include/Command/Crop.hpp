#ifndef PROJECT_CROP_HPP
#define PROJECT_CROP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        /**
         * @class Crop
         * @brief Command to crop an image to a specified rectangle.
         *
         * This command crops the given image starting from (x, y) coordinates
         * with the specified width (w) and height (h).
         */
        class Crop : public Command {
        public:
            /**
             * @brief Construct a new Crop command.
             *
             * @param x The x-coordinate of the top-left corner of the crop rectangle.
             * @param y The y-coordinate of the top-left corner of the crop rectangle.
             * @param w The width of the crop rectangle.
             * @param h The height of the crop rectangle.
             */
            Crop(int x, int y, int w, int h);

            /**
             * @brief Apply the Crop command on the given image.
             *
             * @param img Pointer to the image to be cropped.
             * @return Image* Pointer to the cropped image.
             */
            Image *apply(Image *img) override;

        private:
            int x; ///< X-coordinate of crop start point
            int y; ///< Y-coordinate of crop start point
            int w; ///< Width of the crop area
            int h; ///< Height of the crop area
        };
    }
}

#endif // PROJECT_CROP_HPP
