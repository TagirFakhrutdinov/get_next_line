#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	gnl(int fd)
{
	char	*line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}

int main(void)
{
	int fd;
	int	flag;
	int	count = 400;
	char	test[10];

	if ((fd = open("gnl-war-machine-v2019/tests/Mr._Justice_Maxell_by_Edgar_Wallace.txt", O_RDONLY)) == -1)
		printf("error");
	while (count != 0)
	{
		gnl(fd);
		count--;
	}
	return (0);
}
