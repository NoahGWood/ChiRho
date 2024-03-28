#include "pch.h"
#include "Core/Base.h"
#include "OpenGL/include/OpenGLWindow.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>

namespace ChiRho
{

    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        CR_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    OpenGLWindow::OpenGLWindow(const WindowProps& props)
    {
        Init(props);
    }

    OpenGLWindow::~OpenGLWindow()
    {
        Shutdown();
    }

    void OpenGLWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.IconFile = props.IconPath;
        // Load icon file
        m_Data.Icons[0].pixels = stbi_load(props.IconPath.c_str(), &m_Data.Icons[0].width, &m_Data.Icons[0].height, 0, 4);
        if(m_Data.Icons[0].pixels == NULL)
        {
            CR_CORE_CRITICAL("Icon cannot be loaded at {0}", props.IconPath);
        } else {
            CR_CORE_CRITICAL("Icon was loaded at {0}", props.IconPath);
        }
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        CR_CORE_INFO("Creating window {0} with icon {1} ({2}, {3})", props.Title, props.IconPath, props.Width, props.Height);

        if(!s_GLFWInitialized)
        {
            int success = glfwInit();
            CR_CORE_ASSERT(success, "Could not initialize GLFW!");
            // Set error callback
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        // Setup window
        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwSetWindowIcon(m_Window, 1, m_Data.Icons);
        m_Context = CreateScope<OpenGLRenderContext>(m_Window);
        m_Context->Init();
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowResizeEvent event(width, height);
            data.Width = width;
            data.Height = height;
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, true);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y )
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float)x, (float)y);
            data.EventCallback(event);
        });
    }

    void OpenGLWindow::Shutdown()
    {
        stbi_image_free(m_Data.Icons[0].pixels);
        glfwDestroyWindow(m_Window);
    }

    void OpenGLWindow::OnUpdate()
    {
        
        if(!glfwWindowShouldClose(m_Window))
        {
            glfwPollEvents();
            m_Context->SwapBuffers();
            // Make sure icon isn't changed when windows are popped out
            glfwSetWindowIcon(m_Window, 1, m_Data.Icons);
        }
    }

    void OpenGLWindow::SetVSync(bool enabled)
    {
        
        if(enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
    }
} // namespace ChiRho

