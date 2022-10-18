
void AllocateTriangle(Mesh *mesh) {
    mesh->vertCount = 3;
    
    mesh->data = (void *)malloc(sizeof(vec3) * mesh->vertCount);
    mesh->size = sizeof(vec3) * mesh->vertCount;
    
    mesh->verts = (vec3 *)mesh->data;

    mesh->verts[0] = V3(-1.0f, -1.0f, 0.0f);
    mesh->verts[1] = V3(1.0f, -1.0f, 0.0f);
    mesh->verts[2] = V3(0.0f, 1.0f, 0.0f);

    mesh->indexCount = 3;

    mesh->indices = (uint32 *)malloc(sizeof(uint32) * mesh->indexCount);

    // Counter clockwise
    mesh->indices[0] = 0;
    mesh->indices[1] = 1;
    mesh->indices[2] = 2;
}


void AllocateSegmentedQuad(Mesh* mesh, int32 numOfSegments) {
    int32 segmentCount = numOfSegments + 1;

    mesh->vertCount = segmentCount * segmentCount;
    mesh->texcoordsCount = segmentCount * segmentCount;

    mesh->data = (void *)malloc((sizeof(vec3) * mesh->vertCount) +
                                (sizeof(vec2) * mesh->texcoordsCount));

    mesh->size = (sizeof(vec3) * mesh->vertCount) + (sizeof(vec2) * mesh->texcoordsCount);

    mesh->verts = (vec3*)mesh->data;

    int32 vertLoopCount = 0;
    for (int i = 0; i < segmentCount; i++) {
        for (int j = 0; j < segmentCount; j++) {
            real32 x = (j / segmentCount) - 1.0f;
            real32 y = (i / segmentCount) - 1.0f;
            real32 z = 0.0f;
            mesh->verts[vertLoopCount] = V3(x, y, z);
            vertLoopCount++;
        }
    }

    int32 texcoordsLoopCount = 0;
    for (int i = 0; i < segmentCount; i++) {
        for (int j = 0; j < segmentCount; j++) {
            real32 x = j / segmentCount;
            real32 y = i / segmentCount;
            mesh->texcoords[texcoordsLoopCount] = V2(x, y);
            texcoordsLoopCount++;
        }
    }

    mesh->indexCount = segmentCount * segmentCount * 6;
    mesh->indices = (uint32*)malloc(sizeof(uint32) * mesh->indexCount);
    
    int32 count = 0;
    for (int i = 0; i < segmentCount; i++) {
        for (int j = 1; j < segmentCount; j++) {
            mesh->indices[count] = (i * segmentCount) + j;
            count++;
            mesh->indices[count] = (i * segmentCount) + j + 1;
            count++;
            mesh->indices[count] = ((i + 1) * segmentCount) + j + 1;
            count++;
            mesh->indices[count] = (i * segmentCount) + j;
            count++;
            mesh->indices[count] = ((i + 1) * segmentCount) + j + 1;
            count++;
            mesh->indices[count] = ((i + 1) * segmentCount) + j;
            count++;
        }
    }
}


void AllocateQuad(Mesh *mesh) {
    mesh->vertCount = 4;
    mesh->texcoordsCount = 4;

    mesh->data = (void *)malloc((sizeof(vec3) * mesh->vertCount) +
                                (sizeof(vec2) * mesh->texcoordsCount));
    mesh->size = (sizeof(vec3) * mesh->vertCount) + (sizeof(vec2) * mesh->texcoordsCount);
    
    
    mesh->verts = (vec3 *)mesh->data;

    mesh->verts[0] = V3(-1.0f, 1.0f, 0.0f);
    mesh->verts[1] = V3(1.0f, 1.0f, 0.0f);
    mesh->verts[2] = V3(1.0f, -1.0f, 0.0f);
    mesh->verts[3] = V3(-1.0f, -1.0f, 0.0f);

#if 1
    mesh->texcoords = (vec2 *)((uint8 *)mesh->data + (sizeof(vec3) * mesh->vertCount));

    mesh->texcoords[0] = V2(0, 0);
    mesh->texcoords[1] = V2(1, 0);
    mesh->texcoords[2] = V2(1, 1);
    mesh->texcoords[3] = V2(0, 1);
#endif

    mesh->indexCount = 6;

    mesh->indices = (uint32 *)malloc(sizeof(uint32) * mesh->indexCount);

    // Counter clockwise
    mesh->indices[0] = 0;
    mesh->indices[1] = 1;
    mesh->indices[2] = 2;

    mesh->indices[3] = 0;
    mesh->indices[4] = 2;
    mesh->indices[5] = 3;
}

