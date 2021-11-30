CC 				= gcc
NAME 			= graduate_project
SDL_DIR		= src/sdl
SDL_LIB 	= $(addprefix $(SDL_DIR), /lib)
SDL_INC 	= $(addprefix $(SDL_DIR), /include)
SDL_FLAGS	= -lmingw32 -lSDL2main -lSDL2
CC_FLAGS	= $(addprefix -I, $(SDL_INC)) $(addprefix -L, $(SDL_LIB))

all: install

install: $(NAME)

$(NAME):
	$(CC) main.c $(CC_FLAGS) $(SDL_FLAGS) -o $(NAME)

uninstall:
	del $(addprefix $(NAME), .exe)