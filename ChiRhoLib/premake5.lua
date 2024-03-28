project "ChiRhoLib"
    location "ChiRhoLib"
    kind "StaticLib"
    language "C++"
    cppdialect "C++2a"
    staticruntime "off"
    systemversion "latest"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "ChiRhoLib/src/pch.cpp"

    files
    {
        "%{wks.location}/ChiRhoLib/src/**.h",
        "%{wks.location}/ChiRhoLib/src/**.cpp",
        "%{wks.location}/ChiRhoLib/platforms/**.h",
        "%{wks.location}/ChiRhoLib/platforms/**.cpp",
        "%{wks.location}/vendor/stb_image/**.h",
        "%{wks.location}/vendor/stb_image/**.cpp",
--		"%{wks.location}/vendor/imgui/backends/imgui_impl_glfw.h",
--		"%{wks.location}/vendor/imgui/backends/imgui_impl_opengl3.h"
    }

    includedirs
    {
        "include",
        "platforms/",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.ImGUI}",
        "%{IncludeDir.stb_image}",
    }
    links
    {
        "glfw",
        "Glad",
        "GL",
        "ImGui",
    }

    filter "system:windows"
        defines
        {
            "CR_PLATFORM_WINDOWS"
        }
    filter "system:linux"
        defines
        {
            "CR_PLATFORM_LINUX"
        }
    filter "configurations:Debug"
        defines "CR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CR_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "CR_DIST"
        optimize "On"