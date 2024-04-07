import os
import tkinter as tk
from tkinter import ttk, filedialog, messagebox

def merge_obj_files(directory, output_file, progress_callback):
    try:
        vertices, textures, normals, faces, materials = [], [], [], [], {}
        current_material, obj_count = None, sum(filename.endswith(".obj") for filename in os.listdir(directory))

        for index, filename in enumerate(os.listdir(directory)):
            if filename.endswith(".obj"):
                filepath = os.path.join(directory, filename)
                with open(filepath, 'r') as f:
                    for line in f:
                        if line.startswith('v '):
                            vertices.append(line)
                        elif line.startswith('vt '):
                            textures.append(line)
                        elif line.startswith('vn '):
                            normals.append(line)
                        elif line.startswith('usemtl '):
                            current_material = line.split()[1]
                            if current_material not in materials:
                                materials[current_material] = []
                        elif line.startswith('f '):
                            if current_material:
                                materials[current_material].append(line)

                progress_callback((index + 1) / obj_count * 100)

        with open(output_file, 'w') as f:
            for content in (vertices, textures, normals):
                f.writelines(content)
            for material, fs in materials.items():
                f.write(f'usemtl {material}\n')
                f.writelines(fs)

        messagebox.showinfo("Success", f'Merged OBJ file saved as {output_file}')
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

def select_directory():
    directory = filedialog.askdirectory()
    directory_entry.delete(0, tk.END)
    directory_entry.insert(0, directory)

def update_progress(progress):
    progress_var.set(progress)
    root.update_idletasks()

def start_merging():
    directory = directory_entry.get()
    output_file = output_file_entry.get()
    if not directory or not output_file:
        messagebox.showerror("Error", "Please specify both directory and output file name.")
        return
    merge_obj_files(directory, output_file, update_progress)
    progress_var.set(0)  # Reset progress bar

root = tk.Tk()
root.title("OBJ File Merger")

# Directory selection
tk.Label(root, text="Select directory with OBJ files:").pack()
directory_entry = tk.Entry(root, width=50)
directory_entry.pack()
tk.Button(root, text="Browse", command=select_directory).pack()

# Output file name
tk.Label(root, text="Output file name (e.g., merged_model.obj):").pack()
output_file_entry = tk.Entry(root, width=50)
output_file_entry.pack()

# Progress bar
progress_var = tk.DoubleVar()
progress_bar = ttk.Progressbar(root, length=200, variable=progress_var)
progress_bar.pack()

# Start button
tk.Button(root, text="Merge OBJ Files", command=start_merging).pack()

root.mainloop()
