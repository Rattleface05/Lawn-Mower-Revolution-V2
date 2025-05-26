#include "templates.cpp"

template void drawEnemies<std::vector<Grass>>(std::vector<Grass> patches, sf::RenderWindow *window);

template void drawEnemies<std::vector<Weed>>(std::vector<Weed> patches, sf::RenderWindow *window);