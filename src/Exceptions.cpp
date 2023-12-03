//
// Created by Adrian on 30-Nov-23.
//

#include "../headers/Exceptions.hpp"

const char* TextureLoadException::what() const noexcept {
    return "One or more textures failed to load!";
}

const char* FontLoadException::what() const noexcept {
    return "One or more fonts failed to load!";
}

const char* IconLoadException::what() const noexcept {
    return "Game icon failed to load!";
}

const char* WrongFuncException::what() const noexcept {
    return "Wrong function call!";
}