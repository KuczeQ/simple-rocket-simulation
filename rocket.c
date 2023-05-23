#include "rocket.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int ROCKET_WIDTH = 20;
const int ROCKET_HEIGHT = 40;

Rocket enterRocketData(SDL_Renderer *renderer) {
    Rocket rocket;

    printf("Wprowadź dane o rakiecie:\n");

    printf("Masa rakiety [kg]: ");
    scanf("%lf", &rocket.mass);

    printf("Ciąg silnika [N]: ");
    scanf("%lf", &rocket.thrust);

    printf("Czas spalania silnika [s]: ");
    scanf("%lf", &rocket.burnTime);

    printf("Współczynnik oporu atmosferycznego: ");
    scanf("%lf", &rocket.drag);

    return rocket;
}

void drawRocket(SDL_Renderer *renderer, int x, int y) {
    SDL_Rect rocketRect = {x, y, ROCKET_WIDTH, ROCKET_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rocketRect);
}

void simulateRocketFlight(Rocket rocket, SDL_Renderer *renderer) {
    SDL_Event event;
    bool quit = false;
    int rocketX = WINDOW_WIDTH / 2 - ROCKET_WIDTH / 2;
    int rocketY = WINDOW_HEIGHT - ROCKET_HEIGHT;

    double currentTime = 0.0;
    double deltaTime = 0.01;
    double velocity = 0.0;
    double acceleration = 0.0;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        currentTime += deltaTime;

        if (currentTime <= rocket.burnTime) {
            acceleration = (rocket.thrust - rocket.drag * velocity) / rocket.mass;
            velocity += acceleration * deltaTime;
            rocketY -= velocity * deltaTime * 100; // Skalowanie prędkości dla wizualizacji
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        drawRocket(renderer, rocketX, rocketY);

        SDL_RenderPresent(renderer);

        SDL_Delay(10);
    }
}
