#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to invert the colors of an image.
         * 
         * This command flips each pixel color to its inverse.
         */
        class Invert : public Command {
        public:
            /**
             * @brief Construct a new Invert command.
             */
            Invert();

            /**
             * @brief Apply color inversion to the given image.
             * 
             * @param img Pointer to the image to invert.
             * @return Image* Pointer to the resulting inverted image.
             */
            Image *apply(Image *img) override;
        };

    }
}

#endif // PROJECT_INVERT_HPP
