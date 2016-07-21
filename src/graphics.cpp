#include "graphics.h"
#include "sprite.h"

namespace {
	const int kScreenWidth = 640;
	const int kScreenHeight = 480;
	const int kBitsPerPixel = 32;
}

Graphics::Graphics() {
	screen = SDL_SetVideoMode(	kScreenWidth,
								kScreenHeight,
								kBitsPerPixel,
								SDL_SWSURFACE);

}

Graphics::~Graphics() {
	SDL_FreeSurface(screen);
}

void Graphics::blitSurface(	SDL_Surface* source,
							SDL_Rect* source_rectangle,
							SDL_Rect* destination_rectangle) {
	SDL_BlitSurface(source, source_rectangle, screen, destination_rectangle);
}

void Graphics::flip() {
	SDL_Flip(screen);
}
