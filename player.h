///Aici este implementarea de singleton
#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>

template <typename T>

class Player : public Entity {
    sf::Texture texture;
    std::optional<sf::Sprite> sprite; 
    T damage;

    Player();

public:
    Player(const Player&) = delete;
    Player operator=(const Player&) = delete;

    static Player& definePlayer();
    ~Player();

    void mousePosition(const sf::RenderWindow& aux);

    void update(float dt) override {
        //O sa-l folosesc pentru a regla damage intervale-ul
    }

    void draw(sf::RenderWindow& window) override;

    sf::FloatRect getBounds() const override;

    int getDamage() const;

    void plusDamage(int x = 1);
};

