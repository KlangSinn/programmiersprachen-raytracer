#include <thread>
#include <renderer.hpp>
#include <fensterchen.hpp>
#include <vector>

int main(int argc, char* argv[]) {

	std::vector<Material> materials = SDFLoader::readFile("materials.sdf");
	for (int i = 0; i < materials.size(); ++i) {
		std::cout << materials[i];
	}

	unsigned const width = 600;
	unsigned const height = 600;
	std::string const filename = "./checkerboard.ppm";

	Renderer app(width, height, filename);

	std::thread thr([&app]() { app.render(); });

	Window win(glm::ivec2(width,height));

	while (!win.shouldClose()) {
	if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
		win.stop();
	}

	glDrawPixels( width, height, GL_RGB, GL_FLOAT
				, app.colorbuffer().data());

	win.update();
	}

	thr.join();

	return 0;
}
