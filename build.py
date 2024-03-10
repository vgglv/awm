import subprocess

def main():
    cmake = ['cmake']
    cmake.append('--build')
    cmake.append('build')
    subprocess.run(cmake)


if __name__ == "__main__":
    main()
