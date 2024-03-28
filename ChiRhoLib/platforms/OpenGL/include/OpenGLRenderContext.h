#pragma once

class GLFWwindow;

namespace ChiRho
{
        class OpenGLRenderContext
        {
            public:
                OpenGLRenderContext(GLFWwindow* windowHandle);
                virtual void Init();
                virtual void SwapBuffers();
            private:
                GLFWwindow* m_WindowHandle;

        };
    
} // namespace ChiRho