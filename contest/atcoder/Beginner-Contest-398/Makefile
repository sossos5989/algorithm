CXX = clang++
CXXFLAGS = -Wall -g

# 타겟 파일 이름
TARGET = test
SOURCE = c.cc

# 기본 타겟
all: $(TARGET)

# test.o 생성
test.o: $(SOURCE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# test 실행 파일 생성
$(TARGET): test.o
	$(CXX) $(CXXFLAGS) test.o -o $(TARGET)

# 정리
clean:
	rm -f test.o $(TARGET)