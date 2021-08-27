workspace "Pio"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Pio/vendor/GLFW/include"
IncludeDir["Glad"] = "Pio/vendor/Glad/include"--I know it includes in the additional directories
IncludeDir["ImGui"] = "Pio/vendor/imgui"--I know it includes in the additional directories

include "Pio/vendor/GLFW"
include "Pio/vendor/Glad"--This includes in the References? No.
include "Pio/vendor/imgui"--This includes in the References? It's responsible to make it appear in the Solutions Explorer.

project "Pio"
	location "Pio"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "piopch.h"
	pchsource "Pio/src/piopch.cpp"
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links{
		"GLFW",--Responsible for making Glad appearing in the Solution Explorer? No. Probably References?
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"PIO_PLATFORM_WINDOWS",
			"PIO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PIO_DEBUG"
		buildoptions "/MDd" -- This is a multi-threaded debug (MDd)
		symbols "On"
	
	filter "configurations:Release"
		defines "PIO_RELEASE"
		buildoptions "/MD" -- This is a multi-threaded DLL (MD)
		symbols "On"

	filter "configurations:Dist"
		defines "PIO_DIST"
		buildoptions "/MD" -- This is a multi-threaded DLL (MD)
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Pio/vendor/spdlog/include",
		"Pio/src"
	}

	links{
		"Pio"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"PIO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PIO_DEBUG"
		buildoptions "/MDd" -- This is a multi-threaded debug (MDd)
		symbols "On"
	
	filter "configurations:Release"
		defines "PIO_RELEASE"
		buildoptions "/MD" -- This is a multi-threaded DLL (MD)
		symbols "On"

	filter "configurations:Dist"
		defines "PIO_DIST"
		buildoptions "/MD" -- This is a multi-threaded DLL (MD)
		symbols "On"