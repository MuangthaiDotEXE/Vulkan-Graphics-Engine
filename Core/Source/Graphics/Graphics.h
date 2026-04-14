#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

namespace Core
{
	class Graphics
	{
	protected:
	public:
		Graphics();
		virtual ~Graphics() = default;

		virtual void Render() = 0;
		virtual void Update() = 0;
	};
}

#endif
