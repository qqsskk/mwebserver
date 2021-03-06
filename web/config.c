#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include "config.h"

#include "misc/logger.h"


int config_parse(char* file, config* conf)
{
    conf->port = 2019;
    conf->work_thread = 0;

    conf->timeout_keep_alive = 30;
    conf->connect_time_limit = 30;

    conf->rootdir = "./www";
    DIR *dirp = NULL;
    if (conf->rootdir != NULL &&
        (dirp = opendir(conf->rootdir)) != NULL) {
        closedir(dirp);
        conf->rootdir_fd = open(conf->rootdir, O_RDONLY);
        
        return 0;
    } else {
        debug_sys("rootdir is invalide, ", conf->rootdir);
        return -1;
    }

}