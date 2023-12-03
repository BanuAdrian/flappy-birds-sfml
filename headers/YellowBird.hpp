/**
 * Nume fisier: YellowBird.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 17/11/2023
 * Descriere:
 * \brief Reprezinta pasarea galbena.
 *
 * Aceasta clasa mosteneste clasa de baza "Bird".
 */

#ifndef OOP_YELLOWBIRD_HPP
#define OOP_YELLOWBIRD_HPP

#include "Bird.hpp"

class YellowBird : public Bird{
public:
    /**
     * \brief Creeaza o pasare galbena.
     */
    explicit YellowBird(int localScoreNeeded = 0);

    /**
     * \brief Destructorul specific acestei clase derivate.
     */
    ~YellowBird() override;

    /**
     * \brief "Constructor" virtual
     *
     * @return Pointer la clasa derivata "YellowBird".
     */
    YellowBird* clone() const override;

    /**
     * \brief Getter pentru numarul de vieti al pasarii.
     *
     * @return 0, deoarece este o abilitate specifica clasei derivate "RedBird"
     */
    int getLives() const override;

    /**
     * \brief Getter pentru scorul necesar.
     *
     * @return 0, deoarece este caracterul de inceput.
     */
    int getScoreNeeded() const override;

    /**
     * \brief Implementarea abilitatii de a reinvia in cazul clasei derivate "RedBird".
     */
    void revive() override;

    /**
     * \brief Gestionarea coliziunii.
     */
    void handleCollision() override;

    /**
     * \brief Incarcarea transparentei pentru clasa derivata "BlueBird".
     */
    void loadTransparence() override;

    /**
     * \brief Incarcarea vietilor pentru clasa derivata "RedBird".
     */
    void loadLives() override;

    /**
     * \brief Afisarea unui text special in functie de caracterul curent.
     *
     * @param window Furnieaza o referinta catre fereastra jocului.
     */
    void displaySpecialText(sf::RenderWindow &window) override;

    /**
     * \brief Implementarea abilitatii speciale pentru clasa derivata "BlueBird".
     */
    void specialAbility() override;

    /**
     * \brief Verifica starea de transparenta.
     *
     * @return True daca pasarea este transparenta si False in caz contrar.
     */
    bool isTransparent() const override;
};



#endif //OOP_YELLOWBIRD_HPP
