#pragma once
#include <SDL3/SDL_rect.h>
#include <cglm/types.h>

void projectPoints(vec4 *worldPoints, SDL_FPoint *pix);
void fillLines(SDL_FPoint *pix, SDL_FPoint *lines);
