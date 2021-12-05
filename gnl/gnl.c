#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}

char *ft_strjoin(const char *s1, const char *s2)
{
}

char *get_next_line(int fd)
{
	char *line, *buffer;
	static char *backup;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return NULL;
	line = find_newline(fd, buffer, backup);
	free(buffer);
}
