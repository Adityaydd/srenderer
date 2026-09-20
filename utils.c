#include "matrices.h"
#include <SDL3/SDL_rect.h>
#include <cglm/mat4.h>
#include <cglm/types.h>

void projectPoints(vec4 *worldPoints, SDL_FPoint *pix) {
  mat4 projec;
  mat4 view;
  mat4 viewProj;
  vec4 clippedSpace[8];

  constructProjectionMatrix(fov, np, fp, ar, (float *)projec);
  constructEyeMatrix(eye, target, up, (float *)view);

  glm_mat4_mul(projec, view, viewProj);

  for (int i = 0; i < 8; i++) {
    glm_mat4_mulv(viewProj, worldPoints[i], clippedSpace[i]);
  }

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
//   clipPoints(worldPoints, clippedSpace);
//
//   for (int i = 0; i < 8; i++) {
// printf("Point %d: (x: %8.3f, y: %8.3f, z: %8.3f, w: %8.3f)\n", i,
//            clippedSpace[i][0],  // x
//            clippedSpace[i][1],  // y
//            clippedSpace[i][2],  // z
//            clippedSpace[i][3]); // w
//   }
//
//   return 0;
// }
