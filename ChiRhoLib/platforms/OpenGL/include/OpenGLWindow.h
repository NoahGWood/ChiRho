#pragma once
#include "Core/Base.h"
#include "Core/Window.h"
#include "OpenGL/include/OpenGLRenderContext.h"

#include <GLFW/glfw3.h>
//struct GLFWwindow; // Forward declaration to avoid including glfw3.h
//struct GLFWimage;

namespace ChiRho
{
    class OpenGLWindow : public Window
    {
    
    public:
        OpenGLWindow(const WindowProps& props);
        virtual ~OpenGLWindow();
        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled);
        
        inline virtual void* GetNativeWindow() const { return m_Window; }
    private:
    // Private Methods
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    // Private Attributes
        GLFWwindow* m_Window;
        Scope<OpenGLRenderContext> m_Context;

       struct WindowData
        {
            std::string Title;
            std::string IconFile;
            GLFWimage Icons[1];
            unsigned int Width, Height;
            EventCallbackFn EventCallback;
        };
        WindowData m_Data;
    };
    
    
} // namespace ChiRho
