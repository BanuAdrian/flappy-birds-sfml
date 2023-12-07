/**
 * Nume fisier: RedBird.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 17/11/2023
 * Descriere:
 * \brief Reprezinta pasarea rosie.
 *
 * Aceasta clasa mosteneste clasa de baza "Bird" si, in plus, implementeaza abilitatea de a reinvia specifica acestui tip de pasare.
 */

#ifndef OOP_REDBIRD_HPP
#define OOP_REDBIRD_HPP

#include "Bird.hpp"

class RedBird : public Bird{
private:
    /**
     * \brief Numarul de vieti ale caracterului la un anumit moment.
     */
    static int lives;

    /**
     * \brief Textul utilizat pentru afisarea numarului de vieti.
     */
    sf::Text livesText;

    /**
     * \brief Fontul textului.
     */
    sf::Font font;

    /**
     * \brief Ceas care se ocupa de generarea vietilor.
     */
    std::shared_ptr<sf::Clock> livesGeneratingClock;

public:
    /**
     * \brief Creeaza o pasare rosie.
     * @param localScoreNeeded Scorul necesar pentru o astfel de pasare.
     */
    explicit RedBird(int localScoreNeeded = 5);

    /**
     * \brief Destructorul specific acestei clase derivate.
     */
    ~RedBird() override;

    /**
     * \brief "Constructor" virtual
     *
     * @return Pointer la clasa derivata "RedBird".
     */
//    RedBird* clone() const override;

    /**
     * \brief Getter pentru numarul de vieti al pasarii.
     *
     * @return >= 0, in functie de numarul de vieti disponibile la un anumit moment.
     */
    int getLives() const override;

    /**
     * \brief Getter pentru scorul necesar.
     *
     * @return >= 0 in functie de caracterul curent.
     */
    int getScoreNeeded() const override;

    /**
     * \brief Implementarea abilitatii de a reinvia.
     */
    void revive() override;

    /**
     * \brief Gestionarea coliziunii.
     */
    void handleCollision() override;

    /**
     * \brief Incarcarea transparentei in cazul clasei derivate "BlueBird".
     */
    void loadTransparence() override;

    /**
     * \brief Incarcarea vietilor.
     */
    void loadLives() override;

    /**
     * \brief Verifica starea de transparenta.
     *
     * @return True daca pasarea este transparenta si False in caz contrar.
     */
    bool isTransparent() const override;

    /**
     * \brief Afiseaza numarul de vieti disponibile.
     *
     * @param window Furnieaza o referinta catre fereastra jocului.
     */
    void displaySpecialText(sf::RenderWindow &window) override;

    /**
     * \brief Implementarea transparentei.
     */
    void specialAbility() override;



};


#endif //OOP_REDBIRD_HPP
