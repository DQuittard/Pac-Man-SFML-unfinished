#include "pellet.h"

pellet::pellet(int x, int y)
{
	position.x=6+x*tilesize;
	position.y=6+y*tilesize;
	isEaten=0;
	is_super=0;
	rond.setRadius(2);
	rond.setPosition(1*position.x,1*position.y);
	tilenumber.x=std::round((rond.getPosition().x)/tilesize)+1;
    tilenumber.y=std::round((rond.getPosition().y)/tilesize)+1;
    rond.setFillColor(sf::Color::Yellow);
}

bool pellet::collision(joueur pacman)
{
	if(pacman.tilenumber.x==this->tilenumber.x && pacman.tilenumber.y==this->tilenumber.y)
	{
		this->isEaten=1;
		return(true);
	}
	else
	{
		return(false);
	}
}

pellet::~pellet()
{

}