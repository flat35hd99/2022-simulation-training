import matplotlib.pyplot as plt
import numpy as np


def main():
    input_file = "pi.csv"
    output_file = "pi.png"

    step, pi_calculated = np.loadtxt(input_file, delimiter=",", unpack=True)
    pi_diff = pi_calculated - np.pi

    fig, axs = plt.subplots(nrows=2, figsize=(10, 8))
    axs[0].set_title("Pi calculated")
    axs[0].plot(step, pi_calculated)
    axs[0].set_xlabel("steps")
    axs[0].set_ylabel("pi")
    axs[0].set_ylim([3.140, 3.144])

    axs[1].set_title("Diff with theoretical value")
    axs[1].plot(step, pi_diff)
    axs[1].set_xlabel("steps")
    axs[1].set_ylabel("Diff")
    plt.savefig(output_file)


if __name__ == '__main__':
    main()
