/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_ipc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:14:17 by brda-sil          #+#    #+#             */
/*   Updated: 2024/09/02 21:05:43 by brda-sil         ###   ########.fr       */
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

# include "lem_ipc_profile/define.h"

# define LEM_IPC_LOG_POS			LOG_POS_RIGHT
# define LEM_IPC_PROFILE_SIZE		LEM_IPC_PROFILE_SIZE_VERY_LARGE
# define LEM_IPC_PROFILE_SPEED		LEM_IPC_PROFILE_SPEED_VERY_FAST

# include "lem_ipc_profile/size.h"
# include "lem_ipc_profile/speed.h"


# define	MLX_WHITE	0xFFFFFF
# define	MLX_GRAY	0x808080
# define	MLX_GRAY_2	0x404040
# define 	MLX_BLACK	0x000000

# define	MLX_RED		0xFF0000
# define	MLX_GRE		0x00FF00
# define	MLX_BLU		0x0000FF
# define	MLX_YEL		0xFFFF00
# define	MLX_ORA		0xFFA500
# define	MLX_PUR		0x800080
# define	MLX_CYA		0x00FFFF

# define	MLX_FONT_SIZE_Y		11
# define	MLX_FONT_SIZE_X		5
# define	MLX_FONT_SPACING_Y  3
# define	MLX_FONT_SPACING_X	1
# define	MLX_FONT_UNIT_Y		(MLX_FONT_SPACING_Y + MLX_FONT_SIZE_Y)
# define	MLX_FONT_UNIT_X		(MLX_FONT_SPACING_X + MLX_FONT_SIZE_X)
# define	MLX_FONT_COLOR		LEM_IPC_LOG_BORDER

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

typedef t_uint8							t_lem_team_id;
typedef t_uint16						t_lem_player_id;

# define	LEM_IPC_BOARD_LEN			(LEM_IPC_BOARD_LEN_X * LEM_IPC_BOARD_LEN_Y)
# define	LEM_IPC_GRAPH_FPS_TEXT		10
# define	LEM_IPC_GRAPH_FPS_MLX		60
# define	LEM_IPC_NB_TEAM				8

# define	LEM_IPC_LOG_SIZE_X			300
# define	LEM_IPC_LOG_SIZE_Y			400

# define	LEM_IPC_LOG_BACK			0x36454F
# define	LEM_IPC_LOG_BORDER			0x33FF8D
# define	LEM_IPC_LOG_HEADER_SIZE		4
# define	LEM_IPC_LOG_FOOTER_SIZE		1

# define	LEM_IPC_LEN_NB_TEAM			5
# define	LEM_IPC_LEN_TEAM_ID			3
# define	LEM_IPC_TEAM_ID_SUFFIX		": "
# define	LEM_IPC_LEN_TEAM_STR		(LEM_IPC_LEN_TEAM_ID + ft_strlen(LEM_IPC_TEAM_ID_SUFFIX))
# define	LEM_IPC_LEN_TOTAL			(LEM_IPC_LEN_NB_TEAM + LEM_IPC_LEN_TEAM_STR)

# define	LEM_IPC_LEN_NB_TOTAL		7
# define	LEM_IPC_NB_TOTAL			"Total player: "

typedef struct __attribute__((__packed__)) s_tile
{
	t_lem_team_id		team_id;
	t_lem_player_id		player_id;
}	t_tile;

typedef struct __attribute__((__packed__)) s_lem_ipc_mem
{
	t_uint8				reserved;
	t_lem_player_id		max_player_nb;
	t_lem_player_id		player_nb;
	t_tile				board[LEM_IPC_BOARD_LEN];
}	t_lem_ipc_mem;

typedef	struct s_lem_ipc_sem
{
	sem_t			*max_player_nb;
	sem_t			*player_nb;
	sem_t			*board;
	sem_t			*pause;
}	t_lem_ipc_sem;

typedef	struct	s_pos
{
	t_int16			x;
	t_int16			y;
}	t_pos;

