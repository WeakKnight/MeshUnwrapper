#include <iostream>
#include "xatlas.h"
#include "MeshUnwrapper.h"

xatlas::Atlas* s_atlas = nullptr;
xatlas::PackOptions s_packOptions;
xatlas::MeshDecl s_meshDesc;
uint32_t s_maxAtlasSize;

extern "C"
{
    void mu_init(uint32_t maxAtlasSize, float texelDensity)
    {
        if (s_atlas != nullptr)
        {
            xatlas::Destroy(s_atlas);
            s_atlas = nullptr;
        }
        s_atlas = xatlas::Create();
        s_packOptions.texelsPerUnit = texelDensity;
        s_maxAtlasSize = maxAtlasSize;
    }

    void mu_set_positions(void* position, uint32_t itemSize, uint32_t itemCount)
    {
        s_meshDesc.vertexPositionData = position;
        s_meshDesc.vertexPositionStride = itemSize * 3;
        s_meshDesc.vertexCount = itemCount / 3;
    }

    void mu_set_indices(void* indicies, uint32_t itemSize, uint32_t itemCount)
    {
        s_meshDesc.indexData = indicies;
        s_meshDesc.indexFormat = (itemSize == 2? xatlas::IndexFormat::UInt16: xatlas::IndexFormat::UInt32);
        s_meshDesc.indexCount = itemCount;
    }

    void mu_build()
    {
        xatlas::AddMesh(s_atlas, s_meshDesc);
        xatlas::ComputeCharts(s_atlas);
        xatlas::PackCharts(s_atlas, s_packOptions);
        if (s_atlas->width > s_maxAtlasSize || s_atlas->height > s_maxAtlasSize)
        {
            s_packOptions.texelsPerUnit = 0;
            s_packOptions.resolution = s_maxAtlasSize;
            xatlas::PackCharts(s_atlas, s_packOptions);
        }
    }

    uint32_t mu_get_atlas_width()
    {
        return s_atlas->width;
    }

    uint32_t mu_get_atlas_height()
    {
        return s_atlas->height;
    }

    float mu_get_unwrapped_mesh_u(uint32_t i)
    {
        return s_atlas->meshes[0].vertexArray[i].uv[0] / s_atlas->width;
    }

    float mu_get_unwrapped_mesh_v(uint32_t i)
    {
        return s_atlas->meshes[0].vertexArray[i].uv[0] / s_atlas->height;
    }

    uint32_t mu_get_unwrapped_mesh_original_index(uint32_t i)
    {
        return s_atlas->meshes[0].vertexArray[i].xref;
    }

    uint32_t mu_get_unwrapped_mesh_vertex_count()
    {
        return s_atlas->meshes[0].vertexCount;
    }

    uint32_t mu_get_unwrapped_mesh_index(uint32_t i)
    {
        return s_atlas->meshes[0].indexArray[i];
    }

    uint32_t mu_get_unwrapped_mesh_index_count()
    {
        return s_atlas->meshes[0].indexCount;
    }

    void mu_free()
    {
        xatlas::Destroy(s_atlas);
        s_atlas = nullptr;
    }
}
