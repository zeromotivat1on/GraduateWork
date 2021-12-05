CC 				= g++
NAME 			= procedural_generation

DEL_WIN		= del
DEL_LIN		= rm -rf

INC_DIR		= inc
INC_FILES	= $(wildcard $(INC_DIR)/*.h)

SRC_DIR		= src
SRC_FILES	= $(wildcard $(SRC_DIR)/*.cpp)

SDL_DIR		= $(addprefix $(SRC_DIR), /sdl)
SDL_LIB 	= $(addprefix $(SDL_DIR), /lib)
SDL_INC 	= $(addprefix $(SDL_DIR), /include)
SDL_FLAGS	= -lmingw32 -lSDL2main -lSDL2 $(addprefix -I, $(SDL_INC)) $(addprefix -L, $(SDL_LIB))

all: install

install: $(NAME)

$(NAME):
	$(CC) $(SRC_FILES) $(SDL_FLAGS) -o $@

uninstall:
	$(DEL_WIN) $(addprefix $(NAME), .exe)

reinstall: uninstall install