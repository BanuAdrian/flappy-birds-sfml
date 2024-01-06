//
// Created by Adrian on 11-Nov-23.
//

#include "../headers/Game.hpp"
#include <iostream>
#include <utility>

float Game::elapsedTime;
int Game::score;
int Game::highestScore;
int Game::currentBird;
bool Game::isRunning;
bool Game::hasBegun;

Game::Game() {
    bird = birdFactory.create(YELLOW_BIRD);
//    bird = dynamic_cast<Bird*>(&yellowBird);
    srand(time(nullptr));
    windowSettings();
    textSettings();
    initSettings();
    currentCommand = nullptr;
}

void Game::windowSettings() {
    window.create(sf::VideoMode(450, 700), "Flappy Birds!");
    auto icon = sf::Image();
    if (!icon.loadFromFile("../assets/game-icon.png"))
        throw IconLoadException();
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setVerticalSyncEnabled(true);
    isRunning = window.isOpen();
}

void Game::textSettings() {
    if (!font.loadFromFile("../assets/font.ttf")) {
        throw FontLoadException();
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(3);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(207.5, 75);
    highestScoreText.setFont(font);
    highestScoreText.setCharacterSize(15);
    highestScoreText.setOutlineColor(sf::Color::Black);
    highestScoreText.setOutlineThickness(1);
    highestScoreText.setFillColor(sf::Color::White);
    highestScoreText.setPosition(10, 10);
}

void Game::initSettings() {
    elapsedTime = 0.f;
    hasBegun = false;
    pipeGeneratingClock = std::make_shared<sf::Clock>();
    scoreGeneratingClock = std::make_shared<sf::Clock>();
    frameHandlingClock = std::make_shared<sf::Clock>();
    score = 0;
    currentBird = YELLOW_BIRD;
}

void Game::setCommand(std::shared_ptr<Command> newCommand) {
    currentCommand = std::move(newCommand);
}

void Game::handleEvents() {
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            isRunning = false;
            window.close();
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!hasBegun) {
                hasBegun = true;
                pipes.emplace_back(new Pipe);
                pipeGeneratingClock->restart();
                scoreGeneratingClock->restart();
            }
//            bird->fly();
            setCommand(std::make_shared<FlyCommand>());
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            if (hasBegun) {
//                bird->specialAbility();
                setCommand(std::make_shared<SpecialAbilityCommand>());
            }
        }
    }
    if (currentCommand != nullptr) {
        currentCommand->execute(*this);
        currentCommand = nullptr;
    }
}
void Game::handleTime() {
    elapsedTime = frameHandlingClock->getElapsedTime().asMicroseconds() / 1000.0f / 1000.0f;
    frameHandlingClock->restart();
}
void Game::handleText() {
    std::string scoreString = std::to_string(score);
    std::string highestScoreString = "Highest score: " + std::to_string(highestScore);
    scoreText.setString(scoreString);
    scoreText.setLetterSpacing(1.5);
    highestScoreText.setString(highestScoreString);
}

void Game::handleScore() {
    if (score == 0 && scoreGeneratingClock->getElapsedTime().asSeconds() > 2.2) {
        score++;
        scoreGeneratingClock->restart();
    } else if (score > 0 && scoreGeneratingClock->getElapsedTime().asSeconds() > 2) {
        score++;
        scoreGeneratingClock->restart();
    }
}

void Game::updateObjects() {
    if (hasBegun) {
        bird->update();
        for (const auto & pipe : pipes) {
            pipe->update(elapsedTime);
        }
        if (pipeGeneratingClock->getElapsedTime().asSeconds() > 2) {
//            pipes.emplace_back(new Pipe);
            pipes.emplace_back(std::make_shared<Pipe>());
            pipeGeneratingClock->restart();
            if (pipes.size() > 2) {
//                delete pipes[0];
                pipes.erase(pipes.begin());
            }
        }
        handleScore();
        bird->fall(elapsedTime);
    }
    bird->animateWings(hasBegun);
    ground.move(elapsedTime);
}

void Game::updateHighestScore() {
    if (score > highestScore)
        highestScore = score;
}

void Game::drawObjects() {
    background.draw(window);
    bird->draw(window);
    if (hasBegun) {
        for (const auto & pipe : pipes) {
            pipe->draw(window);
        }
    }
    window.draw(scoreText);
    if (highestScore > 0)
        window.draw(highestScoreText);
    bird->displaySpecialText(window);
    ground.draw(window);
}
void Game::render() {
    window.clear();
    drawObjects();
    updateObjects();
    window.display();
}
void Game::checkCollision()  {
    if (hasBegun)
        handleCollision();
}

