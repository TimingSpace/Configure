#include <stdio.h>
#include <string>
#include "configure.h"
int main(int argc, char ** argv)
{
    std::string config_file_path;
    if(argc>1)
        config_file_path = argv[1];
    else
        config_file_path = "config.txt";
    Configure configure(config_file_path);
    int camera_cx = configure.GetValue<int>("camera_cx");
    printf("%d\n",camera_cx);
    return 0;

}
