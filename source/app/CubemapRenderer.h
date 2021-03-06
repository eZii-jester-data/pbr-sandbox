#pragma once

#include "Mesh.h"
#include <render/backend/driver.h>

class Shader;
class Texture;

/*
 */
class CubemapRenderer
{
public:
	CubemapRenderer(render::backend::Driver *driver);

	void init(
		const Texture *target_texture,
		uint32_t target_mip
	);

	void shutdown();

	void render(
		const Shader *vertex_shader,
		const Shader *fragment_shader,
		const Texture *input_texture,
		uint8_t push_constants_size = 0,
		const uint8_t *push_constants_data = nullptr
	);

private:
	render::backend::Driver *driver {nullptr};
	render::backend::BindSet *bind_set {nullptr};
	render::backend::CommandBuffer *command_buffer {nullptr};
	render::backend::FrameBuffer *frame_buffer {nullptr};
	render::backend::RenderPass *render_pass {nullptr};
	render::backend::UniformBuffer *uniform_buffer {nullptr};
	render::backend::PipelineState *pipeline_state {nullptr};

	Mesh quad;
};
