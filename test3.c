#include <cglm/cglm.h>
#include <stdio.h>

struct Vec4 {
  float x, y, z, w;
};

int main(void) {
  // 1. One test coordinate: (1.0, 2.0, 3.0, 1.0)
  struct Vec4 point = {1.0f, 2.0f, 3.0f, 1.0f};

  // 2. Hardcoded column-major 4x4 matrix:
  // [ 2  0  0  0 ]
  // [ 0  3  0  0 ]
  // [ 0  0  1 10 ]
  // [ 0  0  0  1 ]
  mat4 M = {
      {2.0f, 0.0f, 0.0f, 0.0f}, // Column 0
      {0.0f, 3.0f, 0.0f, 0.0f}, // Column 1
      {0.0f, 0.0f, 1.0f, 0.0f}, // Column 2
      {0.0f, 0.0f, 10.0f, 1.0f} // Column 3 (Translation)
  };

  struct Vec4 result;

  // 3. Multiply matrix by vector: result = M * point
  glm_mat4_mulv(M, (float *)&point, (float *)&result);

  // 4. Print results
  printf("Input:    (%.1f, %.1f, %.1f, %.1f)\n", point.x, point.y, point.z,
         point.w);
  printf("Output:   (%.1f, %.1f, %.1f, %.1f)\n", result.x, result.y, result.z,
         result.w);
  printf("Expected: (2.0, 6.0, 13.0, 1.0)\n");

  return 0;
}
