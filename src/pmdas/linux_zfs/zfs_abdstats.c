#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "zfs_utils.h"
#include "zfs_abdstats.h"

void
zfs_abdstats_refresh(zfs_abdstats_t *abdstats)
{
    char *line = NULL, *mname, *mval;
    char delim[] = " ";
    char fname[MAXPATHLEN];
    FILE *fp;
    size_t len = 0;

    if (zfs_stats_file_check(fname, "abdstats") != 0)
        return;

    fp = fopen(fname, "r");
    if (fp != NULL) {
        while (getline(&line, &len, fp) != -1) {
            mname = strtok(line, delim);
            mval  = strtok(NULL, delim); // not used
            mval  = strtok(NULL, delim);
            if (strcmp(mname, "struct_size") == 0) abdstats->struct_size = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "linear_cnt") == 0) abdstats->linear_cnt = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "linear_data_size") == 0) abdstats->linear_data_size = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_cnt") == 0) abdstats->scatter_cnt = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_data_size") == 0) abdstats->scatter_data_size = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_chunk_waste") == 0) abdstats->scatter_chunk_waste = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_0") == 0) abdstats->scatter_order_0 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_1") == 0) abdstats->scatter_order_1 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_2") == 0) abdstats->scatter_order_2 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_3") == 0) abdstats->scatter_order_3 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_4") == 0) abdstats->scatter_order_4 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_5") == 0) abdstats->scatter_order_5 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_6") == 0) abdstats->scatter_order_6 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_7") == 0) abdstats->scatter_order_7 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_8") == 0) abdstats->scatter_order_8 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_9") == 0) abdstats->scatter_order_9 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_order_10") == 0) abdstats->scatter_order_10 = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_page_multi_chunk") == 0) abdstats->scatter_page_multi_chunk = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_page_multi_zone") == 0) abdstats->scatter_page_multi_zone = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_page_alloc_retry") == 0) abdstats->scatter_page_alloc_retry = strtoul(mval, NULL, 0);
            else if (strcmp(mname, "scatter_sg_table_retry") == 0) abdstats->scatter_sg_table_retry = strtoul(mval, NULL, 0);
        }
        free(line);
    }
    fclose(fp);
}