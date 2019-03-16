//This is a comment
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>

int main (int argc, char* argv[])
{
	int read_fd;
	int write_fd;
	off_t offset=0;

	read_fd = open (argv[0], O_RDONLY);
	write_fd = socket (PF_APPLETALK, SOCK_DGRAM,0);
	sendfile (write_fd, read_fd, &offset, 2);
	close (read_fd);
	close (write_fd);
	return 0;
}
