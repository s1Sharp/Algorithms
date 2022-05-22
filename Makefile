all: build

build:
	cmake --build build/ --config Release --target ALL_BUILD -j 6

bench: Build 

bench_sorting: Build
	./executable/Release/sorting*
