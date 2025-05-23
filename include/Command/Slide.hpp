#ifndef PROJECT_SLIDE_HPP
#define PROJECT_SLIDE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to slide (shift) an image by specified offsets.
         */
        class Slide : public Command {
        public:
            /**
             * @brief Construct a new Slide command.
             *
             * @param x Horizontal offset by which to slide the image.
             * @param y Vertical offset by which to slide the image.
             */
            Slide(int x, int y);

            /**
             * @brief Apply the slide command to an image.
             *
             * @param img Pointer to the image to be slid.
             * @return Image* Pointer to the resulting image after sliding.
             */
            Image *apply(Image *img) override;

        private:
            int x_; ///< Horizontal offset for sliding.
            int y_; ///< Vertical offset for sliding.
        };
    }
}
#endif //PROJECT_SLIDE_HPP
