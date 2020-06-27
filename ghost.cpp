#include "ghost.h"
#include <tgmath.h>

ghost::ghost()
{
	position.x=320;
    position.y=240;
    width=14;
    height=14;
    direction=gauche;
    walking=false;
    frame=0;
    texture.setSmooth(false);
    sprite.scale(1,1);
    movespeed=50.0 / this->tilesize;
    tilemove=16;
}
    	
template<typename T>
T round(T v) {
  return int(v + 0.5);
}

void ghost::Update(sf::Vector2i pacman)
{
    sf::Time time;
    time=clock.getElapsedTime();
    tilenumber.x=round((sprite.getPosition().x)/tilesize)+1;
    tilenumber.y=round((sprite.getPosition().y)/tilesize)+1;

    sf::Vector2i vec_haut;
    sf::Vector2i vec_bas;
    sf::Vector2i vec_gauche;
    sf::Vector2i vec_droite;
    vec_haut=this->tilenumber;
    vec_bas=this->tilenumber;
    vec_gauche=this->tilenumber;
    vec_droite=this->tilenumber;
    vec_haut.y=vec_haut.y-1;
    vec_bas.y=vec_bas.y+1;
    vec_gauche.x=vec_gauche.x-1;
    vec_droite.x=vec_droite.x+1;
    dist_haut=this->calc_distance(vec_haut,pacman);
    dist_bas=this->calc_distance(vec_bas,pacman);
    dist_gauche=this->calc_distance(vec_gauche,pacman);
    dist_droite=this->calc_distance(vec_droite,pacman);
    double h_dist=this->distance(pacman).x;
    double v_dist=this->distance(pacman).y;

    double minx=std::min(abs(dist_gauche.x),abs(dist_droite.x));
    double miny=std::min(abs(dist_haut.y),abs(dist_bas.y));
    double min=std::min(minx,miny);

    bool goleft;
    bool goright;
    bool godown;
    bool goup;


if( (abs(h_dist) > abs(v_dist)) )
{
    if(h_dist < 0 && solid[gauche]==false)
                    {
                        direction=gauche;
                        if(solid[direction]==true)
                        {

                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);

                        }
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(-tilemove,0);
                            clock.restart();
                            walking=true;
                            }

                    }
    else if(h_dist > 0  && solid[droite]==false) 
                {
                        direction=droite;
                        if(solid[direction]==true)
                        {
                           
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                        }
                            
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(tilemove,0);
                            clock.restart();
                            walking=true;
                            }

                    }

    else if( (solid[droite]==true && solid[gauche]==true) || (h_dist > 0 && solid[droite]==true) || (h_dist < 0 && solid[gauche]==true) )
                {   //dist_haut.y < dist_bas.y
                    if(v_dist < 0 && solid[haut]==false)
                    {
                        direction=haut;
                        if(solid[direction]==true)
                        {
                           
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                        }
                            
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(0,-tilemove);
                            clock.restart();
                            walking=true;
                            }
                    }
                    else if(v_dist > 0 && solid[bas]==false)
                    {
                        direction=bas;
                        if(solid[direction]==true)
                        {
                           
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                        }
                            
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(0,tilemove);
                            clock.restart();
                            walking=true;
                            }
                    }
                        
                        

                    }

        else if( (v_dist == 0  && solid[haut]==false) && dist_haut.y==min )
                {
                        direction=haut;
                       
                    if(solid[direction]==true)
                        {
                                //CONDITON FAIL
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                            
                        }
                            
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(0,-tilemove);
                            clock.restart();
                            walking=true;
                            }

                    }
        else if( (v_dist == 0  && solid[bas]==false) && dist_bas.y==min )
                {
                        direction=bas;
                        if(solid[direction]==true)
                        {
                                //CONDITON FAIL
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);

                        }
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(0,tilemove);
                            clock.restart();
                            walking=true;
                            }


                    }
        else if(solid[bas]==true && solid[gauche]==true && solid[haut]==true)
                {
                        direction=droite;
                        if(solid[direction]==true)
                        {
                                //CONDITON FAIL
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);

                        }
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(tilemove,0);
                            clock.restart();
                            walking=true;
                            }


                    }
        

}
else if(abs(v_dist) > abs(h_dist) )
{
    if( (v_dist < 0) && (solid[haut]==false))
                    {
                        direction=haut;
                        if(solid[direction]==true)
                            {
                                sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                            }
                            
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(0,-tilemove);
                            clock.restart();
                            walking=true;
                            }

                    }
    else if(v_dist > 0 && solid[bas]==false)
                {
                        direction=bas;
                        if(solid[direction]==true)
                            {

                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);

                            }
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(0,tilemove);
                            clock.restart();
                            walking=true;
                            }

                    }

    else if( (solid[bas]==true && solid[haut]==true) || (v_dist > 0 && solid[bas]==true) || (v_dist < 0 && solid[haut]==true))
                {
                    if(dist_droite.x < dist_gauche.x && solid[droite]==false)
                    {
                        direction=droite;
                        
                        if(solid[direction]==true)
                            {

                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);

                            }
                        else
                            if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(tilemove,0);
                            clock.restart();
                            walking=true;
                            }
                    }
                    else if(dist_droite.x > dist_gauche.x && solid[gauche]==false) 
                    {
                        direction=gauche;
                        
                        if(solid[direction]==true)
                            {

                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);

                            }
                        else
                            if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(-tilemove,0);
                            clock.restart();
                            walking=true;
                            }

                    }
                }
    else if( (h_dist == 0  && solid[gauche]==false) && dist_gauche.x==min )
                {
                        direction=gauche;
                        if(solid[direction]==true)
                        {
                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);     

                        }
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(-tilemove,0);
                            clock.restart();
                            walking=true;
                            }

                    }
    else if( (h_dist == 0  && solid[droite]==false) && dist_droite.x==min)
                {
                        direction=droite;
                        if(solid[direction]==true)
                        {

                            sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
                        
                        }
                    else
                        if(time.asSeconds()>0.2)
                            {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                            sprite.move(tilemove,0);
                            clock.restart();
                            walking=true;
                            }

                    }

}
else if( (abs(v_dist) == abs(h_dist)) && (v_dist!=0 || h_dist!=0))
{
    if(solid[haut]==false && v_dist < 0 && dist_haut.y==miny)
        {
        direction=haut;
        if(solid[direction]==true)
            {
                sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
            }
        else
            if(time.asSeconds()>0.2)
               {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                 sprite.move(0,-tilemove);
                 clock.restart();
                 walking=true;
               }
        }
    else if(solid[bas]==false && v_dist > 0 && dist_bas.y==miny)
        {
        direction=bas;
        if(solid[direction]==true)
            {
                sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
            }
        else
            if(time.asSeconds()>0.2)
               {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                 sprite.move(0,tilemove);
                 clock.restart();
                 walking=true;
               }
        }
    else if(solid[gauche]==false && h_dist < 0 && dist_gauche.x==minx)
        {
        direction=gauche;
        if(solid[direction]==true)
            {
                sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
            }
        else
            if(time.asSeconds()>0.2)
               {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                 sprite.move(-tilemove,0);
                 clock.restart();
                 walking=true;
               }
        }
    else if(solid[droite]==false && v_dist > 0 && dist_droite.x==minx)
        {
        direction=droite;
        if(solid[direction]==true)
            {
                sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
            }
        else
            if(time.asSeconds()>0.2)
               {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                 sprite.move(tilemove,0);
                 clock.restart();
                 walking=true;
               }
        }
    else if(solid[droite]==false && solid[gauche]==false && solid[haut]==false)
        {
        direction=haut;
        if(solid[direction]==true)
            {
                sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
            }
        else
            if(time.asSeconds()>0.2)
               {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                 sprite.move(0,-tilemove);
                 clock.restart();
                 walking=true;
               }
        }
    else if(solid[droite]==true && solid[gauche]==false && solid[haut]==false)
        {
        direction=haut;
        if(solid[direction]==true)
            {
                sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
            }
        else
            if(time.asSeconds()>0.2)
               {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                 sprite.move(0,-tilemove);
                 clock.restart();
                 walking=true;
               }
        }
    else if(solid[droite]==true && solid[gauche]==true && solid[haut]==false)
        {
        direction=haut;
        if(solid[direction]==true)
            {
                sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y);
            }
        else
            if(time.asSeconds()>0.2)
               {

                            //sprite.setPosition(sprite.getPosition().x,(tilenumber.y*tilesize));
                 sprite.move(0,-tilemove);
                 clock.restart();
                 walking=true;
               }
        }

}

}


