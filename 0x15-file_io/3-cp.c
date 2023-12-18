#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(void);
void close_file_descriptor(int fd);

/**
 * allocate_buffer - Allocates a 1024-byte buffer for file operations.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(void)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO,
                "Error: Unable to allocate memory for buffer\n");
        exit(99);
    }

    return (buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
    int result;

    result = close(fd);

    if (result == -1)
    {
        dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
        exit(100);
    }
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 97 if the argument count is incorrect.
 * Exits with code 98 if the source file does not exist or cannot be read.
 * Exits with code 99 if the destination file cannot be created or written to.
 * Exits with code 100 if either the source or destination file cannot be closed.
 */
int main(int argc, char *argv[])
{
    int source_fd, destination_fd, read_result, write_result;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
        exit(97);
    }

    buffer = allocate_buffer();
    source_fd = open(argv[1], O_RDONLY);
    read_result = read(source_fd, buffer, 1024);
    destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do
    {
        if (source_fd == -1 || read_result == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Unable to read from source file %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        write_result = write(destination_fd, buffer, read_result);
        if (destination_fd == -1 || write_result == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Unable to write to destination file %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

        read_result = read(source_fd, buffer, 1024);
        destination_fd = open(argv[2], O_WRONLY | O_APPEND);

    } while (read_result > 0);

    free(buffer);
    close_file_descriptor(source_fd);
    close_file_descriptor(destination_fd);

    return (0);
}

