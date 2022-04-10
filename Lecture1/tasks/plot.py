import matplotlib.pyplot as plt
import numpy as np

def main():
    input_file = "pi.csv"
    output_file = "pi.png"
    
    step, pi_calculated = np.loadtxt(input_file, delimiter=",", unpack=True)
    
    _, ax = plt.subplots()
    ax.plot(step, pi_calculated)
    ax.set_xlabel("steps")
    ax.set_ylabel("pi")
    ax.set_ylim([3.140, 3.144])
    plt.savefig(output_file)

if __name__ == '__main__':
    main()
