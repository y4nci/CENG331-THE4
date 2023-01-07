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
        "youtube.com/watch?v=dQw4w9WgXcQ",    /* Team Name */

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
    // TODO: Loop unrolling for j
    // TODO: move register int ridx to the top

    register int ridx;
    register int dimm7 = dim - 7;
    int i,j,origridx,
            RED, GREEN, BLUE,
            dimm8 = dim - 8;

    for(i = 0; i < dimm8; i++) {
        for (j = 0; j < dimm7; j++) {
            ridx = origridx = RIDX(i,j,dim);


            RED = src[ridx].red * ker[0].red;
            GREEN= src[ridx].green * ker[0].green;
            BLUE = src[ridx].blue * ker[0].blue;

            RED += src[++ridx].red * ker[1].red;
            GREEN += src[ridx].green * ker[1].green;
            BLUE += src[ridx].blue * ker[1].blue;

            RED += src[++ridx].red * ker[2].red;
            GREEN += src[ridx].green * ker[2].green;
            BLUE += src[ridx].blue * ker[2].blue;

            RED += src[++ridx].red * ker[3].red;
            GREEN += src[ridx].green * ker[3].green;
            BLUE += src[ridx].blue * ker[3].blue;

            RED += src[++ridx].red * ker[4].red;
            GREEN += src[ridx].green * ker[4].green;
            BLUE += src[ridx].blue * ker[4].blue;

            RED += src[++ridx].red * ker[5].red;
            GREEN += src[ridx].green * ker[5].green;
            BLUE += src[ridx].blue * ker[5].blue;

            RED += src[++ridx].red * ker[6].red;
            GREEN += src[ridx].green * ker[6].green;
            BLUE += src[ridx].blue * ker[6].blue;

            RED += src[++ridx].red * ker[7].red;
            GREEN += src[ridx].green * ker[7].green;
            BLUE += src[ridx].blue * ker[7].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[8].red;
            GREEN += src[ridx].green * ker[8].green;
            BLUE += src[ridx].blue * ker[8].blue;

            RED += src[++ridx].red * ker[9].red;
            GREEN += src[ridx].green * ker[9].green;
            BLUE += src[ridx].blue * ker[9].blue;

            RED += src[++ridx].red * ker[10].red;
            GREEN += src[ridx].green * ker[10].green;
            BLUE += src[ridx].blue * ker[10].blue;

            RED += src[++ridx].red * ker[11].red;
            GREEN += src[ridx].green * ker[11].green;
            BLUE += src[ridx].blue * ker[11].blue;

            RED += src[++ridx].red * ker[12].red;
            GREEN += src[ridx].green * ker[12].green;
            BLUE += src[ridx].blue * ker[12].blue;

            RED += src[++ridx].red * ker[13].red;
            GREEN += src[ridx].green * ker[13].green;
            BLUE += src[ridx].blue * ker[13].blue;

            RED += src[++ridx].red * ker[14].red;
            GREEN += src[ridx].green * ker[14].green;
            BLUE += src[ridx].blue * ker[14].blue;

            RED += src[++ridx].red * ker[15].red;
            GREEN += src[ridx].green * ker[15].green;
            BLUE += src[ridx].blue * ker[15].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[16].red;
            GREEN += src[ridx].green * ker[16].green;
            BLUE += src[ridx].blue * ker[16].blue;

            RED += src[++ridx].red * ker[17].red;
            GREEN += src[ridx].green * ker[17].green;
            BLUE += src[ridx].blue * ker[17].blue;

            RED += src[++ridx].red * ker[18].red;
            GREEN += src[ridx].green * ker[18].green;
            BLUE += src[ridx].blue * ker[18].blue;

            RED += src[++ridx].red * ker[19].red;
            GREEN += src[ridx].green * ker[19].green;
            BLUE += src[ridx].blue * ker[19].blue;

            RED += src[++ridx].red * ker[20].red;
            GREEN += src[ridx].green * ker[20].green;
            BLUE += src[ridx].blue * ker[20].blue;

            RED += src[++ridx].red * ker[21].red;
            GREEN += src[ridx].green * ker[21].green;
            BLUE += src[ridx].blue * ker[21].blue;

            RED += src[++ridx].red * ker[22].red;
            GREEN += src[ridx].green * ker[22].green;
            BLUE += src[ridx].blue * ker[22].blue;

            RED += src[++ridx].red * ker[23].red;
            GREEN += src[ridx].green * ker[23].green;
            BLUE += src[ridx].blue * ker[23].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[24].red;
            GREEN += src[ridx].green * ker[24].green;
            BLUE += src[ridx].blue * ker[24].blue;

            RED += src[++ridx].red * ker[25].red;
            GREEN += src[ridx].green * ker[25].green;
            BLUE += src[ridx].blue * ker[25].blue;

            RED += src[++ridx].red * ker[26].red;
            GREEN += src[ridx].green * ker[26].green;
            BLUE += src[ridx].blue * ker[26].blue;

            RED += src[++ridx].red * ker[27].red;
            GREEN += src[ridx].green * ker[27].green;
            BLUE += src[ridx].blue * ker[27].blue;

            RED += src[++ridx].red * ker[28].red;
            GREEN += src[ridx].green * ker[28].green;
            BLUE += src[ridx].blue * ker[28].blue;

            RED += src[++ridx].red * ker[29].red;
            GREEN += src[ridx].green * ker[29].green;
            BLUE += src[ridx].blue * ker[29].blue;

            RED += src[++ridx].red * ker[30].red;
            GREEN += src[ridx].green * ker[30].green;
            BLUE += src[ridx].blue * ker[30].blue;

            RED += src[++ridx].red * ker[31].red;
            GREEN += src[ridx].green * ker[31].green;
            BLUE += src[ridx].blue * ker[31].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[32].red;
            GREEN += src[ridx].green * ker[32].green;
            BLUE += src[ridx].blue * ker[32].blue;

            RED += src[++ridx].red * ker[33].red;
            GREEN += src[ridx].green * ker[33].green;
            BLUE += src[ridx].blue * ker[33].blue;

            RED += src[++ridx].red * ker[34].red;
            GREEN += src[ridx].green * ker[34].green;
            BLUE += src[ridx].blue * ker[34].blue;

            RED += src[++ridx].red * ker[35].red;
            GREEN += src[ridx].green * ker[35].green;
            BLUE += src[ridx].blue * ker[35].blue;

            RED += src[++ridx].red * ker[36].red;
            GREEN += src[ridx].green * ker[36].green;
            BLUE += src[ridx].blue * ker[36].blue;

            RED += src[++ridx].red * ker[37].red;
            GREEN += src[ridx].green * ker[37].green;
            BLUE += src[ridx].blue * ker[37].blue;

            RED += src[++ridx].red * ker[38].red;
            GREEN += src[ridx].green * ker[38].green;
            BLUE += src[ridx].blue * ker[38].blue;

            RED += src[++ridx].red * ker[39].red;
            GREEN += src[ridx].green * ker[39].green;
            BLUE += src[ridx].blue * ker[39].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[40].red;
            GREEN += src[ridx].green * ker[40].green;
            BLUE += src[ridx].blue * ker[40].blue;

            RED += src[++ridx].red * ker[41].red;
            GREEN += src[ridx].green * ker[41].green;
            BLUE += src[ridx].blue * ker[41].blue;

            RED += src[++ridx].red * ker[42].red;
            GREEN += src[ridx].green * ker[42].green;
            BLUE += src[ridx].blue * ker[42].blue;

            RED += src[++ridx].red * ker[43].red;
            GREEN += src[ridx].green * ker[43].green;
            BLUE += src[ridx].blue * ker[43].blue;

            RED += src[++ridx].red * ker[44].red;
            GREEN += src[ridx].green * ker[44].green;
            BLUE += src[ridx].blue * ker[44].blue;

            RED += src[++ridx].red * ker[45].red;
            GREEN += src[ridx].green * ker[45].green;
            BLUE += src[ridx].blue * ker[45].blue;

            RED += src[++ridx].red * ker[46].red;
            GREEN += src[ridx].green * ker[46].green;
            BLUE += src[ridx].blue * ker[46].blue;

            RED += src[++ridx].red * ker[47].red;
            GREEN += src[ridx].green * ker[47].green;
            BLUE += src[ridx].blue * ker[47].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[48].red;
            GREEN += src[ridx].green * ker[48].green;
            BLUE += src[ridx].blue * ker[48].blue;

            RED += src[++ridx].red * ker[49].red;
            GREEN += src[ridx].green * ker[49].green;
            BLUE += src[ridx].blue * ker[49].blue;

            RED += src[++ridx].red * ker[50].red;
            GREEN += src[ridx].green * ker[50].green;
            BLUE += src[ridx].blue * ker[50].blue;

            RED += src[++ridx].red * ker[51].red;
            GREEN += src[ridx].green * ker[51].green;
            BLUE += src[ridx].blue * ker[51].blue;

            RED += src[++ridx].red * ker[52].red;
            GREEN += src[ridx].green * ker[52].green;
            BLUE += src[ridx].blue * ker[52].blue;

            RED += src[++ridx].red * ker[53].red;
            GREEN += src[ridx].green * ker[53].green;
            BLUE += src[ridx].blue * ker[53].blue;

            RED += src[++ridx].red * ker[54].red;
            GREEN += src[ridx].green * ker[54].green;
            BLUE += src[ridx].blue * ker[54].blue;

            RED += src[++ridx].red * ker[55].red;
            GREEN += src[ridx].green * ker[55].green;
            BLUE += src[ridx].blue * ker[55].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[56].red;
            GREEN += src[ridx].green * ker[56].green;
            BLUE += src[ridx].blue * ker[56].blue;

            RED += src[++ridx].red * ker[57].red;
            GREEN += src[ridx].green * ker[57].green;
            BLUE += src[ridx].blue * ker[57].blue;

            RED += src[++ridx].red * ker[58].red;
            GREEN += src[ridx].green * ker[58].green;
            BLUE += src[ridx].blue * ker[58].blue;

            RED += src[++ridx].red * ker[59].red;
            GREEN += src[ridx].green * ker[59].green;
            BLUE += src[ridx].blue * ker[59].blue;

            RED += src[++ridx].red * ker[60].red;
            GREEN += src[ridx].green * ker[60].green;
            BLUE += src[ridx].blue * ker[60].blue;

            RED += src[++ridx].red * ker[61].red;
            GREEN += src[ridx].green * ker[61].green;
            BLUE += src[ridx].blue * ker[61].blue;

            RED += src[++ridx].red * ker[62].red;
            GREEN += src[ridx].green * ker[62].green;
            BLUE += src[ridx].blue * ker[62].blue;

            RED += src[++ridx].red * ker[63].red;
            GREEN += src[ridx].green * ker[63].green;
            BLUE += src[ridx].blue * ker[63].blue;

            dst[origridx] = RED + GREEN + BLUE;
        }



        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        i++;


        for (j = 0; j < dimm7; j++) {
            ridx = origridx = RIDX(i,j,dim);


            RED = src[ridx].red * ker[0].red;
            GREEN= src[ridx].green * ker[0].green;
            BLUE = src[ridx].blue * ker[0].blue;

            RED += src[++ridx].red * ker[1].red;
            GREEN += src[ridx].green * ker[1].green;
            BLUE += src[ridx].blue * ker[1].blue;

            RED += src[++ridx].red * ker[2].red;
            GREEN += src[ridx].green * ker[2].green;
            BLUE += src[ridx].blue * ker[2].blue;

            RED += src[++ridx].red * ker[3].red;
            GREEN += src[ridx].green * ker[3].green;
            BLUE += src[ridx].blue * ker[3].blue;

            RED += src[++ridx].red * ker[4].red;
            GREEN += src[ridx].green * ker[4].green;
            BLUE += src[ridx].blue * ker[4].blue;

            RED += src[++ridx].red * ker[5].red;
            GREEN += src[ridx].green * ker[5].green;
            BLUE += src[ridx].blue * ker[5].blue;

            RED += src[++ridx].red * ker[6].red;
            GREEN += src[ridx].green * ker[6].green;
            BLUE += src[ridx].blue * ker[6].blue;

            RED += src[++ridx].red * ker[7].red;
            GREEN += src[ridx].green * ker[7].green;
            BLUE += src[ridx].blue * ker[7].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[8].red;
            GREEN += src[ridx].green * ker[8].green;
            BLUE += src[ridx].blue * ker[8].blue;

            RED += src[++ridx].red * ker[9].red;
            GREEN += src[ridx].green * ker[9].green;
            BLUE += src[ridx].blue * ker[9].blue;

            RED += src[++ridx].red * ker[10].red;
            GREEN += src[ridx].green * ker[10].green;
            BLUE += src[ridx].blue * ker[10].blue;

            RED += src[++ridx].red * ker[11].red;
            GREEN += src[ridx].green * ker[11].green;
            BLUE += src[ridx].blue * ker[11].blue;

            RED += src[++ridx].red * ker[12].red;
            GREEN += src[ridx].green * ker[12].green;
            BLUE += src[ridx].blue * ker[12].blue;

            RED += src[++ridx].red * ker[13].red;
            GREEN += src[ridx].green * ker[13].green;
            BLUE += src[ridx].blue * ker[13].blue;

            RED += src[++ridx].red * ker[14].red;
            GREEN += src[ridx].green * ker[14].green;
            BLUE += src[ridx].blue * ker[14].blue;

            RED += src[++ridx].red * ker[15].red;
            GREEN += src[ridx].green * ker[15].green;
            BLUE += src[ridx].blue * ker[15].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[16].red;
            GREEN += src[ridx].green * ker[16].green;
            BLUE += src[ridx].blue * ker[16].blue;

            RED += src[++ridx].red * ker[17].red;
            GREEN += src[ridx].green * ker[17].green;
            BLUE += src[ridx].blue * ker[17].blue;

            RED += src[++ridx].red * ker[18].red;
            GREEN += src[ridx].green * ker[18].green;
            BLUE += src[ridx].blue * ker[18].blue;

            RED += src[++ridx].red * ker[19].red;
            GREEN += src[ridx].green * ker[19].green;
            BLUE += src[ridx].blue * ker[19].blue;

            RED += src[++ridx].red * ker[20].red;
            GREEN += src[ridx].green * ker[20].green;
            BLUE += src[ridx].blue * ker[20].blue;

            RED += src[++ridx].red * ker[21].red;
            GREEN += src[ridx].green * ker[21].green;
            BLUE += src[ridx].blue * ker[21].blue;

            RED += src[++ridx].red * ker[22].red;
            GREEN += src[ridx].green * ker[22].green;
            BLUE += src[ridx].blue * ker[22].blue;

            RED += src[++ridx].red * ker[23].red;
            GREEN += src[ridx].green * ker[23].green;
            BLUE += src[ridx].blue * ker[23].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[24].red;
            GREEN += src[ridx].green * ker[24].green;
            BLUE += src[ridx].blue * ker[24].blue;

            RED += src[++ridx].red * ker[25].red;
            GREEN += src[ridx].green * ker[25].green;
            BLUE += src[ridx].blue * ker[25].blue;

            RED += src[++ridx].red * ker[26].red;
            GREEN += src[ridx].green * ker[26].green;
            BLUE += src[ridx].blue * ker[26].blue;

            RED += src[++ridx].red * ker[27].red;
            GREEN += src[ridx].green * ker[27].green;
            BLUE += src[ridx].blue * ker[27].blue;

            RED += src[++ridx].red * ker[28].red;
            GREEN += src[ridx].green * ker[28].green;
            BLUE += src[ridx].blue * ker[28].blue;

            RED += src[++ridx].red * ker[29].red;
            GREEN += src[ridx].green * ker[29].green;
            BLUE += src[ridx].blue * ker[29].blue;

            RED += src[++ridx].red * ker[30].red;
            GREEN += src[ridx].green * ker[30].green;
            BLUE += src[ridx].blue * ker[30].blue;

            RED += src[++ridx].red * ker[31].red;
            GREEN += src[ridx].green * ker[31].green;
            BLUE += src[ridx].blue * ker[31].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[32].red;
            GREEN += src[ridx].green * ker[32].green;
            BLUE += src[ridx].blue * ker[32].blue;

            RED += src[++ridx].red * ker[33].red;
            GREEN += src[ridx].green * ker[33].green;
            BLUE += src[ridx].blue * ker[33].blue;

            RED += src[++ridx].red * ker[34].red;
            GREEN += src[ridx].green * ker[34].green;
            BLUE += src[ridx].blue * ker[34].blue;

            RED += src[++ridx].red * ker[35].red;
            GREEN += src[ridx].green * ker[35].green;
            BLUE += src[ridx].blue * ker[35].blue;

            RED += src[++ridx].red * ker[36].red;
            GREEN += src[ridx].green * ker[36].green;
            BLUE += src[ridx].blue * ker[36].blue;

            RED += src[++ridx].red * ker[37].red;
            GREEN += src[ridx].green * ker[37].green;
            BLUE += src[ridx].blue * ker[37].blue;

            RED += src[++ridx].red * ker[38].red;
            GREEN += src[ridx].green * ker[38].green;
            BLUE += src[ridx].blue * ker[38].blue;

            RED += src[++ridx].red * ker[39].red;
            GREEN += src[ridx].green * ker[39].green;
            BLUE += src[ridx].blue * ker[39].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[40].red;
            GREEN += src[ridx].green * ker[40].green;
            BLUE += src[ridx].blue * ker[40].blue;

            RED += src[++ridx].red * ker[41].red;
            GREEN += src[ridx].green * ker[41].green;
            BLUE += src[ridx].blue * ker[41].blue;

            RED += src[++ridx].red * ker[42].red;
            GREEN += src[ridx].green * ker[42].green;
            BLUE += src[ridx].blue * ker[42].blue;

            RED += src[++ridx].red * ker[43].red;
            GREEN += src[ridx].green * ker[43].green;
            BLUE += src[ridx].blue * ker[43].blue;

            RED += src[++ridx].red * ker[44].red;
            GREEN += src[ridx].green * ker[44].green;
            BLUE += src[ridx].blue * ker[44].blue;

            RED += src[++ridx].red * ker[45].red;
            GREEN += src[ridx].green * ker[45].green;
            BLUE += src[ridx].blue * ker[45].blue;

            RED += src[++ridx].red * ker[46].red;
            GREEN += src[ridx].green * ker[46].green;
            BLUE += src[ridx].blue * ker[46].blue;

            RED += src[++ridx].red * ker[47].red;
            GREEN += src[ridx].green * ker[47].green;
            BLUE += src[ridx].blue * ker[47].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[48].red;
            GREEN += src[ridx].green * ker[48].green;
            BLUE += src[ridx].blue * ker[48].blue;

            RED += src[++ridx].red * ker[49].red;
            GREEN += src[ridx].green * ker[49].green;
            BLUE += src[ridx].blue * ker[49].blue;

            RED += src[++ridx].red * ker[50].red;
            GREEN += src[ridx].green * ker[50].green;
            BLUE += src[ridx].blue * ker[50].blue;

            RED += src[++ridx].red * ker[51].red;
            GREEN += src[ridx].green * ker[51].green;
            BLUE += src[ridx].blue * ker[51].blue;

            RED += src[++ridx].red * ker[52].red;
            GREEN += src[ridx].green * ker[52].green;
            BLUE += src[ridx].blue * ker[52].blue;

            RED += src[++ridx].red * ker[53].red;
            GREEN += src[ridx].green * ker[53].green;
            BLUE += src[ridx].blue * ker[53].blue;

            RED += src[++ridx].red * ker[54].red;
            GREEN += src[ridx].green * ker[54].green;
            BLUE += src[ridx].blue * ker[54].blue;

            RED += src[++ridx].red * ker[55].red;
            GREEN += src[ridx].green * ker[55].green;
            BLUE += src[ridx].blue * ker[55].blue;

            ridx += dimm7;

            RED += src[ridx].red * ker[56].red;
            GREEN += src[ridx].green * ker[56].green;
            BLUE += src[ridx].blue * ker[56].blue;

            RED += src[++ridx].red * ker[57].red;
            GREEN += src[ridx].green * ker[57].green;
            BLUE += src[ridx].blue * ker[57].blue;

            RED += src[++ridx].red * ker[58].red;
            GREEN += src[ridx].green * ker[58].green;
            BLUE += src[ridx].blue * ker[58].blue;

            RED += src[++ridx].red * ker[59].red;
            GREEN += src[ridx].green * ker[59].green;
            BLUE += src[ridx].blue * ker[59].blue;

            RED += src[++ridx].red * ker[60].red;
            GREEN += src[ridx].green * ker[60].green;
            BLUE += src[ridx].blue * ker[60].blue;

            RED += src[++ridx].red * ker[61].red;
            GREEN += src[ridx].green * ker[61].green;
            BLUE += src[ridx].blue * ker[61].blue;

            RED += src[++ridx].red * ker[62].red;
            GREEN += src[ridx].green * ker[62].green;
            BLUE += src[ridx].blue * ker[62].blue;

            RED += src[++ridx].red * ker[63].red;
            GREEN += src[ridx].green * ker[63].green;
            BLUE += src[ridx].blue * ker[63].blue;

            dst[origridx] = RED + GREEN + BLUE;
        }
    }

    for (j = 0; j < dimm7; j++) {
        ridx = origridx = RIDX(i,j,dim);


        RED = src[ridx].red * ker[0].red;
        GREEN= src[ridx].green * ker[0].green;
        BLUE = src[ridx].blue * ker[0].blue;

        RED += src[++ridx].red * ker[1].red;
        GREEN += src[ridx].green * ker[1].green;
        BLUE += src[ridx].blue * ker[1].blue;

        RED += src[++ridx].red * ker[2].red;
        GREEN += src[ridx].green * ker[2].green;
        BLUE += src[ridx].blue * ker[2].blue;

        RED += src[++ridx].red * ker[3].red;
        GREEN += src[ridx].green * ker[3].green;
        BLUE += src[ridx].blue * ker[3].blue;

        RED += src[++ridx].red * ker[4].red;
        GREEN += src[ridx].green * ker[4].green;
        BLUE += src[ridx].blue * ker[4].blue;

        RED += src[++ridx].red * ker[5].red;
        GREEN += src[ridx].green * ker[5].green;
        BLUE += src[ridx].blue * ker[5].blue;

        RED += src[++ridx].red * ker[6].red;
        GREEN += src[ridx].green * ker[6].green;
        BLUE += src[ridx].blue * ker[6].blue;

        RED += src[++ridx].red * ker[7].red;
        GREEN += src[ridx].green * ker[7].green;
        BLUE += src[ridx].blue * ker[7].blue;

        ridx += dimm7;

        RED += src[ridx].red * ker[8].red;
        GREEN += src[ridx].green * ker[8].green;
        BLUE += src[ridx].blue * ker[8].blue;

        RED += src[++ridx].red * ker[9].red;
        GREEN += src[ridx].green * ker[9].green;
        BLUE += src[ridx].blue * ker[9].blue;

        RED += src[++ridx].red * ker[10].red;
        GREEN += src[ridx].green * ker[10].green;
        BLUE += src[ridx].blue * ker[10].blue;

        RED += src[++ridx].red * ker[11].red;
        GREEN += src[ridx].green * ker[11].green;
        BLUE += src[ridx].blue * ker[11].blue;

        RED += src[++ridx].red * ker[12].red;
        GREEN += src[ridx].green * ker[12].green;
        BLUE += src[ridx].blue * ker[12].blue;

        RED += src[++ridx].red * ker[13].red;
        GREEN += src[ridx].green * ker[13].green;
        BLUE += src[ridx].blue * ker[13].blue;

        RED += src[++ridx].red * ker[14].red;
        GREEN += src[ridx].green * ker[14].green;
        BLUE += src[ridx].blue * ker[14].blue;

        RED += src[++ridx].red * ker[15].red;
        GREEN += src[ridx].green * ker[15].green;
        BLUE += src[ridx].blue * ker[15].blue;

        ridx += dimm7;

        RED += src[ridx].red * ker[16].red;
        GREEN += src[ridx].green * ker[16].green;
        BLUE += src[ridx].blue * ker[16].blue;

        RED += src[++ridx].red * ker[17].red;
        GREEN += src[ridx].green * ker[17].green;
        BLUE += src[ridx].blue * ker[17].blue;

        RED += src[++ridx].red * ker[18].red;
        GREEN += src[ridx].green * ker[18].green;
        BLUE += src[ridx].blue * ker[18].blue;

        RED += src[++ridx].red * ker[19].red;
        GREEN += src[ridx].green * ker[19].green;
        BLUE += src[ridx].blue * ker[19].blue;

        RED += src[++ridx].red * ker[20].red;
        GREEN += src[ridx].green * ker[20].green;
        BLUE += src[ridx].blue * ker[20].blue;

        RED += src[++ridx].red * ker[21].red;
        GREEN += src[ridx].green * ker[21].green;
        BLUE += src[ridx].blue * ker[21].blue;

        RED += src[++ridx].red * ker[22].red;
        GREEN += src[ridx].green * ker[22].green;
        BLUE += src[ridx].blue * ker[22].blue;

        RED += src[++ridx].red * ker[23].red;
        GREEN += src[ridx].green * ker[23].green;
        BLUE += src[ridx].blue * ker[23].blue;

        ridx += dimm7;

        RED += src[ridx].red * ker[24].red;
        GREEN += src[ridx].green * ker[24].green;
        BLUE += src[ridx].blue * ker[24].blue;

        RED += src[++ridx].red * ker[25].red;
        GREEN += src[ridx].green * ker[25].green;
        BLUE += src[ridx].blue * ker[25].blue;

        RED += src[++ridx].red * ker[26].red;
        GREEN += src[ridx].green * ker[26].green;
        BLUE += src[ridx].blue * ker[26].blue;

        RED += src[++ridx].red * ker[27].red;
        GREEN += src[ridx].green * ker[27].green;
        BLUE += src[ridx].blue * ker[27].blue;

        RED += src[++ridx].red * ker[28].red;
        GREEN += src[ridx].green * ker[28].green;
        BLUE += src[ridx].blue * ker[28].blue;

        RED += src[++ridx].red * ker[29].red;
        GREEN += src[ridx].green * ker[29].green;
        BLUE += src[ridx].blue * ker[29].blue;

        RED += src[++ridx].red * ker[30].red;
        GREEN += src[ridx].green * ker[30].green;
        BLUE += src[ridx].blue * ker[30].blue;

        RED += src[++ridx].red * ker[31].red;
        GREEN += src[ridx].green * ker[31].green;
        BLUE += src[ridx].blue * ker[31].blue;

        ridx += dimm7;

        RED += src[ridx].red * ker[32].red;
        GREEN += src[ridx].green * ker[32].green;
        BLUE += src[ridx].blue * ker[32].blue;

        RED += src[++ridx].red * ker[33].red;
        GREEN += src[ridx].green * ker[33].green;
        BLUE += src[ridx].blue * ker[33].blue;

        RED += src[++ridx].red * ker[34].red;
        GREEN += src[ridx].green * ker[34].green;
        BLUE += src[ridx].blue * ker[34].blue;

        RED += src[++ridx].red * ker[35].red;
        GREEN += src[ridx].green * ker[35].green;
        BLUE += src[ridx].blue * ker[35].blue;

        RED += src[++ridx].red * ker[36].red;
        GREEN += src[ridx].green * ker[36].green;
        BLUE += src[ridx].blue * ker[36].blue;

        RED += src[++ridx].red * ker[37].red;
        GREEN += src[ridx].green * ker[37].green;
        BLUE += src[ridx].blue * ker[37].blue;

        RED += src[++ridx].red * ker[38].red;
        GREEN += src[ridx].green * ker[38].green;
        BLUE += src[ridx].blue * ker[38].blue;

        RED += src[++ridx].red * ker[39].red;
        GREEN += src[ridx].green * ker[39].green;
        BLUE += src[ridx].blue * ker[39].blue;

        ridx += dimm7;

        RED += src[ridx].red * ker[40].red;
        GREEN += src[ridx].green * ker[40].green;
        BLUE += src[ridx].blue * ker[40].blue;

        RED += src[++ridx].red * ker[41].red;
        GREEN += src[ridx].green * ker[41].green;
        BLUE += src[ridx].blue * ker[41].blue;

        RED += src[++ridx].red * ker[42].red;
        GREEN += src[ridx].green * ker[42].green;
        BLUE += src[ridx].blue * ker[42].blue;

        RED += src[++ridx].red * ker[43].red;
        GREEN += src[ridx].green * ker[43].green;
        BLUE += src[ridx].blue * ker[43].blue;

        RED += src[++ridx].red * ker[44].red;
        GREEN += src[ridx].green * ker[44].green;
        BLUE += src[ridx].blue * ker[44].blue;

        RED += src[++ridx].red * ker[45].red;
        GREEN += src[ridx].green * ker[45].green;
        BLUE += src[ridx].blue * ker[45].blue;

        RED += src[++ridx].red * ker[46].red;
        GREEN += src[ridx].green * ker[46].green;
        BLUE += src[ridx].blue * ker[46].blue;

        RED += src[++ridx].red * ker[47].red;
        GREEN += src[ridx].green * ker[47].green;
        BLUE += src[ridx].blue * ker[47].blue;

        ridx += dimm7;

        RED += src[ridx].red * ker[48].red;
        GREEN += src[ridx].green * ker[48].green;
        BLUE += src[ridx].blue * ker[48].blue;

        RED += src[++ridx].red * ker[49].red;
        GREEN += src[ridx].green * ker[49].green;
        BLUE += src[ridx].blue * ker[49].blue;

        RED += src[++ridx].red * ker[50].red;
        GREEN += src[ridx].green * ker[50].green;
        BLUE += src[ridx].blue * ker[50].blue;

        RED += src[++ridx].red * ker[51].red;
        GREEN += src[ridx].green * ker[51].green;
        BLUE += src[ridx].blue * ker[51].blue;

        RED += src[++ridx].red * ker[52].red;
        GREEN += src[ridx].green * ker[52].green;
        BLUE += src[ridx].blue * ker[52].blue;

        RED += src[++ridx].red * ker[53].red;
        GREEN += src[ridx].green * ker[53].green;
        BLUE += src[ridx].blue * ker[53].blue;

        RED += src[++ridx].red * ker[54].red;
        GREEN += src[ridx].green * ker[54].green;
        BLUE += src[ridx].blue * ker[54].blue;

        RED += src[++ridx].red * ker[55].red;
        GREEN += src[ridx].green * ker[55].green;
        BLUE += src[ridx].blue * ker[55].blue;

        ridx += dimm7;

        RED += src[ridx].red * ker[56].red;
        GREEN += src[ridx].green * ker[56].green;
        BLUE += src[ridx].blue * ker[56].blue;

        RED += src[++ridx].red * ker[57].red;
        GREEN += src[ridx].green * ker[57].green;
        BLUE += src[ridx].blue * ker[57].blue;

        RED += src[++ridx].red * ker[58].red;
        GREEN += src[ridx].green * ker[58].green;
        BLUE += src[ridx].blue * ker[58].blue;

        RED += src[++ridx].red * ker[59].red;
        GREEN += src[ridx].green * ker[59].green;
        BLUE += src[ridx].blue * ker[59].blue;

        RED += src[++ridx].red * ker[60].red;
        GREEN += src[ridx].green * ker[60].green;
        BLUE += src[ridx].blue * ker[60].blue;

        RED += src[++ridx].red * ker[61].red;
        GREEN += src[ridx].green * ker[61].green;
        BLUE += src[ridx].blue * ker[61].blue;

        RED += src[++ridx].red * ker[62].red;
        GREEN += src[ridx].green * ker[62].green;
        BLUE += src[ridx].blue * ker[62].blue;

        RED += src[++ridx].red * ker[63].red;
        GREEN += src[ridx].green * ker[63].green;
        BLUE += src[ridx].blue * ker[63].blue;

        dst[origridx] = RED + GREEN + BLUE;
    }
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
    int halfdim = dim/2, i,j, i2plus1, j2plus1, i2, j2, ridx1, ridx2, iplus1, jplus1, RED, GREEN, BLUE;
    register int ridx;

    for(i = 0; i < halfdim; i+=2) {
        iplus1 = i + 1;
        i2 = i << 1; i2plus1 = (i << 1) + 1;

        for (j = 0; j < halfdim; j+=2) {
            jplus1 = j + 1;
            ridx = RIDX(i, j, halfdim);
            j2 = j << 1; j2plus1 = (j << 1) + 1;

            ridx1 = RIDX(i2, j2, dim);
            ridx2 = RIDX(i2, j2plus1, dim);

            RED = src[ridx1].red;
            GREEN = src[ridx1].green;
            BLUE = src[ridx1].blue;

            RED += src[ridx2].red;
            GREEN += src[ridx2].green;
            BLUE += src[ridx2].blue;

            ridx1 = RIDX(i2plus1, j2, dim);
            ridx2 = RIDX(i2plus1, j2plus1, dim);

            RED += src[ridx1].red;
            GREEN += src[ridx1].green;
            BLUE += src[ridx1].blue;

            RED += src[ridx2].red;
            GREEN += src[ridx2].green;
            BLUE += src[ridx2].blue;

            RED >>= 2;
            GREEN >>= 2;
            BLUE >>= 2;

            dst[ridx].red = RED;
            dst[ridx].green = GREEN;
            dst[ridx].blue = BLUE;





            ridx = RIDX(i, jplus1, halfdim);
            j2 = jplus1 << 1; j2plus1 = (jplus1 << 1) + 1;

            ridx1 = RIDX(i2, j2, dim);
            ridx2 = RIDX(i2, j2plus1, dim);

            RED = src[ridx1].red;
            GREEN = src[ridx1].green;
            BLUE = src[ridx1].blue;

            RED += src[ridx2].red;
            GREEN += src[ridx2].green;
            BLUE += src[ridx2].blue;

            ridx1 = RIDX(i2plus1, j2, dim);
            ridx2 = RIDX(i2plus1, j2plus1, dim);

            RED += src[ridx1].red;
            GREEN += src[ridx1].green;
            BLUE += src[ridx1].blue;

            RED += src[ridx2].red;
            GREEN += src[ridx2].green;
            BLUE += src[ridx2].blue;

            RED >>= 2;
            GREEN >>= 2;
            BLUE >>= 2;

            dst[ridx].red = RED;
            dst[ridx].green = GREEN;
            dst[ridx].blue = BLUE;
        }




        i2 = iplus1<< 1; i2plus1 = (iplus1 <<1)+ 1;

        for (j = 0; j < halfdim; j+=2) {
            jplus1 = j + 1;
            ridx = RIDX(iplus1, j, halfdim);
            j2 = j<<1; j2plus1 = (j <<1) + 1;

            ridx1 = RIDX(i2, j2, dim);
            ridx2 = RIDX(i2, j2plus1, dim);

            RED = src[ridx1].red;
            GREEN = src[ridx1].green;
            BLUE = src[ridx1].blue;

            RED += src[ridx2].red;
            GREEN += src[ridx2].green;
            BLUE += src[ridx2].blue;

            ridx1 = RIDX(i2plus1, j2, dim);
            ridx2 = RIDX(i2plus1, j2plus1, dim);

            RED += src[ridx1].red;
            GREEN += src[ridx1].green;
            BLUE += src[ridx1].blue;

            RED += src[ridx2].red;
            GREEN += src[ridx2].green;
            BLUE += src[ridx2].blue;

            RED >>= 2;
            GREEN >>= 2;
            BLUE >>= 2;

            dst[ridx].red = RED;
            dst[ridx].green = GREEN;
            dst[ridx].blue = BLUE;





            ridx = RIDX(iplus1, jplus1, halfdim);
            j2 = jplus1 << 1; j2plus1 = (jplus1 << 1) + 1;

            ridx1 = RIDX(i2, j2, dim);
            ridx2 = RIDX(i2, j2plus1, dim);

            RED = src[ridx1].red;
            GREEN = src[ridx1].green;
            BLUE = src[ridx1].blue;

            RED += src[ridx2].red;
            GREEN += src[ridx2].green;
            BLUE += src[ridx2].blue;

            ridx1 = RIDX(i2plus1, j2, dim);
            ridx2 = RIDX(i2plus1, j2plus1, dim);

            RED += src[ridx1].red;
            GREEN += src[ridx1].green;
            BLUE += src[ridx1].blue;

            RED += src[ridx2].red;
            GREEN += src[ridx2].green;
            BLUE += src[ridx2].blue;

            RED >>= 2;
            GREEN >>= 2;
            BLUE >>= 2;

            dst[ridx].red = RED;
            dst[ridx].green = GREEN;
            dst[ridx].blue = BLUE;
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

