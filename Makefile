CXX = g++
CXXFLAGS = -Wextra -Wall --std=c++17 -pedantic
CXXINPUTLIB = -I /usr/local/include/opencv2
CXXLIB = -lopencv_core -lopencv_imgcodecs -lopencv_features2d -lopencv_xfeatures2d -lopencv_flann -lopencv_videoio -lopencv_highgui

build: main.o TreeNDimensionalSpace.o LinearCoefficients.o IsVecInNDimensionalSpace.o LNorm.o ComparisonOfDescriptors.o
	$(CXX) $(CXXFLAGS) main.o TreeNDimensionalSpace.o LinearCoefficients.o IsVecInNDimensionalSpace.o LNorm.o ComparisonOfDescriptors.o -o ApplicationStart $(CXXINPUTLIB) $(CXXLIB)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c $(CXXINPUTLIB) $(CXXLIB)

TreeNDimensionalSpace.o: TreeNDimensionalSpace.cpp
	$(CXX) $(CXXFLAGS) TreeNDimensionalSpace.cpp -c $(CXXINPUTLIB) $(CXXLIB)

LinearCoefficients.o: LinearCoefficients.cpp
	$(CXX) $(CXXFLAGS) LinearCoefficients.cpp -c $(CXXINPUTLIB) $(CXXLIB)

IsVecInNDimensionalSpace.o: IsVecInNDimensionalSpace.cpp
	$(CXX) $(CXXFLAGS) IsVecInNDimensionalSpace.cpp -c $(CXXINPUTLIB) $(CXXLIB)

LNorm.o: LNorm.cpp
	$(CXX) $(CXXFLAGS) LNorm.cpp -c $(CXXINPUTLIB) $(CXXLIB)

ComparisonOfDescriptors.o: ComparisonOfDescriptors.cpp
	$(CXX) $(CXXFLAGS) ComparisonOfDescriptors.cpp -c $(CXXINPUTLIB) $(CXXLIB)

clean:
	rm main.o TreeNDimensionalSpace.o LinearCoefficients.o IsVecInNDimensionalSpace.o LNorm.o ComparisonOfDescriptors.o ApplicationStart
