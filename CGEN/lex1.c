/******************************************************
*     Decompiled by Mark Ogden & Andrey Nikitin       *
* Adapted to 128/512KB systems by Ladislau Szilagyi   *
*		ladislau_szilagyi@yahoo.com	      *
*	   December 2022 - April 2025		      *
******************************************************/

/*
 * File - lex1u.c
 */

#include "cgen.h"

/* clang-format on */

/* offsets into character array below */
static int16_t array_987D[] = { 0,     0,     4,     9,     0x0A,  0x0C,  0x0E,  0x1C,  0x2D,
                         0x31,  0x3E,  0x52,  0x54,  0x62,  0x7C,  0x8E,  0x0A0, 0x0A1,
                         0x0A3, 0x0B3, 0x0C3, 0x0D7, 0x0E7, 0x0E8, 0x0EB, 0x0F9, 0x0FB,
                         0x0FD, 0x10B, 0x119, 0x11A, 0x11F, 0x12F, 0x130, 0x147, 0x155,
                         0x165, 0x173, 0x18B, 0x19B, 0x1A9, 0x1B9, 0x1BE, 0x1CE, 0x1DE,
                         0x1EE, 0x1EF, 0x1F4, 0x204, 0x214, 0x216, 0x217, 0x218, 0x219,
                         0x21A, 0x21B, 0x21C, 0x21D, 0x21E, 0x22E, 0x22F, 0x23F, 0x243,
                         0x244, 0x254, 0x255, 0x256, 0x26F, 0x28D, 0x2A6, 0x2B6, 0x2B8 };

static uint8_t array_990D[] = {
    "Qhi\0"                           /* [0 or 1] 000h */
    "PQhi\0"                          /* [2] 004h */
    "\0"                              /* [3] 009h */
    "H\0"                             /* [4] 00Ah */
    "H\0"                             /* [5] 00Ch */
    "HNSTZ]^_djprs\0"                 /* [6] 00Eh */
    "HNSTUVZ]^_dgjprs\0"              /* [7] 01Ch */
    "Qhi\0"                           /* [8] 02Dh */
    "HNTYZ]^djprs\0"                  /* [9] 031h */
    "HNRSTUVZ[]^_`djnprs\0"           /* [10] 03Eh */
    "H\0"                             /* [11] 052h */
    "HNSTZ]^_djprs\0"                 /* [12] 054h */
    "HIMNRSTUVZ[\\]^_`abcdfjprs\0"    /* [13] 062h */
    "HNSTUVYZ]^_djprsw\0"             /* [14] 07Ch */
    "HNSTUVZ]^_djklprs\0"             /* [15] 08Eh */
    "\0"                              /* [16] 0A0h */
    "N\0"                             /* [17] 0A1h */
    "HNSTUVZ]^_djprs\0"               /* [18] 0A3h */
    "HNSTUVZ]^_djprs\0"               /* [19] 0B3h */
    "HNRSTUVYZ[]^_`djprs\0"           /* [20] 0C3h */
    "HNSTUVZ]^_djprs\0"               /* [21] 0D7h */
    "\0"                              /* [22] 0E7h */
    "Nt\0"                            /* [23] 0E8h */
    "HNSTZ]^_djprs\0"                 /* [24] 0EBh */
    "m\0"                             /* [25] 0F9h */
    "H\0"                             /* [26] 0FBh */
    "HNOTYZ]^djprs\0"                 /* [27] 0FDh */
    "HNTUVZ]^djprs\0"                 /* [28] 10Bh */
    "\0"                              /* [29] 119h */
    "PQhi\0"                          /* [30] 11Ah */
    "HNSTUVZ]^_djprs\0"               /* [31] 11Fh */
    "\0"                              /* [32] 12Fh */
    "HNRSTUVWZ[]^_`cdfjprsw\0"        /* [33] 130h */
    "HNSTZ]^_djprs\0"                 /* [34] 147h */
    "HNSTUVZ]^_djprs\0"               /* [35] 155h */
    "HNSTZ]^_djprs\0"                 /* [36] 165h */
    "HINSTUVWZ]^_abcdfjprsvw\0"       /* [37] 173h */
    "HNSTUVZ]^_djprs\0"               /* [38] 18Bh */
    "HNSTZ]^_djprs\0"                 /* [39] 19Bh */
    "HNSTUVZ]^_djprs\0"               /* [40] 1A9h */
    "PQhi\0"                          /* [41] 1B9h */
    "HNSTUVZ]^_djprs\0"               /* [42] 1BEh */
    "HNSTUVZ]^_djprs\0"               /* [43] 1CEh */
    "HNSTUVZ]^_djprs\0"               /* [44] 1DEh */
    "\0"                              /* [45] 1EEh */
    "PQhi\0"                          /* [46] 1EFh */
    "HNSTUVZ]^_djprs\0"               /* [47] 1F4h */
    "HNSTUVZ]^_djprs\0"               /* [48] 204h */
    "H\0"                             /* [49] 214h */
    "\0"                              /* [50] 216h */
    "\0"                              /* [51] 217h */
    "\0"                              /* [52] 218h */
    "\0"                              /* [53] 219h */
    "\0"                              /* [54] 21Ah */
    "\0"                              /* [55] 21Bh */
    "\0"                              /* [56] 21Ch */
    "\0"                              /* [57] 21Dh */
    "HNSTUVZ]^_djprs\0"               /* [58] 21Eh */
    "\0"                              /* [59] 22Eh */
    "HNSTUVZ]^_djprs\0"               /* [60] 22Fh */
    "Qhi\0"                           /* [61] 23Fh */
    "\0"                              /* [62] 243h */
    "HNSTUVZ]^_djprs\0"               /* [63] 244h */
    "\0"                              /* [64] 254h */
    "\0"                              /* [65] 255h */
    "HMNORSTUVZ[\\]^_`acdfjprs\0"     /* [66] 256h */
    "HIJKLNOSTUVYZ]^_abcdfjopqrsux\0" /* [67] 26Fh */
    "HMNRSTUVXZ[\\]^_`acdfjprs\0"     /* [68] 28Dh */
    "HNTWZ]^cdfjprsw\0"               /* [69] 2A6h */
    "H\0"                             /* [70] 2B6h */
    "HNTZ]^cdefjprs"                  /* [71] 2B8h */
};

