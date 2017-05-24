#include "player.hpp"
#include "proto.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"

int	endGame(Player *p1, Player *p2)
{
  if (p2->getTouched() == false && (p1->getHBound(). intersects(p2->getBound()) || p1->getVBound(). intersects(p2->getBound())))
    {
      p2->setTouched(true);
      p2->setPv();
      if (p2->getPv() == 0)
	{
	  if (p1->getNb() == 1)
	    std::cout << "Le joueur 1 a gagné !" << std::endl;
	  else
	    std::cout << "Le joueur 2 a gagné !" << std::endl;
	  return 0;
	}
      else
	return 1;
    }
  else
    return 1;
}
