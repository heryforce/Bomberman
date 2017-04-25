#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player1.hpp"
#include "th.hpp"

// void	bombThread(s_bomb *data)
// {
//   data->p1.putBomb(data->window);
// }

int	main()
{
  sf::RenderWindow	window(sf::VideoMode(500, 500), "BomberSwann");
  Player1		p1;
  sf::Vector2f		pos;
  sf::Event		event;
  bool			b;
  sf::Clock		clock;
  sf::Sprite		spriteBomb;

  b = false;
  while (window.isOpen())
    {
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
	    {
	      if (p1.getAmmo() == true)
		{
		  spriteBomb = p1.putBomb();
		  b = true;
		  clock.restart();
		}
	    }
	  pos = p1.move(event);
	  std::cout << "x = " << pos.x << ", y = " << pos.y << std::endl;
	}
      window.clear();
      if (b == true && clock.getElapsedTime().asSeconds() < 3)
	window.draw(spriteBomb);
      window.draw(p1.getP1());
      window.display();
      if (clock.getElapsedTime().asSeconds() > 3)
	{
	  b = false;
	  p1.setAmmo(true);
	}
    }
  return 0;
}
