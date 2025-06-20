#pragma once

// Forward Declarations
struct SDL_Window;

namespace Crisp
{
	// Primitive Components
	struct Mesh;
	struct Model;
	struct Material;
	struct Texture;
	struct Shader;

	struct FrameData
	{

	};

	// Renderer System Data
	enum BackendAPI : uint8_t
	{
		VULKAN = 0x01
	};

	struct RendererContext
	{
		BackendAPI api;
	};

	struct RendererSettings
	{
		RendererContext context;
		SDL_Window* window_handle;
		uint32_t w;
		uint32_t h;
		bool is_fullscreen;
	};
}