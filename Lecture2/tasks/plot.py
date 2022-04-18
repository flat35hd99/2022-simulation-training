import matplotlib.pyplot as plt
import numpy as np


def load_and_plot(file, step_width, ax):
    v = np.loadtxt(file)
    time = np.array(range(len(v))) * step_width
    ax.plot(time, v, label=file)


def main():
    output_file = "steps.png"

    fig, ax = plt.subplots(figsize=(10, 8))
    ax.set_xlabel("time")
    ax.set_ylabel("velocity")
    # Plot calculated values
    load_and_plot("0.1.dat", 0.1, ax)
    load_and_plot("0.01.dat", 0.01, ax)
    load_and_plot("0.001.dat", 0.001, ax)

    # Plot theoritical value
    time = np.arange(40, step=0.01)
    velocity = 10 * np.exp(-time)
    ax.plot(time, velocity, label="theory")

    plt.legend()
    plt.savefig(output_file)


if __name__ == "__main__":
    main()
