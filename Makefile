NAME 	= graduate_project
CC 		= gcc

all: install

install: $(NAME)

$(NAME): main.o
	$(CC) main.c -o $(NAME)

uninstall:
	del $(addprefix $(NAME), .exe)
