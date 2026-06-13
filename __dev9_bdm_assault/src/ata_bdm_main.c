#include <bdm.h>
#include <irx.h>
#include <loadcore.h>
#include <stdio.h>

#include "../../__bdm_assault/src/bdm/include/module_debug.h"

#define MAJOR_VER 2
#define MINOR_VER 1

IRX_ID("usbd", MAJOR_VER, MINOR_VER);

extern struct irx_export_table _exp_bdm;
extern int dev9_start(int argc, char *argv[]);
extern int bdm_init();
extern void part_init();
extern int bdmfs_fatfs_start(int argc, char *argv[]);

int _start(int argc, char *argv[])
{
    int ret;
    char *dev9_argv[1] = {"dev9"};

    printf("USBD ASSAULT: mass transport v%d.%d\n", MAJOR_VER, MINOR_VER);

    if (argc <= 0 || argv == NULL || argv[0] == NULL)
        ret = dev9_start(1, dev9_argv);
    else
        ret = dev9_start(argc, argv);

    if (ret == MODULE_NO_RESIDENT_END) {
        M_PRINTF("ERROR: low-level mass transport init failed!\n");
        return ret;
    }

    if (RegisterLibraryEntries(&_exp_bdm) != 0) {
        M_PRINTF("ERROR: mass transport already registered!\n");
        return MODULE_NO_RESIDENT_END;
    }

    if (bdm_init() < 0) {
        M_PRINTF("ERROR: mass transport init failed!\n");
        return MODULE_NO_RESIDENT_END;
    }

    part_init();

    return bdmfs_fatfs_start(argc, argv);
}
