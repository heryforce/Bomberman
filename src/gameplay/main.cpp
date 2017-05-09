#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player.hpp"

sf::Sprite	player_putBomb(sf::Event event, Player *p, sf::Clock *clock)
{
  if (event.key.code == sf::Keyboard::Space)
    {
      if (p->getAmmo() == true)
	{
	  p->setAmmo(false);
	  clock->restart();
	  return p->putBomb();
	}
    }
  else if (event.key.code == sf::Keyboard::Return)
    {
      if (p->getAmmo() == true)
	{
	  p->setAmmo(false);
	  clock->restart();
	  return p->putBomb();
	}
    }
}

void		bomb_drawing(Player *p, sf::Clock *clock, sf::Sprite spriteBomb, sf::RenderWindow *window)
{
  static int	x = 1;
  static int	y = 1;

  if (p->getNb() == 1)
    {
      if (p->getAmmo() == false && clock->getElapsedTime().asSeconds() < 1)
	window->draw(spriteBomb);
      else if (p->getAmmo() == false && x <= 9)
	{
	  std::cout << "x = " << x << " before explosion" << std::endl;
	  p->explosion(window, spriteBomb.getPosition(), x++);
	  std::cout << "x = " << x << " after explosion" << std::endl;
	}
      else
	{
	  p->setAmmo(true);
	  x = 1;
	}
    }
  else if (p->getNb() == 2)
    {
      if (p->getAmmo() == false && clock->getElapsedTime().asSeconds() < 1)
	window->draw(spriteBomb);
      else if (p->getAmmo() == false && y <= 9)
	{
	  std::cout << "y = " << y << " before explosion" << std::endl;
	  p->explosion(window, spriteBomb.getPosition(), y++);
	  std::cout << "y = " << y << " after explosion" << std::endl;
	}
      else
	{
	  p->setAmmo(true);
	  y = 1;
	}
    }
}

int			main()
{
  sf::RenderWindow	window(sf::VideoMode(500, 500), "BomberSwann");
  Player		p1(1);
  Player		p2(2);
  sf::Vector2f		pos1;
  sf::Vector2f		pos2;
  sf::Event		event;
  sf::Clock		clock1;
  sf::Clock		clock2;
  sf::Sprite		spriteBomb1;
  sf::Sprite		spriteBomb2;

  while (window.isOpen())
    {
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (event.type == sf::Event::KeyPressed)
	    {
	      spriteBomb1 = player_putBomb(event, &p1, &clock1);
	      spriteBomb2 = player_putBomb(event, &p2, &clock2);
	    }
	  pos1 = p1.move(event);
	  pos2 = p2.move(event);
	  std::cout << "PLAYER 1 : x = " << pos1.x << ", y = " << pos1.y << std::endl;
	  std::cout << "PLAYER 2 : x = " << pos2.x << ", y = " << pos2.y << std::endl;
	}
      window.clear();
      bomb_drawing(&p1, &clock1, spriteBomb1, &window);
      bomb_drawing(&p2, &clock2, spriteBomb2, &window);
      window.draw(p1.getP());
      window.draw(p2.getP());
      window.display();
    }
  return 0;
}
