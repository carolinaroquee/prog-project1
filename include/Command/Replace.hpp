#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to replace one color with another in an image.
         *
         * This command scans the image and replaces all pixels matching color c1 with color c2.
         */
        class Replace : public Command {
        public:
            /**
             * @brief Construct a new Replace command.
             *
             * @param c1 The color to be replaced.
             * @param c2 The color to replace with.
             */
            Replace(Color c1, Color c2);

            /**
             * @brief Apply the color replacement on the given image.
             *
             * @param img The image to modify.
             * @return Image* The modified image (usually the same pointer).
             */
            Image *apply(Image *img) override;

        private:
            Color c1_; ///< The color to be replaced.
            Color c2_; ///< The replacement color.
        };
    }
}
#endif //PROJECT_REPLACE_HPP

