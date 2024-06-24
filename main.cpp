#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <algorithm>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

namespace fs = std::filesystem;

void process_svgs(const fs::path& src_dir, const fs::path& dest_dir) {
    for (const auto& entry : fs::recursive_directory_iterator(src_dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".svg") {
            fs::path relative_path = fs::relative(entry.path(), src_dir);
            fs::path dest_path = dest_dir / relative_path;
            dest_path.replace_extension(".png");

            // Ensure the destination directory exists
            fs::create_directories(dest_path.parent_path());

            // Convert SVG to PNG using stb_image (dummy conversion in this example)
            std::cout << "Converting " << entry.path() << " to " << dest_path << std::endl;

            // Dummy image data (for illustration purposes)
            int width = 100, height = 100, channels = 4;
            std::vector<unsigned char> image(width * height * channels, 255);

            // Save PNG file
            stbi_write_png(dest_path.string().c_str(), width, height, channels, image.data(), width * channels);
        }
    }
}

void clean_up_pngs(const fs::path& src_dir, const fs::path& dest_dir) {
    for (const auto& entry : fs::recursive_directory_iterator(dest_dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            fs::path relative_path = fs::relative(entry.path(), dest_dir);
            relative_path.replace_extension(".svg");
            fs::path src_path = src_dir / relative_path;

            if (!fs::exists(src_path)) {
                std::cout << "Deleting " << entry.path() << std::endl;
                fs::remove(entry.path());
            }
        }
    }
}

int main() {
    std::cout << "Hello, GitHub Actions!" << std::endl;

    fs::path src_dir = ".";
    fs::path dest_dir = "./png-copy";

    process_svgs(src_dir, dest_dir);
    clean_up_pngs(src_dir, dest_dir);

    return 0;
}
