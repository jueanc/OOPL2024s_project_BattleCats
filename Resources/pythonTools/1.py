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
        # 檢查檔名是否以 "bi_attack_" 開頭
        if file_name.startswith("bi_walk_"):
            # 取得檔案的序號部分（例如 bi_attack_0.bmp 中的 0）
            file_number = file_name.split("_")[-1].split(".")[0]
            # 新的檔案名稱為 "attack_" 加上序號和檔案副檔名
            new_file_name = f"walk_{file_number}.bmp"
            # 重命名文件
            os.rename(os.path.join(folder_path, file_name), os.path.join(folder_path, new_file_name))
            print(f"Renamed {file_name} to {new_file_name}")

# 使用範例
folder_path = os.path.dirname(os.path.abspath(__file__))
rename_files_in_folder(folder_path)
