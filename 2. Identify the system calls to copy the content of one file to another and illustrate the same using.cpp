#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return 2;
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        return 3;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytesRead) != bytesRead) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            return 4;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
        close(source_fd);
        close(dest_fd);
        return 5;
    }

    printf("File copied successfully.\n");

    close(source_fd);
    close(dest_fd);

    return 0;
}
