import os
import math


def real_std_err(avg, data, data_size):
    s_sq = 0.0
    for i in range(data_size):
        s_sq += (data[i] - avg) * (data[i] - avg)
    s_sq /= (data_size - 1)
    s = math.sqrt(s_sq)
    std_err = s / math.sqrt(data_size)
    rse = std_err / avg * 100
    return rse


progs = ["adress_sort", "index_sort", "pointer_sort"]
arrs = os.listdir("data/arrs")
opts = ["O0", "O2"]
runs = int(open("../measures/runs.txt").read())

for prog in progs:
    for arr in arrs:
        for opt in opts:
            print(f"{prog}_{arr}_{opt}")
            print("t_n")
            lens = os.listdir(f"../measures/{prog}/{arr}/{opt}")
            for i in range(len(lens)):
                lens[i] = int(lens[i].replace(".txt", ""))
            lens.sort()
            for length in lens:
                with open(f"../measures/{prog}/{arr}/{opt}/{length}.txt") as runs_file:
                    times = runs_file.read().split()
                total_sum = 0
                times = list(map(int, times))
                for time in times:
                    total_sum += time
                average_time = total_sum / runs
                rse = real_std_err(average_time, times, runs)
                print(f"{rse:.2f}")
            print("\n\n")
