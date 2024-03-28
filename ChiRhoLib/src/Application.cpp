#include "pch.h"
#include "Core/Application.h"
#include "Core/Logger.h"
namespace ChiRho
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::s_Instance=nullptr;
//    ImGuiImpl* Application::s_ImGuiImplInstance=nullptr;
    Window* Application::s_Window=nullptr;
    ImGuiLayer* Application::s_Layer=nullptr;
    Application::Application()
    {
        s_Instance = this;
        // log
        CR_CORE_TRACE("TEST INSTANCE");
        // Set up main window
        s_Window = Window::CreatePlatformWindow();
        s_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
        // Add ImGui layers
        s_Layer = new ImGuiLayer();
        // Set up ImGui
        s_Layer->OnAttach();
       // s_ImGuiImplInstance = new ImGuiImpl();
        //s_ImGuiImplInstance->Init();
    }

    Application::~Application()
    {
        CR_CORE_TRACE("TEST EXIT");
        //s_ImGuiImplInstance->Shutdown();
        s_Layer->OnDetach();
    }

    void Application::Run()
    {
        CR_CORE_TRACE("TEST RUN");
        while(m_Running)
        {
            s_Layer->Begin();
            s_Layer->OnImGuiRender();
            s_Layer->End();
            s_Window->OnUpdate();
        }
        //s_ImGuiImplInstance->Render();
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));
        // Send events to layers
        //CR_CORE_TRACE(e);
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e)
    {
        if(e.GetWidth() == 0 | e.GetHeight() == 0)
        {
            m_Minimized = true;
            return false;
        }
        m_Minimized = false;
        // Resize window
        return true;
    }
} // namespace ChiRho
