import subprocess

def main():
    cmake = ['cmake']
    cmake.append('-B build')
    cmake.append('-GNinja')
    cmake.append('.')
    cmake.append('-DAWM_BUILD_TESTS=1')
    cmake.append('-DCMAKE_EXPORT_COMPILE_COMMANDS=1')
    cmake.append('-DCMAKE_CXX_STANDARD=20')
    subprocess.run(cmake)

    build = ['cmake']
    build.append('--build')
    build.append('build')
    build.append('--config Debug')
    subprocess.run(build)

if __name__ == "__main__":
    main()
