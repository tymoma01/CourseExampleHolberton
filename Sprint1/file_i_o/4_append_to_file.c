#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	int fd;
	const char *filename = "log.txt";
	const char *line = "New log entry\n";

	fd = open(filename,
		  O_WRONLY | O_CREAT | O_TRUNC, // O_APPEND / O_TRUNC
		  // O_TRUNC -> override
		  // O_APPEND -> append, add at the end.
		  0644);
	if (fd == -1)
	{
		const char *msg = "Error: cannot open file\n";
		write(STDERR_FILENO, msg, strlen(msg));
		exit(1);
	}

	if (write(fd, line, strlen(line)) == -1)
	{
		const char *msg = "Error: cannot write to file\n";
		write(STDERR_FILENO, msg, strlen(msg));
		close(fd);
		exit(1);
	}

	close(fd);
	return (0);
}
