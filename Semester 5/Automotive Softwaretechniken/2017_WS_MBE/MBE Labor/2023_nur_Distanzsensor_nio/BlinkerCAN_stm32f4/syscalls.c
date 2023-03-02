
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "waijung_hwdrvlib.h"

/* Original file from
** URL: https://code.google.com/p/andrei-development/source/browse/branches/dev/stm32f3-discovery/Navigation/src/newlib_stubs.c
*/

#ifndef UNUSED
#define UNUSED(x) (void)x
#endif

#undef errno
extern int errno;

/*
 * A pointer to a list of environment variables and their values.
 * For a minimal environment, this empty list is adequate.
 */
char *__env[1] = { 0 };
char **environ = __env;

int _write(int file, char *ptr, int len);

void _exit(int status) {
        UNUSED(status);

        _write(1, "exit", 4);
        while (1) {
                ;
        }
}

int _close(int file) {
        UNUSED(file);

        return -1;
}

/*
 * Transfer control to a new process. Minimal implementation (for a system
 * without processes)
 */
int _execve(char *name, char **argv, char **env) {
        UNUSED(name);
        UNUSED(argv);
        UNUSED(env);

        errno = ENOMEM;
        return -1;
}

/*
 * Create a new process. Minimal implementation (for a system without processes)
 */
int _fork() {
        errno = EAGAIN;
        return -1;
}
/*
 * Status of an open file. Minimal implementation.
 */
int _fstat(int file, struct stat *st) {
        UNUSED(file);

        st->st_mode = S_IFCHR;
        return 0;
}

/*
 * Process-ID; this is sometimes used to generate strings unlikely to conflict
 * with other processes. Minimal implementation, for a system without processes.
 */
int _getpid() {
        return 1;
}

/*
 * Query whether output stream is a terminal. For consistency with the other
 * minimal implementation.
 */
int _isatty(int file) {
        UNUSED(file);

		return 0;
}

/*
 * Send a signal. Minimal implementation.
 */
int _kill(int pid, int sig) {
        UNUSED(pid);
        UNUSED(sig);

        errno = EINVAL;
        return (-1);
}

/*
 * Establish a new name for an existing file. Minimal implementation.
 */
int _link(char *old, char *new) {
        UNUSED(old);
        UNUSED(new);

        errno = EMLINK;
        return -1;
}

/*
 * Set position in a file. Minimal implementation.
 */
int _lseek(int file, int ptr, int dir) {
        UNUSED(file);
        UNUSED(ptr);
        UNUSED(dir);

        return 0;
}

/*
 * Increase program data space. Malloc and related functions depend on this.
 */
caddr_t _sbrk(int incr) {

        extern char __bss_end__; // Defined by the linker
        static char *heap_end = 0;
        char *prev_heap_end;

        if (heap_end == 0) {
                heap_end = &__bss_end__;
        }
        prev_heap_end = heap_end;

        char * stack = (char*) __get_MSP();
        if (heap_end + incr >  stack){
			 errno = ENOMEM;
             return  (caddr_t) - 1;
        }

        heap_end += incr;
        return (caddr_t) prev_heap_end;

}

/*
 * Read a character to a file. `libc' subroutines will use this system routine
 * for input from all files, including stdin.
 * Returns -1 on error or blocks until the number of characters have been read.
 */
int _read(int file, char *ptr, int len) {
		UNUSED(file);
		UNUSED(ptr);
		UNUSED(len);
        return 0;
}

/*
 * Status of a file (by name). Minimal implementation.
 * int _EXFUN(stat,( const char *__path, struct stat *__sbuf ));
 */
int _stat(const char *filepath, struct stat *st) {
        UNUSED(filepath);

        st->st_mode = S_IFCHR;
        return 0;
}

/*
 * Timing information for current process. Minimal implementation.
 */
//clock_t _times(struct tms *buf) {
//        UNUSED(buf);
//
//        return -1;
//}

/*
 * Remove a file's directory entry. Minimal implementation.
 */
int _unlink(char *name) {
        UNUSED(name);

        errno = ENOENT;
        return -1;
}

/*
 * Wait for a child process. Minimal implementation.
 */
int _wait(int *status) {
        UNUSED(status);

        errno = ECHILD;
        return -1;
}

/*
 * Write a character to a file. `libc' subroutines will use this system routine
 * for output to all files, including stdout.
 * Returns -1 on error or number of bytes sent.
 */
int _write(int file, char *ptr, int len) {
        UNUSED(file);
		UNUSED(ptr);
		UNUSED(len);
        return 0;
}
