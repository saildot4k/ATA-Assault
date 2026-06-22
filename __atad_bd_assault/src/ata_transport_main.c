#include <irx.h>
#include <loadcore.h>
#include <stdio.h>

#define MAJOR_VER 2
#define MINOR_VER 7

extern int dev9_start(int argc, char *argv[]);
extern int atad_start(int argc, char *argv[]);

int _start(int argc, char *argv[])
{
    int ret;
    char *dev9_argv[1] = {"dev9"};

    printf("USBHDFSD: starting ATA mass transport v%d.%d\n", MAJOR_VER, MINOR_VER);

    if (argc <= 0 || argv == NULL || argv[0] == NULL)
        ret = dev9_start(1, dev9_argv);
    else
        ret = dev9_start(argc, argv);

    if (ret != MODULE_RESIDENT_END) {
        printf("USBHDFSD: DEV9 init failed, ret=%d\n", ret);
        return ret;
    }

    ret = atad_start(argc, argv);
    if (ret != MODULE_RESIDENT_END)
        printf("USBHDFSD: ATAD init failed, ret=%d\n", ret);

    return ret;
}
