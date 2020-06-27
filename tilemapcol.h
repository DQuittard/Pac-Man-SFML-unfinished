#ifndef TILEMAPCOL_H
#define TILEMAPCOL_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class tilemapcol: public sf::Drawable, public sf::Transformable
{
    public:
        tilemapcol();
        virtual ~tilemapcol();
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
        int tilesize;
        bool load(const std::string&, sf::Vector2u, int*, unsigned int, unsigned int);
        //bool myload(const std::string&, sf::Vector2u , const int*, unsigned int , unsigned int);
    protected:

    private:

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif // TILEMAPCOL_H
