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
    int i,j, ridx, i1, i2, i3, i4, i5, i6, i7, j1, j2, j3, j4, j5, j6, j7;

    for(i = 0; i < dim-7; i++) {
        i1 = i + 1; i2 = i + 2; i3 = i + 3; i4 = i + 4; i5 = i + 5; i6 = i + 6; i7 = i + 7;
        for (j = 0; j < dim - 7; j++) {
            j1 = j + 1; j2 = j + 2; j3 = j + 3; j4 = j + 4; j5 = j + 5; j6 = j + 6, j7 = j + 7;
            ridx = RIDX(i,j,dim);
            dst[RIDX(i,j,dim)] = 0;


            dst[ridx] += src[ridx].red * ker[RIDX(0, 0, 8)].red;
            dst[ridx] += src[ridx].green * ker[RIDX(0, 0, 8)].green;
            dst[ridx] += src[ridx].blue * ker[RIDX(0, 0, 8)].blue;

            dst[ridx] += src[RIDX(i, j1, dim)].red * ker[RIDX(0, 1, 8)].red;
            dst[ridx] += src[RIDX(i, j1, dim)].green * ker[RIDX(0, 1, 8)].green;
            dst[ridx] += src[RIDX(i, j1, dim)].blue * ker[RIDX(0, 1, 8)].blue;

            dst[ridx] += src[RIDX(i, j2, dim)].red * ker[RIDX(0, 2, 8)].red;
            dst[ridx] += src[RIDX(i, j2, dim)].green * ker[RIDX(0, 2, 8)].green;
            dst[ridx] += src[RIDX(i, j2, dim)].blue * ker[RIDX(0, 2, 8)].blue;

            dst[ridx] += src[RIDX(i, j3, dim)].red * ker[RIDX(0, 3, 8)].red;
            dst[ridx] += src[RIDX(i, j3, dim)].green * ker[RIDX(0, 3, 8)].green;
            dst[ridx] += src[RIDX(i, j3, dim)].blue * ker[RIDX(0, 3, 8)].blue;

            dst[ridx] += src[RIDX(i, j4, dim)].red * ker[RIDX(0, 4, 8)].red;
            dst[ridx] += src[RIDX(i, j4, dim)].green * ker[RIDX(0, 4, 8)].green;
            dst[ridx] += src[RIDX(i, j4, dim)].blue * ker[RIDX(0, 4, 8)].blue;

            dst[ridx] += src[RIDX(i, j5, dim)].red * ker[RIDX(0, 5, 8)].red;
            dst[ridx] += src[RIDX(i, j5, dim)].green * ker[RIDX(0, 5, 8)].green;
            dst[ridx] += src[RIDX(i, j5, dim)].blue * ker[RIDX(0, 5, 8)].blue;

            dst[ridx] += src[RIDX(i, j6, dim)].red * ker[RIDX(0, 6, 8)].red;
            dst[ridx] += src[RIDX(i, j6, dim)].green * ker[RIDX(0, 6, 8)].green;
            dst[ridx] += src[RIDX(i, j6, dim)].blue * ker[RIDX(0, 6, 8)].blue;

            dst[ridx] += src[RIDX(i, j7, dim)].red * ker[RIDX(0, 7, 8)].red;
            dst[ridx] += src[RIDX(i, j7, dim)].green * ker[RIDX(0, 7, 8)].green;
            dst[ridx] += src[RIDX(i, j7, dim)].blue * ker[RIDX(0, 7, 8)].blue;



            dst[ridx] += src[RIDX(i1, j, dim)].red * ker[RIDX(1, 0, 8)].red;
            dst[ridx] += src[RIDX(i1, j, dim)].green * ker[RIDX(1, 0, 8)].green;
            dst[ridx] += src[RIDX(i1, j, dim)].blue * ker[RIDX(1, 0, 8)].blue;

            dst[ridx] += src[RIDX(i1, j1, dim)].red * ker[RIDX(1, 1, 8)].red;
            dst[ridx] += src[RIDX(i1, j1, dim)].green * ker[RIDX(1, 1, 8)].green;
            dst[ridx] += src[RIDX(i1, j1, dim)].blue * ker[RIDX(1, 1, 8)].blue;

            dst[ridx] += src[RIDX(i1, j2, dim)].red * ker[RIDX(1, 2, 8)].red;
            dst[ridx] += src[RIDX(i1, j2, dim)].green * ker[RIDX(1, 2, 8)].green;
            dst[ridx] += src[RIDX(i1, j2, dim)].blue * ker[RIDX(1, 2, 8)].blue;

            dst[ridx] += src[RIDX(i1, j3, dim)].red * ker[RIDX(1, 3, 8)].red;
            dst[ridx] += src[RIDX(i1, j3, dim)].green * ker[RIDX(1, 3, 8)].green;
            dst[ridx] += src[RIDX(i1, j3, dim)].blue * ker[RIDX(1, 3, 8)].blue;

            dst[ridx] += src[RIDX(i1, j4, dim)].red * ker[RIDX(1, 4, 8)].red;
            dst[ridx] += src[RIDX(i1, j4, dim)].green * ker[RIDX(1, 4, 8)].green;
            dst[ridx] += src[RIDX(i1, j4, dim)].blue * ker[RIDX(1, 4, 8)].blue;

            dst[ridx] += src[RIDX(i1, j5, dim)].red * ker[RIDX(1, 5, 8)].red;
            dst[ridx] += src[RIDX(i1, j5, dim)].green * ker[RIDX(1, 5, 8)].green;
            dst[ridx] += src[RIDX(i1, j5, dim)].blue * ker[RIDX(1, 5, 8)].blue;

            dst[ridx] += src[RIDX(i1, j6, dim)].red * ker[RIDX(1, 6, 8)].red;
            dst[ridx] += src[RIDX(i1, j6, dim)].green * ker[RIDX(1, 6, 8)].green;
            dst[ridx] += src[RIDX(i1, j6, dim)].blue * ker[RIDX(1, 6, 8)].blue;

            dst[ridx] += src[RIDX(i1, j7, dim)].red * ker[RIDX(1, 7, 8)].red;
            dst[ridx] += src[RIDX(i1, j7, dim)].green * ker[RIDX(1, 7, 8)].green;
            dst[ridx] += src[RIDX(i1, j7, dim)].blue * ker[RIDX(1, 7, 8)].blue;



            dst[ridx] += src[RIDX(i2, j, dim)].red * ker[RIDX(2, 0, 8)].red;
            dst[ridx] += src[RIDX(i2, j, dim)].green * ker[RIDX(2, 0, 8)].green;
            dst[ridx] += src[RIDX(i2, j, dim)].blue * ker[RIDX(2, 0, 8)].blue;

            dst[ridx] += src[RIDX(i2, j1, dim)].red * ker[RIDX(2, 1, 8)].red;
            dst[ridx] += src[RIDX(i2, j1, dim)].green * ker[RIDX(2, 1, 8)].green;
            dst[ridx] += src[RIDX(i2, j1, dim)].blue * ker[RIDX(2, 1, 8)].blue;

            dst[ridx] += src[RIDX(i2, j2, dim)].red * ker[RIDX(2, 2, 8)].red;
            dst[ridx] += src[RIDX(i2, j2, dim)].green * ker[RIDX(2, 2, 8)].green;
            dst[ridx] += src[RIDX(i2, j2, dim)].blue * ker[RIDX(2, 2, 8)].blue;

            dst[ridx] += src[RIDX(i2, j3, dim)].red * ker[RIDX(2, 3, 8)].red;
            dst[ridx] += src[RIDX(i2, j3, dim)].green * ker[RIDX(2, 3, 8)].green;
            dst[ridx] += src[RIDX(i2, j3, dim)].blue * ker[RIDX(2, 3, 8)].blue;

            dst[ridx] += src[RIDX(i2, j4, dim)].red * ker[RIDX(2, 4, 8)].red;
            dst[ridx] += src[RIDX(i2, j4, dim)].green * ker[RIDX(2, 4, 8)].green;
            dst[ridx] += src[RIDX(i2, j4, dim)].blue * ker[RIDX(2, 4, 8)].blue;

            dst[ridx] += src[RIDX(i2, j5, dim)].red * ker[RIDX(2, 5, 8)].red;
            dst[ridx] += src[RIDX(i2, j5, dim)].green * ker[RIDX(2, 5, 8)].green;
            dst[ridx] += src[RIDX(i2, j5, dim)].blue * ker[RIDX(2, 5, 8)].blue;

            dst[ridx] += src[RIDX(i2, j6, dim)].red * ker[RIDX(2, 6, 8)].red;
            dst[ridx] += src[RIDX(i2, j6, dim)].green * ker[RIDX(2, 6, 8)].green;
            dst[ridx] += src[RIDX(i2, j6, dim)].blue * ker[RIDX(2, 6, 8)].blue;

            dst[ridx] += src[RIDX(i2, j7, dim)].red * ker[RIDX(2, 7, 8)].red;
            dst[ridx] += src[RIDX(i2, j7, dim)].green * ker[RIDX(2, 7, 8)].green;
            dst[ridx] += src[RIDX(i2, j7, dim)].blue * ker[RIDX(2, 7, 8)].blue;



            dst[ridx] += src[RIDX(i3, j, dim)].red * ker[RIDX(3, 0, 8)].red;
            dst[ridx] += src[RIDX(i3, j, dim)].green * ker[RIDX(3, 0, 8)].green;
            dst[ridx] += src[RIDX(i3, j, dim)].blue * ker[RIDX(3, 0, 8)].blue;

            dst[ridx] += src[RIDX(i3, j1, dim)].red * ker[RIDX(3, 1, 8)].red;
            dst[ridx] += src[RIDX(i3, j1, dim)].green * ker[RIDX(3, 1, 8)].green;
            dst[ridx] += src[RIDX(i3, j1, dim)].blue * ker[RIDX(3, 1, 8)].blue;

            dst[ridx] += src[RIDX(i3, j2, dim)].red * ker[RIDX(3, 2, 8)].red;
            dst[ridx] += src[RIDX(i3, j2, dim)].green * ker[RIDX(3, 2, 8)].green;
            dst[ridx] += src[RIDX(i3, j2, dim)].blue * ker[RIDX(3, 2, 8)].blue;

            dst[ridx] += src[RIDX(i3, j3, dim)].red * ker[RIDX(3, 3, 8)].red;
            dst[ridx] += src[RIDX(i3, j3, dim)].green * ker[RIDX(3, 3, 8)].green;
            dst[ridx] += src[RIDX(i3, j3, dim)].blue * ker[RIDX(3, 3, 8)].blue;

            dst[ridx] += src[RIDX(i3, j4, dim)].red * ker[RIDX(3, 4, 8)].red;
            dst[ridx] += src[RIDX(i3, j4, dim)].green * ker[RIDX(3, 4, 8)].green;
            dst[ridx] += src[RIDX(i3, j4, dim)].blue * ker[RIDX(3, 4, 8)].blue;

            dst[ridx] += src[RIDX(i3, j5, dim)].red * ker[RIDX(3, 5, 8)].red;
            dst[ridx] += src[RIDX(i3, j5, dim)].green * ker[RIDX(3, 5, 8)].green;
            dst[ridx] += src[RIDX(i3, j5, dim)].blue * ker[RIDX(3, 5, 8)].blue;

            dst[ridx] += src[RIDX(i3, j6, dim)].red * ker[RIDX(3, 6, 8)].red;
            dst[ridx] += src[RIDX(i3, j6, dim)].green * ker[RIDX(3, 6, 8)].green;
            dst[ridx] += src[RIDX(i3, j6, dim)].blue * ker[RIDX(3, 6, 8)].blue;

            dst[ridx] += src[RIDX(i3, j7, dim)].red * ker[RIDX(3, 7, 8)].red;
            dst[ridx] += src[RIDX(i3, j7, dim)].green * ker[RIDX(3, 7, 8)].green;
            dst[ridx] += src[RIDX(i3, j7, dim)].blue * ker[RIDX(3, 7, 8)].blue;



            dst[ridx] += src[RIDX(i4, j, dim)].red * ker[RIDX(4, 0, 8)].red;
            dst[ridx] += src[RIDX(i4, j, dim)].green * ker[RIDX(4, 0, 8)].green;
            dst[ridx] += src[RIDX(i4, j, dim)].blue * ker[RIDX(4, 0, 8)].blue;

            dst[ridx] += src[RIDX(i4, j1, dim)].red * ker[RIDX(4, 1, 8)].red;
            dst[ridx] += src[RIDX(i4, j1, dim)].green * ker[RIDX(4, 1, 8)].green;
            dst[ridx] += src[RIDX(i4, j1, dim)].blue * ker[RIDX(4, 1, 8)].blue;

            dst[ridx] += src[RIDX(i4, j2, dim)].red * ker[RIDX(4, 2, 8)].red;
            dst[ridx] += src[RIDX(i4, j2, dim)].green * ker[RIDX(4, 2, 8)].green;
            dst[ridx] += src[RIDX(i4, j2, dim)].blue * ker[RIDX(4, 2, 8)].blue;

            dst[ridx] += src[RIDX(i4, j3, dim)].red * ker[RIDX(4, 3, 8)].red;
            dst[ridx] += src[RIDX(i4, j3, dim)].green * ker[RIDX(4, 3, 8)].green;
            dst[ridx] += src[RIDX(i4, j3, dim)].blue * ker[RIDX(4, 3, 8)].blue;

            dst[ridx] += src[RIDX(i4, j4, dim)].red * ker[RIDX(4, 4, 8)].red;
            dst[ridx] += src[RIDX(i4, j4, dim)].green * ker[RIDX(4, 4, 8)].green;
            dst[ridx] += src[RIDX(i4, j4, dim)].blue * ker[RIDX(4, 4, 8)].blue;

            dst[ridx] += src[RIDX(i4, j5, dim)].red * ker[RIDX(4, 5, 8)].red;
            dst[ridx] += src[RIDX(i4, j5, dim)].green * ker[RIDX(4, 5, 8)].green;
            dst[ridx] += src[RIDX(i4, j5, dim)].blue * ker[RIDX(4, 5, 8)].blue;

            dst[ridx] += src[RIDX(i4, j6, dim)].red * ker[RIDX(4, 6, 8)].red;
            dst[ridx] += src[RIDX(i4, j6, dim)].green * ker[RIDX(4, 6, 8)].green;
            dst[ridx] += src[RIDX(i4, j6, dim)].blue * ker[RIDX(4, 6, 8)].blue;

            dst[ridx] += src[RIDX(i4, j7, dim)].red * ker[RIDX(4, 7, 8)].red;
            dst[ridx] += src[RIDX(i4, j7, dim)].green * ker[RIDX(4, 7, 8)].green;
            dst[ridx] += src[RIDX(i4, j7, dim)].blue * ker[RIDX(4, 7, 8)].blue;



            dst[ridx] += src[RIDX(i5, j, dim)].red * ker[RIDX(5, 0, 8)].red;
            dst[ridx] += src[RIDX(i5, j, dim)].green * ker[RIDX(5, 0, 8)].green;
            dst[ridx] += src[RIDX(i5, j, dim)].blue * ker[RIDX(5, 0, 8)].blue;

            dst[ridx] += src[RIDX(i5, j1, dim)].red * ker[RIDX(5, 1, 8)].red;
            dst[ridx] += src[RIDX(i5, j1, dim)].green * ker[RIDX(5, 1, 8)].green;
            dst[ridx] += src[RIDX(i5, j1, dim)].blue * ker[RIDX(5, 1, 8)].blue;

            dst[ridx] += src[RIDX(i5, j2, dim)].red * ker[RIDX(5, 2, 8)].red;
            dst[ridx] += src[RIDX(i5, j2, dim)].green * ker[RIDX(5, 2, 8)].green;
            dst[ridx] += src[RIDX(i5, j2, dim)].blue * ker[RIDX(5, 2, 8)].blue;

            dst[ridx] += src[RIDX(i5, j3, dim)].red * ker[RIDX(5, 3, 8)].red;
            dst[ridx] += src[RIDX(i5, j3, dim)].green * ker[RIDX(5, 3, 8)].green;
            dst[ridx] += src[RIDX(i5, j3, dim)].blue * ker[RIDX(5, 3, 8)].blue;

            dst[ridx] += src[RIDX(i5, j4, dim)].red * ker[RIDX(5, 4, 8)].red;
            dst[ridx] += src[RIDX(i5, j4, dim)].green * ker[RIDX(5, 4, 8)].green;
            dst[ridx] += src[RIDX(i5, j4, dim)].blue * ker[RIDX(5, 4, 8)].blue;

            dst[ridx] += src[RIDX(i5, j5, dim)].red * ker[RIDX(5, 5, 8)].red;
            dst[ridx] += src[RIDX(i5, j5, dim)].green * ker[RIDX(5, 5, 8)].green;
            dst[ridx] += src[RIDX(i5, j5, dim)].blue * ker[RIDX(5, 5, 8)].blue;

            dst[ridx] += src[RIDX(i5, j6, dim)].red * ker[RIDX(5, 6, 8)].red;
            dst[ridx] += src[RIDX(i5, j6, dim)].green * ker[RIDX(5, 6, 8)].green;
            dst[ridx] += src[RIDX(i5, j6, dim)].blue * ker[RIDX(5, 6, 8)].blue;

            dst[ridx] += src[RIDX(i5, j7, dim)].red * ker[RIDX(5, 7, 8)].red;
            dst[ridx] += src[RIDX(i5, j7, dim)].green * ker[RIDX(5, 7, 8)].green;
            dst[ridx] += src[RIDX(i5, j7, dim)].blue * ker[RIDX(5, 7, 8)].blue;



            dst[ridx] += src[RIDX(i6, j, dim)].red * ker[RIDX(6, 0, 8)].red;
            dst[ridx] += src[RIDX(i6, j, dim)].green * ker[RIDX(6, 0, 8)].green;
            dst[ridx] += src[RIDX(i6, j, dim)].blue * ker[RIDX(6, 0, 8)].blue;

            dst[ridx] += src[RIDX(i6, j1, dim)].red * ker[RIDX(6, 1, 8)].red;
            dst[ridx] += src[RIDX(i6, j1, dim)].green * ker[RIDX(6, 1, 8)].green;
            dst[ridx] += src[RIDX(i6, j1, dim)].blue * ker[RIDX(6, 1, 8)].blue;

            dst[ridx] += src[RIDX(i6, j2, dim)].red * ker[RIDX(6, 2, 8)].red;
            dst[ridx] += src[RIDX(i6, j2, dim)].green * ker[RIDX(6, 2, 8)].green;
            dst[ridx] += src[RIDX(i6, j2, dim)].blue * ker[RIDX(6, 2, 8)].blue;

            dst[ridx] += src[RIDX(i6, j3, dim)].red * ker[RIDX(6, 3, 8)].red;
            dst[ridx] += src[RIDX(i6, j3, dim)].green * ker[RIDX(6, 3, 8)].green;
            dst[ridx] += src[RIDX(i6, j3, dim)].blue * ker[RIDX(6, 3, 8)].blue;

            dst[ridx] += src[RIDX(i6, j4, dim)].red * ker[RIDX(6, 4, 8)].red;
            dst[ridx] += src[RIDX(i6, j4, dim)].green * ker[RIDX(6, 4, 8)].green;
            dst[ridx] += src[RIDX(i6, j4, dim)].blue * ker[RIDX(6, 4, 8)].blue;

            dst[ridx] += src[RIDX(i6, j5, dim)].red * ker[RIDX(6, 5, 8)].red;
            dst[ridx] += src[RIDX(i6, j5, dim)].green * ker[RIDX(6, 5, 8)].green;
            dst[ridx] += src[RIDX(i6, j5, dim)].blue * ker[RIDX(6, 5, 8)].blue;

            dst[ridx] += src[RIDX(i6, j6, dim)].red * ker[RIDX(6, 6, 8)].red;
            dst[ridx] += src[RIDX(i6, j6, dim)].green * ker[RIDX(6, 6, 8)].green;
            dst[ridx] += src[RIDX(i6, j6, dim)].blue * ker[RIDX(6, 6, 8)].blue;

            dst[ridx] += src[RIDX(i6, j7, dim)].red * ker[RIDX(6, 7, 8)].red;
            dst[ridx] += src[RIDX(i6, j7, dim)].green * ker[RIDX(6, 7, 8)].green;
            dst[ridx] += src[RIDX(i6, j7, dim)].blue * ker[RIDX(6, 7, 8)].blue;



            dst[ridx] += src[RIDX(i7, j, dim)].red * ker[RIDX(7, 0, 8)].red;
            dst[ridx] += src[RIDX(i7, j, dim)].green * ker[RIDX(7, 0, 8)].green;
            dst[ridx] += src[RIDX(i7, j, dim)].blue * ker[RIDX(7, 0, 8)].blue;

            dst[ridx] += src[RIDX(i7, j1, dim)].red * ker[RIDX(7, 1, 8)].red;
            dst[ridx] += src[RIDX(i7, j1, dim)].green * ker[RIDX(7, 1, 8)].green;
            dst[ridx] += src[RIDX(i7, j1, dim)].blue * ker[RIDX(7, 1, 8)].blue;

            dst[ridx] += src[RIDX(i7, j2, dim)].red * ker[RIDX(7, 2, 8)].red;
            dst[ridx] += src[RIDX(i7, j2, dim)].green * ker[RIDX(7, 2, 8)].green;
            dst[ridx] += src[RIDX(i7, j2, dim)].blue * ker[RIDX(7, 2, 8)].blue;

            dst[ridx] += src[RIDX(i7, j3, dim)].red * ker[RIDX(7, 3, 8)].red;
            dst[ridx] += src[RIDX(i7, j3, dim)].green * ker[RIDX(7, 3, 8)].green;
            dst[ridx] += src[RIDX(i7, j3, dim)].blue * ker[RIDX(7, 3, 8)].blue;

            dst[ridx] += src[RIDX(i7, j4, dim)].red * ker[RIDX(7, 4, 8)].red;
            dst[ridx] += src[RIDX(i7, j4, dim)].green * ker[RIDX(7, 4, 8)].green;
            dst[ridx] += src[RIDX(i7, j4, dim)].blue * ker[RIDX(7, 4, 8)].blue;

            dst[ridx] += src[RIDX(i7, j5, dim)].red * ker[RIDX(7, 5, 8)].red;
            dst[ridx] += src[RIDX(i7, j5, dim)].green * ker[RIDX(7, 5, 8)].green;
            dst[ridx] += src[RIDX(i7, j5, dim)].blue * ker[RIDX(7, 5, 8)].blue;

            dst[ridx] += src[RIDX(i7, j6, dim)].red * ker[RIDX(7, 6, 8)].red;
            dst[ridx] += src[RIDX(i7, j6, dim)].green * ker[RIDX(7, 6, 8)].green;
            dst[ridx] += src[RIDX(i7, j6, dim)].blue * ker[RIDX(7, 6, 8)].blue;

            dst[ridx] += src[RIDX(i7, j7, dim)].red * ker[RIDX(7, 7, 8)].red;
            dst[ridx] += src[RIDX(i7, j7, dim)].green * ker[RIDX(7, 7, 8)].green;
            dst[ridx] += src[RIDX(i7, j7, dim)].blue * ker[RIDX(7, 7, 8)].blue;

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
    int halfdim = dim/2, i,j, i2plusk, j2plusk, i2, j2, ridx, var1, var2, var3;

    for(i = 0; i < halfdim; i++) {
        i2 = i * 2;
        for (j = 0; j < halfdim; j++) {
            j2 = j * 2;
            dst[RIDX(i, j, halfdim)].red = 0;
            dst[RIDX(i, j, halfdim)].green = 0;
            dst[RIDX(i, j, halfdim)].blue = 0;

            i2plusk = i2;
            j2plusk = j2;

            ridx = RIDX(i2plusk, j2plusk, dim);
            dst[RIDX(i, j, halfdim)].red += src[ridx].red;
            dst[RIDX(i, j, halfdim)].green += src[ridx].green;
            dst[RIDX(i, j, halfdim)].blue += src[ridx].blue;

            j2plusk = j2 + 1;

            ridx = RIDX(i2plusk, j2plusk, dim);
            dst[RIDX(i, j, halfdim)].red += src[ridx].red;
            dst[RIDX(i, j, halfdim)].green += src[ridx].green;
            dst[RIDX(i, j, halfdim)].blue += src[ridx].blue;

            i2plusk = i2 + 1;
            j2plusk = j2;

            ridx = RIDX(i2plusk, j2plusk, dim);
            dst[RIDX(i, j, halfdim)].red += src[ridx].red;
            dst[RIDX(i, j, halfdim)].green += src[ridx].green;
            dst[RIDX(i, j, halfdim)].blue += src[ridx].blue;

            j2plusk = j2 + 1;

            ridx = RIDX(i2plusk, j2plusk, dim);
            dst[RIDX(i, j, halfdim)].red += src[ridx].red;
            dst[RIDX(i, j, halfdim)].green += src[ridx].green;
            dst[RIDX(i, j, halfdim)].blue += src[ridx].blue;

            var1 = dst[RIDX(i, j, halfdim)].red / 4;
            var2 = dst[RIDX(i, j, halfdim)].green / 4;
            var3 = dst[RIDX(i, j, halfdim)].blue / 4;
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

