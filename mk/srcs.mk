# SRCS
SRC_C := free/main.c \
		 free/mlx.c \
		 free/player.c \
		 graphical/mlx/main.c \
		 graphical/text/main.c \
		 graphical/text/stat.c \
		 init/graphical/main.c \
		 init/graphical/mlx.c \
		 init/main.c \
		 init/player/main.c \
		 init/semaphore.c \
		 init/shared_memory.c \
		 init/signal.c \
		 main.c \
		 parsing/cmd/help.c \
		 parsing/cmd/usage.c \
		 parsing/parse.c \
		 player/main.c \
		 semaphore/board.c \
		 semaphore/max_nb_player.c \
		 semaphore/move_player.c \
		 semaphore/nb_player.c \
		 semaphore/pause.c \
		 utils/mlx.1.c \
		 utils/shared_memory.1.c \
		 utils/sig_handler.1.c

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

CFLAGS				+= -DPROG_NAME='"$(TARGET)"'

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
