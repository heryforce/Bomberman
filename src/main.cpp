#include <SFML/Graphics.hpp>
#include <iostream>
#include "tile.hpp"
#include <fstream>

int			main()
{
  sf::RenderWindow	window(sf::VideoMode(500, 500), "Bomberswann");
  Tile			*map[100];
  std::fstream		openfile("map.txt");
  int			i = 0, j = 0;

  if (openfile.is_open())
    {
      while (!openfile.eof())
	{
	  map[i++] = openfile.peek();
	}
    }
  while (window.isOpen())
    {
      sf::Event	event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	}
      i = 0;
      window.clear();
      while (map[i] != NULL)
	window.draw(map[i++]);
      window.display();
    }
  return 0;
}
