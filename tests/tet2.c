#include "matrices.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  float *M1 = malloc(16 * sizeof(float));
  float *M2 = malloc(16 * sizeof(float));
  float *result = malloc(16 * sizeof(float));

  M1 = constructEyeMatrix(eye, target, up);
  M2 = constructProjectionMatrix(fov, np, fp, ar);

  printf("Eye Matrix:\n");
  for (int i = 0; i < 4; i++) {
    printf("[ %f %f %f %f ]\n", M1[4 * i + 0], M1[4 * i + 1], M1[4 * i + 2],
           M1[4 * i + 3]);
  }
  printf("\n");
  printf("Projection Matrix:\n");
  for (int i = 0; i < 4; i++) {
    printf("[ %f %f %f %f ]\n", M2[4 * i + 0], M2[4 * i + 1], M2[4 * i + 2],
           M2[4 * i + 3]);
  }
  return 0;
}
