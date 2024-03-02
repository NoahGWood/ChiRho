#include "pch.h"
#include "Application.h"
#include "Logger.h"

namespace ChiRho
{
    Application* Application::s_Instance=nullptr;
    ImGuiImpl* Application::s_ImGuiImplInstance=nullptr;
    Application::Application()
    {
        s_Instance = this;
        // log
        CR_CORE_TRACE("TEST INSTANCE");
        // Set up ImGui
        s_ImGuiImplInstance = new ImGuiImpl();
        //s_ImGuiImplInstance->Init();
    }

    Application::~Application()
    {
        CR_CORE_TRACE("TEST EXIT");
        s_ImGuiImplInstance->Shutdown();
    }

    void Application::Run()
    {
        CR_CORE_TRACE("TEST RUN");
        s_ImGuiImplInstance->Render();
    }
} // namespace ChiRho
