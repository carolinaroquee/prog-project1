/**
* @file Blank.cpp
 * @brief Implements the Blank command that creates a new image filled with a specified color.
 */

#include "Command/Blank.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        /**
         * @brief Constructs a Blank command.
         *
         * This command creates a new image with the given width, height, and fill color,
         * replacing the original image.
         *
         * @param w Width of the new image.
         * @param h Height of the new image.
         * @param fill Fill color to apply to all pixels.
         */
        Blank::Blank(int w, int h, Color &fill) : Command("Blank"), w(w), h(h), fill(fill) {}

        /**
         * @brief Destructor for the Blank command.
         */
        Blank::~Blank() {}

        /**
         * @brief Applies the Blank command.
         *
         * Deletes the existing image and creates a new one with the specified dimensions and color.
         *
         * @param img The original image (to be deleted).
         * @return A new image filled with the specified color.
         */
        Image *Blank::apply(Image *img) {
            delete img;  ///< Dispose of the existing image
            return new Image(w, h, fill);
        }

        /**
         * @brief Returns a string representation of the Blank command.
         *
         * Includes the dimensions and fill color in the output.
         *
         * @return A descriptive string for debugging or logging.
         */
        std::string Blank::toString() const {
            std::ostringstream ss;
            ss << name() << " w:" << w << " h:" << h << " fill:" << fill;
            return ss.str();
        }

    } // namespace command
} // namespace prog
