/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {
        "rant_yoluna_hayir",    /* Team Name */

        "e244901",      /* First student ID */
        "Baran Yancı",/* First student name */

        "",             /* Second student ID */
        "",           /* Second student name */

        "",             /* Third student ID */
        ""            /* Third student Name */
};


/********************
 * CONVOLUTION KERNEL
 ********************/

/***************************************************************
 * Your different versions of the convolution functions  go here
 ***************************************************************/

/*
 * naive_conv - The naive baseline version of convolution
 */
char naive_conv_descr[] = "naive_conv: Naive baseline implementation";
void naive_conv(int dim, pixel *src, pixel *ker, unsigned *dst) {
    int i,j,k,l;

    for(i = 0; i < dim-8+1; i++)
        for(j = 0; j < dim-8+1; j++) {
            dst[RIDX(i, j, dim)] = 0;
            for(k = 0; k < 8; k++) {
                int iplusk = i + k;
                for (l = 0; l < 8; l++) {
                    int jplusl = j + l;
                    dst[RIDX(i, j, dim)] += src[RIDX(iplusk, jplusl, dim)].red * ker[RIDX(k, l, 8)].red;
                    dst[RIDX(i, j, dim)] += src[RIDX(iplusk, jplusl, dim)].green * ker[RIDX(k, l, 8)].green;
                    dst[RIDX(i, j, dim)] += src[RIDX(iplusk, jplusl, dim)].blue * ker[RIDX(k, l, 8)].blue;
                }
            }

        }
}

/*
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Convolution: Current working version";
void convolution(int dim, pixel *src, pixel *ker, unsigned *dst)
{

    naive_conv(dim,src,ker,dst);

}

/*********************************************************************
 * register_conv_functions - Register all of your different versions
 *     of the convolution functions  with the driver by calling the
 *     add_conv_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_conv_functions() {
    add_conv_function(&naive_conv, naive_conv_descr);
    add_conv_function(&convolution, convolution_descr);
    /* ... Register additional test functions here */
}




/************************
 * AVERAGE POOLING KERNEL
 ************************/

/*********************************************************
 * Your different versions of the average pooling  go here
 *********************************************************/

/*
 * naive_average_pooling - The naive baseline version of average pooling
 */
char naive_average_pooling_descr[] = "Naive Average Pooling: Naive baseline implementation";
void naive_average_pooling(int dim, pixel *src, pixel *dst) {
    int halfdim = dim/2;
    int i,j;

    for(i = 0; i < halfdim; i++) {
        int i2 = i * 2;
        for (j = 0; j < halfdim; j++) {
            int j2 = j * 2;
            dst[RIDX(i, j, halfdim)].red = 0;
            dst[RIDX(i, j, halfdim)].green = 0;
            dst[RIDX(i, j, halfdim)].blue = 0;

            int i2plusk = i2;

            int j2plusk = j2 ;
            int ridx = RIDX(i2plusk, j2plusk, dim);
            dst[RIDX(i, j, halfdim)].red += src[ridx].red;
            dst[RIDX(i, j, halfdim)].green += src[ridx].green;
            dst[RIDX(i, j, halfdim)].blue += src[ridx].blue;

            j2plusk = j2 + 1;
            ridx = RIDX(i2plusk, j2plusk, dim);
            dst[RIDX(i, j, halfdim)].red += src[ridx].red;
            dst[RIDX(i, j, halfdim)].green += src[ridx].green;
            dst[RIDX(i, j, halfdim)].blue += src[ridx].blue;

            i2plusk = i2 + 1;

            j2plusk = j2 ;
            ridx = RIDX(i2plusk, j2plusk, dim);
            dst[RIDX(i, j, halfdim)].red += src[ridx].red;
            dst[RIDX(i, j, halfdim)].green += src[ridx].green;
            dst[RIDX(i, j, halfdim)].blue += src[ridx].blue;

            j2plusk = j2 + 1;
            ridx = RIDX(i2plusk, j2plusk, dim);
            dst[RIDX(i, j, halfdim)].red += src[ridx].red;
            dst[RIDX(i, j, halfdim)].green += src[ridx].green;
            dst[RIDX(i, j, halfdim)].blue += src[ridx].blue;

            int var1 = dst[RIDX(i, j, halfdim)].red / 4;
            int var2 = dst[RIDX(i, j, halfdim)].green / 4;
            int var3 = dst[RIDX(i, j, halfdim)].blue / 4;
            dst[RIDX(i, j, halfdim)].red = var1;
            dst[RIDX(i, j, halfdim)].green = var2;
            dst[RIDX(i, j, halfdim)].blue = var3;
        }
    }
}


/*
 * average_pooling - Your current working version of average_pooling
 * IMPORTANT: This is the version you will be graded on
 */
char average_pooling_descr[] = "Average Pooling: Current working version";
void average_pooling(int dim, pixel *src, pixel *dst)
{

    naive_average_pooling(dim,src,dst);

}

/******************************************************************************
 * register_average_pooling_functions - Register all of your different versions
 *     of the average pooling  with the driver by calling the
 *     add_average_pooling_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 ******************************************************************************/

void register_average_pooling_functions() {
    add_average_pooling_function(&naive_average_pooling, naive_average_pooling_descr);
    add_average_pooling_function(&average_pooling, average_pooling_descr);
    /* ... Register additional test functions here */
}

