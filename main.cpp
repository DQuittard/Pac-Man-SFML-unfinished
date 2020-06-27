

#include <SFML/Audio.hpp>
#include <math.h>
#include <string>
#include "joueur.h"
#include "tilemapcol.h"
#include "ghost.h"
#include "pellet.h"
#include "matrix.h"

using namespace std;

joueur ethan;
ghost blinky;
//ghost blinky2;

matrix matrix2d;

std::vector<pellet> vec_pellet;

int main()
{
    //enum Direction{Down,Left,Right,Up};
    //WINDOW TUTORIAL
    sf::RenderWindow window(sf::VideoMode(640/1.5, 480/1.5), "Project Pacman", sf::Style::Resize | sf::Style::Close);
    sf::Vector2u taille(640*1.5,480*1.5);
    window.setSize(taille);
    window.setTitle("Pacman");
    sf::Vector2i pos(100,100);
    window.setPosition(pos);
    window.setFramerateLimit(60);
        sf::Clock clock;
        sf::Time elapsedtime;
    //window.setKeyRepeatEnabled(false);


     // on définit le niveau à l'aide de numéro de tuiles
     int level[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 3, 3, 3, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    

    matrix2d.load("maptest.txt");


    //int matrix[15][20];
    vector<vector<int> > matrix2;
    int m=36+2;
    int n=28+2;
    int m2=matrix2d.k-1;
    int n2=matrix2d.l;


    /*int level2[] = {
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };*/

    int level2[m2*n2]={};


    for(int i=0; i<matrix2d.vec.size(); ++i)
    {
        level2[i]=matrix2d.vec[i];
    }

    cout << "matrix2d.vec.size()=" << matrix2d.vec.size() << endl;

    matrix2.resize(m2);

cout << "m2=" << m2 << endl;
cout << "matrix2d.k=" << matrix2d.k<< endl;

    for(int i=0;i<m2;i++)
    {
        matrix2[i].resize(n2);
    }


    for(int i = 0 ; i < m2 ; ++i)
    {

        for(int j = 0 ; j < n2 ; ++j)
        {        //modify matrix
         //matrix2[i][j]=level[m*j+i];
         matrix2[i][j]=level2[m2*j+i];

            if(matrix2[i][j]==1)
            {

                pellet pallet(i,j);
                vec_pellet.push_back(pallet);
            }
         //cout << "m[" << i << "][" << j << "]: " << matrix2[i][j] << endl;
        }

    }

    
    /*for(int j=0; j<n; ++j)
    {
        for(int i=0; i<m; ++i)
        {
            matrix2[i][j]=matrix2d.vec[m*j+i];
            if(matrix2[i][j]==1)
            {
                pellet pallet(i,j);
                vec_pellet.push_back(pallet);
            }
        }
    }*/

    /*for(int i=0; i<matrix2d.vec.size(); ++i)
    {
        level2[i]=matrix2d.vec[i];
    }*/

    

    // on crée la tilemap avec le niveau précédemment défini
    tilemapcol map;
    map.tilesize=16;
    map.scale(1,1);
    if (!map.load("2.png", sf::Vector2u(map.tilesize,map.tilesize), level2, m2, n2))
        return -1;

    ethan.tilesize=map.tilesize;
    blinky.tilesize=map.tilesize;
    //blinky2.tilesize=map.tilesize;

    //ethan.movespeed= 100.0 / ethan.tilesize;

    ethan.sprite.setPosition(9*ethan.tilesize,10*ethan.tilesize);
    ethan.sprite_vie.setPosition(20*ethan.tilesize,10*ethan.tilesize);
    //TEXTE: x number of life 
    sf::Font font;
if (!font.loadFromFile("PIXEARG_.TTF"))
{
    std::cout << "error font" << std::endl;
}
    sf::Text text;
    sf::Text text2;
text.setFont(font); // font is a sf::Font

std::string str=" Score: ";
/*std::string str2=to_string(ethan.vies);

str=str+str2;*/

text2.setString(str);

text2.setPosition(21*ethan.tilesize,10*ethan.tilesize);

text2.setCharacterSize(10); // in pixels, not points!

text2.setStyle(sf::Text::Bold);
// set the color
text2.setFillColor(sf::Color::White);


blinky.sprite.setPosition(8*blinky.tilesize,8*blinky.tilesize);
    //blinky2.sprite.setPosition(1*blinky.tilesize,1*blinky.tilesize);


//PALLETS

    /*for(int i = 0 ; i < m ; ++i)
    {

        for(int j = 0 ; j < n ; ++j)
        {        //modify matrix
          if(matrix2[i][j]==1)
          {
            pellet pallet(i,j);
            vec_pellet.push_back(pallet);
          }
         //cout << "m[" << i << "][" << j << "]: " << matrix2[i][j] << endl;
        }

}*/


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //WINDOW EVENTS
            if (event.type == sf::Event::Closed)
                window.close();

        }
        sf::Time deltatime = clock.restart();

        elapsedtime+=deltatime;
        //cout <<deltatime.asMilliseconds() << endl;


        

        ethan.framespeed=deltatime;
        blinky.framespeed=deltatime;
        //blinky2.framespeed=deltatime;

        ethan.frame_number=2;
        blinky.frame_number=2;
        //blinky2.frame_number=2;

        ethan.frame=static_cast<int>((elapsedtime.asSeconds()/0.2)*ethan.frame_number)%(ethan.frame_number);
        blinky.frame=static_cast<int>((elapsedtime.asSeconds()/0.2)*blinky.frame_number)%(blinky.frame_number);
        //blinky2.frame=static_cast<int>((elapsedtime.asSeconds()/0.2)*blinky.frame_number)%(blinky.frame_number);

        ethan.Update();
        blinky.Update(ethan.tilenumber);
        //blinky2.Update(ethan.tilenumber);

        ethan.affichage();
        blinky.affichage();
        //blinky2.affichage();

        //ethan.collisions(matrix2);
        ethan.verif_collision(matrix2);
        blinky.verif_collision(matrix2);
        //blinky2.verif_collision(matrix2);

        clock.restart().asSeconds();
        //cout << "TileX= " << ethan.tilenumber.x << " TileY= " << ethan.tilenumber.y << endl;
        //cout << "dist.x= " << blinky.distance(ethan.tilenumber).x << endl;
        //cout << "dist.y= " << blinky.distance(ethan.tilenumber).y << endl;
        //cout << "blocked= " << blinky.blocked << endl;
        //cout << "x= " << vec_pellet[1].tilenumber.x << " y= " << vec_pellet[1].tilenumber.y << endl;
        //cout << "isEaten= " <<  vec_pellet[1].isEaten << endl;
        //vec_pellet[1].rond.setFillColor(sf::Color::Red);
        int score=0;
        int score_vies=0;
        int check_vie=0;
        int compt_vie=0;
        bool addvie=false;
        int old_vies=ethan.vies;

        window.clear();
        window.draw(map);


    for(int i = 0 ; i < vec_pellet.size() ; ++i)
    {
            score=score+10*vec_pellet[i].isEaten;
            score_vies=score_vies+10*vec_pellet[i].isEaten-200*compt_vie;
            check_vie=false;
            
            if(!vec_pellet[i].collision(ethan) && vec_pellet[i].isEaten==0)
            {
                window.draw(vec_pellet[i].rond);
            }
    }
	
	std::string str2=to_string(score);

        str="Score: "+str2;

        text.setString(str);
	
	text.setPosition(21*ethan.tilesize,10*ethan.tilesize);

text.setCharacterSize(10);

    //std::cout << "score= " << score << " /  check_vie= " << check_vie << " / compteur vie= " << compt_vie << std::endl;
    //std::cout << "calcul: " << score%200 << std::endl;

    //cout << "score= " <<  score << endl;
        window.draw(blinky.sprite);
        //window.draw(blinky2.sprite);
        window.draw(text);
        window.draw(ethan.sprite);
        window.draw(ethan.sprite_vie);
        window.display();
    }

    return 0;
}
