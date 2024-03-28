#include "Core/Window.h"
#include "OpenGL/include/OpenGLWindow.h"

ChiRho::Window* ChiRho::Window::CreatePlatformWindow(const WindowProps& props)
{
    return new OpenGLWindow(props);
}
