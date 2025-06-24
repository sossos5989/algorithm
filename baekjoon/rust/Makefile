# Rust 컴파일러 및 옵션
RUSTC     = rustc
RUSTFLAGS = -C debuginfo=2   # 디버깅 심볼 포함, 최적화 레벨은 기본(0)

# 타겟 파일 이름과 소스 파일
TARGET = test
SOURCE = boj16916.rs

# .PHONY 지정
.PHONY: all clean`

# 기본 타겟: 바이너리 생성
all: $(TARGET)

# 소스에서 실행 파일 생성
$(TARGET): $(SOURCE)
	$(RUSTC) $(RUSTFLAGS) -o $@ $<

touch:
	touch $(SOURCE)

# 정리
clean:
	rm -f $(TARGET)

