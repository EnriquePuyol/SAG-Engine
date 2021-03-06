#version 400 core 

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec2 vertex_uv0;
layout(location = 2) in vec3 vertex_normal;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

out vec2 uv0;
out vec3 normal;
out vec3 position;

void main()
{
	position = (model * vec4(vertex_position, 1.0f)).xyz;
	normal = (model * vec4(vertex_normal, 0.0f)).xyz;
    gl_Position = proj*view*model * vec4(vertex_position, 1.0f);
	uv0 = vertex_uv0;
}