typedef	struct	s_vec
{
	t_pos			pos;
	t_pos			dir;
}	t_vec;

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

# define SHO_SEM_KEY		"lem-ipc_sem"
# define SHO_MSQ_KEY		"lem-ipc_messsage_queue"

typedef enum e_error
{
	SUCCESS,
	SUCCESS_CMD,
	ERR_SHO_FD,
	ERR_SHM_PTR,
	ERR_SIGNAL,
	ERR_SEM_INIT,
	ERR_MSQ_INIT,
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

typedef enum e_algo_id
{
	RANDOM = 0,
	EASY,
	MEDIUM,
	HARD,
	ALGO_UP,
	ALGO_DOWN,
	ALGO_LEFT,
	ALGO_RIGHT,
}	t_algo_id;

# define NB_ALGO	8

// Loop alogrithm function
typedef void	(*t_algo_func)(void);

typedef struct	s_str_algo_func_node
{
	char		*str;
	t_algo_func	func;
}				t_str_algo_func_node;

typedef struct	s_str_int_node
{
	char		*str;
	int			nb;
}				t_str_int_node;

# define AI_ID_DEFAULT	RANDOM

# define LEM_IPC_BOARD_LEN_MAX ( \
	LEM_IPC_BOARD_LEN_X > LEM_IPC_BOARD_LEN_Y \
		? LEM_IPC_BOARD_LEN_X \
		: LEM_IPC_BOARD_LEN_Y \
	)

typedef enum e_player_status
{
	STATUS_UNKNOWN = -1,
	STATUS_LEADER = 1,
	STATUS_FOLLOWER = 2,
}	t_player_status;

// MESSAGE QUEUE PROTOCOL

// Define all the message types that can be sent through the message queue
typedef enum e_lem_ipc_msq_type
{
	MSQ_TYPE_ATK = 1,
}	t_lem_ipc_message_type;

typedef struct __attribute__((__packed__))	s_msq_hdr
{
	t_lem_ipc_message_type	type:8;
	t_lem_player_id			player_id;
}	t_msq_hdr;

typedef struct __attribute__((__packed__))	s_msq_atk
{
	t_pos	leader;
	t_pos	target;
}	t_msq_atk;

# define				MSQ_MSG_MAX		10
	// Maximum size of a message
# define				MSQ_SIZE_MAX	0xffff
	// Size of the header of a message
# define				MSQ_SIZE_HDR	sizeof(t_msq_hdr)
	// Size of the attack message
# define				MSQ_SIZE_ATK	sizeof(t_msq_atk)

/* ########################################################################## */
/* FILES */
/* ##### */

// board.c

t_tile			*get_board(void);
void			set_board(t_pos pos, t_tile tile);
void			set_board_move(t_pos from, t_pos to, t_tile tile);

// debug.c

void			debug_msq_recv(void);
void			debug_msq_get_nearest_attack(void);
void			debug_msq(int ac, char **av);

// free.c

void			free_prog(void);

// ft_get_abs.c

int				ft_get_abs(int n);

// graphical/check_for_player.c

void			check_for_player(void);

// graphical/get_team_color.c

t_int4			mlx_get_team_color(t_uint8 team_id);
char			*text_get_team_color(t_lem_team_id team_id);

// graphical/init_graphical.c

t_error			init_graphical(void);

// graphical/is_player_here.c

t_bool			is_here(char *prefix, char *name, int mode);
t_bool			is_shm_here(char *name);
t_bool			is_sem_here(char *name);
t_bool			is_msq_here(char *name);
t_bool			is_player_here(void);

// graphical/mlx/board.c

void			fill_board(t_tile *board);

// graphical/mlx/free_mlx.c

void			free_mlx(void);

// graphical/mlx/init_graphical_mlx.c

