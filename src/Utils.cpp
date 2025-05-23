//
// Created by joaob on 15/04/2025.
//
#include "Utils.h"
#include <filesystem>
#include <iostream>

using std::string;

namespace fs = std::filesystem;

namespace prog {

    /**
     * @brief Creates a directory and any necessary parent directories.
     *
     * If the directory already exists or the folder name is empty,
     * the function returns true without creating anything.
     *
     * @param foldername The path of the directory to create.
     * @return true if the directory was created successfully or already exists.
     * @return false if the directory could not be created.
     */
    bool mkdir(const std::string & foldername) {

        if (!foldername.empty() && !fs::exists(foldername)) {
            std::error_code ec;
            if (fs::create_directories(foldername, ec)) {
                return true;
            }

            if (ec) {
                std::cerr << "Failed to create directory: " << ec.message() << "\n";
                return false;
            }

            std::cerr << "Failed to create directory\n";
            return false;
        }

        return true;
     }

    /**
     * @brief Deletes all regular files inside the specified directory.
     *
     * Does not remove subdirectories or their contents.
     * Prints an error if the folder does not exist or is not a directory.
     *
     * @param foldername The path to the directory from which files will be deleted.
     * @return true if the files were deleted successfully or if the directory is empty.
     * @return false if the folder does not exist or is not a directory.
     */
     bool delete_files(std::string const & foldername) {

        if (!fs::exists(foldername) || !fs::is_directory(foldername)) {
            std::cerr << "Invalid folder name for deletion: '" << foldername << "'\n";
            return false;
        }

        for (const auto& entry : fs::directory_iterator(foldername)) {
            if (fs::is_regular_file(entry)) {
                fs::remove(entry.path());
            }
        }

        return true;
     }

}