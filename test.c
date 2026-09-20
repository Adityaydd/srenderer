#include <cglm/cglm.h>
#include <cglm/types.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  float M1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  float M2[] = {
      2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0,
  };

  float result[16];

  /*

  passing the Matrix in reverse cuz i have made the matrix in row major and glm
  treats the matrix as collum major it works cuz (A.B)^T == B^T.A^T

  */
  glm_mat4_mul((vec4 *)M2, (vec4 *)M1, (vec4 *)result);

  for (int i = 0; i < 16; i++) {
    printf("%f  ", result[i]);
  }

  return 0;
}
//
// #include <stdio.h>
// #include <xmmintrin.h>
// #if defined(_MSC_VER)
// #define ALIGN16 __declspec(align(16))
// #else
// #define ALIGN16 __attribute__((aligned(16)))
// #endif
//
// void M4x4_SSE(float *A, float *B, float *C) {
//   __m128 row1 = _mm_load_ps(&B[0]);
//   __m128 row2 = _mm_load_ps(&B[4]);
//   __m128 row3 = _mm_load_ps(&B[8]);
//   __m128 row4 = _mm_load_ps(&B[12]);
//   for (int i = 0; i < 4; i++) {
//     __m128 brod1 = _mm_set1_ps(A[4 * i + 0]);
//     __m128 brod2 = _mm_set1_ps(A[4 * i + 1]);
//     __m128 brod3 = _mm_set1_ps(A[4 * i + 2]);
//     __m128 brod4 = _mm_set1_ps(A[4 * i + 3]);
//     __m128 row = _mm_add_ps(
//         _mm_add_ps(_mm_mul_ps(brod1, row1), _mm_mul_ps(brod2, row2)),
//         _mm_add_ps(_mm_mul_ps(brod3, row3), _mm_mul_ps(brod4, row4)));
//     _mm_store_ps(&C[4 * i], row);
//   }
// }
//
// int main2(int argc, char *argv[]) {
//   ALIGN16 float A[16] =
//   {1.0f, 2.0f,  3.0f,  4.0f,  5.0f,  6.0f,  7.0f,  8.0f,
//                          9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f};
//
//   ALIGN16 float B[16] = {17.0f, 18.0f, 19.0f, 20.0f, 21.0f, 22.0f,
//                          23.0f, 24.0f, 25.0f, 26.0f, 27.0f, 28.0f,
//                          29.0f, 30.0f, 31.0f, 32.0f};
//
//   ALIGN16 float C[16] = {0};
//
//   M4x4_SSE(A, B, C);
//   printf("Result Matrix C:\n");
//   for (int i = 0; i < 4; i++) {
//     printf("[ %6.1f %6.1f %6.1f %6.1f ]\n", C[4 * i + 0], C[4 * i + 1],
//            C[4 * i + 2], C[4 * i + 3]);
//   }
//   return 0;
// }
//
// #include <stdio.h>
// #include <cglm/cglm.h>
//
// int main(int argc, char *argv[]) {
//     // Input arrays in standard Row-Major order (matching the calculator)
//     mat4 M1 = {
//         {1, 5, 9, 13},
//         {2, 6, 10, 14},
//         {3, 7, 11, 15},
//         {4, 8, 12, 16}
//     };
//
//     mat4 M2 = {
//         {1, 5, 9, 13},
//         {0, 0, 0, 0},
//         {0, 0, 0, 0},
//         {0, 0, 0, 0}
//     };
//
//     mat4 result;
//
//     // Multiply M1 * M2 using cglm
//     glm_mat4_mul(M1, M2, result);
//
//     // Print result in row-major order (Row 0, Row 1, Row 2, Row 3)
//     for (int r = 0; r < 4; r++) {
//         for (int c = 0; c < 4; c++) {
//             printf("%6.0f ", result[c][r]);
//         }
//         printf("\n");
//     }
//
//     return 0;
// }
