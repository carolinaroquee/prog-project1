#ifndef PROJECT_MOVE_HPP
#define PROJECT_MOVE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to move an image by a given offset.
         *
         * This command shifts the image pixels by (x, y) coordinates.
         */
        class Move : public Command {
        public:
            /**
             * @brief Construct a new Move command.
             *
             * @param x Horizontal offset to move the image.
             * @param y Vertical offset to move the image.
             */
            Move(int x, int y);

            /**
             * @brief Apply the move operation to the given image.
             *
             * @param img Pointer to the image to be moved.
             * @return Image* Pointer to the moved image.
             */
            Image *apply(Image *img) override;

        private:
            int x_; ///< Horizontal offset value.
            int y_; ///< Vertical offset value.
        };
    }
}
#endif //PROJECT_MOVE_HPP
