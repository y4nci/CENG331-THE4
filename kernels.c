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
    int dimm6 = dim - 6;
    pixel *srcPtr1, *srcPtr2, *kerPtr1 = ker, *kerPtr2 = ker + 1;
    unsigned * dstPtr = dst;
    register int i1 = 0, j1;
    int i, j, dimm8 = dim - 8,
            ridx = 0,
            RED, GREEN, BLUE;
    for (i = 0; i < dimm8; i += BLOCK_SIZE) {
        for (i1 = i; i1 < i + BLOCK_SIZE; i1++) {
            ridx = i1 * dim; // RIDX(i1, 0, dim);
            for (j = 0; j < dimm8; j += BLOCK_SIZE) {
                for (j1 = j; j1 < j + BLOCK_SIZE; j1+=2, ridx++) {
                    kerPtr1 = kerPtr2 = ker;
                    dstPtr = dst + ridx;
                    srcPtr1 = srcPtr2 = src + ridx;

                    srcPtr2++; kerPtr2++;

                    RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    *(dstPtr) = RED + GREEN + BLUE;



                    /////////////////////////////////////////////////////////////////////
                    ridx++;
                    kerPtr1 = kerPtr2 = ker;

                    dstPtr++;
                    srcPtr1 = srcPtr2 = src + ridx;



                    srcPtr2++; kerPtr2++;

                    RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    *(dstPtr) = RED + GREEN + BLUE;
                }
            }

            kerPtr1 = kerPtr2 = ker;
            dstPtr++;
            srcPtr1 = srcPtr2 = src + ridx;


            srcPtr2++; kerPtr2++;

            RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            *(dstPtr) = RED + GREEN + BLUE;



            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            i1++;

            ridx = i1*dim;

            for (j = 0; j < dimm8; j += BLOCK_SIZE) {
                for (j1 = j; j1 < j + BLOCK_SIZE; j1+=2, ridx++) {
                    kerPtr1 = kerPtr2 = ker;
                    dstPtr = dst + ridx;
                    srcPtr1 = srcPtr2 = src + ridx;

                    srcPtr2++; kerPtr2++;

                    RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    *(dstPtr) = RED + GREEN + BLUE;



                    /////////////////////////////////////////////////////////////////////
                    ridx++;
                    kerPtr1 = kerPtr2 = ker;

                    dstPtr++;
                    srcPtr1 = srcPtr2 = src + ridx;



                    srcPtr2++; kerPtr2++;

                    RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr1 += dimm6;
                    srcPtr2 += dimm6;

                    kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    srcPtr1 += 2; kerPtr1 += 2;
                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    srcPtr2 += 2; kerPtr2 += 2;
                    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

                    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

                    *(dstPtr) = RED + GREEN + BLUE;
                }
            }

            kerPtr1 = kerPtr2 = ker;
            dstPtr++;
            srcPtr1 = srcPtr2 = src + ridx;


            srcPtr2++; kerPtr2++;
            RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            *(dstPtr) = RED + GREEN + BLUE;
        }
    }

    ridx = i1 * dim;
    for (j = 0; j < dimm8; j += BLOCK_SIZE) {
        for (j1 = j; j1 < j + BLOCK_SIZE; j1+=2, ridx++) {
            kerPtr1 = kerPtr2 = ker;
            dstPtr = dst + ridx;
            srcPtr1 = srcPtr2 = src + ridx;

            srcPtr2++; kerPtr2++;

            RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            *(dstPtr) = RED + GREEN + BLUE;



            /////////////////////////////////////////////////////////////////////
            ridx++;
            kerPtr1 = kerPtr2 = ker;

            dstPtr++;
            srcPtr1 = srcPtr2 = src + ridx;



            srcPtr2++; kerPtr2++;

            RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr1 += dimm6;
            srcPtr2 += dimm6;

            kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            srcPtr1 += 2; kerPtr1 += 2;
            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            srcPtr2 += 2; kerPtr2 += 2;
            RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

            RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

            *(dstPtr) = RED + GREEN + BLUE;
        }
    }

    kerPtr1 = kerPtr2 = ker;
    dstPtr++;
    srcPtr1 = srcPtr2 = src + ridx;


    srcPtr2++; kerPtr2++;

    RED = srcPtr1->red * kerPtr1->red; GREEN = srcPtr1->green * kerPtr1->green; BLUE = srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr1 += dimm6;
    srcPtr2 += dimm6;

    kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr1 += dimm6;
    srcPtr2 += dimm6;

    kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr1 += dimm6;
    srcPtr2 += dimm6;

    kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr1 += dimm6;
    srcPtr2 += dimm6;

    kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr1 += dimm6;
    srcPtr2 += dimm6;

    kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr1 += dimm6;
    srcPtr2 += dimm6;

    kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr1 += dimm6;
    srcPtr2 += dimm6;

    kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    srcPtr1 += 2; kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;

    srcPtr2 += 2; kerPtr2 += 2;
    RED += srcPtr1->red * kerPtr1->red; GREEN += srcPtr1->green * kerPtr1->green; BLUE += srcPtr1->blue * kerPtr1->blue;

    kerPtr1 += 2;
    RED += srcPtr2->red * kerPtr2->red; GREEN += srcPtr2->green * kerPtr2->green; BLUE += srcPtr2->blue * kerPtr2->blue;
    *dstPtr = RED + GREEN + BLUE;

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

