# SRCS
SRC_C := board.c \
		 debug.c \
		 free.c \
		 ft_get_abs.c \
		 graphical/check_for_player.c \
		 graphical/get_team_color.c \
		 graphical/init_graphical.c \
		 graphical/is_player_here.c \
		 graphical/mlx/board.c \
		 graphical/mlx/free_mlx.c \
		 graphical/mlx/init_graphical_mlx.c \
		 graphical/mlx/key_press.c \
		 graphical/mlx/log/mlx_log.c \
		 graphical/mlx/log/mlx_log_free.c \
		 graphical/mlx/log/mlx_log_init.c \
		 graphical/mlx/put_cell.c \
		 graphical/mlx/put_pixel.c \
		 graphical/mlx/put_text.c \
		 graphical/mlx/run_mlx.c \
		 graphical/mlx/stats/default.c \
		 graphical/mlx/stats/team.c \
		 graphical/mlx/stats/total_nb.c \
		 graphical/text/run_text.c \
		 graphical/text/stat.c \
		 graphical/wait_for_player.c \
		 init.c \
		 main.c \
		 message_queue/msq_free.c \
		 message_queue/msq_get_attack.c \
		 message_queue/msq_get_attack_by_id.c \
		 message_queue/msq_get_hdr.c \
		 message_queue/msq_get_nearest_attack.c \
		 message_queue/msq_init.c \
		 message_queue/msq_init_graphical.c \
		 message_queue/msq_recv.c \
		 message_queue/msq_remove_all.c \
		 message_queue/msq_remove_last.c \
		 message_queue/msq_send.c \
		 message_queue/msq_send_attack.c \
		 message_queue/sing_msq_buff.c \
		 parsing/cmd/help.c \
		 parsing/cmd/usage.c \
		 parsing/parse.c \
		 pause.c \
		 player/algo/compute_choose_enemy_ally.c \
		 player/algo/compute_move.c \
		 player/algo/compute_nearest.c \
		 player/algo/debug/dir/algo_down.c \
		 player/algo/debug/dir/algo_left.c \
		 player/algo/debug/dir/algo_right.c \
		 player/algo/debug/dir/algo_up.c \
		 player/algo/player/algo_easy.c \
		 player/algo/player/algo_hard.c \
		 player/algo/player/algo_medium.c \
		 player/algo/player/algo_random.c \
		 player/check_death.c \
		 player/get_nearest_player.c \
		 player/max_player_nb.c \
		 player/player_free.c \
		 player/player_init.c \
		 player/player_move.c \
		 player/player_nb.c \
		 player/player_run_wrapper.c \
		 semaphore/sem_free.c \
		 semaphore/sem_init.c \
		 shared_memory/shm_get.c \
		 shared_memory/shm_init.c \
		 signal/signal_handler.c \
		 signal/signal_init.c

SRC_C				:= $(addprefix $(SRC_DIR)/,$(SRC_C))

CFLAGS				+= -DPROG_NAME='"$(TARGET)"'

# OBJ
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
