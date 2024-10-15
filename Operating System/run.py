import os
import shutil

folder_path = r"D:\All-Program\Collage\Operating System"

for filename in os.listdir(folder_path):
    if filename.endswith(".exe"):
        file_path = os.path.join(folder_path, filename)
        try:
            os.remove(file_path)
            print(f"Deleted: {file_path}")
        except OSError as e:
            print(f"Error deleting {file_path}: {e}")