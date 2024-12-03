#ifndef MINISHELL_H
# define MINISHELL_H



# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <unistd.h>

typedef struct l_list
{
	char *key;
	char *value;
	struct l_list  *next;
}	my_list;

#endif
