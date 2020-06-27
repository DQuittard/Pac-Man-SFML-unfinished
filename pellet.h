#ifndef PELLET_H
#define PELLET_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "joueur.h"

class pellet
{
    public:
    	pellet(int,int);
    	~pellet();

    	bool isEaten=0;
    	bool is_super=0;
    	sf::Sprite sprite;
    	sf::Vector2i position;
    	sf::CircleShape rond;
    	sf::Vector2i tilenumber;
    	int tilesize=16;

    	bool collision(joueur);

};





#endif // PELLET_H
