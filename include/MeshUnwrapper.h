#pragma once

#define MU_API __declspec(dllexport) 

extern "C" 
{
    MU_API void     mu_init(int maxAtlasSize, float texelDensity);
    MU_API void     mu_set_positions(void* position, int itemSize, int itemCount);
    MU_API void     mu_set_indices(void* indicies, int itemSize, int itemCount);
    MU_API void     mu_build();
    MU_API void*    mu_get_unwrapped_uvs();
    MU_API int      mu_get_atlas_width();
    MU_API int      mu_get_atlas_height();
}
