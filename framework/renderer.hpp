// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>

#include "sdfloader.h"

class Renderer {
public:
  Renderer(unsigned w, unsigned h, std::string const& file, SDFLoader const& sdfloader);

  void render();
  void write(Pixel const& p);
  void testOutput();
  Color calculateColor(const Shape* hit_obj, glm::vec3 const& hit_point);

  inline std::vector<Color> const& colorbuffer() const {
    return colorbuffer_;
  }

private:
  unsigned width_;
  unsigned height_;
  std::vector<Color> colorbuffer_;
  std::string filename_;
  PpmWriter ppm_;
  SDFLoader sdfloader_;

  Camera camera_;
  std::vector<Shape*> shapes_;
  std::vector<Light*> lights_;
};

#endif // #ifndef BUW_RENDERER_HPP
