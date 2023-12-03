/**
 * Nume fisier: Game.hpp
 * Autor: Banu Constantin-Adrian
 * Data: 11/11/2023
 * Descriere:
 * \brief Reprezinta jocul propriu-zis.
 *
 * Aceasta clasa se ocupa de functionalitatile jocului.
 */

#ifndef OOP_GAME_HPP
#define OOP_GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Ground.hpp"
#include "YellowBird.hpp"
#include "BlueBird.hpp"
#include "RedBird.hpp"
#include "Pipe.hpp"
#include "Background.hpp"
#include "Exceptions.hpp"

#define YELLOW_BIRD 1
#define RED_BIRD 2
#define BLUE_BIRD 3

class Game {
private:
    /**
     * \brief Fereastra jocului.
     */
    sf::RenderWindow window;

    /**
     * \brief Textul pentru scor.
     */
    sf::Text scoreText;

    /**
     * \brief Textul pentru cel mai mare scor obtinut de jucator.
     */
    sf::Text highestScoreText;

    /**
     * \brief Fontul pentru text.
     */
    sf::Font font;

    /**
     * \brief Ceasul folosit pentru gestionarea cadrelor jocului.
     */
    std::shared_ptr<sf::Clock>frameHandlingClock;

    /**
     * \brief Ceasul folosit pentru generarea tevilor.
     */
    std::shared_ptr<sf::Clock>pipeGeneratingClock;

    /**
     * \brief Ceasul folosit pentru generarea scorului.
     *
     * Din moment ce obstacolele sunt generate la o perioada constanta de timp, scorul creste in functie de acest aspect.
     */
    std::shared_ptr<sf::Clock>scoreGeneratingClock;

    /**
     * \brief Obstacolele jocului reprezentate de tevi.
     */
    std::vector<Pipe*> pipes;

    /**
     * \brief Caracterul curent.
     */
    Bird *bird;

    /**
     * \brief Pasarea rosie.
     */
    RedBird redBird;

    /**
     * \brief Pasarea galbena.
     */
    YellowBird yellowBird;

    /**
     * \brief Pasarea albastra.
     */
    BlueBird blueBird;

    /**
     * \brief Fundalul jocului.
     */
    Background background;

    /**
     * \brief Solul jocului.
     */
    Ground ground;

    /**
     * \brief Timpul dintre ultimele 2 cadre ale jocului, utilizat pentru asigurarea unor miscari fluente ale sprite-urilor.
     */
    static float elapsedTime;

    /**
     * \brief Specifica daca jocul ruleaza.
     */
    static bool isRunning;

    /**
     * \brief Specifica daca jocul a inceput.
     */
    static bool hasBegun;

    /**
     * \brief Scorul obtinut inainte de o coliziune.
     */
    static int score;

    /**
     * \brief Cel mai mare scor obtinut de jucator pentru sesiunea respectiva de joc.
     */
    static int highestScore;

    /**
     * \brief Specifica pasarea curenta.
     */
    static int currentBird;

public:
    /**
     * \brief Creeaza un joc nou.
     */
    Game();

    /**
     * \brief Destructorul jocului.
     */
    ~Game();

    /**
     * \brief Detecteaza coliziunea cu solul.
     * @return True daca pasarea s-a lovit de sol si False in caz contrar.
     */
    bool groundCollision() const;

    /**
     * \brief Detecteaza coliziunea cu tevile.
     * @return True daca pasarea s-a lovit de tevi si False in caz contrar.
     */
    bool pipeCollision() const;

    /**
     * \brief Detecteaza coliziunea cu limitele ecranului.
     * @return True daca pasarea urma sa depaseasca limitele ecranului si False in caz contrar.
     */
    bool outOfScreenCollision() const;

    /**
     * \brief Furnizeaza setarile ferestrei.
     */
    void windowSettings();

    /**
     * \brief Furnizeaza setarile textului.
     */
    void textSettings();

    /**
     * \brief Furnizeaza valori initiale pentru atributele jocului.
     */
    void initSettings();

    /**
     * \brief Gestioneaza evenimentele din cadrul ferestrei jocului.
     *
     * Evenimentele pot fi: inchiderea ferestrei, apasarea unui buton sau a unui click.
     */
    void handleEvents();

    /**
     * \brief Gestioneaza timpul dintre ultimele doua frame-uri ale jocului.
     */
    void handleTime();

    /**
     * \brief Trateaza textul afisat.
     */
    void handleText();

    /**
     * \brief Gestioneaza scorul.
     */
    void handleScore();

    /**
     * \brief Trateaza coliziunea cu obstacolele.
     */
    void handleCollision();

    /**
     * \brief Verifica orice tip de coliziune.
     */
    void checkCollision();

    /**
     * \brief Actualizeaza obiectele jocului.
     */
    void updateObjects();

    /**
     * \brief Deseneaza obiectele jocului.
     */
    void drawObjects();

    /**
     * \brief Randeaza scenele jocului.
     */
    void render();

    /**
     * \brief Actualizeaza caracterul in functie de cel mai mare scor obtinut de jucator.
     */
    void upgradeBird();

    /**
     * \brief Incepe jocul.
     */
    void start();

    /**
     * \brief Actualizeaza cel mai mare scor obtinut de jucator.
     */
    static void updateHighestScore();

    /**
     * \brief Reseteaza scorul.
     */
    static void resetScore();

//    Game &operator=(Game other);
//    Game(const Game& other);
//    friend std::ostream& operator<<(std::ostream& out, const Game& game);
//    friend void swap(Game& gameA, Game& gameB);
};



#endif //OOP_GAME_HPP
