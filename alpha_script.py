import subprocess
import numpy as np 

def start_program():
    #command to execute the program
    execute_command = "./main"

    #execute bash command
    print("Computing trajectory...")
    subprocess.run(execute_command, shell=True)
    print("... done")

def mod_input_alpha(filename, new_alpha):
    with open(filename, 'r') as file:
        lines = file.readlines()
    
    with open(filename, 'w') as file:
        for line in lines:
            if line.startswith("ALPHA"):
                new_line = f"ALPHA      {new_alpha}\n"
                file.write(new_line)
            else:
                file.write(line)

def copy_output(alpha):
    #name of file where to copy the output
    filename = f"alpha/{format(alpha, '.3f')}=alpha.txt"
    #command to copy the output
    copy_command = "cp output.dat "+filename

    #execute the command
    print("Copying output...")
    subprocess.run(copy_command, shell=True)
    print("... done")

if __name__ == "__main__":

    inputfile = "input.dat"
    #define a set of parameters alpha
    alpha_range = np.linspace(0.01, 0.1, 10)
    
    for alpha in alpha_range:
        print("Alpha=", alpha)
        mod_input_alpha(inputfile, alpha)
        start_program()
        copy_output(alpha)
