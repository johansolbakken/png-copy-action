import os
import sys
import cairosvg

def convert_svg_to_png(svg_path, png_path):
    cairosvg.svg2png(url=svg_path, write_to=png_path)

def main(svg_folder, png_folder):
    if not os.path.exists(png_folder):
        os.makedirs(png_folder)

    svg_files = set()
    for root, _, files in os.walk(svg_folder):
        for file in files:
            if file.endswith('.svg'):
                svg_path = os.path.join(root, file)
                relative_path = os.path.relpath(svg_path, svg_folder)
                png_path = os.path.join(png_folder, relative_path.replace('.svg', '.png'))
                os.makedirs(os.path.dirname(png_path), exist_ok=True)
                convert_svg_to_png(svg_path, png_path)
                svg_files.add(png_path)

    existing_png_files = set()
    for root, _, files in os.walk(png_folder):
        for file in files:
            if file.endswith('.png'):
                png_path = os.path.join(root, file)
                existing_png_files.add(png_path)

    for png_file in existing_png_files - svg_files:
        os.remove(png_file)
        print(f"Deleted outdated PNG file: {png_file}")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python convert-svg-to-png.py <svg_folder> <png_folder> <github_token>")
        sys.exit(1)
    svg_folder = sys.argv[1]
    png_folder = sys.argv[2]
    github_token = sys.argv[3]
    main(svg_folder, png_folder)
