BUILD_DIR = build

# The release target will perform additional optimization
# Don't use token pools in libMultiMarkdown
.PHONY : all
all: $(BUILD_DIR)
	sed -i 's/#define kUseObjectPool 1/#define kUseObjectPoolDisabled 1/g' submodules/mmd-6/Sources/libMultiMarkdown/include/token.h
	cd $(BUILD_DIR); \
	cmake -DCMAKE_BUILD_TYPE=Debug ..

# Clean out the build directory
.PHONY : clean
clean:
	rm -rf $(BUILD_DIR)/*

# Create build directory if it doesn't exist
$(BUILD_DIR): 
	-mkdir $(BUILD_DIR) 2>/dev/null
	-cd $(BUILD_DIR); rm -rf *
