import subprocess
import numpy as np

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

if __name__ == "__main__":

    inputfile = "input.dat"
    alpha = 0.01
    phi = 1.0
    z0 = 0.0
    mod_input_alpha(inputfile, alpha)
    mod_input_phi(inputfile, phi)
    mod_input_z0(inputfile, z0)