#pragma once

#define WIDTH 800
#define HEIGHT 600
#define PI 3.14159265358979323846f

struct Vec3 {
  float x;
  float y;
  float z;
};

// camera
extern const struct Vec3 eye;
extern const struct Vec3 target;
extern const struct Vec3 up;

// projection matrix values
extern float ar;  // aspect ratio (width/height)
extern float np;  // nearplane
extern float fp;  // farplane
extern float fov; // theta

// functions
void constructIdentityMatrix(float *matrix);

void constructProjectionMatrix(float fov, float np, float fp, float ar,
                               float *projectionMatrix);

void constructEyeMatrix(struct Vec3 eye, struct Vec3 target, struct Vec3 up,
                        float *viewMatrix);

void constructRoatationMatY(float *RoatationMatY, float theta);
