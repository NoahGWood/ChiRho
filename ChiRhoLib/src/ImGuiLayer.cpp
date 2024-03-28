#include "pch.h"
#include "UI/ImGuiLayer.h"
#include "Core/Application.h"
#include <imgui.h>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h>
namespace ChiRho {
    ImGuiLayer::ImGuiLayer()
    {

    }
    ImGuiLayer::~ImGuiLayer()
    {

    }
    void ImGuiLayer::OnAttach()
    {
        // Setup DearImGui context
        IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;
        io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;
        //io.Fonts->AddFontFromFileTTF("VersaEditor/assets/fonts/OpenSans/static/OpenSans-Bold.ttf", 18.0f);
        //io.FontDefault = io.Fonts->AddFontFromFileTTF("VersaEditor/assets/fonts/OpenSans/static/OpenSans-Regular.ttf", 18.0f);

    	// Setup Dear ImGui style
    	ImGui::StyleColorsDark();
    	//ImGui::StyleColorsClassic();


        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

        io.ConfigViewportsNoDecoration = false; // False - Allow secondary windows

 		Application& app = Application::Get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());
  		// Setup Platform/Renderer bindings
   		ImGui_ImplGlfw_InitForOpenGL(window, true);
   		ImGui_ImplOpenGL3_Init("#version 410");
    }
    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
    void ImGuiLayer::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        // Begin docking space
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    }
    void ImGuiLayer::End()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        int display_w = app.GetWindow().GetWidth();
        int display_h = app.GetWindow().GetHeight();
        io.DisplaySize = ImVec2(display_w, display_h);
        ImGui::Render();
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        glViewport(0,0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        if(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
    		ImGui::UpdatePlatformWindows();
    		ImGui::RenderPlatformWindowsDefault();
    		glfwMakeContextCurrent(backup_current_context);
        }
    }
    void ImGuiLayer::OnImGuiRender() {
        ImGui::Begin("TEST");
        ImGui::End();
            ImGui::ShowDemoWindow();
    }
    void ImGuiLayer::OnEvent(Event& e)
    {
        if(m_blockEvents)
        {
                ImGuiIO& io = ImGui::GetIO();
    			e.m_Handled |= e.IsInCategory(EventCategoryMouse) & io.WantCaptureMouse;
    			e.m_Handled |= e.IsInCategory(EventCategoryKeyboard) & io.WantCaptureKeyboard;
        }
    }
} // namespace ChiRho