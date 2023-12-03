/**
 * Nume fisier: Ground.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 11/11/2023
 * Descriere:
 * \brief Reprezinta solul jocului.
 *
 * Aceasta clasa se ocupa de implementarea si desenarea solului pe ecran.
 */

#ifndef OOP_GROUND_HPP
#define OOP_GROUND_HPP

#include <SFML/Graphics.hpp>
#include "Exceptions.hpp"

class Ground {
private:
    /**
     * \brief Textura solului.
     */
    sf::Texture grTexture;

    /**
     * \brief Sprite-ul solului.
     */
    sf::Sprite grSprite;

    /**
     * \brief Diferenta pe axa OX intre doua sprite-uri ale solului.
     */
    static float offsetX;

    /**
     * \brief Diferenta pe axa OY intre doua sprite-uri ale solului.
     */
    static float offsetY;
public:
    /**
     * \brief Creeaza un sol.
     */
    Ground();

    /**
     * \brief Destructor pentru sol.
     */
    ~Ground();

    /**
     * \brief Miscarea solului.
     * @param elapsedTime Timpul dintre ultimele 2 cadre ale jocului, utilizat pentru asigurarea unei miscari fluente.
     */
    void move(float elapsedTime);

    /**
     * \brief Desenarea solului pe ecran.
     * @param window Furnizeaza o referinta catre fereastra jocului.
     */
    void draw(sf::RenderWindow& window);

    /**
     * Getter pentru sprite-ul solului.
     * @return Referinta constanta catre sprite-ul solului.
     */
    const sf::Sprite & getGroundSprite() const;

//    friend std::ostream& operator<<(std::ostream& out, const Ground& ground);
//    Ground(const Ground& other);
//    Ground& operator=(Ground other);
//    friend void swap(Ground& groundA, Ground& groundB);

};



#endif //OOP_GROUND_HPP
