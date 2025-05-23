#include "Command/V_Mirror.hpp"

namespace prog {
    namespace command {

        /**
         * @class V_Mirror
         * @brief Command to vertically mirror an image (flip vertically).
         */
        V_Mirror::V_Mirror() : Command("v_mirror") {}

        /**
         * @brief Applies vertical mirroring to the image.
         *
         * Swaps the pixels between the top and bottom halves of the image,
         * effectively flipping it vertically.
         *
         * @param img Pointer to the image to mirror.
         * @return Pointer to the vertically mirrored image (same image object).
         */
        Image *V_Mirror::apply(Image *img) {

            // Iterate only through half the height to swap pixels
            for (int y = 0; y < img->height() / 2; ++y) {
                for (int x = 0; x < img->width(); ++x) {
                    Color& top = img->at(x, y);
                    Color& bottom = img->at(x, img->height() - 1 - y);

                    // Swap top and bottom pixels
                    swap(top, bottom);
                }
            }
            return img;
        }
    }
}
