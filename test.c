/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:00:22 by loigonza          #+#    #+#             */
/*   Updated: 2024/11/30 12:12:35 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <unistd.h>


/*int	ft_check_builtin(char *line)
{
	
}*/

int main(void)
{
	char *line;
	char *historial;

	historial = NULL;
	
	while (1)
	{	
		line = readline("Minicaracola: "); //Aquí el programa se para hasta pulsar el intro, y continua el código.
		//Esta linea la recive Gerri en su parseo, y me la devuelve spliteada.
		//En el add_history tenemos que controlar que entra y que no.
	
		

		if (line == NULL) //Caso en el que el usuario entra CTRL+D
		{
			break ;
		}
		if (line[0] != '\0') //Comprueba si no ha sido presionado intro
		{
			if (!historial) //Comprobar si hemos hecho la  primera iteracion con la terminal
			{		
				historial = line; //Guardar la primera iteracion
				add_history(line); 
			}
			else //En caso de que ya tengamos algo en el historial
			{
				if (ft_strncmp(historial, line, ft_strlen(historial))) //Comprueba si el elemento anterior en el historial es el mismo que el actual
				{
					historial = line;
					add_history(line);
				}
			}
		}
		//ft_check_builtin(line);//Pongo line para hacer test, pero debería hacer comprobación con la primera string retornada del parseo.	
	}	
	return (0);
}
