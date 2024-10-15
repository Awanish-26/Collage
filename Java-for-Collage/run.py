import os
import shutil

folder_path = r"D:\All-Program\Collage\Java-for-Collage"

for filename in os.listdir(folder_path):
    if filename.endswith(".class"):
        file_path = os.path.join(folder_path, filename)
        try:
            os.remove(file_path)
            print(f"Deleted: {file_path}")
        except OSError as e:
            print(f"Error deleting {file_path}: {e}")

# source_folder = r"D:\Chrome Downloads"
# destination_folder = r"C:\Users\Bablu\Documents"

# # if not os.path.exists(destination_folder):
# #     os.makedirs(destination_folder)

# for filename in os.listdir(source_folder):
#     if filename.endswith(".pdf"):
#         source_file = os.path.join(source_folder, filename)
#         destination_file = os.path.join(destination_folder, filename)
#         try:
#             shutil.move(source_file, destination_file)
#             print(f"Moved: {source_file} to {destination_file}")
#         except shutil.Error as e:
#             print(f"Error moving {source_file}: {e}")

# folder_path = r"D:\Firefox Downloads\ImageAssistant Batch Image Downloader\www.pixground.com\2024-04-08_22-48-18\Nature_-_Elevate_Your_Screen_with_High-Quality_Wallpapers"

# for filename in os.listdir(folder_path):
#     if filename.endswith(".webp"):
#         old_file = os.path.join(folder_path, filename)
#         # Replace '.webp' with '.jpg'
#         new_file = os.path.join(folder_path, filename[:-5] + ".jpg")
#         try:
#             os.rename(old_file, new_file)
#             # print(f"Renamed: {old_file} to {new_file}")
#         except OSError as e:
#             print(f"Error renaming {old_file}: {e}")
