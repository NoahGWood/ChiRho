#pragma once
#include <ImGuiImpl.h>

namespace ChiRho
{
    class Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();
            //void OnEvent();
            //void PushLayer();

            inline static Application& Get() { return *s_Instance; }
            

        private:
            static Application* s_Instance;
            static ImGuiImpl* s_ImGuiImplInstance;
    };

    // Defined in client
    Application* CreateApplication();

} // namespace ChiRho