#ifndef	PACK_DATA

static int16_t array_9BD4[] = {
    -66,  -65,  -68,  0,    89,   -69,  -65,  -68,  0,    0,    1,    0,    -8,   0,    3,
    62,   -221, 141,  -167, 231,  251,  -151, 264,  -70,  -106, 276,  -100, 0,    5,    64,
    -221, 141,  -90,  163,  170,  234,  251,  -151, 264,  -63,  -70,  274,  278,  -100, 0,
    -64,  -65,  -68,  0,    -28,  -47,  141,  -33,  172,  239,  251,  264,  -70,  -106, -102,
    -100, 0,    8,    68,   -245, -215, 141,  -84,  163,  174,  -250, 234,  251,  -151, -243,
    264,  -70,  -98,  274,  278,  -100, 0,    13,   0,    3,    62,   -221, 141,  -167, 231,
    251,  -151, 264,  -70,  -106, 276,  -100, 0,    9,    58,

    60,   68,   116,  118,  141,  143,  163,  176,  229,  -111, 241,  251,  -151, 253,  255,
    257,  259,  264,  266,  -70,  274,  278,  -100, 0,    5,    64,   121,  141,  -89,  163,
    -36,  182,  234,  251,  -151, 264,  -70,  274,  278,  -100, 283,  0,    18,   64,   -220,
    141,  147,  163,  187,  234,  251,  -151, 264,  -70,  -141, -137, 274,  278,  -100, 0,
    0,    -49,  0,    5,    64,   -221, 141,  -90,  163,  -197, 234,  251,  -151, 264,  -70,
    274,  278,  -100, 0,    23,   64,   -220, 141,  147,  163,  189,  234,  251,  -151, 264,
    -70,  274,  278,  -100, 0,    9,    68,   -245, 123,  141,

    149,  163,  -35,  191,  -251, 234,  251,  -151, -243, 264,  -70,  274,  278,  -100, 0,
    5,    64,   132,  141,  -96,  163,  -202, 234,  251,  -151, 264,  -70,  274,  278,  -100,
    0,    0,    -50,  -114, 0,    3,    62,   -221, 141,  -167, 231,  251,  -151, 264,  -70,
    -106, 276,  -100, 0,    -99,  0,    -16,  0,    -28,  -47,  -148, 141,  -32,  -161, 239,
    251,  264,  -70,  -106, -102, -100, 0,    27,   73,   141,  -74,  163,  -164, 247,  251,
    264,  -70,  274,  279,  -100, 0,    0,    102,  -69,  -65,  -68,  0,    5,    64,   -223,
    141,  155,  163,  200,  234,  251,  -151, 264,  -70,  274,

    278,  -100, 0,    0,    30,   76,   -245, 134,  141,  157,  163,  165,  202,  -247, 234,
    251,  -151, -243, -54,  264,  269,  -70,  274,  278,  -100, -139, 0,    3,    62,   -219,
    141,  -166, 231,  251,  -151, 264,  -70,  -106, 276,  -100, 0,    38,   64,   -219, 141,
    -92,  163,  209,  234,  251,  -151, 264,  -70,  274,  278,  -100, 0,    3,    62,   -219,
    141,  -166, 231,  251,  -151, 264,  -70,  -106, 276,  -100, 0,    42,   -238, 82,   137,
    141,  159,  163,  168,  211,  241,  251,  -151, -51,  -152, 262,  264,  271,  -70,  274,
    278,  -100, 281,  -139, 0,    23,   64,   -219, 141,  -92,

    163,  217,  234,  251,  -151, 264,  -70,  274,  278,  -100, 0,    3,    62,   -219, 141,
    -166, 231,  251,  -151, 264,  -70,  -106, 276,  -100, 0,    5,    64,   -222, 141,  161,
    163,  -170, 234,  251,  -151, 264,  -70,  274,  278,  -100, 0,    89,   -69,  -65,  -68,
    0,    5,    64,   -222, 141,  161,  163,  -170, 234,  251,  -151, 264,  -70,  274,  278,
    -100, 0,    5,    64,   -219, 141,  -92,  163,  -179, 234,  251,  -151, 264,  -70,  274,
    278,  -100, 0,    48,   64,   -219, 141,  -92,  163,  219,  234,  251,  -151, 264,  -70,
    274,  278,  -100, 0,    0,    109,  -69,  -65,  -68,  0,

    5,    64,   -223, 141,  155,  163,  221,  234,  251,  -151, 264,  -70,  274,  278,  -100,
    0,    5,    64,   -216, 141,  -76,  163,  -160, 234,  251,  -151, 264,  -70,  274,  278,
    -100, 0,    52,   0,    0,    0,    0,    0,    0,    0,    0,    0,    5,    64,   -221,
    141,  -90,  163,  -178, 234,  251,  -151, 264,  -70,  274,  278,  -100, 0,    0,    5,
    64,   -221, 141,  -90,  163,  223,  234,  251,  -151, 264,  -70,  274,  278,  -100, 0,
    -67,  -65,  -68,  0,    0,    5,    64,   -227, 141,  -95,  163,  -202, 234,  251,  -151,
    264,  -70,  274,  278,  -100, 0,    0,    0,    9,    -133,

    68,   -149, -245, -212, 141,  -97,  163,  225,  -248, -112, 234,  251,  -151, -243, -52,
    -53,  264,  -61,  -70,  274,  278,  -100, 0,    5,    -237, -104, -252, -242, 64,   -150,
    139,  141,  -73,  163,  -34,  227,  241,  251,  -151, -51,  -152, -55,  264,  272,  -70,
    -241, 274,  -155, 278,  -100, -253, -154, 0,    9,    -133, 68,   -245, -212, 141,  -97,
    163,  -115, 225,  -248, -113, 234,  251,  -151, -243, -52,  -53,  264,  -61,  -70,  274,
    278,  -100, 0,    56,   87,   141,  -142, -165, 239,  251,  -54,  264,  269,  -70,  -106,
    -102, -100, -139, 0,    -18,  0,    -28,  -47,  141,  -158,

    239,  251,  -57,  264,  -62,  -61,  -70,  -106, -102, -100, 0
};

