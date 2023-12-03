/**
 * Nume fisier: Background.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 11/11/2023
 * Descriere:
 * \brief Reprezinta fundalul jocului.
 *
 * Aceasta clasa se ocupa de implementarea si desenarea fundalului pe ecran.
 *
 */

#ifndef OOP_BACKGROUND_HPP
#define OOP_BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include "Exceptions.hpp"

class Background {
protected:
    /**
     * \brief Textura fundalului.
     */
    sf::Texture bgTexture;

    /**
     * \brief Sprite-ul fundalului.
     */
    sf::Sprite bgSprite;

public:
    /**
     * \brief Produce un nou fundal.
     */
    Background();

    /**
     * \brief Deseneaza fundalul pe ecran.
     *
     * @param window Furnizeaza o referinta catre fereastra jocului.
     */
    void draw(sf::RenderWindow& window);

//    Background(const Background& other);
//    friend void swap(Background bgA, Background bgB);
//    Background& operator=(Background other);
//    friend std::ostream& operator<<(std::ostream& out, const Background& background);
};



#endif //OOP_BACKGROUND_HPP
