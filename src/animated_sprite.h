#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_

#include "sprite.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(	const std::string& file_path,
					int source_x, int source_y,
					int width, int height,
					int fps, int num_frames);
	void update(int elapsed_time_ms);

private:
	const int frame_time_;
	const int num_frames_;
	int current_frame_;
	int elapsed_time_;		// since last frame change
};

#endif /* ANIMATEDSPRITE_H_ */
