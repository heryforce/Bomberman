#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "panda.hpp"
//#include "th.hpp"

// void	bombThread(t_th *th_params)
// {
//   while (th_params->window.isOpen())
//     {
//       if (th_params->event.key.code == sf::Keyboard::Space)
// 	{
// 	  th_params->player1.putBomb();
// 	}
//       th_params->window.clear();
//       th_params->window.draw(th_params->player1.getBomb());
//       th_params->window.display();
//     }
// }

int	main()
{
  sf::RenderWindow	window(sf::VideoMode(500, 500), "BomberSwann");
  Panda			player1;
  sf::Vector2f		pos;
  sf::Event		event;
  // t_th			th_params;

  // th_params.window = window;
  // th_params.player1 = player1;
  // th_params.event = event;
  window.setActive(false);
  // sf::Thread		th(&bombThread, &th_params);
  while (window.isOpen())
    {
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (event.type == sf::Event::KeyPressed)
	    pos = player1.move(event);
	  std::cout << "x = " << pos.x << ", y = " << pos.y << std::endl;
	}
      window.clear();
      window.draw(player1.getPanda());
      window.display();
    }
  return 0;
}
