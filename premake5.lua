workspace "ChiRho"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "depends"
    include "vendor/glad"
    include "vendor/imgui"

group ""

include "ChiRhoLib"
include "ChiRhoTest"
include "ChiRhoPi"