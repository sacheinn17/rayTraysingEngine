#include "indexBuffer.hpp"


indexBuffer::indexBuffer(const unsigned int* data,unsigned int count, unsigned int usage)
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(unsigned int),data,usage);
    dataCount = sizeof(data);
}

indexBuffer::~indexBuffer()
{
    glDeleteBuffers(1, &ID);

}

void indexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
}

void indexBuffer::Unbind() const
{ 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void indexBuffer::Delete() const
{
    glDeleteBuffers(1,&ID);
}