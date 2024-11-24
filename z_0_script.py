import subprocess
import numpy as np 

def start_program():
    #command to execute the program
    execute_command = "./main"

    #execute bash command
    print("Computing trajectory...")
    subprocess.run(execute_command, shell=True)
    print("... done")

def mod_input_z0(filename, new_z0):
    with open(filename, 'r') as file:
        lines = file.readlines()
    
    with open(filename, 'w') as file:
        for line in lines:
            if line.startswith("Z0"):
                new_line = f"Z0      {new_z0}\n"
                file.write(new_line)
            else:
                file.write(line)

def copy_output(z0):
    #name of file where to copy the output
    filename = f"z0/{format(z0, '.3f')}=z0.txt"
    #command to copy the output
    copy_command = "cp output.dat "+filename

    #execute the command
    print("Copying output...")
    subprocess.run(copy_command, shell=True)
    print("... done")

if __name__ == "__main__":

    inputfile = "input.dat"
    #define a set of parameters z0
    z0_range = np.linspace(-1.0, -0.1, 10)
    
    for z0 in z0_range:
        print("z0=", z0)
        mod_input_z0(inputfile, z0)
        start_program()
        copy_output(z0)