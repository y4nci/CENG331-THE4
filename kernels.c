/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#define BLOCK_SIZE 8
/*
 * Please fill in the following team_t struct
 */
team_t team = {
        "versankokodtuyerektorolamaz",    /* Team Name */

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
            for(k = 0; k < 8; k++)
                for(l = 0; l < 8; l++) {
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].red * ker[RIDX(k, l, 8)].red;
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].green * ker[RIDX(k, l, 8)].green;
                    dst[RIDX(i, j, dim)] += src[RIDX((i+k),(j+l), dim)].blue * ker[RIDX(k, l, 8)].blue;
                }

        }
}

/*
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Convolution: MY VERSION";
void convolution(int dim, pixel *src, pixel *ker, unsigned *dst) {
    int dimm7 = dim - 7;
    pixel *srcPtr, *kerPtr = ker;
    unsigned * dstPtr = dst;
    register int sum;
    int i, j, dimm8 = dim - 8,
            ridx = 0,
            i1 = 0, j1;
    for (i = 0; i < dimm8; i += BLOCK_SIZE) {
        for (i1 = i; i1 < i + BLOCK_SIZE; i1++) {
            ridx = i1 * dim; // RIDX(i1, 0, dim);
            for (j = 0; j < dimm8; j += BLOCK_SIZE) {
                for (j1 = j; j1 < j + BLOCK_SIZE; j1+=2, ridx++) {
                    kerPtr = ker;
                    dstPtr = dst + ridx;
                    srcPtr = src + ridx;

                    sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    *(dstPtr) = sum;



                    /////////////////////////////////////////////////////////////////////
                    ridx++;
                    kerPtr = ker;

                    dstPtr++;
                    srcPtr = src + ridx;


                    sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    *(dstPtr) = sum;
                }
            }

            kerPtr = ker;
            dstPtr++;
            srcPtr = src + ridx;

            sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            *(dstPtr) = sum;



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            i1++;

            ridx = i1*dim;

            for (j = 0; j < dimm8; j += BLOCK_SIZE) {
                for (j1 = j; j1 < j + BLOCK_SIZE; j1+=2, ridx++) {
                    kerPtr = ker;
                    dstPtr = dst + ridx;
                    srcPtr = src + ridx;

                    sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    *(dstPtr) = sum;



                    /////////////////////////////////////////////////////////////////////
                    ridx++;
                    kerPtr = ker;

                    dstPtr++;
                    srcPtr = src + ridx;


                    sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr += dimm7;
                    kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    srcPtr++; kerPtr++;
                    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

                    *(dstPtr) = sum;
                }
            }

            kerPtr = ker;
            dstPtr++;
            srcPtr = src + ridx;


            sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            *(dstPtr) = sum;
        }
    }

    ridx = i1 * dim;
    for (j = 0; j < dimm8; j += BLOCK_SIZE) {
        for (j1 = j; j1 < j + BLOCK_SIZE; j1+=2, ridx++) {
            kerPtr = ker;
            dstPtr = dst + ridx;
            srcPtr = src + ridx;

            sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            *(dstPtr) = sum;



            /////////////////////////////////////////////////////////////////////
            ridx++;
            kerPtr = ker;

            dstPtr++;
            srcPtr = src + ridx;


            sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr += dimm7;
            kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            srcPtr++; kerPtr++;
            sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

            *(dstPtr) = sum;
        }
    }

    dstPtr++;
    kerPtr = ker;
    srcPtr = src + ridx;

    sum = srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr += dimm7;
    kerPtr++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr += dimm7;
    kerPtr++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr += dimm7;
    kerPtr++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr += dimm7;
    kerPtr++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr += dimm7;
    kerPtr++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr += dimm7;
    kerPtr++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr += dimm7;
    kerPtr++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;

    srcPtr ++; kerPtr ++;
    sum += srcPtr->red * kerPtr->red; sum += srcPtr->green * kerPtr->green; sum += srcPtr->blue * kerPtr->blue;
    *dstPtr = sum;

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
    int i,j,k,l;

    for(i = 0; i < dim/2; i++)
        for(j = 0; j < dim/2; j++) {
            dst[RIDX(i, j, dim/2)].red = 0;
            dst[RIDX(i, j, dim/2)].green = 0;
            dst[RIDX(i, j, dim/2)].blue = 0;
            for(k = 0; k < 2; k++) {
                for (l = 0; l < 2; l++) {
                    dst[RIDX(i, j, dim/2)].red += src[RIDX(i*2 + k, j*2 + l, dim)].red;
                    dst[RIDX(i, j, dim/2)].green += src[RIDX(i*2 + k, j*2 + l, dim)].green;
                    dst[RIDX(i, j, dim/2)].blue += src[RIDX(i*2 + k, j*2 + l, dim)].blue;
                }
            }
            dst[RIDX(i, j, dim/2)].red /= 4;
            dst[RIDX(i, j, dim/2)].green /= 4;
            dst[RIDX(i, j, dim/2)].blue /= 4;
        }
}


/*
 * average_pooling - Your current working version of average_pooling
 * IMPORTANT: This is the version you will be graded on
 */
