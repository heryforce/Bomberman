#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player1.hpp"
#include "player2.hpp"

sf::Sprite	player1_putBomb(sf::Event event, Player1 *p1, sf::Clock *clock)
{
  if (event.key.code == sf::Keyboard::Space)
    {
      if (p1->getAmmo() == true)
	{
	  clock->restart();
	  return p1->putBomb();
	}
    }
}

sf::Sprite	player2_putBomb(sf::Event event, Player2 *p2, sf::Clock *clock)
{
  if (event.key.code == sf::Keyboard::Return)
    {
      if (p2->getAmmo() == true)
	{
	  clock->restart();
	  return p2->putBomb();
	}
    }
}

int			main()
{
  sf::RenderWindow	window(sf::VideoMode(500, 500), "BomberSwann");
  Player1		p1;
  Player2		p2;
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
	      // spriteBomb1 = player1_putBomb(event, &p1, &clock1);
	      // spriteBomb2 = player2_putBomb(event, &p2, &clock2);
	      if (event.key.code == sf::Keyboard::Space)
	      	{
	      	  if (p1.getAmmo() == true)
	      	    {
		      std::cout << "dans space" << std::endl;
		      p1.setAmmo(false);
	      	      spriteBomb1 = p1.putBomb();
	      	      clock1.restart();
	      	    }
	      	}
	      else if (event.key.code == sf::Keyboard::Return)
	      	{
	      	  if (p2.getAmmo() == true)
	      	    {
		      std::cout << "dans return" << std::endl;
		      p2.setAmmo(false);
	      	      spriteBomb2 = p2.putBomb();
	      	      clock2.restart();
	      	    }
	      	}
	    }
	  pos1 = p1.move(event);
	  pos2 = p2.move(event);
	  std::cout << "PLAYER 1 : x = " << pos1.x << ", y = " << pos1.y << std::endl;
	  std::cout << "PLAYER 2 : x = " << pos2.x << ", y = " << pos2.y << std::endl;
	}
      window.clear();
      if (p1.getAmmo() == false && clock1.getElapsedTime().asSeconds() < 1)
	window.draw(spriteBomb1);
      if (p2.getAmmo() == false && clock2.getElapsedTime().asSeconds() < 1)
	window.draw(spriteBomb2);
      window.draw(p1.getP1());
      window.draw(p2.getP2());
      window.display();
      if (clock1.getElapsedTime().asSeconds() > 1)
	p1.setAmmo(true);
      if (clock2.getElapsedTime().asSeconds() > 1)
	p2.setAmmo(true);
    }
  return 0;
}
