#include <syslog.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]){
    int return_code;

    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3)
    {
        syslog(LOG_ERR, "not enough arguments passed in!");
        syslog(LOG_ERR, "writefile and writestr are required! Exiting...");

        closelog();
        return 1;
    }

    char* writefile = argv[1];
    char* writestr = argv[2];

    FILE* file = fopen(writefile, "w");

    if (file == NULL)
    {
        syslog(LOG_ERR, "Error from errno: %s", strerror(errno));
        syslog(LOG_ERR, "Unable to create file %s! Exiting...", writefile);

        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    
    return_code = fprintf(file, "%s", writestr);

    if (return_code <= 0)
    {
        syslog(LOG_ERR, "Unable to write to file %s! Exiting...", writefile);

        closelog();
        fclose(file);
        return 1;
    }

    return_code = fclose(file);

    if (return_code != 0)
    {
        syslog(LOG_ERR, "Unable to close file %s! Exiting...", writefile);

        closelog();
        return 1;
    }

    closelog();
    return 0;
}