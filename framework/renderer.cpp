// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------
#define _USE_MATH_DEFINES

#include "renderer.hpp"
#include <math.h>

Renderer::Renderer(unsigned w, unsigned h, std::string const& file, SDFLoader const& sdfloader) 
	: width_(w)
	, height_(h)
	, colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
	, filename_(file)
	, ppm_(width_, height_)
	, sdfloader_(sdfloader)
{}

void Renderer::render() {

	// get objects
	camera_ = sdfloader_.getCamera();
	shapes_ = sdfloader_.getShapes();
	lights_ = sdfloader_.getLights();

	// calculate distance from IP to camera by given opening angle
	camera_.position = glm::vec3(0, 0, tan((90 - camera_.opening_angle / 2) * M_PI / 180) * (width_ / 2));

	// output all scene objects and parameters
	testOutput(); 

	Ray prim_ray;
	for (unsigned y = 0; y < height_; ++y) {
		for (unsigned x = 0; x < width_; ++x) {
			Pixel p(x, y);

			// create ray
			glm::vec3 poip = glm::vec3((double)x - width_ / 2, (double)y - height_ / 2, 0);
			prim_ray.origin = camera_.position;
			prim_ray.direction = poip - camera_.position;

			// find closest object to IP
			double delta = -1;
			Shape *closest_obj;
			for (int i = 0; i < shapes_.size(); ++i) {
				double d = shapes_[i]->intersect(prim_ray);
				if (d > 1.0 && (d < delta || delta == -1)) {
					delta = d;
					closest_obj = shapes_[i];
				}
			}

			// calculate color
			if (delta == -1) {
				p.color = Color(0.0, 0.0, 0.0);
			} else {
				glm::vec3 hit_point = prim_ray.origin + (float) delta * prim_ray.direction;
				p.color = calculateColor(closest_obj, hit_point);
			}

			// draw pixel
			write(p);
		}
	}
	ppm_.save(filename_);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}

void Renderer::testOutput() {
	std::cout << "Objekte der Szene" << std::endl;
	for (int i = 0; i < shapes_.size(); ++i) {
		std::cout << "Objekt: " << shapes_[i]->getName() << std::endl;
	}
	for (int i = 0; i < lights_.size(); ++i) {
		std::cout << "Lichtquelle: " << lights_[i]->getName() << std::endl;
	}
	std::cout << "Camera: " << camera_.name << " | Focal Length: " << camera_.position.z << std::endl;
}

Color Renderer::calculateColor(const Shape* hit_obj, glm::vec3 const& hit_point) {
	Color final_color = Color(0.0, 0.0, 0.0);
	for (int i = 0; i < lights_.size(); ++i) {

		// normal at hit point and direction to light source
		glm::vec3 n = hit_obj->getNormalAt(hit_point);
		glm::vec3 l = lights_[i]->getPosition() - hit_point;
		
		// Ray to light source
		Ray sec_ray = Ray(hit_point, l);

		// Diffuse Light
		Color diffuse_light;
		if (!isInShadow(sec_ray) && glm::dot(glm::normalize(n), glm::normalize(l)) > 0) {
			Color Ip = lights_[i]->getLD();
			Color kd = hit_obj->getMaterial().getKD();			
			diffuse_light = (Ip * kd * glm::dot(glm::normalize(n), glm::normalize(l)));
		} else {
			diffuse_light = Color(0.0, 0.0, 0.0);
		}

		// Ambient Light
		Color Ia = lights_[i]->getLA();
		Color ka = hit_obj->getMaterial().getKA();
		Color ambient_light = Ia * ka;

		// Lightning Equation
		final_color += diffuse_light + ambient_light;
	}	
	return final_color;
}

bool Renderer::isInShadow(Ray sec_ray) {
	for (int i = 0; i < shapes_.size(); ++i) {
		double d = shapes_[i]->intersect(sec_ray);
		if (d > 0 && d < 1)
			return true;
	}
	return false;
}
