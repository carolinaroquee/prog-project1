//
// Created by JBispo on 05/04/2025.
//

#ifndef PROJECT_COMMAND_HPP
#define PROJECT_COMMAND_HPP

#include "Image.hpp"
#include <string>

namespace prog {

    /**
     * @brief Abstract base class representing an image command.
     *
     * Each command can be applied to an Image to perform a transformation.
     */
    class Command {
    public:
        /**
         * @brief Constructor that initializes the command with a name.
         * @param command_name The name of the command.
         */
        Command(std::string command_name);

        /**
         * @brief Virtual destructor (pure virtual, making this an abstract class).
         */
        virtual ~Command() = 0;

        /**
         * @brief Applies this command to the given image.
         *
         * @param img Pointer to the image to modify.
         * @return Pointer to the resulting image after applying the command.
         * The returned pointer can be the same as the input or a new one.
         * If a new image pointer is returned, the old one should be deleted.
         */
        virtual Image *apply(Image *img) = 0;

        /**
         * @brief Returns a string representation of the command.
         *
         * Useful for logging or debugging.
         *
         * @return std::string String describing the command.
         */
        virtual std::string toString() const;

        /**
         * @brief Returns the name of the command.
         * @return std::string The command's name.
         */
        std::string name() const;

    private:
        std::string command_name; ///< Name of the command instance
    };
}

/**
 * @brief Output stream operator for Command.
 *
 * Allows printing the command's string representation.
 *
 * @param output Output stream.
 * @param command Command to print.
 * @return std::ostream& Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, const prog::Command &command);

#endif //PROJECT_COMMAND_HPP
