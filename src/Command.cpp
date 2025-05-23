//
// Created by JBispo on 05/04/2025.
//
#include "Command.hpp"

namespace prog {

    /**
     * @class Command
     * @brief Abstract base class representing a generic command.
     */

    /**
     * @brief Constructor initializing the command with a name.
     * @param command_name The name/identifier of the command.
     */
    Command::Command(std::string command_name) : command_name(command_name) {
    }

    /**
     * @brief Virtual destructor.
     */
    Command::~Command() {
    }

    /**
     * @brief Retrieves the name of the command.
     * @return The command's name as a string.
     */
    std::string Command::name() const {
        return command_name;
    }

    /**
     * @brief Returns a string representation of the command.
     *
     * Default implementation simply returns the command name.
     * Derived classes can override to provide more details.
     *
     * @return A string describing the command.
     */
    std::string Command::toString() const {
        return command_name;
    }

} // namespace prog

/**
 * @brief Overloads the output stream operator to write the command's string representation.
 *
 * @param output The output stream.
 * @param command The command object to output.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &output, const prog::Command &command) {
    output << command.toString();
    return output;
}