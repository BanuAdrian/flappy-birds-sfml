/**
 * Nume fisier: BlueBird.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 17/11/2023
 * Descriere:
 * \brief Reprezinta pasarea albastra.
 *
 * Aceasta clasa mosteneste clasa de baza "Bird" si, in plus, implementeaza transparenta specifica acestui tip de pasare.
 */

#ifndef OOP_BLUEBIRD_HPP
#define OOP_BLUEBIRD_HPP

#include <memory>
#include "Bird.hpp"

class BlueBird : public Bird{
private:
    /**
     * \brief Specifica daca abilitatea de transparenta este pregatita.
     */
    bool transparenceReady;

    /**
     * \brief Specifica daca pasarea este transparenta la momentul respectiv.
     */
    bool transparentNow;

    /**
     * \brief Textul pentru a afisa un mesaj sugestiv in legatura cu disponibilitatea abilitatii de transparenta.
     */
    sf::Text transparenceText;

    /**
     * \brief Fontul folosit pentru text.
     */
    sf::Font font;

    /**
     * \brief Ceasul folosit pentru a gestiona transparenta.
     */
    std::shared_ptr<sf::Clock> transparenceHandlingClock;

public:
    /**
     * \brief Construieste o noua pasare albastra.
     * @param localScoreNeeded Scorul necesar pentru o astfel de pasare.
     */
    explicit BlueBird(int localScoreNeeded = 2);

    /**
     * \brief Destructorul specific acestei clase derivate.
     */
    ~BlueBird() override;

    /**
     * \brief "Constructor" virtual
     *
     * @return Pointer la clasa derivata "BlueBird".
     */
//    BlueBird* clone() const override;

    /**
     * \brief Getter pentru numarul de vieti al pasarii.
     *
     * @return 0, deoarece este o abilitate specifica clasei derivate "RedBird"
     */
    int getLives() const override;

    /**
     * \brief Getter pentru scorul necesar.
     *
     * @return >= 0 in functie de caracterul curent.
     */
    int getScoreNeeded() const override;

    /**
     * \brief Implementarea abilitatii de a reinvia in cazul clasei derivate RedBird.
     */
    void revive() override;

    /**
     * \brief Gestionarea coliziunii.
     */
    void handleCollision() override;

    /**
     * \brief Incarcarea transparentei.
     */
    void loadTransparence() override;

    /**
     * \brief Incarcarea vietilor pentru clasa derivata "RedBird".
     */
    void loadLives() override;

    /**
     * \brief Verifica starea de transparenta.
     *
     * @return True daca pasarea este transparenta si False in caz contrar.
     */
    bool isTransparent() const override;

    /**
     * \brief Afiseaza disponibilitatea transparentei.
     *
     * @param window Furnieaza o referinta catre fereastra jocului.
     */
    void displaySpecialText(sf::RenderWindow &window) override;

    /**
     * \brief Implementarea abilitatii speciale pentru clasa derivata "BlueBird".
     */
    void specialAbility() override;
};


#endif //OOP_BLUEBIRD_HPP
