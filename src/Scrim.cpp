//
// Created by JBispo on 05/04/2025.
//
#include "Scrim.hpp"
#include "Logger.hpp"

using prog::Command;

namespace prog {

    /**
     * @brief Constructs a Scrim object with a list of commands.
     *
     * @param commands Reference to a vector of pointers to Command objects to be applied in sequence.
     */
    Scrim::Scrim(std::vector<Command *> &commands) : commands(commands) {
    }

    /**
     * @brief Destructor for Scrim.
     *
     * Deletes all commands stored in the vector to free memory.
     */
    Scrim::~Scrim() {
        // Deallocate each command
        for (Command *c: commands) {
            delete c;
        }
    };

    /**
     * @brief Applies all commands sequentially to the given image.
     *
     * Each command modifies the image, and the result is passed to the next command.
     * Logs the application of each command.
     *
     * @param img Pointer to the Image object to be processed.
     * @return Image* Pointer to the resulting Image after all commands have been applied.
     */
    Image *Scrim::run(Image *img) {
        for (Command *c: commands) {
            *Logger::out() << "Applying command '" << c->toString() << "'\n";
            img = c->apply(img);
        }

        return img;
    }

    /**
     * @brief Applies all commands to a null image.
     *
     * Calls run with a nullptr image.
     *
     * @return Image* Resulting Image after applying all commands starting from null.
     */
    Image *Scrim::run() {
        return this->run(nullptr);
    }

    /**
     * @brief Returns the vector of commands stored in the Scrim.
     *
     * @return std::vector<Command *> Vector of pointers to Command objects.
     */
    std::vector<Command *> Scrim::getCommands() const {
        return commands;
    }
}
