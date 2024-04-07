import tkinter as tk
from tkinter import filedialog, messagebox
import open3d as o3d
import threading

class MeshViewerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Mesh and Point Cloud Viewer")

        # Load Point Cloud Button
        self.load_btn = tk.Button(root, text="Load Point Cloud", command=self.load_point_cloud)
        self.load_btn.pack(pady=5)

        # Ball Pivoting Reconstruction Button
        self.reconstruct_btn = tk.Button(root, text="Ball Pivoting Reconstruction", command=self.start_ball_pivoting, state='disabled')
        self.reconstruct_btn.pack(pady=5)

        self.pcd = None

    def load_point_cloud(self):
        file_path = filedialog.askopenfilename(filetypes=[("PLY files", "*.ply"), ("All files", "*.*")])
        if file_path:
            self.pcd = o3d.io.read_point_cloud(file_path)
            o3d.visualization.draw_geometries([self.pcd])
            self.reconstruct_btn['state'] = 'normal'
        else:
            messagebox.showinfo("Info", "No file selected.")

    def ball_pivoting(self):
        if self.pcd:
            radii = [0.005, 0.01, 0.02, 0.04]
            rec_mesh = o3d.geometry.TriangleMesh.create_from_point_cloud_ball_pivoting(
                self.pcd, o3d.utility.DoubleVector(radii))
            o3d.visualization.draw_geometries([self.pcd, rec_mesh])
        else:
            messagebox.showinfo("Info", "Please load a point cloud first.")

    def start_ball_pivoting(self):
        threading.Thread(target=self.ball_pivoting, daemon=True).start()

if __name__ == "__main__":
    root = tk.Tk()
    app = MeshViewerApp(root)
    root.mainloop()
