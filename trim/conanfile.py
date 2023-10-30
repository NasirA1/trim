from conans import ConanFile, CMake, tools

class TrimConan(ConanFile):
    name = "trim"
    version = "1.0.0"
    license = "Free software"
    url = "https://github.com/NasirA1/trim"
    description = "Sample Conan recipe for a C++ lib package"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"

    generators = "cmake"
    export_source = "include/*", "src/*", "CMakeLists.txt", "*.cmake"

    build_requires = (
        "cmake/3.27.7",
    )


    def source(self):
        self.run("git clone https://github.com/NasirA1/trim")
        self.run("cd trim && git checkout conan_tut3")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="trim/trim")
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        # self.cpp_info.libs = ["libutil.a", "libai.a"]
        self.cpp_info.names["cmake_find_package"] = "trim"
        self.cpp_info.names["cmake_find_package_multi"] = "trim"
        self.cpp_info.components["ai"].names["cmake_find_package"] = "ai"
        self.cpp_info.components["ai"].libs = "libai.a"
        self.cpp_info.components["util"].names["cmake_find_package"] = "util"
        self.cpp_info.components["util"].libs = "libutil.a"
