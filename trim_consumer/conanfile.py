from conans import ConanFile, CMake, tools

class TrimConsumer(ConanFile):
    # Other configurations for your project
    generators = "cmake"

    def requirements(self):
        self.requires("trim/1.0.0@nasir/wip", components={"calc", "util"})
