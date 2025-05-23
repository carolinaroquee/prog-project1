#ifndef PROJECT_TOGRAYSCALE_HPP
#define PROJECT_TOGRAYSCALE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to convert an image to grayscale.
         */
        class ToGrayScale : public Command {
        public:
            /**
             * @brief Construct a new ToGrayScale command.
             */
            ToGrayScale();

            /**
             * @brief Apply the grayscale conversion to the given image.
             *
             * @param img Pointer to the image to be converted.
             * @return Image* Pointer to the converted grayscale image.
             */
            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_TOGRAYSCALE_HPP
