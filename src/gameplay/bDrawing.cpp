#include <SFML/Graphics.hpp>
#include "player.hpp"

int             bomb_drawing(Player *p, sf::Clock *clock, sf::Sprite spriteBomb, sf::RenderWindow *window)
{
  static int    x = 1;

  if (p->getAmmo() == false && clock->getElapsedTime().asSeconds() < 1)
    {
      window->draw(spriteBomb);
      return 0;
    }
  else if (p->getAmmo() == false && x <= 9)
    {
      p->explosion(window, spriteBomb.getPosition(), x++);
      return 0;
    }
  else
    {
      p->setAmmo(true);
      x = 1;
      p->unsetEBound();
      return 1;
    }
}

int             bomb_drawing2(Player *p, sf::Clock *clock, sf::Sprite spriteBomb, sf::RenderWindow *window)
{
  static int    x = 1;

  if (p->getAmmo() == false && clock->getElapsedTime().asSeconds() < 1)
    {
      window->draw(spriteBomb);
      return 0;
    }
  else if (p->getAmmo() == false && x <= 9)
    {
      p->explosion(window, spriteBomb.getPosition(), x++);
      return 0;
    }
  else
    {
      p->setAmmo(true);
      x = 1;
      p->unsetEBound();
      return 1;
    }
}
