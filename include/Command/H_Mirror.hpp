#ifndef PROJECT_H_MIRROR_HPP
#define PROJECT_H_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        /**
         * @class H_Mirror
         * @brief Command to horizontally mirror an image.
         *
         * This command flips the image horizontally (left-right inversion).
         */
        class H_Mirror : public Command {
        public:
            /**
             * @brief Construct a new H_Mirror command.
             */
            H_Mirror();

            /**
             * @brief Apply the horizontal mirror operation on the given image.
             *
             * @param img Pointer to the image to be mirrored.
             * @return Image* Pointer to the mirrored image.
             */
            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_H_MIRROR_HPP
