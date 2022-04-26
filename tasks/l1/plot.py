import numpy as np
import matplotlib.pyplot as plt
import sys

def main():
    data = np.loadtxt(sys.argv[1])
    fig, ax = plt.subplots()
    
    theory = lambda x: (1/np.sqrt(2 * np.pi)) * np.exp(- (x**2)/2)
    
    hist, bin_edge = np.histogram(data, bins=100, density=True)

    bin_edge_shift = np.roll(bin_edge, -1)
    bin_center = (bin_edge + bin_edge_shift)/2
    bin_center = bin_center[:-1]
    
    theoritical_value = theory(bin_center)
    
    ax.plot(bin_center, hist, label="random")
    ax.plot(bin_center, theoritical_value, label="theory")
    plt.legend()
    plt.savefig("diff_between_random_and_theory.png")
    
    diff = hist - theoritical_value
    rms = np.sum(np.sqrt(diff**2))
    print(f"RMS = {rms}")

if __name__ == '__main__':
    main()
    