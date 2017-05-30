#include <SFML/Graphics.hpp>
#include <iostream>

void		getMenu(sf::RenderWindow *win)
{
  sf::Event	event;
  sf::Sprite	s;
  sf::Texture	m1;
  sf::Texture	m2;

  if (!m1.loadFromFile("../../sprites/menu/menu1.png"))
    {
      std::cerr << "no menu" << std::endl;
      exit(1);
    }
  if (!m2.loadFromFile("../../sprites/menu/menu2.png"))
    {
      std::cerr << "no menu" << std::endl;
      exit(1);
    }
  s.setTexture(m1);
  win->clear();
  win->draw(s);
  win->display();
  while (event.key.code != sf::Keyboard::Return)
    {
      while (win->pollEvent(event))
	{
	  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
	    {
	      s.setTexture(m2);
	    }
	  else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
	    {
	      s.setTexture(m1);
	    }
	}
      win->clear();
      win->draw(s);
      win->display();
    }
  if (s.getTexture() == &m2)
    exit(0);
}
