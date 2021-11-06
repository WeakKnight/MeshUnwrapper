#pragma once
#include <stdint.h>

#define MU_API __declspec(dllexport) 

extern "C" 
{
    MU_API void         mu_init(uint32_t maxAtlasSize, float texelDensity);
    MU_API void         mu_set_positions(void* position, uint32_t itemSize, uint32_t itemCount);
    MU_API void         mu_set_indices(void* indicies, uint32_t itemSize, uint32_t itemCount);
    MU_API void         mu_build();

    MU_API uint32_t     mu_get_atlas_width();
    MU_API uint32_t     mu_get_atlas_height();

    /*Per Vertex Data*/
    MU_API float        mu_get_unwrapped_mesh_u(uint32_t i);
    MU_API float        mu_get_unwrapped_mesh_v(uint32_t i);
    MU_API uint32_t     mu_get_unwrapped_mesh_original_index(uint32_t i);
    MU_API uint32_t     mu_get_unwrapped_mesh_vertex_count();

    /*Per Index Data*/
    MU_API uint32_t     mu_get_unwrapped_mesh_index(uint32_t i);
    MU_API uint32_t     mu_get_unwrapped_mesh_index_count();

    MU_API void         mu_free();
}
