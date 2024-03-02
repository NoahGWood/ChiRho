#pragma once

#include "Window.h"

struct GLFWwindow; // Forward declaration to avoid including glfw3.h

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

        inline void SetEventCallback() override { }
        void SetVSync(bool enabled);
        
        inline virtual void* GetNativeWindow() const { return m_Window; }
    private:
    // Private Methods
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    // Private Attributes
        GLFWwindow* m_Window;
    
       struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            // Callback
        };
        WindowData m_Data;
    };
    
    
} // namespace ChiRho
