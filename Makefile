##
## EPITECH PROJECT, 2021
## B-CPP-300-STG-3-1-CPPrush3-maxime.frechard [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

NAME 	=	nanotekspice

SRC		=	main.cpp				\
			Circuit.cpp				\
			C4001.cpp				\
			Component.cpp			\
			Gate.cpp				\
			Input.cpp				\
			Output.cpp				\
			Parse.cpp				\
			True.cpp				\
			False.cpp				\
			Clock.cpp				\
			C4081.cpp				\
			C4030.cpp				\
			C4069.cpp				\
			C4071.cpp				\
			C4011.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)
	rm -f vgcore*

re:	fclean all