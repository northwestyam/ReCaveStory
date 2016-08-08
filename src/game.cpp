#include <SDL/SDL.h>
#include "game.h"
#include "graphics.h"
#include "player.h"
#include "input.h"


namespace {
	const int kFPS = 60;
}

// static
int Game::kTileSize = 32;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_ShowCursor(SDL_DISABLE);
	eventLoop();
}

Game::~Game() {
	SDL_Quit();
}

void Game::eventLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	player_.reset(new Player(graphics, 320, 240));

	bool running = true;
	int last_update_time = SDL_GetTicks();
	while (running) {
		const int start_time = SDL_GetTicks();
		input.beginNewFrame();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_KEYDOWN:
					input.keyDownEvent(event);
					break;
				case SDL_KEYUP:
					input.keyUpEvent(event);
					break;
				default:
					break;
			}
		}

		if (input.wasKeyPressed(SDLK_ESCAPE)) {
			running = false;
		}

		// if both left and right are being pressed, stop moving
		if (input.isKeyHeld(SDLK_LEFT) && input.isKeyHeld(SDLK_RIGHT)) {
			player_->stopMoving();
		} else if (input.isKeyHeld(SDLK_LEFT)) {
			player_->startMovingLeft();
		} else if (input.isKeyHeld(SDLK_RIGHT)) {
			player_->startMovingRight();
		} else {
			player_->stopMoving();
		}
		const int current_time = SDL_GetTicks();
		update(current_time - last_update_time);
		last_update_time = current_time;

		draw(graphics);
		const int elapsed_time = SDL_GetTicks() - start_time;
		SDL_Delay(1000/kFPS - elapsed_time);	// This loop lasts 1/60th of a second, or 1000/60th of a ms

	}
}

void Game::update(int elapsed_time) {
	player_->update(elapsed_time);
}

void Game::draw(Graphics& graphics) {
	graphics.clear();
	player_->draw(graphics);
	graphics.flip();
}
