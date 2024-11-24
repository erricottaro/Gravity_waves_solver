import subprocess
import numpy as np 

def start_program():
    #command to execute the program
    execute_command = "./main"

    #execute bash command
    print("Computing trajectory...")
    subprocess.run(execute_command, shell=True)
    print("... done")

def mod_input_phi(filename, new_phi):
    with open(filename, 'r') as file:
        lines = file.readlines()
    
    with open(filename, 'w') as file:
        for line in lines:
            if line.startswith("PHI"):
                new_line = f"PHI      {new_phi}\n"
                file.write(new_line)
            else:
                file.write(line)

def copy_output(phi):
    #name of file where to copy the output
    filename = f"phi/{format(phi, '.3f')}=phi.txt"
    #command to copy the output
    copy_command = "cp output.dat "+filename

    #execute the command
    print("Copying output...")
    subprocess.run(copy_command, shell=True)
    print("... done")

if __name__ == "__main__":

    inputfile = "input.dat"
    #define a set of parameters phi
    phi_range = np.linspace(0.5, 2.0, 16)
    print(phi_range)

    for phi in phi_range:
        print("Phi=", phi)
        mod_input_phi(inputfile, phi)
        start_program()
        copy_output(phi)
    