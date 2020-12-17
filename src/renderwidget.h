#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QVector3D>
#include <QMatrix4x4>

#include <vector>

#include "glm/glm.hpp"
#include "mesh/mesh.h"

class RenderWidget
        : public QOpenGLWidget
        , protected QOpenGLExtraFunctions
{
public:
    RenderWidget(QWidget* parent);
    virtual ~RenderWidget();

private:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int w, int h);

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);

    glm::vec3 eye;
    glm::vec3 center;
    glm::vec3 up;

    Mesh mesh;

    // Arcball
    int radius;
    glm::ivec2 sphereCenter;
    glm::ivec2 oldPoint;
    bool moving;

    void initializeArcball();
    glm::quat pointToQuat(glm::ivec2 screenPoint);
    void rotate(glm::ivec2 p1, glm::ivec2 p2);

    void createMesh();
    void updateMesh();
    void createCube();
    void createSphere();
    void createVBO();
    void createTexture(const std::string& imagePath);

    QOpenGLShaderProgram program;

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    std::vector< glm::vec3 > vertices;
    std::vector< glm::vec3 > normals;
    std::vector< glm::vec2 > texCoords;
    std::vector< unsigned int > indices;

    glm::mat4x4 model;
    glm::mat4x4 view;
    glm::mat4x4 proj;

    unsigned int textureID;
};

#endif // RENDERWIDGET_H
