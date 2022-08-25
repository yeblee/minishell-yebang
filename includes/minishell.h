#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>

# include <readline/readline.h>
# include <readline/history.h>

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

# define LOOP 1

# define ON 1
# define OFF 0

# define SUCCESS 0
# define ERROR -1

/* 2022.08.26 (yeblee) 추가 */
# define TRUE	1
# define FALSE	0

enum	e_token
{
	NONE,
	OR,
	AND,
	PIPE,
	CMD,
	S_QUOTE,
	D_QUOTE,
	STR,
	INP_RD,
	OUT_RD,
	APP_RD,
	HERE_DOC,
	L_PARENS,
	R_PARENS
};

enum	e_type
{
	TK_OR,
	TK_AND,
	TK_PIPE,
	TK_WORD,
	TK_REDIR,
	TK_PARENS
};

// 전역 변수로 사용할 구조체
typedef struct s_global
{
	int		status;
	char	**env;
} t_global;

// token : 가장 작은 단위로 나눔
typedef struct s_token
{
	enum e_token	type;
	char			*data;
	struct s_token	*next;
}				t_token;

typedef struct s_node
{
	enum e_type		type;
	t_token			*tokens;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef struct s_minishell
{
	t_node		*root;
	t_token		*tokens;
}				t_minishell;

void	ft_start_screen(void);
void	rl_replace_line (const char *text, int clear_undo);
t_list	*get_token_list(char *line);

#endif
