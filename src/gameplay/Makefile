CC		= g++

SRCS		= main.cpp \
		bDrawing.cpp \
		bomb.cpp \
		player.cpp \
		endGame.cpp \
		wallDrawing.cpp

RM		= rm -rf

CXXFLAGS	+= -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-network -lsfml-window

OBJS		= $(SRCS:.cpp=.o)

NAME		= BomberSwann

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -std=c++11 $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