void AllocateSegmentedQuadTopLeft(Mesh* mesh, int32 numOfSegments) {
    int32 segmentCount = numOfSegments + 1;

    mesh->vertCount = segmentCount * segmentCount;
    mesh->texcoordsCount = segmentCount * segmentCount;

    mesh->data = (void*)malloc((sizeof(vec3) * mesh->vertCount) +
        (sizeof(vec2) * mesh->texcoordsCount));

    mesh->size = (sizeof(vec3) * mesh->vertCount) + (sizeof(vec2) * mesh->texcoordsCount);

    mesh->verts = (vec3*)mesh->data;

    int32 vertLoopCount = 0;
    for (int i = 0; i < segmentCount; i++)
    {
        for (int j = 0; j < segmentCount; j++)
        {
            real32 x= (j / numOfSegments);
            real32 y= (-i / numOfSegments);
            real32 z = 0.0f;
            mesh->verts[vertLoopCount] = V3(x, y, z);
            vertLoopCount++;
        }
    }

#if 1
    int32 texcoordsLoopCount = 0;
    mesh->texcoords = (vec2*)((uint8*)mesh->data + (sizeof(vec3) * mesh->vertCount));
    for (int i = 0; i < segmentCount; i++)
    {
        for (int j = 0; j < segmentCount; j++)
        {
            real32 x = (j / numOfSegments);
            real32 y = (i / numOfSegments);
            mesh->texcoords[texcoordsLoopCount] = V2(x, y);
            texcoordsLoopCount++;
        }
    }
#endif

    mesh->indexCount = numOfSegments * numOfSegments * 6;

    mesh->indices = (uint32*)malloc(sizeof(uint32) * mesh->indexCount);

    int32 count = 0;
    for (int i = 0; i < numOfSegments; i++)
    {
        for (int j = 0; j < numOfSegments; j++)
        {
            /*mesh->indices[count] = 0;
            count++;
            mesh->indices[count] = 1;
            count++;
            mesh->indices[count] = 1;
            count++;
            mesh->indices[count] = 0;
            count++;
            mesh->indices[count] = 2;
            count++;
            mesh->indices[count] = 2;
            count++;*/
            mesh->indices[count] = (i * numOfSegments) + j;
            count++;
            mesh->indices[count] = (i * numOfSegments) + j + 1;
            count++;
            mesh->indices[count] = ((i + 1) * numOfSegments) + j + 2;
            count++;
            mesh->indices[count] = (i * numOfSegments) + j;
            count++;
            mesh->indices[count] = ((i + 1) * numOfSegments) + j + 1;
            count++;
            mesh->indices[count] = ((i + 1) * numOfSegments) + j + 2;
            count++;
            
        }
    }


}

void AllocateQuadTopLeft(Mesh *mesh) {
    mesh->vertCount = 4;
    mesh->texcoordsCount = 4;

    mesh->data = (void *)malloc((sizeof(vec3) * mesh->vertCount) +
                                (sizeof(vec2) * mesh->texcoordsCount));
    mesh->size = (sizeof(vec3) * mesh->vertCount) + (sizeof(vec2) * mesh->texcoordsCount);
    
    
    mesh->verts = (vec3 *)mesh->data;

    mesh->verts[0] = V3(0, 0, 0);
    mesh->verts[1] = V3(1.0f, 0.0f, 0.0f);
    mesh->verts[2] = V3(1.0f, -1.0f, 0.0f);
    mesh->verts[3] = V3(0.0f, -1.0f, 0.0f);

#if 1
    mesh->texcoords = (vec2 *)((uint8 *)mesh->data + (sizeof(vec3) * mesh->vertCount));

    mesh->texcoords[0] = V2(0, 0);
    mesh->texcoords[1] = V2(1, 0);
    mesh->texcoords[2] = V2(1, 1);
    mesh->texcoords[3] = V2(0, 1);
#endif    

    mesh->indexCount = 6;

    mesh->indices = (uint32 *)malloc(sizeof(uint32) * mesh->indexCount);

    // Counter clockwise
    mesh->indices[0] = 0;
    mesh->indices[1] = 1;
    mesh->indices[2] = 2;

    mesh->indices[3] = 0;
    mesh->indices[4] = 2;
    mesh->indices[5] = 3;
}

