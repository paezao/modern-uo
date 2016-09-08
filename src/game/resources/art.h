#ifndef _RESOURCES_ART_H_
#define _RESOURCES_ART_H_

#include "../core/texture.h"

static Texture * land_textures[0x3FFF];

Texture * get_land_texture(int index);
void unload_land_textures();

#endif
