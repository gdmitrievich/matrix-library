CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c11
LDLIBS := -lcheck -lsubunit -lm

TARGET_NAME := s21_matrix
TARGET := $(TARGET_NAME).a

SRC_DIR := .
OBJ_DIR := ../obj
BIN_DIR := ../bin
TEST_DIR := ../test
GCOV_REPORT_DIR := ../gcov_report

HDRS := $(shell find $(SRC_DIR) -name '*.h')
SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TEST_PREFIX := _tests
TEST_SRCS := $(shell find $(TEST_DIR) -name '*$(TEST_PREFIX).c')
TEST_BINS := $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/%,$(TEST_SRCS))

TEST_HELPER_PREFIX := _helpers
TEST_HELPER_HDRS := $(shell find $(TEST_DIR) -name '*$(TEST_HELPER_PREFIX).h')
TEST_HELPER_SRCS := $(shell find $(TEST_DIR) -name '*$(TEST_HELPER_PREFIX).c')
TEST_HELPER_OBJS := $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/%.o,$(TEST_HELPER_SRCS))

.PHONY: all $(TARGET) test gcov_report clean ci correct_code_style memory_check

# TODO: Fix gcov_report error after running it as a dependency of 'all' target.
all: $(TARGET) test # gcov_report

# Builds static library for the s21_matrix project.
$(TARGET): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds test files and run them.
test: $(TEST_BINS)
	@for test_bin in $(TEST_BINS); do $$test_bin; done

$(BIN_DIR)/%$(TEST_PREFIX): $(OBJ_DIR)/%$(TEST_PREFIX).o $(TEST_HELPER_OBJS) $(TARGET)
	@mkdir -p $(@D)
	$(CC) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Generates code coverage report as html page and opens it.
gcov_report: CFLAGS += --coverage
gcov_report: LDLIBS += -lgcov
gcov_report: COVERAGE_INFO := $(GCOV_REPORT_DIR)/coverage.info
gcov_report: COVERAGE_HTML_DIR := $(GCOV_REPORT_DIR)/coverage_html
gcov_report: clean test
	@mkdir -p $(GCOV_REPORT_DIR) $(COVERAGE_HTML_DIR)
	@lcov --directory $(OBJ_DIR) --capture --output-file $(COVERAGE_INFO)
	@lcov --extract $(COVERAGE_INFO) '*/src/*' --output-file $(COVERAGE_INFO)
	@genhtml $(COVERAGE_INFO) --function-coverage --legend --output-directory $(COVERAGE_HTML_DIR)
	open $(COVERAGE_HTML_DIR)/index.html

# Cleans all generated artefacts.
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TARGET) $(GCOV_REPORT_DIR)

# -------------------- Others --------------------

# Corrects cody style, checks tests and memory issues.
ci: correct_code_style memory_check

# Corrects all *.h and *.c files from src and test dirs using clang-format tool.
correct_code_style:
	clang-format -i $(SRCS) $(HDRS) $(TEST_SRCS) $(TEST_HELPER_SRCS) $(TEST_HELPER_HDRS)

# Builds test files and checks them for memory issues using valgrind tool.
memory_check: CFLAGS += -g
memory_check: clean $(TEST_BINS)
	@for test_bin in $(TEST_BINS); do \
		if ! valgrind --leak-check=full --track-origins=yes --error-exitcode=1 ./$$test_bin; then \
			exit 1; \
		fi; \
  done