t_error			init_scene_board_border(t_size cell_size);
void			init_scene_log_border(void);
t_error			init_scene(t_mlx_texture *scene, t_pos size);
t_error			init_scenes(void);
void			get_screen_size(void);
t_error			init_graphical_mlx(void);

// graphical/mlx/key_press.c

char			*key_code_to_str(int key_code);
int				key_press(int key_code, void *mlx);
int				key_release(int key_code, void *mlx);
int				end_hook(void *mlx);

// graphical/mlx/log/mlx_log.c

int				mlx_log_get_last_id(char **log_str);
void			mlx_log_at(int lvl, char *msg, int color);
void			mlx_log_move_up(char **log_str);
t_bool			mlx_log(char *msg);
t_size			print_mlx_log(const char *format, ...);

// graphical/mlx/log/mlx_log_free.c

void			mlx_log_free(char **log_str);

// graphical/mlx/log/mlx_log_init.c

void			get_nb_log_line(void);
void			init_log_str(char ***log_str);

// graphical/mlx/put_cell.c

void			put_cell(t_pos pos, t_lem_team_id team_id, t_mlx_texture *scene);

// graphical/mlx/put_pixel.c

void			ft_put_pixel(t_pos pos, t_mlx_texture *image, t_int4 color);

// graphical/mlx/put_text.c

void			update_index_new_line(t_pos *pos);
void			mlxput_text_at(char *msg, int color, t_pos pos, t_bool inv_y);

// graphical/mlx/run_mlx.c

int				handler_mlx(void *mlx);
t_bin			run_graphical_mlx(void);

// graphical/mlx/stats/default.c

void			mlx_log_put_team_default(void);
void			mlx_log_put_total_nb_default(void);

// graphical/mlx/stats/team.c

void			mlx_log_put_team_get_stat(t_tile *board, int *stats);
void			mlx_log_put_stat_team(int *stat, int color);
int				*mlx_log_put_stat(t_tile *board);

// graphical/mlx/stats/total_nb.c

void			mlx_log_put_total_nb(void);

// graphical/text/run_text.c

t_size			print_tile_color(t_lem_team_id team_id, char *line);
t_size			print_tile_char(t_lem_player_id player_id, char *line);
t_size			print_tile(t_tile tile, char *line);
t_size			print_border(int cx, int cy, char *line, int *i);
void			render_map(t_tile *map);
t_error			run_graphical_text(void);

// graphical/text/stat.c

void			graphical_text_print_stat(t_tile *board);

// graphical/wait_for_player.c

int				wait_for_player(char *name, t_uint32 oflag, t_uint32 perm);

// init.c

t_error			init_prog(void);

// main.c

t_bin			init(int ac, char **av);
t_bin			run(void);
int				main(int ac, char **av);

// message_queue/msq_free.c

void			unlink_msqs(void);
void			close_msqs(void);

// message_queue/msq_get_attack.c

t_msq_atk		*msq_get_attack(void);

// message_queue/msq_get_attack_by_id.c

t_msq_atk		*msq_get_attack_by_id(t_lem_player_id id);

// message_queue/msq_get_hdr.c

t_msq_hdr		*msq_get_header(void);

// message_queue/msq_get_nearest_attack.c

t_msq_atk		*msq_get_nearest_attack(void);

// message_queue/msq_init.c

t_error			init_msq(mqd_t *msq, char *name);
t_error			set_attr_msq(mqd_t *msq);
char			*get_msq_key(t_lem_team_id team_id);
t_error			init_msqs(void);

// message_queue/msq_init_graphical.c

t_error			init_msq_graphical(mqd_t *msq, char *name);
t_error			init_msqs_graphical(void);

// message_queue/msq_recv.c

t_bool			msq_recv(t_lem_ipc_message_type type);

// message_queue/msq_remove_all.c

void			msq_remove_all(t_lem_ipc_message_type type);

// message_queue/msq_remove_last.c

void			msq_remove_last(t_lem_ipc_message_type type);

// message_queue/msq_send.c

t_bool			msq_send(void);

// message_queue/msq_send_attack.c

