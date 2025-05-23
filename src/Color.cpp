#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {

    /**
     * @class Color
     * @brief Represents an RGB color with red, green, and blue components.
     */

    /**
     * @brief Default constructor. Initializes color to black (0,0,0).
     */
    Color::Color() {
        red_ = 0;
        green_ = 0;
        blue_ = 0;
    }

    /**
     * @brief Copy constructor.
     * @param other Another Color object to copy from.
     */
    Color::Color(const Color &other) {
        red_ = other.red_;
        green_ = other.green_;
        blue_ = other.blue_;
    }

    /**
     * @brief Constructor with specified RGB values.
     * @param red Red component value.
     * @param green Green component value.
     * @param blue Blue component value.
     */
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        red_ = red;
        green_ = green;
        blue_ = blue;
    }

    /**
     * @brief Get the red component (const).
     * @return Red component value.
     */
    rgb_value Color::red() const {
        return red_;
    }

    /**
     * @brief Get the green component (const).
     * @return Green component value.
     */
    rgb_value Color::green() const {
        return green_;
    }

    /**
     * @brief Get the blue component (const).
     * @return Blue component value.
     */
    rgb_value Color::blue() const {
        return blue_;
    }

    /**
     * @brief Get a reference to the red component for modification.
     * @return Reference to red component.
     */
    rgb_value &Color::red() {
        return red_;
    }

    /**
     * @brief Get a reference to the green component for modification.
     * @return Reference to green component.
     */
    rgb_value &Color::green() {
        return green_;
    }

    /**
     * @brief Get a reference to the blue component for modification.
     * @return Reference to blue component.
     */
    rgb_value &Color::blue() {
        return blue_;
    }

} // namespace prog

/**
 * @brief Extraction operator overload to read color components from a stream.
 *
 * Reads three integers (r, g, b) from the input stream and sets
 * the corresponding components of the Color object.
 *
 * @param input Input stream to read from.
 * @param c Color object to populate.
 * @return Reference to the input stream.
 */
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

/**
 * @brief Insertion operator overload to write color components to a stream.
 *
 * Outputs the color components in the format "R:G:B".
 *
 * @param output Output stream to write to.
 * @param c Color object to output.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int)c.red() << ":" << (int)c.green() << ":" << (int)c.blue();
    return output;
}