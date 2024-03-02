project "ChiRhoTest"
    location "ChiRhoTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++2a"
    staticruntime "off"
    systemversion "latest"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{wks.location}/ChiRhoTest/src/**.h",
        "%{wks.location}/ChiRhoTest/src/**.cpp",
        "%{wks.location}/ChiRhoTest/src/*/**.h",
        "%{wks.location}/ChiRhoTest/src/*/**.cpp",
    }

    includedirs
    {
        "include",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.ImGUI}",
        "%{wks.location}/ChiRhoLib/include",
    }

    links
    {
        "ChiRhoLib",
        "ImGui",
        "glfw",
        "GL",
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