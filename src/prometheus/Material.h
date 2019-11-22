#pragma once
#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include <memory>
#include <string>
#include <rend/rend.h>


#include "Resource.h"

namespace prometheus
{
	class Model;


	class Material : public	Resource
	{
	public:
		void load(std::string shader);
		void setModel(std::shared_ptr<Model> model);
		void setUniform();

		std::shared_ptr<rend::Shader> getMaterial();

	private:
		std::shared_ptr<rend::Shader> shader;
		const char* src =
			"#ifdef VERTEX                                 \n" \
			"                                              \n" \
			"attribute vec3 a_Position;                    \n" \
			"attribute vec2 a_TexCoord;                    \n" \
			"                                              \n" \
			"uniform mat4 u_Projection;                    \n" \
			"                                              \n" \
			"varying vec2 v_TexCoord;                      \n" \
			"                                              \n" \
			"void main()                                   \n" \
			"{                                             \n" \
			"  vec3 pos = a_Position + vec3(0, 0, -5);     \n" \
			"  gl_Position = u_Projection * vec4(pos, 1);  \n" \
			"  v_TexCoord = a_TexCoord;                    \n" \
			"}                                             \n" \
			"                                              \n" \
			"#endif                                        \n" \
			"#ifdef FRAGMENT                               \n" \
			"                                              \n" \
			"varying vec2 v_TexCoord;                      \n" \
			"                                              \n" \
			"void main()                                   \n" \
			"{                                             \n" \
			"  gl_FragColor = vec4(v_TexCoord, 0, 1);      \n" \
			"}                                             \n" \
			"                                              \n" \
			"#endif                                        \n";

	};
}
#endif // !_MATERIAL_H_
