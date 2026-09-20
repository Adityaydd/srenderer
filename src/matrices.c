#include "matrices.h"
#include <math.h>
#include <string.h>

// camera values
const struct Vec3 eye = {0.0f, 0.0f, 5.0f};
const struct Vec3 target = {0.0f, 0.0f, 0.0f};
const struct Vec3 up = {0.0f, 1.0f, 0.0f};

// projection values
float fov = 60.0f * (PI / 180.0f);
float np = 0.1f;
float fp = 100.0f;
float ar = (float)WIDTH / (float)HEIGHT;

void constructIdentityMatrix(float *matrix) {
  memset(matrix, 0, 16 * sizeof(float));

  matrix[0] = 1.0f;
  matrix[5] = 1.0f;
  matrix[10] = 1.0f;
  matrix[15] = 1.0f;
}

void constructProjectionMatrix(float fov, float np, float fp, float ar,
                               float *projectionMatrix) {
  memset(projectionMatrix, 0, 16 * sizeof(float));

  float a = tanf(fov / 2.0f);

  projectionMatrix[0] = 1.0f / (ar * a);
  projectionMatrix[5] = 1.0f / a;
  projectionMatrix[10] = -((fp + np) / (fp - np));
  projectionMatrix[11] = -1.0f;
  projectionMatrix[14] = (-2.0f * fp * np) / (fp - np);
}

void constructEyeMatrix(struct Vec3 eye, struct Vec3 target, struct Vec3 up,
                        float *viewMatrix) {
  constructIdentityMatrix(viewMatrix);

  viewMatrix[14] = -eye.z;
}

void constructRoatationMatY(float *RoatationMatY, float theta) {

  constructIdentityMatrix(RoatationMatY);

  RoatationMatY[0] = cos(theta);
  RoatationMatY[2] = sin(theta);
  RoatationMatY[8] = -sin(theta);
  RoatationMatY[10] = cos(theta);
}
