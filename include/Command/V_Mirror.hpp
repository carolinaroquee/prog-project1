#ifndef PROJECT_V_MIRROR_HPP
#define PROJECT_V_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to vertically mirror an image.
         */
        class V_Mirror : public Command {
        public:
            /**
             * @brief Construct a new V_Mirror command.
             */
            V_Mirror();

            /**
             * @brief Apply vertical mirroring to the given image.
             *
             * @param img Pointer to the image to be mirrored.
             * @return Image* Pointer to the vertically mirrored image.
             */
            Image *apply(Image *img) override;
        };
    }
}
#endif //PROJECT_V_MIRROR_HPP
