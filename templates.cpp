#include "templates.h"

template <typename T>

void drawEnemies(T patches, sf::RenderWindow *window){
    for (auto& thing : patches) {
                thing.draw(*window);
            }
}