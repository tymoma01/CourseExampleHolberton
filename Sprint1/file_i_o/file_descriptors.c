#include <unistd.h>
#include <string.h>

int main(void)
{
	const char *msg_out = "This goes to STDOUT\n";
	const char *msg_err = "This goes to STDERR\n";

	/* Using symbolic constants instead of raw numbers */
	write(STDOUT_FILENO, msg_out, strlen(msg_out));
	write(STDERR_FILENO, msg_err, strlen(msg_err));

	/* Equivalent, but worse style: write(1, ...), write(2, ...) */
	return (0);
}
