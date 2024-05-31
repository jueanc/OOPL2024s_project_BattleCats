import os
import sys

def rename_files_in_folder(folder_path):
    # 獲取程式碼的檔名
    script_name = os.path.basename(sys.argv[0])
    # 遍歷資料夾中的文件
    for file_name in os.listdir(folder_path):
        # 排除程式碼檔案
        if file_name == script_name:
            continue
        # 檢查檔名中是否包含 "longcat_"
        if "snake_" in file_name:
            # 將檔名中的 "longcat_" 替換成空白
            new_file_name = file_name.replace("snake_", "")
            # 重命名文件
            os.rename(os.path.join(folder_path, file_name), os.path.join(folder_path, new_file_name))
            print(f"Renamed {file_name} to {new_file_name}")

# 使用範例
folder_path = os.path.dirname(os.path.abspath(__file__))
rename_files_in_folder(folder_path)
