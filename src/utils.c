#include "matrices.h"
#include <SDL3/SDL_rect.h>
#include <cglm/mat4.h>
#include <cglm/types.h>

float g_Yangle = 100.0f;
void getRoatation(mat4 roat) {

  float theta = g_Yangle * (PI / 180.0f);
  constructRoatationMatY((float *)roat, theta);
  g_Yangle += 1.0f;
}

void projectPoints(vec4 *worldPoints, SDL_FPoint *pix) {
  mat4 projec;
  mat4 view;
  mat4 temp;
  mat4 roat;
  mat4 result;

  vec4 clippedSpace[8];

  constructProjectionMatrix(fov, np, fp, ar, (float *)projec);
  constructEyeMatrix(eye, target, up, (float *)view);
  getRoatation(roat);

  glm_mat4_mul(projec, view, temp);
  glm_mat4_mul(temp, roat, result);

  for (int i = 0; i < 8; i++) {
    glm_mat4_mulv(result, worldPoints[i], clippedSpace[i]);
  }

  // to pixels
  for (int i = 0; i < 8; i++) {
    float invW = 1.0f / clippedSpace[i][3];

    float ndc_x = clippedSpace[i][0] * invW;
    float ndc_y = clippedSpace[i][1] * invW;

    pix[i].x = (int)((ndc_x + 1.0f) * 0.5f * (float)WIDTH);
    pix[i].y = (int)((1.0f - ndc_y) * 0.5f * (float)HEIGHT);
  }
}

void fillLines(SDL_FPoint *pix, SDL_FPoint *lines) {
  const int path_indices[16] = {0, 1, 2, 3, 0, 4, 5, 6, 7, 4, 5, 1, 2, 6, 7, 3};

  for (int i = 0; i < 16; i++) {
    lines[i] = pix[path_indices[i]];
  }
}

// int main(int argc, char *argv[]) {
//
//   vec4 worldPoints[] = {
//       {-1.0f, -1.0f, 1.0f, 1.0f},  {1.0f, -1.0f, 1.0f, 1.0f},
//       {1.0f, 1.0f, 1.0f, 1.0f},    {-1.0f, 1.0f, 1.0f, 1.0f},
//       {-1.0f, -1.0f, -1.0f, 1.0f}, {1.0f, -1.0f, -1.0f, 1.0f},
//       {1.0f, 1.0f, -1.0f, 1.0f},   {-1.0f, 1.0f, -1.0f, 1.0f}};
//
//   vec4 clippedSpace[8];
//
//   mat4 roat;
//   float theta = 60.0f * (PI / 180.0f);
//
//   constructRoatationMatY((float *)roat, theta);
//   float *r = (float *)roat;
//
//   for (int i = 0; i < 16; i++) {
//     printf("%f  ", r[i]);
//   }
//
//   // clipPoints(worldPoints, clippedSpace);
//
//   //   for (int i = 0; i < 8; i++) {
//   // printf("Point %d: (x: %8.3f, y: %8.3f, z: %8.3f, w: %8.3f)\n", i,
//   //            clippedSpace[i][0],  // x
//   //            clippedSpace[i][1],  // y
//   //            clippedSpace[i][2],  // z
//   //            clippedSpace[i][3]); // w
//   //   }
//
//   return 0;
// }
