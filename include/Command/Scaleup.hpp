#ifndef PROJECT_SCALEUP_HPP
#define PROJECT_SCALEUP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        /**
         * @brief Command to scale up (enlarge) an image by integer factors.
         */
        class ScaleUp : public Command {
        public:
            /**
             * @brief Construct a new ScaleUp command.
             *
             * @param factorX Scaling factor in the horizontal direction.
             * @param factorY Scaling factor in the vertical direction.
             */
            ScaleUp(int factorX, int factorY);

            /**
             * @brief Apply the scale-up command to an image.
             *
             * @param img Pointer to the image to be scaled up.
             * @return Image* Pointer to the new scaled image.
             */
            Image *apply(Image *img) override;

        private:
            int factorX; ///< Horizontal scaling factor.
            int factorY; ///< Vertical scaling factor.
        };

    }
}

#endif //PROJECT_SCALEUP_HPP
