import tkinter as tk
from tkinter import filedialog, messagebox
import open3d as o3d
import laspy
import numpy as np

def convert_las_to_pcd(las_file_path):
    """将LAS文件转换为PCD格式。"""
    las = laspy.read(las_file_path)
    points = np.vstack((las.x, las.y, las.z)).transpose()
    pcd = o3d.geometry.PointCloud()
    pcd.points = o3d.utility.Vector3dVector(points)
    if hasattr(las, 'intensity'):
        pcd.intensities = o3d.utility.DoubleVector(las.intensity)
    return pcd

def preprocess_point_cloud(pcd, voxel_size):
    """对点云进行预处理。"""
    pcd_down = pcd.voxel_down_sample(voxel_size)
    radius_normal = voxel_size * 2
    pcd_down.estimate_normals(
        o3d.geometry.KDTreeSearchParamHybrid(radius=radius_normal, max_nn=30))
    return pcd_down

def surface_reconstruction(pcd_down):
    """从下采样的点云中重建表面。"""
    mesh, densities = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(
        pcd_down, depth=9)
    return mesh

def convert_to_stl():
    """选择点云文件，进行处理，并保存为STL格式。"""
    file_path = filedialog.askopenfilename(title="选择点云文件", filetypes=[("LAS files", "*.las"), ("PLY files", "*.ply"), ("PCD files", "*.pcd")])
    if not file_path:
        messagebox.showwarning("警告", "未选择文件！")
        return

    try:
        # 根据文件类型加载点云
        if file_path.lower().endswith('.las'):
            pcd = convert_las_to_pcd(file_path)
        else:
            pcd = o3d.io.read_point_cloud(file_path)

        if pcd.is_empty:
            raise ValueError("点云数据为空。")

        # 点云预处理
        voxel_size = 0.05  # 可根据需要调整
        pcd_down = preprocess_point_cloud(pcd, voxel_size)

        # 表面重建
        mesh = surface_reconstruction(pcd_down)

        # 保存为STL格式
        stl_file_path = file_path.rsplit(".", 1)[0] + ".stl"
        success = o3d.io.write_triangle_mesh(stl_file_path, mesh)
        if not success:
            raise IOError("保存STL文件失败。")
        messagebox.showinfo("完成", f"模型已保存为：{stl_file_path}")
    except Exception as e:
        messagebox.showerror("错误", f"处理过程中出现错误：{e}")

# 创建GUI窗口
root = tk.Tk()
root.title("点云转STL模型")

# 设置按钮
convert_button = tk.Button(root, text="选择点云并转换为STL", command=convert_to_stl)
convert_button.pack(pady=20)

# 运行GUI
root.mainloop()
