#ifndef __prog_PNG_hpp__
#define __prog_PNG_hpp__

#include <string>
#include <iostream>
#include "Image.hpp"

namespace prog {
    /**
     * @brief Loads an image from a PNG file.
     *
     * @param file Path to the PNG file to load.
     * @return Pointer to a newly allocated Image object containing the loaded image.
     *         Returns nullptr if loading fails.
     */
    Image* loadFromPNG(const std::string &file);

    /**
     * @brief Saves an Image object to a PNG file.
     *
     * @param file Path to the output PNG file.
     * @param img Pointer to the Image object to save.
     */
    void saveToPNG(const std::string& file, const Image* img);

    /**
     * @brief Compares two PNG files for equality.
     *
     * @param file1 Path to the first PNG file.
     * @param file2 Path to the second PNG file.
     * @return true if the PNG files are identical, false otherwise.
     */
    bool comparePNG(const std::string& file1, const std::string& file2);
}

#endif
