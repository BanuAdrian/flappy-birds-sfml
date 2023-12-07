/**
 * Nume fisier: Bird.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 17/11/2023
 * Descriere:
 * \brief Reprezinta clasa de baza/interfata pentru caracterul jocului.
 *
 * Aceasta clasa se ocupa de reprezentarea in joc, desenarea si furnizarea caracteristicilor pentru fiecare
 * tip de pasare.
 */

#ifndef OOP_BIRD_HPP
#define OOP_BIRD_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Exceptions.hpp"

class Bird {
protected:
    /**
     * \brief Textura pasarii cu aripile in sus.
     */
    sf::Texture birdTextureUpFlap;

    /**
     * \brief Textura pasarii cu aripile centrate;
     */
    sf::Texture birdTextureMidFlap;

    /**
     * \brief Textura pasarii cu aripile in jos.
     */
    sf::Texture birdTextureDownFlap;

    /**
     * \brief Sprite-ul pasarii.
     */
    sf::Sprite birdSprite;

    /**
     * \brief Ceasul folosit pentru animatia aripilor.
     */
    std::shared_ptr<sf::Clock> wingsAnimationGeneratingClock;

    /**
     * \brief Scorul necesar ca jucatorul sa poata faca upgrade la acest caracter.
     */
    int scoreNeeded;

    /**
     * \brief Determina daca aripile sunt orientate in sus sau in jos.
     */
    bool wingsUp;

    /**
     * \brief Pozitia pe axa OX.
     */
    float posX;

    /**
     * \brief Pozitia pe axa OY.
     */
    float posY;

    /**
     * \brief Viteza caracterului.
     */
    float velocity;

    /**
     * \brief Unghiul de rotatie al sprite-ului.
     */
    float rotationAngle;

public:
    /**
     * \brief Construieste o noua pasare.
     *
     * @param localScoreNeeded Scorul necesar pentru aceasta pasare.
     */
    explicit Bird(int localScoreNeeded = 0);

    /**
     * \brief Destructor virtual.
     */
    virtual ~Bird();

    /**
     * \brief Determina abilitatea pasarii de a zbura.
     */
    void fly();

    /**
     * \brief Determina caderea pasarii.
     *
     * @param elapsedTime Timpul dintre ultimele 2 cadre ale jocului, utilizat pentru asigurarea unei miscari fluente.
     */
    void fall(float elapsedTime);

    /**
     * \brief Actualizeaza pozitia pasarii.
     */
    void update();

    /**
     * \brief Deseneaza caracterul pe ecran.
     *
     * @param window Furnizeaza o referinta catre fereastra jocului.
     */
    void draw(sf::RenderWindow &window);

    /**
     * \brief Permite resetarea atributelor in momentul coliziunii.
     */
    void reset();

    /**
     * \brief Implementeaza animatia aripilor.
     *
     * @param gameHasBegun Comunica starea jocului.
     */
    void animateWings(bool gameHasBegun);

    /**
     * \brief Getter pentru sprite-ul caracterului.
     *
     * @return Referinta constanta catre sprite-ul caracterului.
     */
    const sf::Sprite & getBirdSprite() const;

    /**
     * \brief "Constructor" virtual
     *
     * @return Pointer la clasa de baza Bird.
     */
//    virtual Bird* clone() const = 0;

    /**
     * \brief Getter pentru numarul de vieti al pasarii.
     *
     * @return Strict 0 pentru clasele derivate "YellowBird" si "BlueBird"; >= 0 pentru clasa derivata "RedBird".
     */
    virtual int getLives() const = 0;

    /**
     * \brief Getter pentru scorul necesar.
     *
     * @return >= 0 in functie de caracterul curent.
     */
    virtual int getScoreNeeded() const = 0;

    /**
     * \brief Implementarea abilitatii de a reinvia in cazul clasei derivate "RedBird".
     */
    virtual void revive() = 0;

    /**
     * \brief Gestionarea coliziunii.
     */
    virtual void handleCollision() = 0;

    /**
     * \brief Afisarea unui text special in functie de caracterul curent.
     *
     * @param window Furnieaza o referinta catre fereastra jocului.
     */
    virtual void displaySpecialText(sf::RenderWindow &window) = 0;

    /**
     * \brief Implementarea abilitatii speciale pentru clasa derivata "BlueBird".
     */
    virtual void specialAbility() = 0;

    /**
     * \brief Incarcarea transparentei pentru clasa derivata "BlueBird".
     */
    virtual void loadTransparence() = 0;

    /**
     * \brief Incarcarea vietilor pentru clasa derivata "RedBird".
     */
    virtual void loadLives() = 0;

    /**
     * \brief Verifica starea de transparenta.
     *
     * @return True daca pasarea este transparenta si False in caz contrar.
     */
    virtual bool isTransparent() const = 0;

    //    friend std::ostream& operator<<(std::ostream& out, const Pet& pet);
};


#endif //OOP_BIRD_HPP
