#include <SFML/Graphics.hpp>
#include <iostream>

void		wallDrawing(sf::RenderWindow *window)
{
  sf::Texture	tWall;
  sf::Sprite	sWall;
  int		i = 0;

  if (!tWall.loadFromFile("../../sprites/map/ast.png"))
    {
      std::cerr << "Couldn't load the wall" << std::endl;
      exit(1);
    }
  sWall.setTexture(tWall);
  while (i < 486)
    {
      sWall.setPosition(-9, i);
      window->draw(sWall);
      i += 9;
    }
  while (i > -9)
    {
      sWall.setPosition(477, i);
      window->draw(sWall);
      i -= 9;
    }
  while (i < 486)
    {
      sWall.setPosition(i, -9);
      window->draw(sWall);
      i += 9;
    }
  while (i > -9)
    {
      sWall.setPosition(i, 477);
      window->draw(sWall);
      i -= 9;
    }
}
