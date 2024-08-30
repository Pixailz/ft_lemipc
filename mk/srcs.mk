# SRCS
SRC_C := free/free.c \
		 free/message_queue.c \
		 free/mlx.c \
		 free/player.c \
		 free/semaphore.c \
		 graphical/mlx/board.c \
		 graphical/mlx/key_press.c \
		 graphical/mlx/main.c \
		 graphical/mlx/put_text.c \
		 graphical/mlx/run_mlx.c \
		 graphical/mlx/stats/default.c \
		 graphical/mlx/stats/team.c \
		 graphical/mlx/stats/total_nb.c \
		 graphical/text/run_text.c \
		 graphical/text/stat.c \
		 init/init.c \
		 init/init_graphical.c \
		 init/init_graphical_mlx.c \
		 init/init_player.c \
		 init/message_queue.c \
		 init/message_queue_graphical.c \
		 init/semaphore.c \
		 init/shared_memory.c \
		 init/signal.c \
		 main.c \
		 parsing/cmd/help.c \
		 parsing/cmd/usage.c \
		 parsing/parse.c \
		 player/low.c \
		 player/random.c \
		 player/run_player.c \
		 semaphore/board.c \
		 semaphore/max_nb_player.c \
		 semaphore/move_player.c \
		 semaphore/nb_player.c \
		 semaphore/pause.c \
		 utils/is_player_here.c \
		 utils/mlx.1.c \
		 utils/mlx_log/free.c \
		 utils/mlx_log/init.c \
		 utils/mlx_log/mlx_log.c \
		 utils/shared_memory.1.c \
		 utils/sig_handler.1.c

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

CFLAGS				+= -DPROG_NAME='"$(TARGET)"'

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
