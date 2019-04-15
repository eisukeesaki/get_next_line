#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(void)
{
		int		fd;
		char	buff[100+1];
		int		rc;

		fd = open("test.txt", O_RDONLY);
		if (fd == -1)
		{
				printf("file open error\n");
				return (1);
		}
		rc = read(fd, buff, 100);
		if (rc == -1)
		{
				printf("file read error\n");
		}
		else
		{
				buff[rc] = '\0';
				printf("read:%d - %s\n", rc, buff);
		}
		close(fd);
	return (0);
}
