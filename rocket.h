#ifndef ROCKET_H
#define ROCKET_H

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct Rocket {
    double mass;      // Masa rakiety [kg]
    double thrust;    // Ciąg silnika [N]
    double burnTime;  // Czas spalania silnika [s]
    double drag;      // Współczynnik oporu atmosferycznego
} Rocket;

Rocket enterRocketData(SDL_Renderer *renderer);

void simulateRocketFlight(Rocket rocket, SDL_Renderer *renderer);

#endif