bool Game::groundCollision() const {
    return bird->getBirdSprite().getGlobalBounds().intersects(ground.getGroundSprite().getGlobalBounds());
}
bool Game::pipeCollision() const {
    return pipes[0]->getTopPipeSprite().getGlobalBounds().intersects(bird->getBirdSprite().getGlobalBounds()) ||
           pipes[0]->getBottomPipeSprite().getGlobalBounds().intersects(bird->getBirdSprite().getGlobalBounds());
}

bool Game::outOfScreenCollision() const {
    return bird->getBirdSprite().getGlobalBounds().getPosition().y < -10;
}

void Game::resetScore() {
    score = 0;
}

void Game::handleCollision() {
    if (groundCollision() || pipeCollision() || outOfScreenCollision()) {
        if (!bird->isTransparent() || groundCollision() || outOfScreenCollision()) {
            hasBegun = false;
            pipes.clear();
            updateHighestScore();
            if (bird->getLives() == 0)
                resetScore();
            bird->handleCollision();
            upgradeBird();
        }
    }
}

void Game::upgradeBird() {
    if (highestScore >= bird->getScoreNeededForNextBird() && currentBird == YELLOW_BIRD) {
        bird = birdFactory.create(BLUE_BIRD, 3);
        currentBird = BLUE_BIRD;
    }
    else if (highestScore >= bird->getScoreNeededForNextBird() && currentBird == BLUE_BIRD) {
        bird = birdFactory.create(RED_BIRD);
        currentBird = RED_BIRD;
    }
}
void Game::start() {
    while(isRunning) {
        handleEvents();
        handleTime();
        handleText();
        render();
        checkCollision();
    }
}

//void swap(Game &gameA, Game &gameB) {
//    std::swap(gameA.window, gameB.window);
//    std::swap(gameA.scoreText, gameB.scoreText);
//    std::swap(gameA.highestScoreText, gameB.highestScoreText);
//    std::swap(gameA.font, gameB.font);
//    std::swap(gameA.frameHandlingClock, gameB.frameHandlingClock);
//    std::swap(gameA.pipeGeneratingClock, gameB.pipeGeneratingClock);
//    std::swap(gameA.scoreGeneratingClock, gameB.scoreGeneratingClock);
//    std::swap(gameA.pipes, gameB.pipes);
//    std::swap(gameA.bird, gameB.bird);
//    std::swap(gameA.redBird, gameB.redBird);
//    std::swap(gameA.yellowBird, gameB.yellowBird);
//    std::swap(gameA.blueBird, gameB.blueBird);
//    std::swap(gameA.background, gameB.background);
//    std::swap(gameA.ground, gameB.ground);
//    std::swap(gameA.elapsedTime, gameB.elapsedTime);
//    std::swap(gameA.isRunning, gameB.isRunning);
//    std::swap(gameA.hasBegun, gameB.hasBegun);
//    std::swap(gameA.score, gameB.score);
//    std::swap(gameA.highestScore, gameB.highestScore);
//    std::swap(gameA.currentBird, gameB.currentBird);
//}

//Game &Game::operator=(Game other) {
//    swap(*this, other);
//    return *this;
//}

//Game::Game(const Game &other) : window(other.window), scoreText(other.scoreText), highestScoreText(other.highestScoreText), font(other.font),
//                                bird(other.bird->clone()), redBird(other.redBird), yellowBird(other.yellowBird), blueBird(other.blueBird),
//                                background(other.background), ground(other.ground) {
//    frameHandlingClock = std::make_shared<sf::Clock>(*other.frameHandlingClock);
//    pipeGeneratingClock = std::make_shared<sf::Clock>(*other.pipeGeneratingClock);
//    scoreGeneratingClock = std::make_shared<sf::Clock>(*other.scoreGeneratingClock);
//    for (const auto& pipe: other.pipes) {
//        pipes.emplace_back(new Pipe(*pipe));
//    }
//}

//std::ostream& operator<<(std::ostream& out, const Game& game) {
//    out << "Jocul este in curs de rulare! => isRunning = " << game.isRunning << "\n";
//    return out;
//}

//Game::~Game() {
//    for (const auto & pipe : pipes)
//        delete pipe;
//}

std::shared_ptr<Bird> Game::getBird() const {
    return bird;
}
