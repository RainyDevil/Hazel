workspace "Hazel"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Hazel"
    location "Hazel"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outdir .. "/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "Hazel/src/hzpch.cpp"

    files 
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h",
    }

    includedirs 
    {
        "%{prj.name}/src",
        "%{prj.name}/vender/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "HAZEL_PLATFORM_WINDOWS",
            "HAZEL_BUILD_DLL"
        }
        
        postbuildcommands 
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "HAZEL_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "HAZEL_RELEASE"
        optimize "On"    
    filter "configurations:Dist"
        defines "HAZEL_DEBUG"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h",
    }

    includedirs 
    {
        "Hazel/vender/spdlog/include",
        "Hazel/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "HAZEL_PLATFORM_WINDOWS",
        }
        
        links "Hazel"

    filter "configurations:Debug"
        defines "HAZEL_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "HAZEL_RELEASE"
        optimize "On"    
    filter "configurations:Dist"
        defines "HAZEL_DEBUG"
        optimize "On"