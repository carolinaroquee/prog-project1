//
// Created by José Proença on 16/04/2025.
//
#include "Logger.hpp"

namespace prog {

    /**
     * @class Logger
     * @brief Singleton logger class for logging messages and errors with a prefix.
     */

    /**
     * @brief Returns the singleton instance of Logger.
     * @return Reference to the Logger instance.
     */
    Logger& Logger::getInstance() {
        static Logger instance;
        return instance;
    }

    /**
     * @brief Sets the output stream used for normal log messages.
     * @param stream Reference to an output stream (e.g., std::cout, file stream).
     */
    void Logger::setEStream(std::ostream& stream) {
        Logger::getInstance().err_ = &stream;
    }

    /**
     * @brief Sets the output stream used for error messages.
     * @param stream Reference to an output stream (e.g., std::cerr, file stream).
     */
    void Logger::setOStream(std::ostream& stream) {
        Logger::getInstance().out_ = &stream;
    }

    /**
     * @brief Logs a message to the output stream with a prefix.
     * @param message The message string to log.
     */
    void Logger::log(const std::string& message) {
        std::ostream* out = getInstance().out_;
        if (out) {
            (*out) << getInstance().prefix << message << std::endl;
        }
    }

    /**
     * @brief Logs an error message to the error stream with a prefix.
     * @param message The error message string to log.
     */
    void Logger::error(const std::string& message) {
        std::ostream* err = getInstance().err_;
        if (err) {
            (*err) << getInstance().prefix << message << std::endl;
        }
    }

    /**
     * @brief Returns a pointer to the output stream, with the prefix inserted.
     * @return Pointer to the output stream.
     */
    std::ostream* Logger::out() {
        return &(*getInstance().out_ << getInstance().prefix);
    }

    /**
     * @brief Returns a pointer to the error stream, with the prefix inserted.
     * @return Pointer to the error stream.
     */
    std::ostream* Logger::err() {
        return &(*getInstance().err_ << getInstance().prefix);
    }

} // namespace prog
