/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:07:12 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/14 14:33:45 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include <sys/types.h>

# define PARSING_STOPPER "|<>\'\""

typedef enum e_token {
	TK_ERROR = -1,
	TK_WORD,
	TK_WORD_SUB,
	TK_PIPE,
	TK_EXEC,
	TK_INF,
	TK_SUP,
	TK_DINF,
	TK_DSUP,
	TK_SQUOTE,
	TK_DQUOTE,
	TK_EOF
}			t_token;

enum e_error_parsing {
	ERR_SQUOTE_CLOSE = 1,
	ERR_DQUOTE_CLOSE,
	ERR_PARSING
};

typedef enum e_bool {
	TRUE = 1,
	FALSE = 0
}				t_bool;

typedef struct s_node {
	int				id;
	t_token			token_type;
	char			*token;
	char			*file_name;
	int				flags_open;
	mode_t			mode_open;
	char			**cmd;
	struct s_node	*right;
	struct s_node	*left;
	struct s_node	*redir;
	t_list			*lst_heredoc;
}					t_node;

typedef struct s_garb
{
	void			*ptr;
	int				id;
	struct s_garb	*next;
}					t_garb;

typedef struct s_source {
	int				id;
	char			*line_before;
	char			*line;
	size_t			line_size;
	size_t			cur;
	int				error;
}					t_source;

typedef struct s_param {
	t_source		source;
	t_garb			*garb;
	char			**env;
}					t_param;

typedef struct s_fd
{
	int	fd[2];
}				t_fd;

typedef struct s_pipe
{
	int		argc;
	t_node	**argv;
	t_param	*prm;
	t_fd	*fd_list;
	int		*pids;
	t_node	*root;
}				t_pipe;

#endif
