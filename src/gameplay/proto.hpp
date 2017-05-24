#ifndef PROTO_HPP_
# define PROTO_HPP_

# include <SFML/Graphics.hpp>
# include "player.hpp"

sf::Sprite	player_putBomb(sf::Event, Player *, sf::Clock *);
int		bomb_drawing(Player *, sf::Clock *, sf::Sprite, sf::RenderWindow *);
int		bomb_drawing2(Player *, sf::Clock *, sf::Sprite, sf::RenderWindow *);
int		endGame(Player *, Player*);

#endif
