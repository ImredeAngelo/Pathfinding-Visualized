#include "VertexArray.h"
#include "Shader.h"

namespace OpenGL {

    /**
     * Only one window will ever be rendered
     */
    class Renderer
    {
    public:
        void draw(const VertexArray* vertexArray, const IndexBuffer* indexBuffer, const Shader* shader) const;
        void clear() const;
        void drawSquare() const;
    };
}

