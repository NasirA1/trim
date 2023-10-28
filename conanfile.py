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

    exports_sources = "include/*", "CMakeLists.txt", "src/*"  # Update according to your library structure

    def source(self):
        # This function is used to retrieve the source code of your library
        # For this example, let's assume you're using a CMake build system
        self.run("git clone https://github.com/your_username/your_repository.git")
        self.run("cd your_repository && git checkout tags/v1.0.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="your_repository")
        cmake.build()

    def package(self):
        # Specify the files to be included in the package
        self.copy("*.h", dst="include", src="your_repository/include")
        self.copy("*MyLibrary.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["MyLibrary"]
