#include <fcntl.h>      /* open */
#include <unistd.h>     /* write, close */
#include <sys/stat.h>   /* permission macros */
#include <string.h>     /* strlen */

int main(void)
{
	int fd;
	const char *filename = "demo_permissions.txt";
	const char *text = "Secret data\n";

	/* rw------- for the owner (user) only */
	fd = open(filename,
		  O_WRONLY | O_CREAT | O_TRUNC,
		  S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		const char *msg = "Error: cannot create file\n";
		write(STDERR_FILENO, msg, strlen(msg));
		return (1);
	}

	if (write(fd, text, strlen(text)) == -1)
	{
		const char *msg = "Error: cannot write to file\n";
		write(STDERR_FILENO, msg, strlen(msg));
		close(fd);
		return (1);
	}

	close(fd);
	return (0);
}
