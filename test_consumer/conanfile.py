import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.build import cross_building


class TestConsumerConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps", "VirtualBuildEnv"
    build_requires = "cmake/3.27.7"
    requires = "reusable_stuff/1.0.0@nasir/wip"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

