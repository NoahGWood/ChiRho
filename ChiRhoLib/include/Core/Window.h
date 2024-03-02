#pragma once
#include "Base.h"

namespace ChiRho
{
    struct WindowProps
    {
        /* data */
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string& title="ChiRho",
            uint32_t width=1280,
            uint32_t height=720)
            : Title(title), Width(width), Height(height) {}
    };

    class Window
    {
    public:
        virtual ~Window() = default;
        virtual void OnUpdate() = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        // Window Attributes
        virtual void SetEventCallback() = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
    
} // namespace ChiRho
