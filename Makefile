all: build

build:
	cmake --build build/ --config Release --target ALL_BUILD -j 6

