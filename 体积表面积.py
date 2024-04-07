import open3d as o3d
import tkinter as tk
from tkinter import filedialog, ttk, messagebox
import threading

class MeshVolumeApp:
    def __init__(self, root):
        self.root = root
        root.title("三角网格体积计算")

        # 设置选择文件按钮
        self.load_button = ttk.Button(root, text="选择三角网格文件", command=self.load_file)
        self.load_button.pack(pady=10)

        # 设置显示结果的标签
        self.result_label = ttk.Label(root, text="体积: 未计算")
        self.result_label.pack(pady=10)

    def load_file(self):
        file_path = filedialog.askopenfilename(
            filetypes=[
                ("Supported files", "*.ply;*.stl;*.obj"),
                ("PLY files", "*.ply"),
                ("STL files", "*.stl"),
                ("OBJ files", "*.obj"),
                ("All files", "*.*")
            ]
        )
        if file_path:
            self.result_label['text'] = "处理中..."
            # 在新线程中处理三角网格数据
            threading.Thread(target=self.calculate_volume, args=(file_path,)).start()

    def calculate_volume(self, file_path):
        try:
            # 根据文件扩展名读取三角网格文件
            mesh = o3d.io.read_triangle_mesh(file_path)
            if mesh.is_empty():
                raise ValueError("读取的网格为空。")

            if not mesh.is_watertight():
                messagebox.showwarning("警告", "网格不是水密的，体积计算可能不准确。")

            # 计算体积
            volume = mesh.get_volume()
            # 更新界面显示结果
            self.result_label['text'] = f"体积: {volume:.2f}"
        except Exception as e:
            messagebox.showerror("错误", f"处理三角网格数据时发生错误: {e}")
            self.result_label['text'] = "体积: 错误"

if __name__ == "__main__":
    root = tk.Tk()
    app = MeshVolumeApp(root)
    root.mainloop()
