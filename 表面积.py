import open3d as o3d
import tkinter as tk
from tkinter import filedialog, ttk, messagebox

# 函数：读取网格并计算表面积
def load_mesh_and_calculate_area(file_path):
    # 根据文件扩展名加载相应的网格
    mesh = o3d.io.read_triangle_mesh(file_path)

    # Open3D的TriangleMesh类没有is_triangle_mesh方法
    # 直接计算表面积
    surface_area = mesh.get_surface_area()
    return surface_area

# GUI 类
class MeshSurfaceAreaApp:
    def __init__(self, root):
        self.root = root
        root.title("网格表面积计算器")

        # 设置选择文件的按钮
        self.load_button = ttk.Button(root, text="选择网格文件", command=self.load_file)
        self.load_button.pack(pady=20)

        # 设置显示表面积的标签
        self.area_label = ttk.Label(root, text="表面积: 未计算")
        self.area_label.pack(pady=20)

    # 函数：加载文件并显示表面积
    def load_file(self):
        file_path = filedialog.askopenfilename(
            title="选择网格文件",
            filetypes=[("All mesh files", "*.ply *.stl *.obj"), ("PLY files", "*.ply"), ("STL files", "*.stl"), ("OBJ files", "*.obj")]
        )
        if file_path:
            try:
                area = load_mesh_and_calculate_area(file_path)
                self.area_label['text'] = f"表面积: {area:.2f}"
            except Exception as e:
                messagebox.showerror("错误", str(e))

# 主程序
if __name__ == "__main__":
    root = tk.Tk()
    app = MeshSurfaceAreaApp(root)
    root.mainloop()
