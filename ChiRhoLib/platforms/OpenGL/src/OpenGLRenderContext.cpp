#include "pch.h"
#include "OpenGL/include/OpenGLRenderContext.h"

#include <glad/glad.h>
#include "GLFW/glfw3.h"

namespace ChiRho
{
    OpenGLRenderContext::OpenGLRenderContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        CR_CORE_ASSERT(windowHandle, "Window handle is null!");
    }
    void OpenGLRenderContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        // Setup Glad
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        CR_CORE_ASSERT(status, "Failed to initialize glad.");
        char* vendor = (char*)glGetString(GL_VENDOR);
        char* renderer = (char*)glGetString(GL_RENDERER);
        char* version = (char*)glGetString(GL_VERSION);
        CR_CORE_INFO("OpenGL Info:");
        CR_CORE_INFO("  Vendor: {0}", vendor);
        CR_CORE_INFO("  Renderer: {0}", renderer);
        CR_CORE_INFO("  Version: {0}", (char*)glGetString(GL_VERSION));
        #ifdef VM_ENABLE_ASSERTS
            int versionMajor;
            int versionMinor;
    		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
    		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);
    		CR_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "VersaMachina requires at least OpenGL version 4.5!");
        #endif     
    }
    void OpenGLRenderContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }    
} // namespace ChiRho