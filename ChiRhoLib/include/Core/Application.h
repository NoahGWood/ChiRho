#pragma once
#include "Core/Window.h"
#include "UI/ImGuiLayer.h"
//#include <ImGuiImpl.h>

namespace ChiRho
{
    class Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();
            void OnEvent(Event& e);
            //void PushLayer();

            inline static Application& Get() { return *s_Instance; }

            inline Window& GetWindow() { return *s_Window; }
            
        private:
            bool OnWindowClose(WindowCloseEvent& e);
            bool OnWindowResize(WindowResizeEvent& e);

        private:
            static Application* s_Instance;
            static Window* s_Window;
            static ImGuiLayer* s_Layer;
            //static ImGuiImpl* s_ImGuiImplInstance;
            // Stats
            bool m_Running = true;
            bool m_Minimized = false;
    };

    // Defined in client
    Application* CreateApplication();

} // namespace ChiRho
