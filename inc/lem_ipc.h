/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_ipc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/08/26 09:32:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IPC_H
# define LEM_IPC_H

# include "libft.h"

# include <mlx.h>

# include <signal.h>
/* signal
 * SIGINT
 */

# include <sys/mman.h>
/* PROT_READ
 * PROT_WRITE
 * MAP_SHARED
 * MAP_ANONYMOUS
 * mmap()
 */

#include <stdio.h>
/* perror()
 */

#include <errno.h>
/* errno
 * perror()
 */

#include <semaphore.h>
/* sem_t
 * sem_init()
 */

#include <mqueue.h>
/* mqd_t
 * mq_open()
 */

typedef t_uint8		t_lem_team_id;
typedef t_uint16	t_lem_player_id;

// # define	LEM_IPC_BOARD_LEN_X		200
// # define	LEM_IPC_BOARD_LEN_Y		100

# define	LEM_IPC_BOARD_LEN_X		50
# define	LEM_IPC_BOARD_LEN_Y		25
# define	LEM_IPC_BOARD_LEN		(LEM_IPC_BOARD_LEN_X * LEM_IPC_BOARD_LEN_Y)
# define	LEM_IPC_GRAPH_FPS_TEXT	10
# define	LEM_IPC_GRAPH_FPS_MLX	144
# define	LEM_IPC_NB_TEAM			8
# define 	LEM_IPC_FREQ			A_SEC / 10
// # define 	LEM_IPC_FREQ			100

typedef enum e_log_pos
{
	LOG_POS_DISABLE = 0,
	LOG_POS_RIGHT = 1,
	LOG_POS_LEFT = 2,
	LOG_POS_TOP = 3,
	LOG_POS_BOTTOM = 4
}	t_log_pos;

# define	LEM_IPC_LOG_SIZE_X			200
# define	LEM_IPC_LOG_SIZE_Y			200
# define	LEM_IPC_LOG_POS				LOG_POS_RIGHT

# define	LEM_IPC_LOG_BACK			0x36454F
# define	LEM_IPC_LOG_BORDER			0x33FF8D
# define	LEM_IPC_LOG_FONT_COLOR		LEM_IPC_LOG_BORDER
# define	LEM_IPC_LOG_FONT_SIZE_Y		12
# define	LEM_IPC_LOG_FONT_SIZE_X		6
# define	LEM_IPC_LOG_FONT_SPACING	3
# define	LEM_IPC_LOG_FONT_UNIT_Y		LEM_IPC_LOG_FONT_SPACING + LEM_IPC_LOG_FONT_SIZE_Y
# define	LEM_IPC_LOG_FONT_UNIT_X		LEM_IPC_LOG_FONT_SPACING + LEM_IPC_LOG_FONT_SIZE_X
# define	LEM_IPC_LOG_HEADER_SIZE		4
# define	LEM_IPC_LOG_FOOTER_SIZE		1

# define	CELL_SIZE	8

# define	MLX_WHITE	0xFFFFFF
# define	MLX_GRAY	0x808080
# define 	MLX_BLACK	0x000000

# define	MLX_RED		0xFF0000
# define	MLX_GRE		0x00FF00
# define	MLX_BLU		0x0000FF
# define	MLX_YEL		0xFFFF00
# define	MLX_ORA		0xFFA500
# define	MLX_PUR		0x800080
# define	MLX_CYA		0x00FFFF

typedef struct __attribute__((__packed__)) s_tile
{
	t_lem_team_id		team_id;
	t_lem_player_id		player_id;
}	t_tile;

typedef struct __attribute__((__packed__)) s_lem_ipc_mem
{
	t_uint8				reserved;
	t_lem_player_id		max_nb_player;
	t_lem_player_id		nb_player;
	t_tile				board[LEM_IPC_BOARD_LEN];
}	t_lem_ipc_mem;

typedef	struct s_lem_ipc_sem
{
	sem_t			*max_nb_player;
	sem_t			*nb_player;
	sem_t			*board;
	sem_t			*pause;
}	t_lem_ipc_sem;

typedef	struct	s_pos
{
	t_int16			x;
	t_int16			y;
}	t_pos;

typedef struct	s_mlx_texture
{
	void			*ptr;
	t_uint32		*buff;
	int				bpp;
	int				line_len;
	int				endian;
}	t_mlx_texture;

typedef struct s_sho
{
	char		*name;
	t_size		size;
	t_uint32	o_oflag;
	t_uint32	o_perm;
	t_uint32	m_prot;
	t_uint32	m_flag;
}	t_sho;

# define SHO_MEM_KEY		"/lem-ipc_mem"
# define SHO_MEM_OFLAG		O_RDWR
# define SHO_MEM_PERM		0666
# define SHO_MEM_SIZE		sizeof(t_lem_ipc_mem)

# define SHM_PROT			PROT_READ | PROT_WRITE
# define SHM_FLAG			MAP_SHARED


typedef enum e_error
{
	SUCCESS,
	ERR_SHO_FD,
	ERR_SHM_PTR,
	ERR_SIGNAL,
	ERR_SEM_INIT,
	ERR_PARSING,
	ERR_INIT_MLX,
	ERR_INIT_MLX_WIN,
	ERR_INIT_MLX_IMG,
	STOP_SIGINT,
	BOARD_FULL,
}	t_error;

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_dir;

typedef enum e_ai_id
{
	RANDOM = 0,
	LOW = 1,
}	t_ai_id;

