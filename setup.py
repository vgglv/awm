import subprocess

def main():
    cmake = ['cmake']
    cmake.append('-B build')
    cmake.append('-GNinja')
    cmake.append('.')
    cmake.append('-DAWM_BUILD_TESTS=1')
    cmake.append('-DCMAKE_EXPORT_COMPILE_COMMANDS=1')
    subprocess.run(cmake)

if __name__ == "__main__":
    main()
