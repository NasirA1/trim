from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout


class ReusableStuffConan(ConanFile):
    name = "reusable_stuff"
    version = "1.0.0"

    # Optional metadata
    license = "Free software"
    author = "NasirA1"
    url = "TODO"
    description = "Conan components example"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "ai/*", "calc/*", "util/*"


    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.set_property("cmake_file_name", "reusable_stuff")

        self.cpp_info.components["ai"].includedirs = ["include/ai"]
        self.cpp_info.components["ai"].libs = ["ai"]
        self.cpp_info.components["ai"].set_property("cmake_target_name", "reusable_stuff::ai")

        self.cpp_info.components["util"].includedirs = ["include/util"]
        self.cpp_info.components["util"].libs = ["util"]
        self.cpp_info.components["util"].set_property("cmake_target_name", "reusable_stuff::util")

        self.cpp_info.components["calc"].includedirs = ["include/calc"]
        self.cpp_info.components["calc"].set_property("cmake_target_name", "reusable_stuff::calc")