typedef struct s_ai_id_list
{
	int		id;
	char	*str;
}	t_ai_id_list;


# define AI_ID_DEFAULT	RANDOM

	// KEYBOARD
		// DEFAULT
# define KEY_A							0x61
# define KEY_W							0x77
# define KEY_S							0x73
# define KEY_D							0x64
# define KEY_E							0x65
# define KEY_M							0x6d
# define KEY_SPACE						0x20
# define KEY_TAB						0xff09
# define KEY_LSHIFT						0xffe1
# define KEY_ESC						0xff1b

		// ARROW
# define KEY_RIGHT						0xff53
# define KEY_LEFT						0xff51

/* ########################################################################## */
/* FILES */
/* ##### */

// free/main.c

void			free_prog(void);

// free/mlx.c

void			free_mlx(void);

// free/player.c

void			free_player(void);

// graphical/mlx/board.c

void			fill_board(t_tile *board);

// graphical/mlx/key_press.c

char			*key_code_to_str(int key_code);
int				key_press(int key_code, void *mlx);
int				key_release(int key_code, void *mlx);
int				end_hook(void *mlx);

// graphical/mlx/main.c

int				handler_mlx(void *mlx);
t_bin			run_graphical_mlx(void);

// graphical/mlx/team.c

void			mlx_log_put_team(t_tile *board);
void			mlx_log_put_team_default_update_index(int *index, int to_add);
void			mlx_log_put_team_default(void);

// graphical/text/main.c

char			*text_get_team_color(t_lem_team_id team_id);
t_size			print_tile_color(t_lem_team_id team_id, char *line);
t_size			print_tile_char(t_lem_player_id player_id, char *line);
t_size			print_tile(t_tile tile, char *line);
t_size			print_border(int cx, int cy, char *line, int *i);
void			render_map(t_tile *map);
t_error			run_graphical_text(void);

// graphical/text/stat.c

void			graphical_text_print_stat(t_tile *board);

// init/graphical/main.c

t_error			init_graphical(void);

// init/graphical/mlx.c

t_error			init_scene_board_border(t_size cell_size);
void			init_scene_log_border(void);
t_error			init_scene(t_mlx_texture *scene, t_pos size);
t_error			init_scenes(void);
void			get_screen_size(void);
t_error			init_graphical_mlx(void);

// init/main.c

t_error			init_prog(void);

// init/message_queue.c

t_error			init_message_queue(mqd_t *msq, char *name);
t_error			init_messages_queue(void);

// init/player/main.c

t_error			get_random_pos(void);
t_error			init_player(void);

// init/semaphore.c

t_error			init_semaphore(sem_t **sem, char *name, int value);
t_error			init_semaphores(void);

// init/shared_memory.c

t_error			init_shared_memory_mem(void);
t_error			init_shared_memory(void);

// init/signal.c

t_error			init_signal(void);

// main.c

t_bin			run(int ac, char **av);
int				main(int ac, char **av);

// parsing/cmd/help.c

void			help_header(void);
void			help_part_1(void);
void			help_footer(void);
t_bin			help(void);

// parsing/cmd/usage.c

t_bin			usage(void);

// parsing/parse.c

t_lem_team_id	get_team_id(void);
t_ai_id			translate_ai_id(char *ai_id_str);
t_bin			get_ai(void);
t_bin			post_parse_grapical(void);
t_bin			post_parse_player(void);
t_bin			post_parse(void);
t_bin			parse_opts(int ac, char **av);

// player/low.c

void			loop_low(void);

// player/main.c

t_error			run_player(void);

// player/random.c

void			loop_random(void);

// semaphore/board.c

t_tile			*get_board(void);
void			set_board(t_pos pos, t_tile tile);

// semaphore/max_nb_player.c

t_lem_player_id	inc_max_nb_player(void);
t_lem_player_id	get_max_nb_player(void);

// semaphore/move_player.c

t_bool			is_dead(t_pos pos, t_tile *board);
t_bool			move_player(t_dir dir);

// semaphore/nb_player.c

t_lem_player_id	inc_nb_player(void);
t_lem_player_id	dec_nb_player(void);
t_lem_player_id	get_nb_player(void);

// semaphore/pause.c

void			lemipc_check_pause(void);
void			lemipc_pause_toggle(void);

// utils/mlx.1.c

void			ft_put_pixel(t_pos pos, t_mlx_texture *image, t_int4 color);
t_int4			get_team_color(t_uint8 team_id);
void			put_cell(t_pos pos, t_lem_team_id team_id, t_mlx_texture *scene);
void			wait_for_memory(void);

// utils/mlx_log/free.c

void			mlx_log_free(char **log_str);

// utils/mlx_log/init.c

void			init_log_str(char ***log_str);

// utils/mlx_log/main.c

int				mlx_log_get_last_id(char **log_str);
void			mlx_log_at(int lvl, char *msg, int color);
void			mlx_log_move_up(char **log_str);
t_bool			mlx_log(char *msg);
t_size			print_mlx_log(const char *format, ...);

// utils/shared_memory.1.c

int				get_sho_fd(char *name, t_size size, t_uint32 oflag, t_uint32 perm);
void			*get_shm_ptr(int sho_fd, t_size size, t_uint32 prot, t_uint32 flag);
void			*get_shared_memory(t_sho sho);

// utils/sig_handler.1.c

void			sig_handler(int sig);

// semaphore/move_player.c
/* ########################################################################## */

#endif //LEM_IPC_H
