#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "tilemapcol.h"

class joueur
{
    public:
        //FORME CANONIQUE
        joueur();
        virtual ~joueur();
        //operator=(const joueur &);

        //METHODES
        std::string get_name(std::string);
        void Update();
        void affichage();
        bool collisions(std::vector<std::vector<int> >);
        void verif_collision(std::vector<std::vector<int> >);

        //ATTRIBUTS
        sf::Vector2f position;
        int width;
        int height;
        enum facing_direction
        {droite,gauche,bas,haut};
        facing_direction direction;
        facing_direction last_direction;
        bool walking;
        bool battle;
        
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

        sf::IntRect vie;
        int vies;
        sf::Sprite sprite_vie;

        double tilemove;
        bool win;


    protected:

    private:
};

#endif // JOUEUR_H
