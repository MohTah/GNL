int	main()
{
	char	*line;
	int		fd = 0;

	fd = open("/home/mohtah/GNL/test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);
	
	return (0);
}