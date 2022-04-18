import matplotlib.pyplot as plt
import numpy as np


def main():
    input_files = ["0.1.dat", "0.01.dat", "0.001.dat"]
    output_file = "steps.png"

    velocities = [np.loadtxt(f) for f in input_files]

    fig, ax = plt.subplots(figsize=(10, 8))
    for v, file_name in zip(velocities, input_files):
        step = range(len(v))
        ax.plot(step, v, label=file_name)

    plt.legend()
    plt.savefig(output_file)


if __name__ == "__main__":
    main()
