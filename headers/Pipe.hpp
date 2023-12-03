/**
 * Nume fisier: Pipe.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 11/11/2023
 * Descriere:
 * \brief Reprezinta tevile de sus si jos.
 *
 * Aceasta clasa se ocupa de implementarea si desenarea tevilor pe ecran.
 *
 */

#ifndef OOP_PIPE_HPP
#define OOP_PIPE_HPP

#include <SFML/Graphics.hpp>
#include "Exceptions.hpp"

class Pipe {
protected:
    /**
     * \brief Textura unei tevi.
     */
    sf::Texture pipeTexture;

    /**
     * \brief Sprite-ul tevii de sus.
     */
    sf::Sprite topPipeSprite;

    /**
     * \brief Sprite-ul tevii de jos.
     */
    sf::Sprite bottomPipeSprite;

    /**
     * \brief Viteza tevilor.
     */
    sf::Vector2f velocity;

    /**
     * \brief Pozitia pe axa OY a tevilor.
     */
    int PosY;
public:
    /**
     * \brief Creeaza un obstacol.
     */
    Pipe();

    /**
     * \brief Deseneaza tevile pe ecran.
     * @param window Furnizeaza o referinta catre fereastra jocului.
     */
    void draw(sf::RenderWindow& window);

    /**
     * \brief Actualizeaza tevile.
     * @param elapsedTime Timpul dintre ultimele 2 cadre ale jocului, utilizat pentru asigurarea unei miscari fluente.
     */
    void update(float elapsedTime);

    /**
     * Getter pentru sprite-ul tevii de sus.
     * @return Referinta constanta catre sprite-ul tevii de sus.
     */
    const sf::Sprite & getTopPipeSprite() const;

    /**
     * Getter pentru sprite-ul tevii de jos.
     * @return Referinta constanta catre sprite-ul tevii de jos.
     */
    const sf::Sprite & getBottomPipeSprite() const;

//    Pipe(const Pipe& other);
//    friend void swap(Pipe pipeA, Pipe pipeB);
//    Pipe& operator=(Pipe other);
};



#endif //OOP_PIPE_HPP
