#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <map>
#include <string>

struct SDL_Surface;
struct SDL_Rect;

class Graphics {


public:
	typedef SDL_Surface* SurfaceID;

	Graphics();
	virtual ~Graphics();

	SurfaceID loadImage(const std::string& file_path);

	void blitSurface(	SurfaceID source,
						SDL_Rect* source_rectangle,
						SDL_Rect* destination_rectangle);
	void clear();
	void flip();

private:
	typedef std::map<std::string, SDL_Surface*> SpriteMap;
	SDL_Surface* screen_;
	SpriteMap sprite_sheets_;
};

#endif /* GRAPHICS_H_ */
