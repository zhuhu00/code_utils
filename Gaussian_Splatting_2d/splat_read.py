import numpy as np
import plyfile

# Define the path to your PLY file
ply_file_path = '/Users/hu/OneDrive - The Hong Kong Polytechnic University/19-Project_out/Vanilla_3DGS/bonsai/point_cloud/iteration_7000/point_cloud.ply'

# Read the PLY file
ply_data = plyfile.PlyData.read(ply_file_path)

# Access the vertex data
vertices = np.array(ply_data['vertex'].data)

# Print the number of vertices
print(f"Number of vertices: {len(vertices)}")

# Print the first 10 vertices
print(vertices[0])