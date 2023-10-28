#include <SFML/Graphics.hpp>
#include <iostream>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

class Bird {
private:
    sf::Texture birdTexture;
    sf::Sprite birdSprite;
    float posY;
    float velocity;
public:
    Bird(){
        if (!birdTexture.loadFromFile("../assets/bird.png")) {
            perror("Eroare la incarcarea texturii!");
        }
        birdSprite.setTexture(birdTexture);
        birdSprite.setScale(sf::Vector2f(2.f, 2.f));
        posY = 400;
        velocity = 0;
    }
    ~Bird() = default;
    void fly() {
        velocity = -420;
    }
    void fall(float elapsedTime) {
        velocity += elapsedTime * 1200;
        posY += velocity * elapsedTime;
    }
    void draw(sf::RenderWindow &window) {
        birdSprite.setPosition(160, posY);
        if (velocity > 0) {
            birdSprite.setRotation(30);
        } else if (velocity == 0) {
            birdSprite.setRotation(0);
        } else {
            birdSprite.setRotation(-30);
        }
        window.draw(birdSprite);
    }
    friend std::ostream& operator<<(std::ostream& out, const Bird& bird) {
        out << "posY = " << bird.posY << " | velocity = " << bird.velocity << "\n";
        return out;
    }
};

class Background {
private:
    sf::Texture bgTexture;
    sf::Sprite bgSprite;
public:
    Background() {
        if (!bgTexture.loadFromFile("../assets/bg.png")) {
            perror("Eroare la incarcarea texturii!");
        }
        bgSprite.setTexture(bgTexture);
        bgSprite.setScale(sf::Vector2f(2.f, 1.5f));
    }
    Background(const Background& other) : bgTexture(other.bgTexture), bgSprite(other.bgSprite) {}
    Background& operator=(const Background& other) {
        bgTexture = other.bgTexture;
        bgSprite = other.bgSprite;
        return *this;
    }
    ~Background() = default;
    void draw(sf::RenderWindow& window) {
        window.draw(bgSprite);
    }
    friend std::ostream& operator<<(std::ostream& out, const Background& background) {
        float posX = sf::Vector2f(background.bgSprite.getPosition()).x;
        float posY = sf::Vector2f(background.bgSprite.getPosition()).y;
        out << "Background position: (" << posX << ", " << posY << ")\n";
        return out;
    }
};

class Ground {
private:
    sf::Texture grTexture;
    sf::Sprite grSprite;
    float offsetX;
    float offsetY;
public:
    Ground() {
        offsetX = 0.f;
        offsetY = 600.f;
        if (!grTexture.loadFromFile("../assets/gr.png"))
            perror("Eroare la incarcarea texturii!");
        grSprite.setTexture(grTexture);
        grSprite.setScale(sf::Vector2f(1.4f, 1.f));
        grSprite.setPosition(sf::Vector2f(0.f, offsetX));
    }
    ~Ground() = default;
    void move(float elapsedTime) {
        offsetX -= elapsedTime * 200;
        if (offsetX <= -24) {
            offsetX += 24;
        }
        grSprite.setPosition(sf::Vector2f(offsetX, offsetY));
    }
    void draw(sf::RenderWindow& window) {
        window.draw(grSprite);
    }
    friend std::ostream& operator<<(std::ostream& out, const Ground& ground) {
        out << "offsetX = " << ground.offsetX << " | offsetY = " << ground.offsetY << "\n";
        return out;
    }
};

class Game {
private:
    sf::RenderWindow window;
    sf::Clock clock;
    Background background;
    Bird bird;
    Ground ground;
    float elapsedTime;
    bool isRunning;
public:
    Game() {
        window.create(sf::VideoMode(450, 700), "Flappy Pet!");
        isRunning = window.isOpen();
        elapsedTime = 0.f;
    }
    ~Game() = default;
    void handleEvents() {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
                isRunning = 0;
            }
            else if(event.type == sf::Event::MouseButtonPressed || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                bird.fly();
        }
    }
    void handleTime() {
        elapsedTime = clock.getElapsedTime().asMicroseconds() / 1000.0f / 1000.0f;
        clock.restart();
    }
    void drawObjects() {
        background.draw(window);
        bird.draw(window);
        bird.fall(elapsedTime);
        ground.move(elapsedTime);
        ground.draw(window);
    }
    void render() {
        window.clear();
        drawObjects();
        window.display();
    }
    void start() {
        while(isRunning) {
            handleEvents();
            handleTime();
            render();
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Game& game) {
        out << "Jocul este in curs de rulare! => isRunning = " << game.isRunning << "\n";
        return out;
    }
};

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    Game game;
    std::cout << game;
    game.start();


    return EXIT_SUCCESS;
}
