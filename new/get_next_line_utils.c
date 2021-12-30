char *buffer_div(char *buffer)
{
	static char *rest;
	int i;

	i = 0;
	while(buffer[i] != '\n')
	{
			line[i] = buffer[i];
			i++;
	}
	line[i++] = '\n';
	line = ft_strjoin(rest, line);
	rest = 
	free(buffer);

}