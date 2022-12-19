#include "shaderClass.hpp"

shaderProgram::shaderProgram(const char* vertexPath,const char* fragmentPath)
{
    unsigned int v,f;
    int success;
    char infoLog[512];

    std::string line,text;
    std::ifstream in (vertexPath);
    while(std::getline(in, line))
    {
       text += line + "\n";
    }
   const char* vertexCode = text.c_str();

    v = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v,1,&vertexCode,NULL);
    glCompileShader(v);
    glGetShaderiv(v, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(v, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    };

    

    text = "";
    line = "";

    std::ifstream ino(fragmentPath);
    while(std::getline(ino, line))
    {
       text += line + "\n";
    }
    const char* fragmentCode = text.c_str();

    f = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f,1,&fragmentCode,NULL);
    glCompileShader(f);
    glGetShaderiv(f, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(v, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    };

    shaderID = glCreateProgram();
    glAttachShader(shaderID,v);
    glAttachShader(shaderID,f);
    glLinkProgram(shaderID);

    glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
if(!success)
{
glGetProgramInfoLog(shaderID, 512, NULL, infoLog);
std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<
infoLog << std::endl;
}


}

void shaderProgram::use() const
{
    glUseProgram(shaderID);
}

void shaderProgram::setfloat1(const char* uniformName, float someName)
{
    glUniform1f(glGetUniformLocation(shaderID,uniformName),someName);    
}

void shaderProgram::setfloat2(const char* uniformName, float someName[])
{
    glUniform2f(glGetUniformLocation(shaderID,uniformName),someName[0],someName[1]);
}

void shaderProgram::setfloat3(const char* uniformName, float someName[])
{
    glUniform3f(glGetUniformLocation(shaderID,uniformName),someName[0],someName[1],someName[2]);
}

void shaderProgram::setfloat4(const char* uniformName, float someName[])
{
    glUniform4f(glGetUniformLocation(shaderID,uniformName),someName[0],someName[1],someName[2],someName[3]);
}

