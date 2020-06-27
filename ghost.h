#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>

class ghost
{
    public:
    	ghost();
    	~ghost();

    	//METHODES
        void Update(sf::Vector2i);
        void affichage();
        bool collisions(std::vector<std::vector<int> >);
        void verif_collision(std::vector<std::vector<int> >);
        sf::Vector2i distance(sf::Vector2i);
        sf::Vector2i calc_distance(sf::Vector2i,sf::Vector2i);

        //ATTRIBUTS
        sf::Vector2f position;
        int width;
        int height;
        enum facing_direction
        {droite,gauche,bas,haut};
        facing_direction direction;
        facing_direction last_direction;
        bool walking;
        sf::Sprite sprite;
        sf::IntRect coupage;
        sf::Texture texture;
        std::string name;
        int frame;
        sf::Time framespeed;
        sf::Clock clock;
        int animationFrameDuration;
        int frame_number;
        int movespeed;
        int tilesize;
        sf::Vector2i tilenumber;
        bool solid[4];
        bool blocked;


        sf::Vector2i old_pos;
        sf::Vector2i dist_haut;
        sf::Vector2i dist_bas;
        sf::Vector2i dist_gauche;
        sf::Vector2i dist_droite;
        double tilemove;

};





#endif // JOUEUR_H