sf::Vector2i ghost::distance(sf::Vector2i pos)
{
	double x=pos.x-this->tilenumber.x;
	double y=pos.y-this->tilenumber.y;
	sf::Vector2i retour;
    retour.x=x;
    retour.y=y;
	return(retour);
}

sf::Vector2i ghost::calc_distance(sf::Vector2i posd, sf::Vector2i posa)
{
	double x=posa.x-posd.x;
	double y=posa.y-posd.y;
	sf::Vector2i retour;
    retour.x=x;
    retour.y=y;
	return(retour);
}


void ghost::affichage()
{
        if (!texture.loadFromFile("pacman.png"))
   {
       std::cout << "ERROR LOADING TEXTURE ! " << std::endl;
   };

      /* if (direction==droite && walking==false)
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
        }*/

       //coupage.top=1;
       coupage.width=width;
       coupage.height=height;
       sprite.setTextureRect(coupage);
       sprite.setTexture(texture);


    if(direction==droite && frame==0)
    {
        coupage.left=19;
        coupage.top=65;
         sprite.setTextureRect(coupage);
        frame=1;
    }
    else if(direction==droite && frame==1)
    {
        coupage.left=3;
        coupage.top=65;
         sprite.setTextureRect(coupage);
         frame=0;
    }
      if(direction==gauche && frame==0)
    {
        coupage.left=51;
        coupage.top=65;
         sprite.setTextureRect(coupage);
        frame=1;
    }
    else if(direction==gauche && frame==1)
    {
        coupage.left=36;
        coupage.top=65;
         sprite.setTextureRect(coupage);
         frame=0;
    }
    //BAS
     if(direction==bas && frame==0)
    {
        coupage.left=115;
        coupage.top=65;
        //coupage.width=15;
        //coupage.height=15;
         sprite.setTextureRect(coupage);
        frame=1;
    }
    else if(direction==bas && frame==1)
    {
        coupage.left=99;
        coupage.top=65;
        //coupage.width=15;
        //coupage.height=15;
         sprite.setTextureRect(coupage);
         frame=0;
    }
    
    //HAUT

    if(direction==haut && frame==0)
    {
        coupage.left=83;
        coupage.top=65;
        //coupage.width=15;
        //coupage.height=15;
         sprite.setTextureRect(coupage);
        frame=1;
    }
    else if(direction==haut && frame==1)
    {
        coupage.left=67;
        coupage.top=65;
        //coupage.width=15;
        //coupage.height=15;
         sprite.setTextureRect(coupage);
         frame=0;
    }

}


void ghost::verif_collision(std::vector<std::vector<int> > matrix)
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




ghost::~ghost()
{

}