void AllocateGlyphQuad(Mesh *mesh) {
    mesh->vertCount = 4;
    mesh->texcoordsCount = 4;

    mesh->data = (void *)malloc((sizeof(vec3) * mesh->vertCount) +
                                (sizeof(vec2) * mesh->texcoordsCount));
    mesh->size = (sizeof(vec3) * mesh->vertCount) + (sizeof(vec2) * mesh->texcoordsCount);
    
    
    mesh->verts = (vec3 *)mesh->data;

    mesh->verts[0] = V3(0, 0, 0.0f);
    mesh->verts[1] = V3(1.0f, 0.0f, 0.0f);
    mesh->verts[2] = V3(1.0f, 1.0f, 0.0f);
    mesh->verts[3] = V3(0.0f, 1.0f, 0.0f);
    

#if 1
    mesh->texcoords = (vec2 *)((uint8 *)mesh->data + (sizeof(vec3) * mesh->vertCount));

    mesh->texcoords[0] = V2(0, 0);
    mesh->texcoords[1] = V2(1, 0);
    mesh->texcoords[2] = V2(1, 1);
    mesh->texcoords[3] = V2(0, 1);
#endif    

    mesh->indexCount = 6;

    mesh->indices = (uint32 *)malloc(sizeof(uint32) * mesh->indexCount);

    // Counter clockwise
    mesh->indices[0] = 0;
    mesh->indices[1] = 1;
    mesh->indices[2] = 2;

    mesh->indices[3] = 0;
    mesh->indices[4] = 2;
    mesh->indices[5] = 3;
}


