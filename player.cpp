#include "player.h"


template <typename T> Player<T>::Player(){
    try {
        if (!texture.loadFromFile("sprites/Player.png")) {
            throw std::runtime_error("Failed to load texture: ");
        }

        sprite.emplace(texture); // Now safe: sf::Sprite(texture)
        sprite->setOrigin({texture.getSize().x / 2.0f, texture.getSize().y / 2.0f});
    } catch (const std::exception& e) {
        std::cerr << "[Texture Error] " << e.what() << '\n';
    }

    damage = 5;
}

template <typename T> Player<T>& Player<T>::definePlayer(){
    static Player<T> player;
    return player;
}

template <typename T> Player<T>::~Player(){}

template <typename T> void Player<T>::mousePosition(const sf::RenderWindow& aux) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(aux);
    sf::Vector2f worldPos = aux.mapPixelToCoords(mousePos);

    sprite->setPosition(worldPos);
    setPositionByChild(worldPos);
}


template <typename T> void Player<T>::draw(sf::RenderWindow& window) {
    if (sprite) {
        window.draw(*sprite);
    }
}

template <typename T> sf::FloatRect Player<T>::getBounds() const {
    return sprite ? sprite->getGlobalBounds() : sf::FloatRect{};
}

template <typename T> int Player<T>::getDamage() const {
    return damage;
}

template <typename T> void Player<T>::plusDamage(int x) {
    damage+=x;
}