char average_pooling_descr[] = "Pooling: MY VERSION";
void average_pooling(int dim, pixel *src, pixel *dst){
    int halfdim = dim/2, i,j, RED, GREEN, BLUE, dimm1 = dim - 1, dim2 = dim * 2;
    int ridx;
    register pixel *srcPtr;

    for(i = 0; i < halfdim; i++) {
        for (j = 0; j < halfdim; j++) {
            srcPtr = src + i * dim2 + 2 * j;

            ridx = RIDX(i, j, halfdim);

            RED = srcPtr->red;
            GREEN = srcPtr->green;
            BLUE = srcPtr->blue;

            srcPtr++;
            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            srcPtr+=dimm1;

            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            srcPtr++;
            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            RED >>= 2;
            GREEN >>= 2;
            BLUE >>= 2;

            dst[ridx].red = RED;
            dst[ridx].green = GREEN;
            dst[ridx].blue = BLUE;


            j++;

            ridx++;

            srcPtr -= dimm1;

            RED = srcPtr->red;
            GREEN = srcPtr->green;
            BLUE = srcPtr->blue;

            srcPtr++;
            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            srcPtr+=dimm1;

            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            srcPtr++;
            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            RED >>= 2;
            GREEN >>= 2;
            BLUE >>= 2;

            dst[ridx].red = RED;
            dst[ridx].green = GREEN;
            dst[ridx].blue = BLUE;

            //srcPtr += 2;
        }



        i++;


        for (j = 0; j < halfdim; j++) {
            srcPtr = src + i * dim2 + 2 * j;

            ridx = RIDX(i, j, halfdim);

            RED = srcPtr->red;
            GREEN = srcPtr->green;
            BLUE = srcPtr->blue;

            srcPtr++;
            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            srcPtr+=dimm1;

            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            srcPtr++;
            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            RED >>= 2;
            GREEN >>= 2;
            BLUE >>= 2;

            dst[ridx].red = RED;
            dst[ridx].green = GREEN;
            dst[ridx].blue = BLUE;


            j++;

            ridx++;

            srcPtr -= dimm1;

            RED = srcPtr->red;
            GREEN = srcPtr->green;
            BLUE = srcPtr->blue;

            srcPtr++;
            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            srcPtr+=dimm1;

            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            srcPtr++;
            RED += srcPtr->red;
            GREEN += srcPtr->green;
            BLUE += srcPtr->blue;

            RED >>= 2;
            GREEN >>= 2;
            BLUE >>= 2;

            dst[ridx].red = RED;
            dst[ridx].green = GREEN;
            dst[ridx].blue = BLUE;

            //srcPtr += 2;
        }
    }
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

