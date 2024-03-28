#pragma once
#include <GLFW/glfw3.h>

namespace ChiRho
{
    class ImGuiImpl
    {
    private:
        /* data */
        GLFWwindow* m_Window;
    public:
        ImGuiImpl(/* args */) { Init(); }
        ~ImGuiImpl() { Shutdown(); }
        void Init();
        void Shutdown();
        void Render();
        bool enableTest = true;
    };
    static void glfw_error_callback(int error, const char* description);
} // namespace ChiRho