void AllocateCube(Mesh *mesh) {
    uint32 vertexSize = sizeof(vec3) * sizeof(vec3) + sizeof(vec2);

    // @NOTE: we're duplicating vertices
    mesh->vertCount = 24;
    mesh->size = vertexSize * mesh->vertCount;
    mesh->data = malloc(mesh->size);

    mesh->verts = (vec3 *)(mesh->data);
    mesh->normals = (vec3 *)((uint8 *)mesh->data + sizeof(vec3) * mesh->vertCount);
    mesh->texcoords = (vec2 *)((uint8 *)mesh->data + (sizeof(vec3) + sizeof(vec3)) * mesh->vertCount);

    mesh->indexCount = 36;
    mesh->indices = (uint32 *)malloc(sizeof(uint32) * mesh->indexCount);

    // @NOTE: all triangles are counter-clockwise from the outside

    uint32 vertexOffset = 0;
    uint32 indexOffset = 0;
        
    // Pos X
    {
        vec3 normal = V3(1, 0, 0);

        mesh->verts[vertexOffset + 0] = V3( 1.0f, -1.0f,  -1.0f);
        mesh->verts[vertexOffset + 1] = V3( 1.0f, -1.0f, 1.0f);
        mesh->verts[vertexOffset + 2] = V3( 1.0f,  1.0f, 1.0f);
        mesh->verts[vertexOffset + 3] = V3( 1.0f,  1.0f,  -1.0f);

        mesh->normals[vertexOffset + 0] = normal;
        mesh->normals[vertexOffset + 1] = normal;
        mesh->normals[vertexOffset + 2] = normal;
        mesh->normals[vertexOffset + 3] = normal;

        mesh->texcoords[vertexOffset + 0] = V2(1, 0);
        mesh->texcoords[vertexOffset + 1] = V2(0, 0);
        mesh->texcoords[vertexOffset + 2] = V2(0, 1);
        mesh->texcoords[vertexOffset + 3] = V2(1, 1);

        mesh->indices[indexOffset + 0] = vertexOffset + 0;
        mesh->indices[indexOffset + 1] = vertexOffset + 1;
        mesh->indices[indexOffset + 2] = vertexOffset + 2;

        mesh->indices[indexOffset + 3] = vertexOffset + 0;
        mesh->indices[indexOffset + 4] = vertexOffset + 2;
        mesh->indices[indexOffset + 5] = vertexOffset + 3;
    }

    vertexOffset += 4;
    indexOffset += 6;

    // Pos Z
    {
        vec3 normal = -V3(0, 0, 1);

        mesh->verts[vertexOffset + 0] = V3( 1.0f, -1.0f, 1.0f);
        mesh->verts[vertexOffset + 1] = V3(-1.0f, -1.0f, 1.0f);
        mesh->verts[vertexOffset + 2] = V3(-1.0f,  1.0f, 1.0f);
        mesh->verts[vertexOffset + 3] = V3( 1.0f,  1.0f, 1.0f);

        mesh->normals[vertexOffset + 0] = normal;
        mesh->normals[vertexOffset + 1] = normal;
        mesh->normals[vertexOffset + 2] = normal;
        mesh->normals[vertexOffset + 3] = normal;

        mesh->texcoords[vertexOffset + 0] = V2(1, 0);
        mesh->texcoords[vertexOffset + 1] = V2(0, 0);
        mesh->texcoords[vertexOffset + 2] = V2(0, 1);
        mesh->texcoords[vertexOffset + 3] = V2(1, 1);

        mesh->indices[indexOffset + 0] = vertexOffset + 0;
        mesh->indices[indexOffset + 1] = vertexOffset + 1;
        mesh->indices[indexOffset + 2] = vertexOffset + 2;

        mesh->indices[indexOffset + 3] = vertexOffset + 0;
        mesh->indices[indexOffset + 4] = vertexOffset + 2;
        mesh->indices[indexOffset + 5] = vertexOffset + 3;
    }

    vertexOffset += 4;
    indexOffset += 6;

    // Neg X
    {
        vec3 normal = V3(-1, 0, 0);

        mesh->verts[vertexOffset + 0] = V3(-1.0f, -1.0f,  1.0f);
        mesh->verts[vertexOffset + 1] = V3(-1.0f, -1.0f, -1.0f);
        mesh->verts[vertexOffset + 2] = V3(-1.0f,  1.0f, -1.0f);
        mesh->verts[vertexOffset + 3] = V3(-1.0f,  1.0f,  1.0f);

        mesh->normals[vertexOffset + 0] = normal;
        mesh->normals[vertexOffset + 1] = normal;
        mesh->normals[vertexOffset + 2] = normal;
        mesh->normals[vertexOffset + 3] = normal;

        mesh->texcoords[vertexOffset + 0] = V2(1, 0);
        mesh->texcoords[vertexOffset + 1] = V2(0, 0);
        mesh->texcoords[vertexOffset + 2] = V2(0, 1);
        mesh->texcoords[vertexOffset + 3] = V2(1, 1);

        mesh->indices[indexOffset + 0] = vertexOffset + 0;
        mesh->indices[indexOffset + 1] = vertexOffset + 1;
        mesh->indices[indexOffset + 2] = vertexOffset + 2;

        mesh->indices[indexOffset + 3] = vertexOffset + 0;
        mesh->indices[indexOffset + 4] = vertexOffset + 2;
        mesh->indices[indexOffset + 5] = vertexOffset + 3;
    }

    vertexOffset += 4;
    indexOffset += 6;

    // Neg Z
    {
        vec3 normal = -V3(0, 0, -1);

        mesh->verts[vertexOffset + 0] = V3(-1.0f, -1.0f, -1.0f);
        mesh->verts[vertexOffset + 1] = V3( 1.0f, -1.0f, -1.0f);
        mesh->verts[vertexOffset + 2] = V3( 1.0f,  1.0f, -1.0f);
        mesh->verts[vertexOffset + 3] = V3(-1.0f,  1.0f, -1.0f);

        mesh->normals[vertexOffset + 0] = normal;
        mesh->normals[vertexOffset + 1] = normal;
        mesh->normals[vertexOffset + 2] = normal;
        mesh->normals[vertexOffset + 3] = normal;

        mesh->texcoords[vertexOffset + 0] = V2(1, 0);
        mesh->texcoords[vertexOffset + 1] = V2(0, 0);
        mesh->texcoords[vertexOffset + 2] = V2(0, 1);
        mesh->texcoords[vertexOffset + 3] = V2(1, 1);

        mesh->indices[indexOffset + 0] = vertexOffset + 0;
        mesh->indices[indexOffset + 1] = vertexOffset + 1;
        mesh->indices[indexOffset + 2] = vertexOffset + 2;

        mesh->indices[indexOffset + 3] = vertexOffset + 0;
        mesh->indices[indexOffset + 4] = vertexOffset + 2;
        mesh->indices[indexOffset + 5] = vertexOffset + 3;
    }

    vertexOffset += 4;
    indexOffset += 6;

    // Pos Y
    {
        vec3 normal = -V3(0, 1, 0);

        mesh->verts[vertexOffset + 0] = V3(-1.0f,  1.0f,  -1.0f);
        mesh->verts[vertexOffset + 1] = V3( 1.0f,  1.0f,  -1.0f);
        mesh->verts[vertexOffset + 2] = V3( 1.0f,  1.0f, 1.0f);
        mesh->verts[vertexOffset + 3] = V3(-1.0f,  1.0f, 1.0f);

        mesh->normals[vertexOffset + 0] = normal;
        mesh->normals[vertexOffset + 1] = normal;
        mesh->normals[vertexOffset + 2] = normal;
        mesh->normals[vertexOffset + 3] = normal;

        mesh->texcoords[vertexOffset + 0] = V2(1, 0);
        mesh->texcoords[vertexOffset + 1] = V2(0, 0);
        mesh->texcoords[vertexOffset + 2] = V2(0, 1);
        mesh->texcoords[vertexOffset + 3] = V2(1, 1);

        mesh->indices[indexOffset + 0] = vertexOffset + 0;
        mesh->indices[indexOffset + 1] = vertexOffset + 1;
        mesh->indices[indexOffset + 2] = vertexOffset + 2;

        mesh->indices[indexOffset + 3] = vertexOffset + 0;
        mesh->indices[indexOffset + 4] = vertexOffset + 2;
        mesh->indices[indexOffset + 5] = vertexOffset + 3;
    }

    vertexOffset += 4;
    indexOffset += 6;

    // Neg Y
    {
        vec3 normal = -V3(0, -1, 0);

        mesh->verts[vertexOffset + 0] = V3(-1.0f, -1.0f, 1.0f);
        mesh->verts[vertexOffset + 1] = V3( 1.0f, -1.0f, 1.0f);
        mesh->verts[vertexOffset + 2] = V3( 1.0f, -1.0f,  -1.0f);
        mesh->verts[vertexOffset + 3] = V3(-1.0f, -1.0f,  -1.0f);

        mesh->normals[vertexOffset + 0] = normal;
        mesh->normals[vertexOffset + 1] = normal;
        mesh->normals[vertexOffset + 2] = normal;
        mesh->normals[vertexOffset + 3] = normal;

        mesh->texcoords[vertexOffset + 0] = V2(1, 0);
        mesh->texcoords[vertexOffset + 1] = V2(0, 0);
        mesh->texcoords[vertexOffset + 2] = V2(0, 1);
        mesh->texcoords[vertexOffset + 3] = V2(1, 1);

        mesh->indices[indexOffset + 0] = vertexOffset + 0;
        mesh->indices[indexOffset + 1] = vertexOffset + 1;
        mesh->indices[indexOffset + 2] = vertexOffset + 2;

        mesh->indices[indexOffset + 3] = vertexOffset + 0;
        mesh->indices[indexOffset + 4] = vertexOffset + 2;
        mesh->indices[indexOffset + 5] = vertexOffset + 3;
    }

    vertexOffset += 4;
    indexOffset += 6;
}