#else

// 3 bytes per 2 items, instead of 4 bytes

static unsigned char byte_array_9BD4[] = {
190, 255, 251,
188, 15, 0,
89, 176, 251,
191, 207, 251,
0, 0, 0,
1, 0, 0,
248, 15, 0,
3, 224, 3,
35, 223, 8,
89, 127, 14,
251, 144, 246,
8, 161, 251,
150, 79, 17,
156, 15, 0,
5, 0, 4,
35, 223, 8,
166, 63, 10,
170, 160, 14,
251, 144, 246,
8, 17, 252,
186, 47, 17,
22, 193, 249,
0, 0, 252,
191, 207, 251,
0, 64, 254,
209, 223, 8,
223, 207, 10,
239, 176, 15,
8, 161, 251,
150, 175, 249,
156, 15, 0,
8, 64, 4,
11, 159, 242,
141, 192, 250,
163, 224, 10,
6, 175, 14,
251, 144, 246,
13, 143, 16,
186, 239, 249,
18, 97, 17,
156, 15, 0,
13, 0, 0,
3, 224, 3,
35, 223, 8,
89, 127, 14,
251, 144, 246,
8, 161, 251,
150, 79, 17,
156, 15, 0,
9, 160, 3,
60, 64, 4,
116, 96, 7,
141, 240, 8,
163, 0, 11,
229, 16, 249,
241, 176, 15,
105, 223, 15,
255, 16, 16,
3, 129, 16,
10, 161, 251,
18, 97, 17,
156, 15, 0,
5, 0, 4,
121, 208, 8,
167, 63, 10,
220, 111, 11,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
27, 1, 0,
18, 0, 4,
36, 223, 8,
147, 48, 10,
187, 160, 14,
251, 144, 246,
8, 161, 251,
115, 127, 247,
18, 97, 17,
156, 15, 0,
0, 240, 252,
0, 80, 0,
64, 48, 242,
141, 96, 250,
163, 176, 243,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
0, 112, 1,
64, 64, 242,
141, 48, 9,
163, 208, 11,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
0, 144, 0,
68, 176, 240,
123, 208, 8,
149, 48, 10,
221, 255, 11,
5, 175, 14,
251, 144, 246,
13, 143, 16,
186, 47, 17,
22, 193, 249,
0, 80, 0,
64, 64, 8,
141, 0, 250,
163, 96, 243,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
0, 0, 0,
206, 239, 248,
0, 48, 0,
62, 48, 242,
141, 144, 245,
231, 176, 15,
105, 143, 16,
186, 111, 249,
20, 193, 249,
0, 208, 249,
0, 0, 255,
0, 64, 254,
209, 207, 246,
141, 0, 254,
95, 255, 14,
251, 128, 16,
186, 111, 249,
154, 207, 249,
0, 176, 1,
73, 208, 8,
182, 63, 10,
92, 127, 15,
251, 128, 16,
186, 47, 17,
23, 193, 249,
0, 0, 0,
102, 176, 251,
191, 207, 251,
0, 80, 0,
64, 16, 242,
141, 176, 9,
163, 128, 12,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
0, 0, 0,
30, 192, 4,
11, 111, 8,
141, 208, 9,
163, 80, 10,
202, 144, 240,
234, 176, 15,
105, 223, 240,
202, 143, 16,
13, 161, 251,
18, 97, 17,
156, 95, 247,
0, 48, 0,
62, 80, 242,
141, 160, 245,
231, 176, 15,
105, 143, 16,
186, 111, 249,
20, 193, 249,
0, 96, 2,
64, 80, 242,
141, 64, 250,
163, 16, 13,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
0, 48, 0,
62, 80, 242,
141, 160, 245,
231, 176, 15,
105, 143, 16,
186, 111, 249,
20, 193, 249,
0, 160, 2,
18, 47, 5,
137, 208, 8,
159, 48, 10,
168, 48, 13,
241, 176, 15,
105, 223, 252,
104, 111, 16,
8, 241, 16,
186, 47, 17,
22, 193, 249,
25, 81, 247,
0, 112, 1,
64, 80, 242,
141, 64, 250,
163, 144, 13,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
0, 48, 0,
62, 80, 242,
141, 160, 245,
231, 176, 15,
105, 143, 16,
186, 111, 249,
20, 193, 249,
0, 80, 0,
64, 32, 242,
141, 16, 10,
163, 96, 245,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
0, 144, 5,
187, 255, 251,
188, 15, 0,
5, 0, 4,
34, 223, 8,
161, 48, 10,
86, 175, 14,
251, 144, 246,
8, 161, 251,
18, 97, 17,
156, 15, 0,
5, 0, 4,
37, 223, 8,
164, 63, 10,
77, 175, 14,
251, 144, 246,
8, 161, 251,
18, 97, 17,
156, 15, 0,
48, 0, 4,
37, 223, 8,
164, 63, 10,
219, 160, 14,
251, 144, 246,
8, 161, 251,
18, 97, 17,
156, 15, 0,
0, 208, 6,
187, 255, 251,
188, 15, 0,
5, 0, 4,
33, 223, 8,
155, 48, 10,
221, 160, 14,
251, 144, 246,
8, 161, 251,
18, 97, 17,
156, 15, 0,
5, 0, 4,
40, 223, 8,
180, 63, 10,
96, 175, 14,
251, 144, 246,
8, 161, 251,
18, 97, 17,
156, 15, 0,
52, 0, 0,
0, 0, 0,
0, 0, 0,
0, 0, 0,
0, 0, 0,
5, 0, 4,
35, 223, 8,
166, 63, 10,
78, 175, 14,
251, 144, 246,
8, 161, 251,
18, 97, 17,
156, 15, 0,
0, 80, 0,
64, 48, 242,
141, 96, 250,
163, 240, 13,
234, 176, 15,
105, 143, 16,
186, 47, 17,
22, 193, 249,
0, 208, 251,
191, 207, 251,
0, 0, 0,
5, 0, 4,
29, 223, 8,
161, 63, 10,
54, 175, 14,
251, 144, 246,
8, 161, 251,
18, 97, 17,
156, 15, 0,
0, 0, 0,
9, 176, 247,
68, 176, 246,
11, 207, 242,
141, 240, 249,
163, 16, 14,
8, 15, 249,
234, 176, 15,
105, 223, 240,
204, 191, 252,
8, 49, 252,
186, 47, 17,
22, 193, 249,
0, 80, 0,
19, 143, 249,
4, 239, 240,
64, 160, 246,
139, 208, 8,
183, 63, 10,
222, 63, 14,
241, 176, 15,
105, 223, 252,
104, 159, 252,
8, 1, 17,
186, 255, 240,
18, 81, 246,
22, 193, 249,
3, 111, 246,
0, 144, 0,
123, 79, 4,
11, 207, 242,
141, 240, 249,
163, 208, 248,
225, 128, 240,
143, 175, 14,
251, 144, 246,
13, 207, 252,
203, 143, 16,
195, 175, 251,
18, 97, 17,
156, 15, 0,
56, 112, 5,
141, 32, 247,
91, 255, 14,
251, 160, 252,
8, 209, 16,
186, 111, 249,
154, 207, 249,
117, 15, 0,
238, 15, 0,
228, 31, 253,
141, 32, 246,
239, 176, 15,
199, 143, 16,
194, 63, 252,
186, 111, 249,
154, 207, 249,
0, 0
};

int getnr(unsigned char* array, int index);

#endif

/*********************************************************
 * sub_13D	Ok++ PMO		Used in: sub_1F4B
 * This function wasn't optimised in original code hence
 * it is split out separately
 *********************************************************/
int sub_13D(int a, int b) {
    int i;

    for (i = array_987D[b]; array_990D[i] != 0 && array_990D[i] != a; i++)
        ;
#ifndef PACK_DATA
    return array_9BD4[i];
#else
    return getnr(byte_array_9BD4, i);
#endif
}

/* end of file lex1u.c */
