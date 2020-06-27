#include "joueur.h"


joueur::joueur()
{
    //position.x=320;
    //position.y=240;
    width=14;
    height=14;
    direction=gauche;
    walking=false;
    battle=false;
    frame=0;
    texture.setSmooth(false);
    sprite.scale(1,1);
    movespeed=100.0 / this->tilesize;
    tilemove=16;
    //this->sprite.setPosition(this->tilesize,this->tilesize);
}

template<typename T>
T round(T v) {
  return int(v + 0.5);
}

/*joueur::operator=(const joueur &gold)
{
    position.x=gold.position.x;
    position.y=gold.position.y;
    width=gold.width;
    height=gold.height;
    direction=gold.direction;
    walking=gold.walking;
    battle=gold.battle;
}*/

std::string joueur::get_name(std::string input)
{

}

void joueur::Update()
{
    sf::Time time;
    time=clock.getElapsedTime();
    tilenumber.x=round((sprite.getPosition().x)/tilesize)+1;
    tilenumber.y=round((sprite.getPosition().y)/tilesize)+1;


     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        direction=bas;
                        if(solid[direction]==true)
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                    else
                        if(time.asSeconds()>0.12)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(0,tilemove);
                            clock.restart();
                            walking=true;
                            }


                        frame_number=3;
                    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        direction=gauche;
                        if(solid[direction]==true)
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                    else
                        if(time.asSeconds()>0.12)
                            {

                            sprite.move(-tilemove,0);
                            clock.restart();
                            walking=true;
                            }



                        frame_number=2;
                    }

     else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        direction=droite;
                        if(solid[direction]==true)
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                        else
                        if(time.asSeconds()>0.12)
                            {
                            sprite.move(tilemove,0);
                            clock.restart();
                             walking=true;
                            }



                        frame_number=2;

                       /*if(sprite.getPosition().x>=32*tilenumber.x)
                            {*/
                            //tilenumber.x++;
                            /*}
                        else
                            sprite.move((tilesize/movespeed/2),0);*/

                    }
     else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        direction=haut;
                        if(solid[direction]==true)
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                        else
                         if(time.asSeconds()>0.12)
                            {

                            sprite.move(0,-tilemove);
                            walking=true;
                            clock.restart();
                            }


                        frame_number=3;
                    }

                    last_direction=direction;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)==false && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)==false && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)==false && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==false)
    {
        walking=false;
        direction=last_direction;
        clock.restart();
    }
    /*std::cout<< "walking= " << walking << std::endl;
    std::cout << "sprite.position.x= " << sprite.getPosition().x << std::endl;
    std::cout << "tilenumber.x= " << tilenumber.x << std::endl;
    std::cout << "time: " << time.asSeconds() << std::endl;*/

}

void joueur::affichage()
{
       if (!texture.loadFromFile("pacman.png"))
   {
       std::cout << "ERROR LOADING TEXTURE ! " << std::endl;
   };



       if (direction==droite && walking==false)
       {
           coupage.left=19;
           coupage.top=1;
       }
       else if(direction==gauche && walking==false)
       {
        coupage.left=20;
        coupage.top=17;
       }
            
       else if(direction==bas && walking==false)
       {
           coupage.left=19;
           coupage.top=49;
       }
        else if(direction==haut && walking==false)
        {
            coupage.left=19;
           coupage.top=34;
        }

       //coupage.top=1;
       coupage.width=width;
       coupage.height=height;
       sprite.setTextureRect(coupage);
       sprite.setTexture(texture);


    if(direction==droite && frame==0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)==true)
    {
        coupage.left=19;
        coupage.top=1;
         sprite.setTextureRect(coupage);
        frame=1;
    }
    else if(direction==droite && frame==1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)==true)
    {
        coupage.left=4;
        coupage.top=1;
         sprite.setTextureRect(coupage);
         frame=0;
    }
      if(direction==gauche && frame==0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)==true)
    {
        coupage.left=7;
        coupage.top=17;
         sprite.setTextureRect(coupage);
        frame=1;
    }
    else if(direction==gauche && frame==1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)==true)
    {
        coupage.left=20;
        coupage.top=17;
         sprite.setTextureRect(coupage);
         frame=0;
    }
    //BAS
     if(direction==bas && frame==0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)==true)
    {
        coupage.left=19;
        coupage.top=49;
        //coupage.width=15;
        //coupage.height=15;
         sprite.setTextureRect(coupage);
        frame=1;
    }
    else if(direction==bas && frame==1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)==true)
    {
        coupage.left=3;
        coupage.top=49;
        //coupage.width=15;
        //coupage.height=15;
         sprite.setTextureRect(coupage);
         frame=0;
    }
    
    //HAUT

    if(direction==haut && frame==0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==true)
    {
        coupage.left=19;
        coupage.top=34;
        //coupage.width=15;
        //coupage.height=15;
         sprite.setTextureRect(coupage);
        frame=1;
    }
    else if(direction==haut && frame==1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)==true)
    {
        coupage.left=3;
        coupage.top=34;
        //coupage.width=15;
        //coupage.height=15;
         sprite.setTextureRect(coupage);
         frame=0;
    }


    //std::cout << "frame= " << frame << std::endl;

}

bool joueur::collisions(std::vector<std::vector<int> > matrix)
{

            if(matrix[tilenumber.x-1][tilenumber.y-1]==0)
        {
            std::cout << "DE L'EAU " << std::endl;
            return true;
        }

            return false;
}

void joueur::verif_collision(std::vector<std::vector<int> > matrix)
{
        //HAUT EAU ?
            if(matrix[tilenumber.x-1][tilenumber.y-2]==0)
        {

            //std::cout << "DE L'EAU EN HAUT" << std::endl;
            solid[haut]=true;

        }
        else
            solid[haut]=false;

        //EAU BAS
            if(matrix[tilenumber.x-1][tilenumber.y]==0)
        {
            //std::cout << "DE L'EAU EN BAS" << std::endl;
            solid[bas]=true;

        }
        else
            solid[bas]=false;


        //EAU GAUCHE ?
            if(matrix[tilenumber.x-2][tilenumber.y-1]==0)
        {
            //std::cout << "DE L'EAU A GAUCHE" << std::endl;
            solid[gauche]=true;
        }
        else
            solid[gauche]=false;

        //HAUT DROITE ?
            if(matrix[tilenumber.x][tilenumber.y-1]==0)
        {
            //std::cout << "DE L'EAU A DROITE" << std::endl;
            solid[droite]=true;
        }
        else
            solid[droite]=false;
}


joueur::~joueur()
{
    //dtor
}
