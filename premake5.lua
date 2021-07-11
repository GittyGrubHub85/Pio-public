workspace "Pio"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pio"
	location "Pio"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
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