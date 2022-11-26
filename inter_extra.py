import os

work_path = os.getcwd()

interp_path = "\\interp\\x64\\Release\\interp.exe"
extrap_path = "\\extrap\\x64\\Release\\extrap.exe"

print("1. Interpolation")
print("2. Extrapolation")
branch = input("Enter code = ")

if (branch == 1):
    os.system('{}'.format(work_path+interp_path))
else:
    os.system('{}'.format(work_path+extrap_path))