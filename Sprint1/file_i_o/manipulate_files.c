#include <fcntl.h>   /* open */
#include <unistd.h>  /* read, write, close */
#include <stdlib.h>  /* exit */
#include <string.h>  /* strlen */

int main(int ac, char **av)
{
	int fd;
	ssize_t n_read;
	char buffer[32];

	if (ac != 2)
	{
		const char *msg = "Usage: ./a.out filename\n";
		write(STDERR_FILENO, msg, strlen(msg));
		exit(1);
	}

	/* Open the file in read-only mode */
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		const char *msg = "Error: cannot open file\n";
		write(STDERR_FILENO, msg, strlen(msg));
		exit(1);
	}

	/* Read up to 32 bytes and write them to STDOUT */
	n_read = read(fd, buffer, sizeof(buffer));
	if (n_read == -1)
	{
		const char *msg = "Error: cannot read file\n";
		write(STDERR_FILENO, msg, strlen(msg));
		close(fd);
		exit(1);
	}

	write(STDOUT_FILENO, buffer, n_read);

	/* Always close the file descriptor when done */
	if (close(fd) == -1)
	{
		const char *msg = "Error: cannot close file descriptor\n";
		write(STDERR_FILENO, msg, strlen(msg));
		exit(1);
	}

	return (0);
}
