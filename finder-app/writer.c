#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

bool checkFileExists(const char* filepath)
{
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

int main (int argc, char* argv[])
{
    openlog("writer", 0, LOG_USER);
    // Check argument count and throw an error if it does not have file name and string
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments");
        exit(1);
    }
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

    const char *filename = argv[1];
    const char *string = argv[2];

    if (!checkFileExists(filename))
    {
        // Create file
        FILE *fp = fopen(filename, "w");
        if (fp == NULL) {
            syslog(LOG_ERR, "Error opening file: %s", strerror(errno));
            exit(1);
        }
        fclose(fp);
    }

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error opening file: %s", strerror(errno));
        exit(1);
    }

    fprintf(fp, "%s\n", string);
    fclose(fp);
}