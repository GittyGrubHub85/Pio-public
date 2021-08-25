workspace "Pio"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {} -- I don't know what this is...
IncludeDir["GLFW"] = "Pio/vendor/GLFW/include" -- it includes in the additional Include directories

include "Pio/vendor/GLFW" --what does this thing do?

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
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"PIO_PLATFORM_WINDOWS",
			"PIO_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PIO_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "PIO_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "PIO_DIST"
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
		symbols "On"
	
	filter "configurations:Release"
		defines "PIO_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "PIO_DIST"
		symbols "On"