t_bool			msq_send_attack(t_pos enemy_pos);

// message_queue/sing_msq_buff.c

char			*sing_msq_buff(void);
size_t			*sing_msq_buff_len(void);

// parsing/cmd/help.c

void			help_header(void);
void			help_part_1(void);
void			help_footer(void);
t_bin			help(void);

// parsing/cmd/usage.c

t_bin			usage(void);

// parsing/parse.c

t_lem_team_id	get_team_id(void);
t_algo_id		translate_algo_id(char *algo_id_str);
t_bin			get_ai(void);
t_bin			post_parse_grapical(void);
t_bin			post_parse_player(void);
t_bin			post_parse(void);
t_bin			parse_opts(int ac, char **av);

// pause.c

void			lemipc_check_pause(void);
void			lemipc_pause_toggle(void);
void			lemipc_pause_set(t_bool target);

// player/algo/compute_choose_enemy_ally.c

t_vec			compute_choose_enemy_ally(t_vec enemy, t_vec ally);

// player/algo/compute_move.c

void			computed_move(t_vec next_move);

// player/algo/compute_nearest.c

t_vec			compute_nearest_player(t_tile *board, int mode);
t_vec			compute_nearest_ally(t_tile *board);
t_vec			compute_nearest_enemy(t_tile *board);

// player/algo/debug/dir/algo_down.c

void			down_move(void);

// player/algo/debug/dir/algo_left.c

void			left_move(void);

// player/algo/debug/dir/algo_right.c

void			right_move(void);

// player/algo/debug/dir/algo_up.c

void			up_move(void);

// player/algo/player/algo_easy.c

t_vec			handler_move_easy(t_tile *board);
void			loop_easy(void);

// player/algo/player/algo_hard.c

t_vec			handler_move_hard(t_tile *board);
void			loop_hard(void);

// player/algo/player/algo_medium.c

t_vec			handler_move_medium(t_tile *board);
void			loop_medium(void);

// player/algo/player/algo_random.c

void			random_move(void);

// player/check_death.c

t_bool			check_death(t_pos pos, t_tile *board);

// player/get_nearest_player.c

int				get_tile_team_id(t_tile *board, t_pos pos);
t_pos			get_nearest_line(t_tile *board, t_vec vec, int index, int mode);
t_pos			get_nearest_column(t_tile *board, t_vec vec, int index, int mode);
t_pos			get_nearest_player(t_tile *board, int mode);

// player/max_player_nb.c

t_lem_player_id	inc_max_player_nb(void);
t_lem_player_id	get_max_player_nb(void);

// player/player_free.c

void			free_player(void);

// player/player_init.c

t_error			get_random_pos(void);
t_error			init_player(void);

// player/player_move.c

t_bool			player_move(t_dir dir);
void			ensure_player_move(t_dir dir);

// player/player_nb.c

t_lem_player_id	inc_player_nb(void);
t_lem_player_id	dec_player_nb(void);
t_lem_player_id	get_player_nb(void);

// player/player_run_wrapper.c

t_bool			player_loop(void);
t_error			run_player(void);

// semaphore/sem_free.c

void			close_sems(void);
void			unlink_sems(void);

// semaphore/sem_init.c

t_error			init_sem(sem_t **sem, char *name, int value);
char			*get_sem_key(char *key);
t_error			init_sems(void);

// shared_memory/shm_get.c

int				get_sho_fd(char *name, t_size size, t_uint32 oflag, t_uint32 perm);
void			*get_shm_ptr(int sho_fd, t_size size, t_uint32 prot, t_uint32 flag);
void			*get_shm(t_sho sho);

// shared_memory/shm_init.c

t_error			init_shm_mem(void);
t_error			init_shm(void);

// signal/signal_handler.c

void			sig_handler(int sig);

// signal/signal_init.c

t_error			init_signal(void);

// sem/player_move.c
/* ########################################################################## */

#endif //LEM_IPC_H
