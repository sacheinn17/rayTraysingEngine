#pragma once

#include "vertexArray.hpp"
#include "indexBuffer.hpp"
#include "shaderClass.hpp"

class renderer
{

public:
    void clear(float red,float green,float blue,float alpha);
    void draw(unsigned int MODE,const vertexArray &va, const indexBuffer &ib, const shaderProgram &shader) const;
};