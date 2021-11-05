#include <iostream>
#include "xatlas.h"

xatlas::Atlas* s_atlas = nullptr;
xatlas::PackOptions s_packOptions;
xatlas::MeshDecl s_meshDesc;
int s_maxAtlasSize;

extern "C"
{
    void mu_init(int maxAtlasSize, float texelDensity)
    {
        if (s_atlas != nullptr)
        {
            xatlas::Destroy(s_atlas);
        }
        s_atlas = xatlas::Create();
        s_packOptions.texelsPerUnit = texelDensity;
        s_maxAtlasSize = maxAtlasSize;
    }

    void mu_set_positions(void* position, int itemSize, int itemCount)
    {
        s_meshDesc.vertexPositionData = position;
        s_meshDesc.vertexPositionStride = itemSize * 3;
        s_meshDesc.vertexCount = itemCount / 3;
    }

    void mu_set_indices(void* indicies, int itemSize, int itemCount, bool isUInt32)
    {

    }

    void mu_set_texel_density(float density)
    {

    }

    void mu_build()
    {

    }

    void* mu_get_unwrapped_uvs()
    {
        return nullptr;
    }
}
