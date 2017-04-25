#ifndef TH_HPP
#define TH_HPP

#include <SFML/Graphics.hpp>
#include "player1.hpp"
#include "bomb.hpp"

typedef struct	s_bomb
{
  sf::RenderWindow	*window;
  Player1		p1;
}			t_bomb;

#endif
