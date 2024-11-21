#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char **argv)
{
	char *line;
	int	i;

	(void)argc;
	(void)argv;

	i = 0;
	while (1)
	{	
		line = readline("Minicaracola: "); //Aquí el programa se para hasta pulsar el intro, y continua el código.
		//Esta linea la recive Gerri en su parseo
		//En el add_history tenemos que controlar que entra y que no.
		if (line)
			add_history(line);
			
	}	
		return (0);
	
}
