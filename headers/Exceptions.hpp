/**
 * File name: Exceptions.hpp
 * Author: Banu Constantin-Adrian
 * Date: 30/11/2023
 * Description:
 *
 * \brief Represents the class responsible for exception handling.
 */

#ifndef OOP_EXCEPTIONS_HPP
#define OOP_EXCEPTIONS_HPP

#include <iostream>

class TextureLoadException : public std::exception {
public:
    /**
     * \brief Displays a suggestive message when a texture fails to load correctly.
     * @return User-friendly message.
     */
    const char* what() const noexcept;
};

class FontLoadException : public std::exception {
public:
    /**
     * \brief Displays a suggestive message when a font fails to load correctly.
     * @return User-friendly message.
     */
    const char* what() const noexcept;
};

class IconLoadException : public std::exception {
public:
    /**
     * \brief Displays a suggestive message when the game icon fails to load correctly.
     * @return User-friendly message.
     */
    const char* what() const noexcept;
};

class WrongFuncException : public std::exception {
public:
    /**
     * \brief Displays a suggestive message when a function is not called from the appropriate derived class.
     * @return User-friendly message.
     */
    const char* what() const noexcept;
};

class UnknownBirdException : public std::exception {
public:
    /**
     * \brief Displays a suggestive message when the bird sent as an argument to the factory class creation function does not exist.
     * @return User-friendly message.
     */
    const char* what() const noexcept;
};

#endif //OOP_EXCEPTIONS_HPP
