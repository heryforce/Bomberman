#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player.hpp"
#include "proto.hpp"

sf::Sprite	player_putBomb(sf::Event event, Player *p, sf::Clock *clock)
{
  if (p->getNb() == 1)
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
    }
  else
    {
      if (event.key.code == sf::Keyboard::Return)
	{
	  if (p->getAmmo() == true)
	    {
	      p->setAmmo(false);
	      clock->restart();
	      return p->putBomb();
	    }
	}
    }
}

int			main()
{
  sf::RenderWindow	window(sf::VideoMode(500, 500), "BomberSwann");
  Player		p1(1);
  Player		p2(2);
  sf::Event		event;
  sf::Clock		clock1;
  sf::Clock		clock2;
  sf::Sprite		spriteBomb1;
  sf::Sprite		spriteBomb2;
  sf::Texture		tbg;
  sf::Sprite		bg;

  if (!tbg.loadFromFile("../../sprites/map/background.png"))
    {
      std::cerr << "couldn't load background" << std::endl;
      exit(1);
    }
  bg.setTexture(tbg);
  window.setFramerateLimit(60);
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
	  p1.move(event);
	  p2.move(event);
	  p1.setBound();
	  p2.setBound();
	}
      window.clear();
      window.draw(bg);
      if (bomb_drawing(&p1, &clock1, spriteBomb1, &window) == 1)
	p2.setTouched(false);
      if (bomb_drawing2(&p2, &clock2, spriteBomb2, &window) == 1)
	p1.setTouched(false);
      window.draw(p1.getP());
      window.draw(p2.getP());
      window.display();
      if (endGame(&p1, &p2) == 0 || endGame(&p2, &p1) == 0)
	return 0;
    }
  return 0;
}
