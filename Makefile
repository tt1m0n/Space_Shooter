CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror

NAME = ft_retro

SRC = main.cpp AScreenElement.cpp Asteroid.cpp Bullet.cpp\
	  Enemy.cpp EnemyBullet.cpp SpaceShip.cpp Window.cpp\
	  Health.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) -lncurses

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
