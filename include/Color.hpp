#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

#include <iostream>

namespace prog {

    using rgb_value = unsigned char;

    /**
     * @brief Represents a color using RGB values.
     */
    class Color {
    private:
        rgb_value red_, green_, blue_; ///< Red, Green, and Blue color components

    public:
        /**
         * @brief Default constructor. Initializes color components to zero.
         */
        Color();

        /**
         * @brief Copy constructor.
         * @param c Color object to copy from.
         */
        Color(const Color &c);

        /**
         * @brief Constructor initializing color with specific RGB values.
         * @param r Red component (0-255)
         * @param g Green component (0-255)
         * @param b Blue component (0-255)
         */
        Color(rgb_value r, rgb_value g, rgb_value b);

        /**
         * @brief Get the red component (read-only).
         * @return rgb_value Red component value.
         */
        rgb_value red() const;

        /**
         * @brief Get the red component (modifiable).
         * @return Reference to the red component.
         */
        rgb_value &red();

        /**
         * @brief Get the green component (read-only).
         * @return rgb_value Green component value.
         */
        rgb_value green() const;

        /**
         * @brief Get the green component (modifiable).
         * @return Reference to the green component.
         */
        rgb_value &green();

        /**
         * @brief Get the blue component (read-only).
         * @return rgb_value Blue component value.
         */
        rgb_value blue() const;

        /**
         * @brief Get the blue component (modifiable).
         * @return Reference to the blue component.
         */
        rgb_value &blue();
    };
}

/**
 * @brief Extracts a Color from an input stream.
 * @param input Input stream.
 * @param c Color object to populate.
 * @return std::istream& Reference to the input stream.
 */
std::istream &operator>>(std::istream &input, prog::Color &c);

/**
 * @brief Inserts a Color into an output stream.
 * @param output Output stream.
 * @param c Color object to insert.
 * @return std::ostream& Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, const prog::Color &c);

#endif
