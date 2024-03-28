#pragma once
#include "Core/Base.h"
#include "Events/Event.h"

namespace ChiRho
{
    struct WindowProps
    {
        /* data */
        std::string Title;
        std::string IconPath;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string& title="ChiRho",
            const std::string& icon="ChiRhoTest/assets/icon.png",
            uint32_t width=1280,
            uint32_t height=720)
            : Title(title), IconPath(icon), Width(width), Height(height) {}
    };

    class Window
    {
    public:
        virtual ~Window() = default;
        virtual void OnUpdate() = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        // Window Attributes
        using EventCallbackFn = std::function<void(Event&)>;
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual void* GetNativeWindow() const = 0;

        static Window* CreatePlatformWindow(const WindowProps& props = WindowProps());
    };

} // namespace ChiRho
