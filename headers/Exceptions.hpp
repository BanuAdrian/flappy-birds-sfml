/**
 * Nume fisier: Exceptions.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 30/11/2023
 * Descriere:
 *
 * \brief Reprezinta clasa care se ocupa cu gestionarea exceptiilor.
 */

#ifndef OOP_EXCEPTIONS_HPP
#define OOP_EXCEPTIONS_HPP

#include <iostream>

class TextureLoadException : public std::exception {
public:
    /**
     * \brief Afiseaza un mesaj sugestiv atunci cand o textura nu s-a putut incarca corect.
     * @return Mesajul pentru utilizator.
     */
    const char* what() const noexcept;
};

class FontLoadException : public std::exception {
public:
    /**
     * \brief Afiseaza un mesaj sugestiv atunci cand un font nu s-a putut incarca corect.
     * @return Mesajul pentru utilizator.
     */
    const char* what() const noexcept;
};

class IconLoadException : public std::exception {
public:
    /**
     * \brief Afiseaza un mesaj sugestiv atunci cand iconita jocului nu s-a putut incarca corect.
     * @return Mesajul pentru utilizator.
     */
    const char* what() const noexcept;
};

class WrongFuncException : public std::exception {
public:
    /**
     * \brief Afiseaza un mesaj sugestiv atunci cand o functie nu este apelata din clasa derivata corespunzatoare.
     * @return Mesajul pentru utilizator.
     */
    const char* what() const noexcept;
};
#endif //OOP_EXCEPTIONS_HPP
