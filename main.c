/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:00:22 by loigonza          #+#    #+#             */
/*   Updated: 2024/12/03 14:10:07 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	ft_check_builtin(char *line)
{
	
}*/

my_list *create_node(char *key, char *value)
{
	my_list	*new_node;

	new_node = malloc(sizeof(my_list));
	if (!new_node)
		return (NULL);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;
	return (new_node);
}

my_list	*add_node(my_list **head, char *key, char *value)
{
	my_list	*current;
	my_list	*new_node;

	new_node = create_node(key, value);
	if (!new_node)
		return (NULL);
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return (new_node);
}


my_list *parse_env(char **env)
{
		
		my_list *head;
		char	**splited;
		int		i;
		 
		head = NULL;
		i = 0;
		while (env[i])//Aquí iteramos sobre el enviroment y lo splitemaos dentro de nuestra linked list
		{
			splited = ft_split(env[i], '=');
			if (splited)
			{
				add_node(&head, splited[0], splited[1]);
				free(splited);
			}
			i++;
		}
	return (head);
}

void	print_env_list(my_list *head)
{
	while (head)
	{
		printf("Key: %s, Value: %s\n", head->key, head->value);
		head = head->next;
	}
}

void	free_env_list(my_list *head)
{
	my_list	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	char *line;
	char *history;
	my_list *env_list;

	history = NULL;
	
	env_list = (my_list *)malloc(sizeof(my_list));
	if (!env_list)
		return (1);
	ft_memset(env_list, 0, sizeof(my_list));
	while (1)
	{
		line = readline("Minicaracola: "); //Aquí el programa se para hasta pulsar el intro, y continua el código.
		//En el add_history tenemos que controlar que entra y que no.
		if (line == NULL) //Caso en el que el usuario entra CTRL+D
			break ;
		if (line[0] != '\0') //Comprueba si no ha sido presionado intro
		{
			if (!history) //Comprobar si hemos hecho la  primera iteracion con la terminal
			{
				history = line; //Guardar la primera iteracion
				add_history(line); 
			}
			else //En caso de que ya tengamos algo en el historial
			{
				if (ft_strncmp(history, line, ft_strlen(history) + 1)) //Comprueba si el elemento anterior en el historial es el mismo que el actual
				{
					history = line;
					add_history(line);
				}
			}
		}
		//Esta linea la recive Gerri en su parseo, y me la devuelve spliteada.
		//Una vez añadido al historial pasamos la linea a Gerri, donde nos la devolverá spliteada y parseada.
		env_list = parse_env(env);
		print_env_list(env_list);
		free_env_list(env_list);
		chdir("Documents");
		//ft_check_builtin(line);//Pongo line para hacer test, pero debería hacer comprobación con la primera string retornada del parseo.	
	}	
	return (0);
}
