#pragma once
#include <Prey/CryRenderer/CommonResource.h>
#include <Prey/CryRenderer/ITexture.h>

class __declspec(align(8)) CTexture : public ITexture, public CBaseResource {
public:
	static constexpr size_t OFFSET_SHADER_RESOURCE = 0xB0;
};